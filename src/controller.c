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
//    ThreadvilleMap *map = create_threadville_map();
//    Vehicle* v = create_vehicle(BLUE_CAR, NORTH);
//    VehicleThreadInfo *vti = create_vehicle_thread_info(v, map);
//
//    pthread_t maintenance_thread;
//    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vti);
//    pthread_detach(maintenance_thread);

//    printf("%s\n", "Carro creado");

//    contador++;
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

//++Fila0
    //Segmento 0
    create_object(++contador, BLUECARF, 0.085, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.101, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.117, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.133, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.149, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.165, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.181, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.007,"B1");
    //Segmento 1
    create_object(++contador, BLUECARF, 0.2235, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.2425, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.2585, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.2745, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.2905, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.3065, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.3225, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.007,"B1");
    //Segmento 2
    create_object(++contador, BLUECARF, 0.365, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.384, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.400, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.416, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.432, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.448, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.464, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.007,"B1");
    //Segmento 3
    create_object(++contador, BLUECARF, 0.5035, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.5225, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.5385, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.5545, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.5705, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.5865, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.6025, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.007,"B1");
    //Segmento 4
    create_object(++contador, BLUECARF, 0.644, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.663, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.679, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.695, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.711, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.727, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.743, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.007,"B1");
    //Segmento 5
    create_object(++contador, BLUECARF, 0.785, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.803, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.819, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.834, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.851, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.867, 0.007,"B1");
    create_object(++contador, BLUECARL, 0.883, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.007,"B1");

//++Fila1
    //Segmento 0
    create_object(++contador, BLUECARF, 0.085, 0.194,"B1");//++Fila1
    create_object(++contador, BLUECARL, 0.101, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.117, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.133, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.149, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.165, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.181, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.194,"B1");
    //Segmento 1
    create_object(++contador, BLUECARF, 0.2235, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.2425, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.2585, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.2745, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.2905, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.3065, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.3225, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.194,"B1");
    //Segmento 2
    create_object(++contador, BLUECARF, 0.365, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.384, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.400, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.416, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.432, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.448, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.464, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.194,"B1");
    //Segmento 3
    create_object(++contador, BLUECARF, 0.5035, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.5225, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.5385, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.5545, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.5705, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.5865, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.6025, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.194,"B1");
    //Segmento 4
    create_object(++contador, BLUECARF, 0.644, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.663, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.679, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.695, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.711, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.727, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.743, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.194,"B1");
    //Segmento 5
    create_object(++contador, BLUECARF, 0.785, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.803, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.819, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.834, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.851, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.867, 0.194,"B1");
    create_object(++contador, BLUECARL, 0.883, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.194,"B1");    
//++Fila2
    //Segmento 0
    create_object(++contador, BLUECARF, 0.085, 0.778,"B1");//++Fila1
    create_object(++contador, BLUECARL, 0.101, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.117, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.133, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.149, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.165, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.181, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.778,"B1");
    //Segmento 1
    create_object(++contador, BLUECARF, 0.2235, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.2425, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.2585, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.2745, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.2905, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.3065, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.3225, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.778,"B1");
    //Segmento 2
    create_object(++contador, BLUECARF, 0.365, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.384, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.400, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.416, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.432, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.448, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.464, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.778,"B1");
    //Segmento 3
    create_object(++contador, BLUECARF, 0.5035, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.5225, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.5385, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.5545, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.5705, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.5865, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.6025, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.778,"B1");
    //Segmento 4
    create_object(++contador, BLUECARF, 0.644, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.663, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.679, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.695, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.711, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.727, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.743, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.778,"B1");
    //Segmento 5
    create_object(++contador, BLUECARF, 0.785, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.803, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.819, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.834, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.851, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.867, 0.778,"B1");
    create_object(++contador, BLUECARL, 0.883, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.778,"B1");
