#include"interface.h"
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<pthread.h>
#include<string.h>
#include"dict.h"
#include"linked_list_cars.h"


#define SIZE 62 //Number is the same of the len in the enum in interface.h
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

//Variables to calculate the responsive in a quick time
static struct DataItem* hashImages[SIZE];
static struct data_node* semaphores[5];
static int before_height = 0;
static int before_width = 0;
static int map_height = 0;
static int map_width = 0;
static node_t * vehicle_list = NULL;
static gint64 last_tick = 0;
static int fps = 60;
static pthread_mutex_t lock_vehicle;
static pthread_mutex_t lock_semaphore;

//Definition of functions
struct DataItem * create_item(char *image_path, images_enum type_item, float real_height, float real_width);
GdkPixbuf * transform_image(GdkPixbuf *map_image, float real_h, float real_w, int actual_height, int actual_width);
GdkPixbuf * transform_image_relation(GdkPixbuf *image, float real_h, float real_w, int actual_height, int actual_width);
void paint_all_map(cairo_t *cr);
void paint_vehicles(cairo_t *cr);
data_node * create_semaphore(images_enum type_image_p, float x, float y);
void generate_semaphores();

//Funtions code
void load_interface(){
    //MAP load
    insertDict(MAP, create_item("images/Map.PNG", MAP, 1.0, 1.0), hashImages, SIZE);
    //SEMAPHORE load
    insertDict(SEMAPHORED, create_item("images/SD.png", SEMAPHORED, 0.16, 0.020), hashImages, SIZE);
    insertDict(SEMAPHOREU, create_item("images/SU.png", SEMAPHOREU, 0.16, 0.020), hashImages, SIZE);
    //Blue car load
    insertDict(BLUECARL, create_item("images/BLUECARL.jpg", BLUECARL, 0.027, 0.015), hashImages, SIZE);
    insertDict(BLUECARR, create_item("images/BLUECARR.jpg", BLUECARR, 0.027, 0.015), hashImages, SIZE);
    insertDict(BLUECARB, create_item("images/BLUECARB.jpg", BLUECARB, 0.027, 0.019), hashImages, SIZE);
    insertDict(BLUECARF, create_item("images/BLUECARF.jpg", BLUECARF, 0.027, 0.019), hashImages, SIZE);



	if (pthread_mutex_init(&lock_vehicle, NULL) != 0){
        printf("\n Mutex of vehicle init failed\n");
    }
    if (pthread_mutex_init(&lock_semaphore, NULL) != 0){
        printf("\n Mutex of semaphore init failed\n");
    }
    //Generate semaphores
    generate_semaphores();
}

void generate_semaphores(){
    semaphores[0] = create_semaphore(SEMAPHORED, 0.211, 0.42);
    semaphores[1] = create_semaphore(SEMAPHORED, 0.351, 0.42);
    semaphores[2] = create_semaphore(SEMAPHORED, 0.491, 0.42);
    semaphores[3] = create_semaphore(SEMAPHORED, 0.632, 0.42);
    semaphores[4] = create_semaphore(SEMAPHORED, 0.773, 0.42);
}

data_node * create_semaphore(images_enum type_image_p, float x, float y){
    struct data_node *data_add = (struct data_node*) malloc(sizeof(struct data_node));
    
    //Data to draw images
    data_add->width = x;
    data_add->height = y;
    data_add->type_image = type_image_p;
    return data_add;
}

void paint_semaphores(cairo_t *cr){
    struct DataItem *item = NULL;

    for (int i = 0; i < 5; ++i)
    {
        item = search(semaphores[i]->type_image, hashImages, SIZE);
        gdk_cairo_set_source_pixbuf(cr, 
            item->trans_image, 
            semaphores[i]->width*map_width,
            semaphores[i]->height*map_height);
        cairo_paint(cr);
    }
}

