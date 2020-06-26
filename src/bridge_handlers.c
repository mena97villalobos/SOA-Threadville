#include "threadville_map.h"
#include "bridge_handlers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <interface.h>
#include <errno.h>

double elapsed_seconds(clock_t begin) {
    clock_t end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

pthread_cond_t *get_conditional_mutex(BridgesType type) {
    extern pthread_cond_t *cond_larry;
    extern pthread_cond_t *cond_joe;
    extern pthread_cond_t *cond_curly;
    extern pthread_cond_t *cond_shemp;
    switch (type) {
        case LARRY:
            return cond_larry;
        case JOE:
            return cond_joe;
        case CURLY:
            return cond_curly;
        case SHEMP:
            return cond_shemp;
        case MOE:
        default:
            return NULL;
    }
}

pthread_mutex_t *get_bridge_mutex(BridgesType type) {
    extern pthread_mutex_t *mutex_larry;
    extern pthread_mutex_t *mutex_joe;
    extern pthread_mutex_t *mutex_curly;
    extern pthread_mutex_t *mutex_shemp;
    switch (type) {
        case LARRY:
            return mutex_larry;
        case JOE:
            return mutex_joe;
        case CURLY:
            return mutex_curly;
        case SHEMP:
            return mutex_shemp;
        case MOE:
        default:
            return NULL;
    }
}

void error_pthread_cond_timedwait(const int timed_wait_rv) {
    fprintf(stderr, "Conditional timed wait, failed.\n");
    switch (timed_wait_rv) {
        case ETIMEDOUT:
            fprintf(stderr, "The time specified by abstime to pthread_cond_timedwait() has passed.\n");
            break;
        case EINVAL:
            fprintf(stderr, "The value specified by abstime, cond or mutex is invalid.\n");
            break;
        case EPERM:
            fprintf(stderr, "The mutex was not owned by the current thread at the time of the call.\n");
            break;
        default:
            break;
    }
}

_Noreturn
void *handleLarryJoe(void *arg) {
    // Get side of the bridge
    // Check if direction must change
    extern int K;
    struct timespec time;


    LarryJoeInformation *information = (LarryJoeInformation *) arg;
    pthread_cond_t *cond = get_conditional_mutex(information->type);
    pthread_mutex_t *mutex = get_bridge_mutex(information->type);
    priority_semaphore *currentSemaphore;
    priority_semaphore *oppositeSemaphore;
    images_enum bridge_image;
    // Keep count of the number of cars that has pass
    int local_counter = 0;
    // South direction
    if (information->direction) {
        oppositeSemaphore = information->north_side;
        currentSemaphore = information->south_side;
        bridge_image = SEMAPHOREU;
    } else {
        oppositeSemaphore = information->south_side;
        currentSemaphore = information->north_side;
        bridge_image = SEMAPHORED;
    }
    while (1) {
        pthread_mutex_lock(mutex);

        // See which side of the bridge should be available
        if (information->direction != *information->nextDirection) {
            // Sleep if is this side should not be available
            pthread_cond_wait(&cond[information->direction], mutex);
        }

        lock_priority_semaphore(0, oppositeSemaphore);
        edit_semaphore(information->type, bridge_image);
        pthread_mutex_lock(&currentSemaphore->mutex);

        while (local_counter < K) {
            timespec_get(&time, TIME_UTC);
            time.tv_sec += 5;
            
            // pthread_cond_wait(&currentSemaphore->mutex_condition, &currentSemaphore->mutex);
            const int res = pthread_cond_timedwait(&currentSemaphore->mutex_condition, &currentSemaphore->mutex,
                                                   &time);
            if (res) {
                break;
            }
            local_counter++;
            printf("Semaforo liberado: %s\n", information->direction ? "South" : "North");
        }
        fflush(stdout);
        *information->nextDirection = !*information->nextDirection;
        local_counter = 0;

        pthread_mutex_unlock(&currentSemaphore->mutex);
        unlock_priority_semaphore(0, oppositeSemaphore);

        // weak up next thread
        pthread_cond_signal(&cond[*information->nextDirection]);
        pthread_mutex_unlock(mutex);
    }
}

_Noreturn
void *handleCurlyShemp(void *arg) {
    // Get side of the bridge
    extern int M;
    extern int N;
    CurlyShempInformation *information = (CurlyShempInformation *) arg;
    pthread_cond_t *cond = get_conditional_mutex(information->type);
    pthread_mutex_t *mutex = get_bridge_mutex(information->type);
    priority_semaphore *prioritySemaphore;
    images_enum bridge_image;
    int *seconds;
    // South direction
    if (information->direction) {
        prioritySemaphore = information->north_side;
        bridge_image = SEMAPHOREU;
        seconds = &M;
    } else {
        prioritySemaphore = information->south_side;
        bridge_image = SEMAPHORED;
        seconds = &N;
    }
    while (1) {
        pthread_mutex_lock(mutex);
        // See which side of the bridge should be available
        if (information->direction != *information->nextDirection) {
            // Sleep if is this side should not be available
            pthread_cond_wait(&cond[information->direction], mutex);
        }

        lock_priority_semaphore(0, prioritySemaphore);
        edit_semaphore(information->type, bridge_image);
        sleep(*seconds);
        unlock_priority_semaphore(0, prioritySemaphore);
        *information->nextDirection = !*information->nextDirection;

        // weak up next thread
        pthread_cond_signal(&cond[*information->nextDirection]);
        pthread_mutex_unlock(mutex);
    }
}

CurlyShempInformation *createCurlyShempInfo(
        bool direction, BridgesType type, bool *nextDirection,
        priority_semaphore *north_side, priority_semaphore *south_side
) {
    CurlyShempInformation *info = malloc(sizeof(CurlyShempInformation));
    info->direction = direction;
    info->nextDirection = nextDirection;
    info->type = type;
    info->north_side = north_side;
    info->south_side = south_side;
    return info;
}

LarryJoeInformation *createLarryJoeInfo(
        bool direction, BridgesType type, bool *nextDirection,
        priority_semaphore *north_side, priority_semaphore *south_side
) {
    LarryJoeInformation *info = malloc(sizeof(LarryJoeInformation));
    info->direction = direction;
    info->nextDirection = nextDirection;
    info->type = type;
    info->north_side = north_side;
    info->south_side = south_side;
    return info;
}
