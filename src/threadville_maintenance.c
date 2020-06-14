#include "threadville_maintenance.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"

double ran_expo() {
    double u;
    u = rand() / (RAND_MAX + 1.0);
    // Mean value of 40 -> lambda = 0.025
    return -log(1 - u) / 0.025;
}

int random_threadville_id() {
    return rand() % (MAX_ID_NUMBER + 1);
}

MaintenanceInfo *create_maintenance_info(ThreadvilleMap* map) {
    MaintenanceInfo* info = malloc(sizeof(MaintenanceInfo));
    info->threadvilleMap = map;
    return info;
}

_Noreturn void* run_maintenance(void *arg) {
    MaintenanceInfo* info = (MaintenanceInfo *) arg;
    int maintenance_time;
    int threadville_id;
    double current_waiting_time;

    time_t t;
    srand((unsigned) time(&t));

    current_waiting_time = ran_expo();
    while (1) {
        printf("Current Waiting Time: %f\n", current_waiting_time);
        fflush(stdout);
        sleep(current_waiting_time);
        threadville_id = random_threadville_id();
        pthread_mutex_t *mutex = lookup(info->threadvilleMap->map, threadville_id);
        pthread_mutex_lock(mutex);
        maintenance_time = ((rand() % 4) + 1) * 5;
        printf("Current Maintenance Time: %d\n", maintenance_time);
        fflush(stdout);
        sleep(maintenance_time);
        pthread_mutex_unlock(mutex);
        current_waiting_time = ran_expo();
    }
}
