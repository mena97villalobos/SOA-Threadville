#include "vehicle.h"
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "hash_table.h"
#include "interface.h"
#include "floyd.h"
#include "globals.h"

// #define AF_DISTANCE 36.0 // distance from A1 to F2
#define AF_DISTANCE 6.0

LinkedList *createRoute() {
    LinkedList *l = create_linked_list();
    int *path = floyd_path(S001C, X002C);
    for (int i = path[0]; i >= 1; --i) {
        push(l, create_node(path[i]));
        printf("%d ", path[i]);
        fflush(stdout);
    }
    free(path);
//    append(l, create_node(M002C));
//    append(l, create_node(M012P));
//    append(l, create_node(M011P));
//    append(l, create_node(M010P));
//    append(l, create_node(M009P));
//    append(l, create_node(M008P));
//    append(l, create_node(M007P));
//    append(l, create_node(M001C));
//
//    append(l, create_node(N002C));
//    append(l, create_node(N012P));
//    append(l, create_node(N011P));
//    append(l, create_node(N010P));
//    append(l, create_node(N009P));
//    append(l, create_node(N008P));
//    append(l, create_node(N007P));
//    append(l, create_node(N001C));
//
//    append(l, create_node(O002C));
//    append(l, create_node(O012P));
//    append(l, create_node(O011P));
//    append(l, create_node(O010P));
//    append(l, create_node(O009P));
//    append(l, create_node(O008P));
//    append(l, create_node(O007P));
//    append(l, create_node(O001C));
//
//    append(l, create_node(P002C));
//    append(l, create_node(P012P));
//    append(l, create_node(P011P));
//    append(l, create_node(P010P));
//    append(l, create_node(P009P));
//    append(l, create_node(P008P));
//    append(l, create_node(P007P));
//    append(l, create_node(P001C));
//
//    append(l, create_node(Q002C));
//    append(l, create_node(Q012P));
//    append(l, create_node(Q011P));
//    append(l, create_node(Q010P));
//    append(l, create_node(Q009P));
//    append(l, create_node(Q008P));
//    append(l, create_node(Q007P));
//    append(l, create_node(Q001C));
//
//    append(l, create_node(R002C));
//    append(l, create_node(R012P));
//    append(l, create_node(R011P));
//    append(l, create_node(R010P));
//    append(l, create_node(R009P));
//    append(l, create_node(R008P));
//    append(l, create_node(R007P));
//    append(l, create_node(R001C));
//    append(l, create_node(S001C));
//    append(l, create_node(S001P));
//    append(l, create_node(S002P));
//    append(l, create_node(S003P));
//    append(l, create_node(S004P));
//    append(l, create_node(S005P));
//    append(l, create_node(S006P));
//    append(l, create_node(S002C));
//
//    append(l, create_node(T001C));
//    append(l, create_node(T001P));
//    append(l, create_node(T002P));
//    append(l, create_node(T003P));
//    append(l, create_node(T004P));
//    append(l, create_node(T005P));
//    append(l, create_node(T006P));
//    append(l, create_node(T002C));
//
//    append(l, create_node(U001C));
//    append(l, create_node(U001P));
//    append(l, create_node(U002P));
//    append(l, create_node(U003P));
//    append(l, create_node(U004P));
//    append(l, create_node(U005P));
//    append(l, create_node(U006P));
//    append(l, create_node(U002C));
//
//    append(l, create_node(V001C));
//    append(l, create_node(V001P));
//    append(l, create_node(V002P));
//    append(l, create_node(V003P));
//    append(l, create_node(V004P));
//    append(l, create_node(V005P));
//    append(l, create_node(V006P));
//    append(l, create_node(V002C));
//
//    append(l, create_node(W001C));
//    append(l, create_node(W001P));
//    append(l, create_node(W002P));
//    append(l, create_node(W003P));
//    append(l, create_node(W004P));
//    append(l, create_node(W005P));
//    append(l, create_node(W006P));
//    append(l, create_node(W002C));
//
//    append(l, create_node(X001C));
//    append(l, create_node(X001P));
//    append(l, create_node(X002P));
//    append(l, create_node(X003P));
//    append(l, create_node(X004P));
//    append(l, create_node(X005P));
//    append(l, create_node(X006P));
//    append(l, create_node(X002C));
    return l;
}

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

Vehicle *create_vehicle(VehicleType type, VehicleDir dir) {
    Vehicle *v = malloc(sizeof(Vehicle));
    float speed = getVehiculeSpeed(type);
    if (speed < 0) {
        return NULL;
    }

    node_t *ui_info = create_object(
            v,
            from_vehicle_type(type, dir),
            0.223f, 0.223f,
            "B1"
    );

    v->ui_info = ui_info;
    v->vehicleType = type;
    v->vehicleDir = dir;
    v->speed = speed;
    v->current_route = createRoute();
    int *destinations = calloc(2, sizeof(int));
    destinations[0] = B008S;
    destinations[1] = B008S;
    v->destinations = destinations;
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
            //usleep(vehicle->speed * 1500);
            sleep(1);
            // TODO CRITICAL SECTION, LOCK SLEEP UNLOCK
            // TODO CAMBIAR DIRECCI'ON

            StreetInfo *streetInfo = lookup_street_info(threadvilleMap->streetInfoTable, currentNode->destination_id);
            printf("X: %f, Y: %f, ID: %d\n", streetInfo->x, streetInfo->y, currentNode->destination_id);
            fflush(stdout);
            edit_object_with_node(
                    vehicle->ui_info,
                    from_vehicle_type(vehicle->vehicleType, vehicle->vehicleDir),
                    streetInfo->x, streetInfo->y, "Z1"
            );

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
        vehicle->current_route = createRoute();
        nextDestination++;
    }
}