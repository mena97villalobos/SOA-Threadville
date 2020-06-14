#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "threadville_maintenance.h"
#include "threadville_map.h"
#include "interface.h"

//Interface variables
GtkWidget *window;
GtkWidget *drA_maps_images;

//Interface builder
GtkBuilder *builder;

int main(int argc, char *argv[]) {
    ThreadvilleMap *map = create_threadville_map();
    MaintenanceInfo *maintenanceInfo = create_maintenance_info(map);

//    pthread_t maintenance_thread;
//    pthread_create(&maintenance_thread, NULL, &run_maintenance, maintenanceInfo);
//    pthread_join(maintenance_thread, NULL);

    //Init
    gtk_init(&argc, &argv);
    load_interface();

    //Add glade files
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/threadville.glade", NULL);

    //Conect xml with code with main code/variables
    window = GTK_WIDGET(gtk_builder_get_object(builder, "win_threadville"));
    drA_maps_images = GTK_WIDGET(gtk_builder_get_object(builder, "drA_maps_images"));
    g_signal_connect(drA_maps_images, "draw", G_CALLBACK(on_window_draw), NULL);


    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    g_timeout_add(1000 / 60 / 2, (GSourceFunc) on_tick, drA_maps_images);  //60 is the fps

    gtk_main();

    return 0;
}