void paint_vehicles(cairo_t *cr){
	if (vehicle_list==NULL){
		return;
	}

	struct DataItem *item = NULL;
	node_t * current = vehicle_list;
    while (current != NULL) {
        //Draw vehicule
    	item = search(current->data->type_image, hashImages, SIZE);
    	gdk_cairo_set_source_pixbuf(cr, 
    		item->trans_image, 
    		current->data->width*map_width,
    		current->data->height*map_height);
        cairo_paint(cr);
        //Pos of text 
        int total_h = item->real_h*map_height;
        int total_w = item->real_w*map_width;
        //Write text for vehicule
        cairo_set_source_rgb (cr, 0.0/255.0, 0.0/255.0, 255.0/255.0);
        cairo_set_font_size(cr, (0.80)*min(total_w,total_h));
        cairo_move_to(cr, current->data->width*map_width, current->data->height*map_height+(1.3*(total_h)/2));
        cairo_show_text(cr, current->data->next_stop);
        cairo_fill(cr);
        //Next element
        current = current->next;
    }

}

void paint_all_map(cairo_t *cr){
	struct DataItem *item = search(MAP, hashImages, SIZE);
	gdk_cairo_set_source_pixbuf(cr, item->trans_image, 0, 0);
    cairo_paint(cr);
    paint_semaphores(cr);
    paint_vehicles(cr);
}

struct DataItem * create_item(char *image_path, images_enum type_item, float real_height, float real_width){
	GError *err = NULL;
	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	if(err){
        printf("Error : %s\n", err->message);
        g_error_free(err);
    }
	item-> key = type_item;
	item-> image = gdk_pixbuf_new_from_file(image_path, &err);
	item-> width = gdk_pixbuf_get_width(item-> image);
   	item-> height = gdk_pixbuf_get_height(item-> image);
   	item-> real_h = real_height;
  	item-> real_w = real_width;
    item-> trans_image = NULL;
    return item;
}

//CCall every n FPS
gboolean on_tick (gpointer *parameters) {
	GtkWidget *drawing = (GtkWidget *)parameters;
    gint64 current = g_get_real_time ();
    if ((current - last_tick) < (1000/ fps)) {
        last_tick = current;
        return G_SOURCE_CONTINUE;
    }

    //Posible error de semaforos
	gtk_widget_queue_draw_area(drawing, 0, 0, before_width, before_height);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}

GdkPixbuf * transform_image(GdkPixbuf *image, float real_h, float real_w, int actual_height, int actual_width){
    GdkPixbuf * final_image =  gdk_pixbuf_scale_simple (image,
                         real_w*actual_width,
                         real_h*actual_height,
                         GDK_INTERP_BILINEAR);

    return final_image;
}

GdkPixbuf * transform_image_relation(GdkPixbuf *image, float real_h, float real_w, int actual_height, int actual_width){
    int w,h;
    w = gdk_pixbuf_get_width(image);
    h = gdk_pixbuf_get_height(image);


    GdkPixbuf * final_image =  gdk_pixbuf_scale_simple (image,
                         real_w*actual_width,
                         (int)((((float)h/(float)w)*(float)actual_width)*(float)real_w),
                         GDK_INTERP_BILINEAR);

    return final_image;
}

gboolean on_window_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data){
    int actual_height = gtk_widget_get_allocated_height (widget);
    int actual_width = gtk_widget_get_allocated_width (widget);
    int flat = 0;

    //Posible error de semaforos
    if (before_height!= actual_height) {
    	before_height = actual_height;
    	flat = 1;
    }
    if (before_width!= actual_width) {
    	before_width = actual_width;\
    	flat = 1;
    }
    
    if (flat == 1){

        //Mao responsive
        struct DataItem *item_map = search(MAP, hashImages, SIZE);
        item_map->trans_image = transform_image_relation(item_map->image,
            item_map->real_h, 
            item_map->real_w,
            before_height, 
            before_width);
        map_height = gdk_pixbuf_get_height(item_map->trans_image);
        map_width = gdk_pixbuf_get_width(item_map->trans_image);

        //All image responsive about the map
    	for(int i = 0; i<SIZE; i++) {
            if(i!=MAP){
        		if(hashImages[i] != NULL){
        			if (hashImages[i]-> trans_image != NULL){
        				g_object_unref(hashImages[i]-> trans_image);
        			}
        			hashImages[i]->trans_image = transform_image(hashImages[i]->image, 
        				hashImages[i]->real_h, 
    	      			hashImages[i]->real_w,
    	      			map_height, 
    	      			map_width);
        		}	
    		}
    	}
    }
    pthread_mutex_lock(&lock_vehicle);
    pthread_mutex_lock(&lock_semaphore);
    paint_all_map(cr);
    pthread_mutex_unlock(&lock_semaphore);
    pthread_mutex_unlock(&lock_vehicle);
    return TRUE;
}

