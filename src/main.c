#include <stdio.h>
#include <stdlib.h>
#include "threadville_maintenance.h"
#include "threadville_map.h"

int main() {
    ThreadvilleMap *map = create_threadville_map();
    MaintenanceInfo* maintenanceInfo = create_maintenance_info(map);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &run_maintenance, maintenanceInfo);
    pthread_join(maintenance_thread, NULL);

    return 0;
}
