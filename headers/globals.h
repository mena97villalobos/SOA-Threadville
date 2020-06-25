//
// Created by bmena on 6/18/20.
//

#ifndef PROYECTO3_GLOBALS_H
#define PROYECTO3_GLOBALS_H

#include <gtk/gtk.h>
#include <gtk/gtktypes.h>
#include "threadville_map.h"
#include <stdbool.h>


GtkBuilder *builder;
GtkWidget *window;

ThreadvilleMap *map;

volatile int K = 0;
volatile int M = 0;
volatile int N = 0;


volatile bool isa_bred  = false;
volatile bool isa_bgreen  = false;
volatile bool isa_borange  = false;
volatile bool isa_bblue  = false;
volatile bool isa_bgray  = false;
volatile bool isa_bpink  = false;
volatile bool isa_blblue  = false;
volatile bool isa_bwhite  = false;
volatile bool isa_bblack  = false;

#endif //PROYECTO3_GLOBALS_H
