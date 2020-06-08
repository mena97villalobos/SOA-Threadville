#include "vehicle.h"
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "hash_table.h"

#define AF_DISTANCE 36.0 // distance from A1 to F2

float getVehiculeSpeed(VehicleType type) {
    // Speed given in "spots" per second
    float speed;
    switch (type) {
        case ORANGE_BUS:
            speed = 7.0 / AF_DISTANCE;
            break;
        case AMBULANCE:
            speed = 0.5 / AF_DISTANCE;
            break;
        case RED_CAR:
            speed = 1.0 / AF_DISTANCE;
            break;
        case BLUE_CAR:
            speed = AF_DISTANCE / 2.0;
            break;
        case PINK_BUS:
        case LIGHT_BLUE_BUS:
        case GREEN_CAR:
            speed = AF_DISTANCE / 3.0;
            break;
        case WHITE_BUS:
        case GRAY_BUS:
        case BLACK_BUS:
        case BLACK_CAR:
            speed = AF_DISTANCE / 4.0;
            break;
        case RED_BUS:
        case GREEN_BUS:
        case BLUE_BUS:
        case WHITE_CAR:
            speed = AF_DISTANCE / 5.0;
            break;
        case YELLOW_CAR:
            speed = AF_DISTANCE / 6.0;
            break;
        default:
            speed = -1;
            break;
    }
    return speed;
}

Vehicle *create_vehicle(VehicleType type) {
    Vehicle *v = malloc(sizeof(Vehicle));
    float speed = getVehiculeSpeed(type);
    if (speed < 0) {
        return NULL;
    }
    v->vehicleType = type;
    v->speed = speed;
    v->current_route = NULL;
    return v;
}

VehicleThreadInfo *create_vehicle_thread_info(Vehicle *vehicle, ThreadvilleMap *threadvilleMap) {
    VehicleThreadInfo *info = malloc(sizeof(VehicleThreadInfo));
    info->vehicle = vehicle;
    info->map = threadvilleMap;
    return info;
}

void *handle_vehicle(void *arg) {
    VehicleThreadInfo *info = (VehicleThreadInfo *) arg;
    Vehicle *vehicle = info->vehicle;
    ThreadvilleMap *threadvilleMap = info->map;
    // Start vehicle at the roundabout
    int startDestination;
    int nextDestination = 0;
    while (nextDestination != 2) {
        while (vehicle->current_route->first_node != NULL) {
            NodeL *currentNode = vehicle->current_route->first_node;
            pthread_mutex_t *currentStreet = lookup(threadvilleMap->map, currentNode->destination_id);

            pthread_mutex_lock(currentStreet);
            // TODO PASAR DE SEGUNDOS A MILISEGUNDOS PARA QUE SIRVA BIEN EL SLEEP
            usleep(vehicle->speed);
            // TODO CRITICAL SECTION, LOCK SLEEP UNLOCK
            if (vehicle->current_route->first_node->next_node == NULL) {
                startDestination = vehicle->current_route->first_node->destination_id;
            }
            pop(vehicle->current_route);
            pthread_mutex_unlock(currentStreet);
        }
        pthread_mutex_t *currentStop = lookup(threadvilleMap->map, vehicle->destinations[nextDestination]);
        pthread_mutex_lock(currentStop);
        sleep(3);
        pthread_mutex_unlock(currentStop);
        // TODO UPDATE CURRENT ROUTE TO SHOW THE NEXT DESTINATION FROM startDestinatio to vehicle->destinations[++nextDestination]
        nextDestination++;
    }

}