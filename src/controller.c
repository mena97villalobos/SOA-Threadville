#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
#include<cairo.h>
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include"interface.h"
#include"linked_list_cars.h"
#include "vehicle.h"

static node_t *node = NULL;
static int contador = 0;

//Called when window is closed
void on_window_main_destroy(GtkWidget *widget, gpointer user_data) {
    gtk_main_quit();
}

void on_press_btn_create_car_aleatory(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Carro aleatorio creado");
    // TODO CREATE CAR
    ThreadvilleMap *map = create_threadville_map();
    Vehicle* v = create_vehicle(BLUE_CAR, NORTH);
    VehicleThreadInfo *vti = create_vehicle_thread_info(v, map);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vti);
    pthread_detach(maintenance_thread);

    printf("%s\n", "Carro creado");

    contador++;
//    printf("%s\n", "Carro aleatorio creado");
//    contador++;
//    node = create_object(contador, BLUECARF, 0.223, 0.223,"B1");
//    node = create_object(contador, BLUECARF, 0.223, 0.196,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.169,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.142,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.115,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.088,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.061,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.034,"Z1");
//    node = create_object(contador, BLUECARF, 0.223, 0.007,"Z1");
//    edit_semaphore(1, SEMAPHOREU);
//    edit_semaphore(2, SEMAPHORED);
}

void on_press_btn_create_car_config(GtkWidget *widget, gpointer user_data) {
    printf("%s\n", "Carro eliminado");
    detele_object(contador--);
}

void on_press_btn_create_bus_blue(GtkWidget *widget, gpointer user_data) {
    edit_object(contador, BLUECARF, 0.223, 0.223, "B1");
    // H018P = 678 = 0.223, 0.223
}

void on_press_btn_delete_bus_blue(GtkWidget *widget, gpointer user_data) {
    edit_object_with_node(node, BLUECARB, 0.223, 0.223, "B1");
}