//++Fila3
    //Segmento 0
    create_object(++contador, BLUECARF, 0.085, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.101, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.117, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.133, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.149, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.165, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.181, 0.965,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.965,"B1");
    //Segmento 1
    create_object(++contador, BLUECARF, 0.2235, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.2425, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.2585, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.2745, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.2905, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.3065, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.3225, 0.965,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.965,"B1");
    //Segmento 2
    create_object(++contador, BLUECARF, 0.365, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.384, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.400, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.416, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.432, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.448, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.464, 0.965,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.965,"B1");
    //Segmento 3
    create_object(++contador, BLUECARF, 0.5035, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.5225, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.5385, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.5545, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.5705, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.5865, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.6025, 0.965,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.965,"B1");
    //Segmento 4
    create_object(++contador, BLUECARF, 0.644, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.663, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.679, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.695, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.711, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.727, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.743, 0.965,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.965,"B1");
    //Segmento 5
    create_object(++contador, BLUECARF, 0.785, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.803, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.819, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.834, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.851, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.867, 0.965,"B1");
    create_object(++contador, BLUECARL, 0.883, 0.965,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.965,"B1");

//Parte superior
//Columna 0
    create_object(++contador, BLUECARF, 0.085, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.345,"B1");
//Columna 1
    create_object(++contador, BLUECARF, 0.200, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.345,"B1");
//Columna 2
    create_object(++contador, BLUECARF, 0.2235, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.345,"B1");
//Columna 3
    create_object(++contador, BLUECARF, 0.3415, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.345,"B1");
//Columna 4
    create_object(++contador, BLUECARF, 0.365, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.345,"B1");
//Columna 5
    create_object(++contador, BLUECARF, 0.483, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.345,"B1");
//Columna 6
    create_object(++contador, BLUECARF, 0.5035, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.345,"B1");
//Columna 7
    create_object(++contador, BLUECARF, 0.6215, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.345,"B1");
//Columna 8
    create_object(++contador, BLUECARF, 0.644, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.345,"B1");
//Columna 9
    create_object(++contador, BLUECARF, 0.762, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.345,"B1");
//Columna 10
    create_object(++contador, BLUECARF, 0.785, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.163,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.345,"B1");
//Columna 11
    create_object(++contador, BLUECARF, 0.900, 0.007,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.040,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.065,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.090,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.115,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.138,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.163,"B1"); 
    create_object(++contador, BLUECARF, 0.900, 0.194,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.226,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.251,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.275,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.300,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.323,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.345,"B1");


//Parte inferior
//Columna 0
    create_object(++contador, BLUECARF, 0.085, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.085, 0.965,"B1");
//Columna 1
    create_object(++contador, BLUECARF, 0.200, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.200, 0.965,"B1");
//Columna 2
    create_object(++contador, BLUECARF, 0.2235, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.2235, 0.965,"B1");
//Columna 3
    create_object(++contador, BLUECARF, 0.3415, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.3415, 0.965,"B1");
//Columna 4
    create_object(++contador, BLUECARF, 0.365, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.365, 0.965,"B1");
//Columna 5
    create_object(++contador, BLUECARF, 0.483, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.483, 0.965,"B1");
//Columna 6
    create_object(++contador, BLUECARF, 0.5035, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.5035, 0.965,"B1");
//Columna 7
    create_object(++contador, BLUECARF, 0.6215, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.6215, 0.965,"B1");
//Columna 8
    create_object(++contador, BLUECARF, 0.644, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.644, 0.965,"B1");
//Columna 9
    create_object(++contador, BLUECARF, 0.762, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.762, 0.965,"B1");
//Columna 10
    create_object(++contador, BLUECARF, 0.785, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.785, 0.965,"B1");
//Columna 11
    create_object(++contador, BLUECARF, 0.900, 0.629,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.654,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.676,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.700,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.723,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.750,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.778,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.812,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.839,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.861,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.882,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.907,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.933,"B1");
    create_object(++contador, BLUECARF, 0.900, 0.965,"B1");
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