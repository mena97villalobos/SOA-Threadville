#ifndef PROYECTO_3_BRIDGE_HANDLERS_H
#define PROYECTO_3_BRIDGE_HANDLERS_H

#include <stdbool.h>

typedef enum BridgesType {
    LARRY,
    JOE,
    CURLY,
    SHEMP,
    MOE
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
