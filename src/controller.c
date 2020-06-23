#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
#include<cairo.h>
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<stdbool.h> 
#include"interface.h"
#include"linked_list_cars.h"
#include"vehicle.h"
#include "globals.h"

static node_t *node = NULL;
static int contador = 0;
static int cartype = 1;

//Definition funtions
void change_botons_sensitive(char* active, char* desactive);

//Called when window is closed
void on_window_main_destroy(GtkWidget *widget, gpointer user_data) {
    gtk_main_quit();
}

void on_press_btn_create_car_aleatory(GtkWidget *widget, gpointer user_data) {
//    Vehicle* v = create_vehicle(BLUE_BUS, NORTH);
    Vehicle* v = create_vehicle(BLUE_CAR, NORTH);
    VehicleThreadInfo* vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
}

void on_press_btn_create_car_config(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Carro configurado creado");
}

void on_press_btn_create_bus_red(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus rojo creado");
    change_botons_sensitive("btn_dbr", "btn_cbr");
}

void on_press_btn_delete_bus_red(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus rojo eliminado");
    change_botons_sensitive("btn_cbr", "btn_dbr");
}

void on_press_btn_create_bus_gray(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus gris creado");
    change_botons_sensitive("btn_dbg", "btn_cbg");
}

void on_press_btn_delete_bus_gray(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus gris eliminado");
    change_botons_sensitive("btn_cbg", "btn_dbg");
}

void on_press_btn_create_bus_green(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus verde creado");
    change_botons_sensitive("btn_dbgr", "btn_cbgr");
}

void on_press_btn_delete_bus_green(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus verde eliminado");
    change_botons_sensitive("btn_cbgr", "btn_dbgr");
}

void on_press_btn_create_bus_pink(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus rosa creado");
    change_botons_sensitive("btn_dbp", "btn_cbp");
}

void on_press_btn_delete_bus_pink(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus rosa eliminado");
    change_botons_sensitive("btn_cbp", "btn_dbp");
}

void on_press_btn_create_bus_orange(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus naranja creado");
    change_botons_sensitive("btn_dbo", "btn_cbo");
}

void on_press_btn_delete_bus_orange(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus naranja eliminado");
    change_botons_sensitive("btn_cbo", "btn_dbo");
}

void on_press_btn_create_bus_lblue(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus celeste creado");
    change_botons_sensitive("btn_dblb", "btn_cblb");
}

void on_press_btn_delete_bus_lblue(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus celeste eliminado");
    change_botons_sensitive("btn_cblb", "btn_dblb");
}

void on_press_btn_create_bus_blue(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus azul creado");
    change_botons_sensitive("btn_dbb", "btn_cbb");
}

void on_press_btn_delete_bus_blue(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus azul eliminado");
    change_botons_sensitive("btn_cbb", "btn_dbb");
}

void on_press_btn_create_bus_white(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus blanco creado");
    change_botons_sensitive("btn_dbw", "btn_cbw");
}

void on_press_btn_delete_bus_white(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus blanco eliminado");
    change_botons_sensitive("btn_cbw", "btn_dbw");
}

void on_press_btn_create_bus_black(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus negro creado");
    change_botons_sensitive("btn_dbbl", "btn_cbbl");
}

void on_press_btn_delete_bus_black(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Bus negro eliminado");
    change_botons_sensitive("btn_cbbl", "btn_dbbl");
}

void on_press_btn_create_ambulance(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Ambulancia creada");

}


//Funtions
void change_botons_sensitive(char* active, char* desactive) {
    
    GtkWidget *active_w= GTK_WIDGET(gtk_builder_get_object(builder, active));;
    GtkWidget *desactive_w = GTK_WIDGET(gtk_builder_get_object(builder, desactive));;
    gtk_widget_set_sensitive(desactive_w, false);
    gtk_widget_set_sensitive(active_w, true);

}