#ifndef PROYECTO3_THREADVILLE_MAINTENANCE_H
#define PROYECTO3_THREADVILLE_MAINTENANCE_H

#include "threadville_map.h"

typedef struct MaintenanceInfo {
    ThreadvilleMap* threadvilleMap;
} MaintenanceInfo;

_Noreturn void* run_maintenance(void *arg);

double ran_expo();

int random_threadville_id();

MaintenanceInfo *create_maintenance_info(ThreadvilleMap* map);
#endif //PROYECTO3_THREADVILLE_MAINTENANCE_H
