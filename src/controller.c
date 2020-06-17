#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
#include<cairo.h>
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include"interface.h"
#include"linked_list_cars.h"
#include "vehicle.h"
#include "floyd.h"

static node_t *node = NULL;
static int contador = 0;
static int cartype = 1;


//Called when window is closed
void on_window_main_destroy(GtkWidget *widget, gpointer user_data) {
    gtk_main_quit();
}

void on_press_btn_create_car_aleatory(GtkWidget *widget, gpointer user_data) {
    if (contador>66){
        return;
    }
    detele_object(contador-1);
    printf("%s\n", "Carro aleatorio creado");
    create_object(contador, cartype, 0.0,0.0,"B1");
    printf("%d\n", cartype);
    cartype++;
    contador++;

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