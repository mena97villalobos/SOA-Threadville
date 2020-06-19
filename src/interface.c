#include"interface.h"
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<pthread.h>
#include<string.h>
#include"dict.h"
#include"linked_list_cars.h"
#include "utils.h"


#define SIZE 68 //Number is the same of the len in the enum in interface.h
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
    insertDict(MAP, create_item("images/MAP.PNG", MAP, 1.0, 1.0), hashImages, SIZE);
    //SEMAPHORE load
    insertDict(SEMAPHORED, create_item("images/SD.png", SEMAPHORED, 0.16, 0.020), hashImages, SIZE);
    insertDict(SEMAPHOREU, create_item("images/SU.png", SEMAPHOREU, 0.16, 0.020), hashImages, SIZE);
    //REPAIR load
    insertDict(REPAIR, create_item("images/REPAIR.jpg", REPAIR, 0.025, 0.015), hashImages, SIZE);
    //Red bus load
    insertDict(REDBUSL, create_item("images/RED_BL.png", REDBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(REDBUSR, create_item("images/RED_BR.png", REDBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(REDBUSB, create_item("images/RED_BB.png", REDBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(REDBUSF, create_item("images/RED_BF.png", REDBUSF, 0.050, 0.015), hashImages, SIZE);
    //Grenn bus load
    insertDict(GREENBUSL, create_item("images/GREEN_BL.png", GREENBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(GREENBUSR, create_item("images/GREEN_BR.png", GREENBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(GREENBUSB, create_item("images/GREEN_BB.png", GREENBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(GREENBUSF, create_item("images/GREEN_BF.png", GREENBUSF, 0.050, 0.015), hashImages, SIZE);
    //Blue bus load
    insertDict(BLUEBUSL, create_item("images/BLUE_BL.png", BLUEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(BLUEBUSR, create_item("images/BLUE_BR.png", BLUEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(BLUEBUSB, create_item("images/BLUE_BB.png", BLUEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(BLUEBUSF, create_item("images/BLUE_BF.png", BLUEBUSF, 0.050, 0.015), hashImages, SIZE);
    //White busload    
    insertDict(WHITEBUSL, create_item("images/WHITE_BL.png", WHITEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(WHITEBUSR, create_item("images/WHITE_BR.png", WHITEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(WHITEBUSB, create_item("images/WHITE_BB.png", WHITEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(WHITEBUSF, create_item("images/WHITE_BF.png", WHITEBUSF, 0.050, 0.015), hashImages, SIZE);
     //Gray bus load   
    insertDict(GRAYBUSL, create_item("images/GRAY_BL.png", GRAYBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(GRAYBUSR, create_item("images/GRAY_BR.png", GRAYBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(GRAYBUSB, create_item("images/GRAY_BB.png", GRAYBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(GRAYBUSF, create_item("images/GRAY_BF.png", GRAYBUSF, 0.050, 0.015), hashImages, SIZE);
     //Black bus load   
    insertDict(BLACKBUSL, create_item("images/BLACK_BL.png", BLACKBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(BLACKBUSR, create_item("images/BLACK_BR.png", BLACKBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(BLACKBUSB, create_item("images/BLACK_BB.png", BLACKBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(BLACKBUSF, create_item("images/BLACK_BF.png", BLACKBUSF, 0.050, 0.015), hashImages, SIZE);
     //Pink bus load   
    insertDict(PINKBUSL, create_item("images/PINK_BL.png", PINKBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(PINKBUSR, create_item("images/PINK_BR.png", PINKBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(PINKBUSB, create_item("images/PINK_BB.png", PINKBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(PINKBUSF, create_item("images/PINK_BF.png", PINKBUSF, 0.050, 0.015), hashImages, SIZE);
     //Ligth blue bus load   
    insertDict(LIGHTBLUEBUSL, create_item("images/LBLUE_BL.png", LIGHTBLUEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(LIGHTBLUEBUSR, create_item("images/LBLUE_BR.png", LIGHTBLUEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(LIGHTBLUEBUSB, create_item("images/LBLUE_BB.png", LIGHTBLUEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(LIGHTBLUEBUSF, create_item("images/LBLUE_BF.png", LIGHTBLUEBUSF, 0.050, 0.015), hashImages, SIZE);
    //Orange bus load  
    insertDict(ORANGEBUSL, create_item("images/ORANGE_BL.png", ORANGEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertDict(ORANGEBUSR, create_item("images/ORANGE_BR.png", ORANGEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertDict(ORANGEBUSB, create_item("images/ORANGE_BB.png", ORANGEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertDict(ORANGEBUSF, create_item("images/ORANGE_BF.png", ORANGEBUSF, 0.050, 0.015), hashImages, SIZE);
     //Ambulance load   
    insertDict(AMBULANCEL, create_item("images/AMBULANCEL.jpg", AMBULANCEL, 0.025, 0.015), hashImages, SIZE);
    insertDict(AMBULANCER, create_item("images/AMBULANCER.jpg", AMBULANCER, 0.025, 0.015), hashImages, SIZE);
    insertDict(AMBULANCEB, create_item("images/AMBULANCEB.jpg", AMBULANCEB, 0.025, 0.015), hashImages, SIZE);
    insertDict(AMBULANCEF, create_item("images/AMBULANCEF.jpg", AMBULANCEF, 0.025, 0.015), hashImages, SIZE);
    //Red car load  
    insertDict(REDCARL, create_item("images/REDL.jpg", REDCARL, 0.025, 0.015), hashImages, SIZE);
    insertDict(REDCARR, create_item("images/REDR.jpg", REDCARR, 0.025, 0.015), hashImages, SIZE);
    insertDict(REDCARB, create_item("images/REDB.jpg", REDCARB, 0.025, 0.015), hashImages, SIZE);
    insertDict(REDCARF, create_item("images/REDF.jpg", REDCARF, 0.025, 0.015), hashImages, SIZE);
    //Green car load    
    insertDict(GREENCARL, create_item("images/GREENL.jpg", GREENCARL, 0.025, 0.015), hashImages, SIZE);
    insertDict(GREENCARR, create_item("images/GREENR.jpg", GREENCARR, 0.025, 0.015), hashImages, SIZE);
    insertDict(GREENCARB, create_item("images/GREENB.jpg", GREENCARB, 0.025, 0.015), hashImages, SIZE);
    insertDict(GREENCARF, create_item("images/GREENF.jpg", GREENCARF, 0.025, 0.015), hashImages, SIZE);
    //Blue car load
    insertDict(BLUECARL, create_item("images/BLUEL.jpg", BLUECARL, 0.025, 0.015), hashImages, SIZE);
    insertDict(BLUECARR, create_item("images/BLUER.jpg", BLUECARR, 0.025, 0.015), hashImages, SIZE);
    insertDict(BLUECARB, create_item("images/BLUEB.jpg", BLUECARB, 0.025, 0.015), hashImages, SIZE);
    insertDict(BLUECARF, create_item("images/BLUEF.jpg", BLUECARF, 0.025, 0.015), hashImages, SIZE);
    //White car load
    insertDict(WHITECARL, create_item("images/WHITEL.jpg", WHITECARL, 0.025, 0.015), hashImages, SIZE);
    insertDict(WHITECARR, create_item("images/WHITER.jpg", WHITECARR, 0.025, 0.015), hashImages, SIZE);
    insertDict(WHITECARB, create_item("images/WHITEB.jpg", WHITECARB, 0.025, 0.015), hashImages, SIZE);
    insertDict(WHITECARF, create_item("images/WHITEF.jpg", WHITECARF, 0.025, 0.015), hashImages, SIZE);
    //Black car load    
    insertDict(BLACKCARL, create_item("images/BLACKL.jpg", BLACKCARL, 0.025, 0.015), hashImages, SIZE);
    insertDict(BLACKCARR, create_item("images/BLACKR.jpg", BLACKCARR, 0.025, 0.015), hashImages, SIZE);
    insertDict(BLACKCARB, create_item("images/BLACKB.jpg", BLACKCARB, 0.025, 0.015), hashImages, SIZE);
    insertDict(BLACKCARF, create_item("images/BLACKF.jpg", BLACKCARF, 0.025, 0.015), hashImages, SIZE);
     //Yellow car load   
    insertDict(YELLOWCARL, create_item("images/YELLOWL.jpg", YELLOWCARL, 0.025, 0.015), hashImages, SIZE);
    insertDict(YELLOWCARR, create_item("images/YELLOWR.jpg", YELLOWCARR, 0.025, 0.015), hashImages, SIZE);
    insertDict(YELLOWCARB, create_item("images/YELLOWB.jpg", YELLOWCARB, 0.025, 0.015), hashImages, SIZE);
    insertDict(YELLOWCARF, create_item("images/YELLOWF.jpg", YELLOWCARF, 0.025, 0.015), hashImages, SIZE);


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

    int tentatibe_width = real_w*actual_width;
    int tentatibe_height = real_w*(int)((((float)h/(float)w)*(float)actual_width)*(float)real_w);

    GdkPixbuf * final_image  = NULL;

    if (tentatibe_height<= actual_height){
        final_image =  gdk_pixbuf_scale_simple (image,
                             tentatibe_width,
                             (int)((((float)h/(float)w)*(float)actual_width)*(float)real_w),
                             GDK_INTERP_BILINEAR);
    }else{
        final_image =  gdk_pixbuf_scale_simple (image,
                             (int)((((float)w/(float)h)*(float)actual_height)*(float)real_h),
                             real_h*actual_height,
                             GDK_INTERP_BILINEAR);
    }

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
	if (result == -2){
		if(vehicle_list->data!=NULL){
			free(vehicle_list->data);
		}
		free(vehicle_list);
		vehicle_list = NULL;
	}
	pthread_mutex_unlock(&lock_vehicle);
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