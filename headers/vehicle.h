#ifndef PROYECTO3_VEHICLE_H
#define PROYECTO3_VEHICLE_H

#include "utils.h"
#include "linked_list.h"
#include "threadville_map.h"
#include "linked_list_cars.h"

typedef enum VehicleType {
    RED_BUS,
    GREEN_BUS,
    BLUE_BUS,
    WHITE_BUS,
    GRAY_BUS,
    BLACK_BUS,
    PINK_BUS,
    LIGHT_BLUE_BUS,
    ORANGE_BUS,
    AMBULANCE,
    RED_CAR,
    BLUE_CAR,
    GREEN_CAR,
    BLACK_CAR,
    WHITE_CAR,
    YELLOW_CAR
} VehicleType;

typedef enum VehicleDir {
    NORTH,
    SOUTH,
    WEST,
    EAST
} VehicleDir;

typedef struct Vehicle {
    VehicleType vehicleType;
    VehicleDir  vehicleDir;
    // Vehicle speed
    double speed;
    // Route to get current destination
    LinkedList *current_route;
    // Vehicle must have 2 destinations
    int* destinations;
    node_t* ui_info;
} Vehicle;

typedef struct VehicleThreadInfo {
    Vehicle *vehicle;
    ThreadvilleMap *map;
} VehicleThreadInfo;

Vehicle *create_vehicle(VehicleType, VehicleDir);

VehicleThreadInfo *create_vehicle_thread_info(Vehicle *, ThreadvilleMap *);

void *handle_vehicle(void *arg);

#endif //PROYECTO3_VEHICLE_H
