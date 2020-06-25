#include "threadville_map.h"
#include "bridge_handlers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t *cond = NULL;

static bool NORTH_DIR_BRIDGE = false;
static bool SOUTH_DIR_BRIDGE = true;

double elapsed_seconds(clock_t begin) {
    clock_t end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

_Noreturn
void *handleLarryJoe(void *arg) {
    // Get side of the bridge
    LarryJoeInformation* information = (LarryJoeInformation *) arg;
    // Keep count of the number of cars that has pass
    int local_counter = 0;

    while (1) {
        pthread_mutex_lock(&mutex);
        // See which side of the bridge should be available
        if (information->direction != *information->nextDirection) {
            // Sleep if is this side should not be available
            pthread_cond_wait(&cond[information->direction], &mutex);
        }

        // Critical section, allow one car to pass the bridge
        // Increment local counter of cars that has pass the bridge
        printf("%d ", information->direction);
        fflush(stdin);
        local_counter++;

        // Check if direction must change
        extern int K;
        if (local_counter > K - 1) {
            *information->nextDirection = !*information->nextDirection;
            local_counter = 0;
        }

        // weak up next thread
        pthread_cond_signal(&cond[*information->nextDirection]);
        pthread_mutex_unlock(&mutex);
    }
}

_Noreturn
void *handleCurlyShemp(void *arg) {
    // Get side of the bridge
    extern int M;
    extern int N;
    CurlyShempInformation* information = (CurlyShempInformation *) arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        // See which side of the bridge should be available
        if (information->direction != *information->nextDirection) {
            // Sleep if is this side should not be available
            pthread_cond_wait(&cond[information->direction], &mutex);
        }

        // Critical section, allow one car to pass the bridge
        // Increment local counter of cars that has pass the bridge
        clock_t begin = clock();
        int seconds;
        if (information->direction) {
            seconds = M;
        } else {
            seconds = N;
        }
        while (elapsed_seconds(begin) < seconds) {
            printf("%d ", information->direction);
            fflush(stdout);
        }
        *information->nextDirection = !*information->nextDirection;

        // weak up next thread
        pthread_cond_signal(&cond[*information->nextDirection]);
        pthread_mutex_unlock(&mutex);
    }
}

CurlyShempInformation *createCurlyShempInfo(
        bool direction, BridgesType type, bool* nextDirection,
        priority_semaphore *north_side, priority_semaphore *south_side
) {
    CurlyShempInformation *info = malloc(sizeof(CurlyShempInformation));
    info->direction = direction;
    info->nextDirection = nextDirection;
    info->type = type;
    return info;
}

LarryJoeInformation * createLarryJoeInfo(
        bool direction, BridgesType type, bool* nextDirection,
        priority_semaphore *north_side, priority_semaphore *south_side
    ) {
    LarryJoeInformation *info = malloc(sizeof(LarryJoeInformation));
    info->direction = direction;
    info->nextDirection = nextDirection;
    info->type = type;
    return info;
}

// Initialize all variables
int mainPruebaLarryJoe() {
    pthread_t *tid;
    volatile int i;

    // allocate memory to cond (conditional variable),
    // thread id's and array of size threads
    cond = (pthread_cond_t *) malloc(sizeof(pthread_cond_t) * 2);
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* nextDirection = create_shared_memory(sizeof(bool));

//    LarryJoeInformation* northInfo = createLarryJoeInfo(NORTH_DIR_BRIDGE, LARRY, nextDirection);
//    LarryJoeInformation* southInfo = createLarryJoeInfo(SOUTH_DIR_BRIDGE, LARRY, nextDirection);
//
//    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) northInfo);
//    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) southInfo);
//
//    // waiting for thread
//    for (i = 0; i < 2; i++) {
//        pthread_join(tid[i], NULL);
//    }

    return 0;
}

int mainPruebaCurlyShemp() {
    pthread_t *tid;
    volatile int i;

    // allocate memory to cond (conditional variable),
    // thread id's and array of size threads
    cond = (pthread_cond_t *) malloc(sizeof(pthread_cond_t) * 2);
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* nextDirection = create_shared_memory(sizeof(bool));

//    CurlyShempInformation* northInfo = createCurlyShempInfo(NORTH_DIR_BRIDGE, CURLY, nextDirection);
//    CurlyShempInformation* southInfo = createCurlyShempInfo(SOUTH_DIR_BRIDGE, CURLY, nextDirection);
//
//    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) northInfo);
//    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) southInfo);
//
//    // waiting for thread
//    for (i = 0; i < 2; i++) {
//        pthread_join(tid[i], NULL);
//    }

    return 0;
}