node_t * create_object(int num, images_enum type_image_p, float x, float y, char * next_stop_p){
	struct data_node *data_add = (struct data_node*) malloc(sizeof(struct data_node));
	
	//Data to draw images
	data_add->width = x;
	data_add->height = y;
	data_add->type_image = type_image_p;
    strcpy(data_add->next_stop, next_stop_p);

	pthread_mutex_lock(&lock_vehicle);
	node_t * new_node;
	if (vehicle_list==NULL){
		vehicle_list = (node_t *) malloc(sizeof(node_t));
		vehicle_list->val = num;
		vehicle_list->next = NULL;
		vehicle_list->data = data_add;
		new_node = vehicle_list;
	}else{
		new_node = push_begin(&vehicle_list, num, data_add);

	}
    pthread_mutex_unlock(&lock_vehicle);
	printf("Carro pintado\n");
	fflush(stdout);
    return new_node;

	print_list(vehicle_list);
}

void detele_object(int num){
	pthread_mutex_lock(&lock_vehicle);
	if (vehicle_list==NULL){
		pthread_mutex_unlock(&lock_vehicle);
		return;
	}

	int result = remove_by_val(&vehicle_list, num);
	if (result == -1){
		if(vehicle_list->data!=NULL){
			free(vehicle_list->data);
		}
		free(vehicle_list);
		vehicle_list = NULL;
	}
	pthread_mutex_unlock(&lock_vehicle);

	printf("%d\n", result);
	print_list(vehicle_list);
}

void edit_object(int num, images_enum type_image_p, float x_p, float y_p, char * next_stop_p){
    pthread_mutex_lock(&lock_vehicle);
    node_t * current = vehicle_list;
    while (current != NULL) {
    	if(current->val == num){
    		current->data->width = x_p;
    		current->data->height = y_p;
    		current->data->type_image = type_image_p;
            strcpy(current->data->next_stop, next_stop_p);
    		break;
    	}
        current = current->next;
    }
    pthread_mutex_unlock(&lock_vehicle);
}

void edit_semaphore(int num, images_enum type_image_p){
    if(num>=0 && num<5){
        pthread_mutex_lock(&lock_semaphore);
        semaphores[num]->type_image = type_image_p;
        pthread_mutex_unlock(&lock_semaphore);
    }
}

void edit_object_with_node(node_t * node, images_enum type_image_p, float x_p, float y_p, char * next_stop_p){
    printf("Editando carro\n");
    fflush(stdout);
    pthread_mutex_lock(&lock_vehicle);
    node->data->width = x_p;
    node->data->height = y_p;
    node->data->type_image = type_image_p;
    strcpy(node->data->next_stop, next_stop_p);
    pthread_mutex_unlock(&lock_vehicle);
    printf("Carro editado\n");
    fflush(stdout);
}

