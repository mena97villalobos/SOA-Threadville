#ifndef PROYECTO3_THREADVILLE_MAP_H
#define PROYECTO3_THREADVILLE_MAP_H

#include "hash_table.h"
#include "hash_table_street_info.h"
#include "utils.h"

typedef struct ThreadvilleMap {
    Table *map;
    TableStreetInfo* streetInfoTable;
} ThreadvilleMap;

ThreadvilleMap *create_threadville_map();

void insert_highways(Table *, TableStreetInfo *, pthread_mutexattr_t *);

void insert_bridges(Table *, TableStreetInfo *, pthread_mutexattr_t *);

void insert_roundabouts(Table *, TableStreetInfo *, pthread_mutexattr_t *);

void insert_stops(Table *, TableStreetInfo *, pthread_mutexattr_t *);

void insert_streets(Table *, TableStreetInfo *, pthread_mutexattr_t *);

void insert_corners(Table *, TableStreetInfo *, pthread_mutexattr_t *);

void insert_street_info_highways(TableStreetInfo *, HighwaysIds);

void insert_street_info_bridge(TableStreetInfo *, BridgeIds);

void insert_street_info_bridge_up(TableStreetInfo *t, BridgeIds id);

void insert_street_info_roundabouts(TableStreetInfo *, RoundaboutIds);

void insert_street_info_stops(TableStreetInfo *, StopIds);

void insert_street_info_streets(TableStreetInfo *, StreetIds);

void insert_street_info_corners(TableStreetInfo *, CornersIds);

#endif //PROYECTO3_THREADVILLE_MAP_H
