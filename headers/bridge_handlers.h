#ifndef PROYECTO_3_BRIDGE_HANDLERS_H
#define PROYECTO_3_BRIDGE_HANDLERS_H

#include <stdbool.h>

#define NORTH_DIR_BRIDGE false
#define SOUTH_DIR_BRIDGE true

typedef enum BridgesType {
    LARRY = 0,
    CURLY = 1,
    MOE   = 2,
    SHEMP = 3,
    JOE   = 4
} BridgesType;

typedef struct CurlyShempInformation {
    priority_semaphore *north_side;
    priority_semaphore *south_side;
    BridgesType type;
    bool direction;
    bool *nextDirection;
} CurlyShempInformation;

typedef struct LarryJoeInformation {
    priority_semaphore *north_side;
    priority_semaphore *south_side;
    BridgesType type;
    bool direction;
    bool *nextDirection;
} LarryJoeInformation;

void *handleLarryJoe(void *arg);

void *handleCurlyShemp(void *arg);

CurlyShempInformation *createCurlyShempInfo(
        bool direction, BridgesType type, bool *nextDirection,
        priority_semaphore *north_side, priority_semaphore *south_side
);

LarryJoeInformation *createLarryJoeInfo(
        bool direction, BridgesType type, bool *nextDirection,
        priority_semaphore *north_side, priority_semaphore *south_side
);

#endif //PROYECTO_3_BRIDGE_HANDLERS_H