images_enum from_vehicle_type(VehicleType type, VehicleDir dir) {
    switch (type) {
        case RED_BUS:
            switch (dir) {
                case NORTH:
                    return REDBUSB;
                case SOUTH:
                    return REDBUSF;
                case WEST:
                    return REDBUSL;
                case EAST:
                    return REDBUSR;
            }
            break;
        case GREEN_BUS:
            switch (dir) {
                case NORTH:
                    return GREENBUSB;
                case SOUTH:
                    return GREENBUSF;
                case WEST:
                    return GREENBUSL;
                case EAST:
                    return GREENBUSR;
            }
            break;
        case BLUE_BUS:
            switch (dir) {
                case NORTH:
                    return BLUEBUSB;
                case SOUTH:
                    return BLUEBUSF;
                case WEST:
                    return BLUEBUSL;
                case EAST:
                    return BLUEBUSR;
            }
            break;
        case WHITE_BUS:
            switch (dir) {
                case NORTH:
                    return WHITEBUSB;
                case SOUTH:
                    return WHITEBUSF;
                case WEST:
                    return WHITEBUSL;
                case EAST:
                    return WHITEBUSR;
            }
            break;
        case GRAY_BUS:
            switch (dir) {
                case NORTH:
                    return GRAYBUSB;
                case SOUTH:
                    return GRAYBUSF;
                case WEST:
                    return GRAYBUSL;
                case EAST:
                    return GRAYBUSR;
            }
            break;
        case BLACK_BUS:
            switch (dir) {
                case NORTH:
                    return BLACKBUSB;
                case SOUTH:
                    return BLACKBUSF;
                case WEST:
                    return BLACKBUSL;
                case EAST:
                    return BLACKBUSR;
            }
            break;
        case PINK_BUS:
            switch (dir) {
                case NORTH:
                    return PINKBUSB;
                case SOUTH:
                    return PINKBUSF;
                case WEST:
                    return PINKBUSL;
                case EAST:
                    return PINKBUSR;
            }
            break;
        case LIGHT_BLUE_BUS:
            switch (dir) {
                case NORTH:
                    return LIGHTBLUEBUSB;
                case SOUTH:
                    return LIGHTBLUEBUSF;
                case WEST:
                    return LIGHTBLUEBUSL;
                case EAST:
                    return LIGHTBLUEBUSR;
            }
            break;
        case ORANGE_BUS:
            switch (dir) {
                case NORTH:
                    return ORANGEBUSB;
                case SOUTH:
                    return ORANGEBUSF;
                case WEST:
                    return ORANGEBUSL;
                case EAST:
                    return ORANGEBUSR;
            }
            break;
        case AMBULANCE:
            switch (dir) {
                case NORTH:
                    return AMBULANCEB;
                case SOUTH:
                    return AMBULANCEF;
                case WEST:
                    return AMBULANCEL;
                case EAST:
                    return AMBULANCER;
            }
            break;
        case RED_CAR:
            switch (dir) {
                case NORTH:
                    return REDCARB;
                case SOUTH:
                    return REDCARF;
                case WEST:
                    return REDCARL;
                case EAST:
                    return REDCARR;
            }
            break;
        case BLUE_CAR:
            switch (dir) {
                case NORTH:
                    return BLUECARB;
                case SOUTH:
                    return BLUECARF;
                case WEST:
                    return BLUECARL;
                case EAST:
                    return BLUECARR;
            }
            break;
        case GREEN_CAR:
            switch (dir) {
                case NORTH:
                    return GREENCARB;
                case SOUTH:
                    return GREENCARF;
                case WEST:
                    return GREENCARL;
                case EAST:
                    return GREENCARR;
            }
            break;
        case BLACK_CAR:
            switch (dir) {
                case NORTH:
                    return BLACKCARB;
                case SOUTH:
                    return BLACKCARF;
                case WEST:
                    return BLACKCARL;
                case EAST:
                    return BLACKCARR;
            }
            break;
        case WHITE_CAR:
            switch (dir) {
                case NORTH:
                    return WHITECARB;
                case SOUTH:
                    return WHITECARF;
                case WEST:
                    return WHITECARL;
                case EAST:
                    return WHITECARR;
            }
            break;
        case YELLOW_CAR:
            switch (dir) {
                case NORTH:
                    return YELLOWCARB;
                case SOUTH:
                    return YELLOWCARF;
                case WEST:
                    return YELLOWCARL;
                case EAST:
                    return YELLOWCARR;
            }
            break;
    }
}