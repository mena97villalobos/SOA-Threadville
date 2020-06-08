#ifndef PROYECTO3_THREADVILLE_MAP_H
#define PROYECTO3_THREADVILLE_MAP_H

#include "hash_table.h"

typedef struct ThreadvilleMap {
    Table *map;
} ThreadvilleMap;

ThreadvilleMap *create_threadville_map();

void insert_highways(Table *, pthread_mutexattr_t *);

void insert_bridges(Table *, pthread_mutexattr_t *);

void insert_roundabouts(Table *, pthread_mutexattr_t *);

void insert_stops(Table *, pthread_mutexattr_t *);

void insert_streets(Table *, pthread_mutexattr_t *);

#endif //PROYECTO3_THREADVILLE_MAP_H
