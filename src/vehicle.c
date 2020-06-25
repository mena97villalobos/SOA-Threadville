#include "vehicle.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "hash_table.h"
#include "interface.h"
#include "floyd.h"
#include "bus.h"

#define AF_DISTANCE 48.0 // distance from A1 to F2

extern ThreadvilleMap *map;

int random_stop_id() {
    return (rand() % (R006S - A001S + 1)) + A001S;
}

int random_car_id() {
    return (rand() % (YELLOW_CAR - RED_CAR + 1)) + RED_CAR;
}

char *get_stop_id(int stop, int destinations_left) {
    char *res = calloc(6, sizeof(char));
    switch (stop) {
        case A001S:
            sprintf(res, "%s-%d", "A1", destinations_left);
            return res;
            break;
        case A002S:
            sprintf(res, "%s-%d", "A2", destinations_left);
            return res;
            break;
        case A003S:
            sprintf(res, "%s-%d", "A3", destinations_left);
            return res;
            break;
        case A004S:
            sprintf(res, "%s-%d", "A4", destinations_left);
            return res;
            break;
        case A005S:
            sprintf(res, "%s-%d", "A5", destinations_left);
            return res;
            break;
        case A006S:
            sprintf(res, "%s-%d", "A6", destinations_left);
            return res;
            break;
        case A007S:
            sprintf(res, "%s-%d", "A7", destinations_left);
            return res;
            break;
        case A008S:
            sprintf(res, "%s-%d", "A8", destinations_left);
            return res;
            break;
        case B001S:
            sprintf(res, "%s-%d", "B1", destinations_left);
            return res;
            break;
        case B002S:
            sprintf(res, "%s-%d", "B2", destinations_left);
            return res;
            break;
        case B003S:
            sprintf(res, "%s-%d", "B3", destinations_left);
            return res;
            break;
        case B004S:
            sprintf(res, "%s-%d", "B4", destinations_left);
            return res;
            break;
        case B005S:
            sprintf(res, "%s-%d", "B5", destinations_left);
            return res;
            break;
        case B006S:
            sprintf(res, "%s-%d", "B6", destinations_left);
            return res;
            break;
        case B007S:
            sprintf(res, "%s-%d", "B7", destinations_left);
            return res;
            break;
        case B008S:
            sprintf(res, "%s-%d", "B8", destinations_left);
            return res;
            break;
        case C001S:
            sprintf(res, "%s-%d", "C1", destinations_left);
            return res;
            break;
        case C002S:
            sprintf(res, "%s-%d", "C2", destinations_left);
            return res;
            break;
        case C003S:
            sprintf(res, "%s-%d", "C3", destinations_left);
            return res;
            break;
        case C004S:
            sprintf(res, "%s-%d", "C4", destinations_left);
            return res;
            break;
        case C005S:
            sprintf(res, "%s-%d", "C5", destinations_left);
            return res;
            break;
        case C006S:
            sprintf(res, "%s-%d", "C6", destinations_left);
            return res;
            break;
        case C007S:
            sprintf(res, "%s-%d", "C7", destinations_left);
            return res;
            break;
        case C008S:
            sprintf(res, "%s-%d", "C8", destinations_left);
            return res;
            break;
        case D001S:
            sprintf(res, "%s-%d", "D1", destinations_left);
            return res;
            break;
        case D002S:
            sprintf(res, "%s-%d", "D2", destinations_left);
            return res;
            break;
        case D003S:
            sprintf(res, "%s-%d", "D3", destinations_left);
            return res;
            break;
        case D004S:
            sprintf(res, "%s-%d", "D4", destinations_left);
            return res;
            break;
        case D005S:
            sprintf(res, "%s-%d", "D5", destinations_left);
            return res;
            break;
        case D006S:
            sprintf(res, "%s-%d", "D6", destinations_left);
            return res;
            break;
        case D007S:
            sprintf(res, "%s-%d", "D7", destinations_left);
            return res;
            break;
        case D008S:
            sprintf(res, "%s-%d", "D8", destinations_left);
            return res;
            break;
        case E001S:
            sprintf(res, "%s-%d", "E1", destinations_left);
            return res;
            break;
        case E002S:
            sprintf(res, "%s-%d", "E2", destinations_left);
            return res;
            break;
        case E003S:
            sprintf(res, "%s-%d", "E3", destinations_left);
            return res;
            break;
        case E004S:
            sprintf(res, "%s-%d", "E4", destinations_left);
            return res;
            break;
        case E005S:
            sprintf(res, "%s-%d", "E5", destinations_left);
            return res;
            break;
        case E006S:
            sprintf(res, "%s-%d", "E6", destinations_left);
            return res;
            break;
        case E007S:
            sprintf(res, "%s-%d", "E7", destinations_left);
            return res;
            break;
        case E008S:
            sprintf(res, "%s-%d", "E8", destinations_left);
            return res;
            break;
        case F001S:
            sprintf(res, "%s-%d", "F1", destinations_left);
            return res;
            break;
        case F002S:
            sprintf(res, "%s-%d", "F2", destinations_left);
            return res;
            break;
        case F003S:
            sprintf(res, "%s-%d", "F3", destinations_left);
            return res;
            break;
        case F004S:
            sprintf(res, "%s-%d", "F4", destinations_left);
            return res;
            break;
        case F005S:
            sprintf(res, "%s-%d", "F5", destinations_left);
            return res;
            break;
        case F006S:
            sprintf(res, "%s-%d", "F6", destinations_left);
            return res;
            break;
        case F007S:
            sprintf(res, "%s-%d", "F7", destinations_left);
            return res;
            break;
        case F008S:
            sprintf(res, "%s-%d", "F8", destinations_left);
            return res;
            break;
        case S001S:
            sprintf(res, "%s-%d", "S1", destinations_left);
            return res;
            break;
        case S002S:
            sprintf(res, "%s-%d", "S2", destinations_left);
            return res;
            break;
        case S003S:
            sprintf(res, "%s-%d", "S3", destinations_left);
            return res;
            break;
        case S004S:
            sprintf(res, "%s-%d", "S4", destinations_left);
            return res;
            break;
        case S005S:
            sprintf(res, "%s-%d", "S5", destinations_left);
            return res;
            break;
        case S006S:
            sprintf(res, "%s-%d", "S6", destinations_left);
            return res;
            break;
        case S007S:
            sprintf(res, "%s-%d", "S7", destinations_left);
            return res;
            break;
        case S008S:
            sprintf(res, "%s-%d", "S8", destinations_left);
            return res;
            break;
        case T001S:
            sprintf(res, "%s-%d", "T1", destinations_left);
            return res;
            break;
        case T002S:
            sprintf(res, "%s-%d", "T2", destinations_left);
            return res;
            break;
        case T003S:
            sprintf(res, "%s-%d", "T3", destinations_left);
            return res;
            break;
        case T004S:
            sprintf(res, "%s-%d", "T4", destinations_left);
            return res;
            break;
        case T005S:
            sprintf(res, "%s-%d", "T5", destinations_left);
            return res;
            break;
        case T006S:
            sprintf(res, "%s-%d", "T6", destinations_left);
            return res;
            break;
        case T007S:
            sprintf(res, "%s-%d", "T7", destinations_left);
            return res;
            break;
        case T008S:
            sprintf(res, "%s-%d", "T8", destinations_left);
            return res;
            break;
        case U001S:
            sprintf(res, "%s-%d", "U1", destinations_left);
            return res;
            break;
        case U002S:
            sprintf(res, "%s-%d", "U2", destinations_left);
            return res;
            break;
        case U003S:
            sprintf(res, "%s-%d", "U3", destinations_left);
            return res;
            break;
        case U004S:
            sprintf(res, "%s-%d", "U4", destinations_left);
            return res;
            break;
        case U005S:
            sprintf(res, "%s-%d", "U5", destinations_left);
            return res;
            break;
        case U006S:
            sprintf(res, "%s-%d", "U6", destinations_left);
            return res;
            break;
        case U007S:
            sprintf(res, "%s-%d", "U7", destinations_left);
            return res;
            break;
        case U008S:
            sprintf(res, "%s-%d", "U8", destinations_left);
            return res;
            break;
        case V001S:
            sprintf(res, "%s-%d", "V1", destinations_left);
            return res;
            break;
        case V002S:
            sprintf(res, "%s-%d", "V2", destinations_left);
            return res;
            break;
        case V003S:
            sprintf(res, "%s-%d", "V3", destinations_left);
            return res;
            break;
        case V004S:
            sprintf(res, "%s-%d", "V4", destinations_left);
            return res;
            break;
        case V005S:
            sprintf(res, "%s-%d", "V5", destinations_left);
            return res;
            break;
        case V006S:
            sprintf(res, "%s-%d", "V6", destinations_left);
            return res;
            break;
        case V007S:
            sprintf(res, "%s-%d", "V7", destinations_left);
            return res;
            break;
        case V008S:
            sprintf(res, "%s-%d", "V8", destinations_left);
            return res;
            break;
        case W001S:
            sprintf(res, "%s-%d", "W1", destinations_left);
            return res;
            break;
        case W002S:
            sprintf(res, "%s-%d", "W2", destinations_left);
            return res;
            break;
        case W003S:
            sprintf(res, "%s-%d", "W3", destinations_left);
            return res;
            break;
        case W004S:
            sprintf(res, "%s-%d", "W4", destinations_left);
            return res;
            break;
        case W005S:
            sprintf(res, "%s-%d", "W5", destinations_left);
            return res;
            break;
        case W006S:
            sprintf(res, "%s-%d", "W6", destinations_left);
            return res;
            break;
        case W007S:
            sprintf(res, "%s-%d", "W7", destinations_left);
            return res;
            break;
        case W008S:
            sprintf(res, "%s-%d", "W8", destinations_left);
            return res;
            break;
        case X001S:
            sprintf(res, "%s-%d", "X1", destinations_left);
            return res;
            break;
        case X002S:
            sprintf(res, "%s-%d", "X2", destinations_left);
            return res;
            break;
        case X003S:
            sprintf(res, "%s-%d", "X3", destinations_left);
            return res;
            break;
        case X004S:
            sprintf(res, "%s-%d", "X4", destinations_left);
            return res;
            break;
        case X005S:
            sprintf(res, "%s-%d", "X5", destinations_left);
            return res;
            break;
        case X006S:
            sprintf(res, "%s-%d", "X6", destinations_left);
            return res;
            break;
        case X007S:
            sprintf(res, "%s-%d", "X7", destinations_left);
            return res;
            break;
        case X008S:
            sprintf(res, "%s-%d", "X8", destinations_left);
            return res;
            break;
        case G001S:
            sprintf(res, "%s-%d", "G1", destinations_left);
            return res;
            break;
        case G002S:
            sprintf(res, "%s-%d", "G2", destinations_left);
            return res;
            break;
        case G003S:
            sprintf(res, "%s-%d", "G3", destinations_left);
            return res;
            break;
        case G004S:
            sprintf(res, "%s-%d", "G4", destinations_left);
            return res;
            break;
        case G005S:
            sprintf(res, "%s-%d", "G5", destinations_left);
            return res;
            break;
        case G006S:
            sprintf(res, "%s-%d", "G6", destinations_left);
            return res;
            break;
        case H001S:
            sprintf(res, "%s-%d", "H1", destinations_left);
            return res;
            break;
        case H002S:
            sprintf(res, "%s-%d", "H2", destinations_left);
            return res;
            break;
        case H003S:
            sprintf(res, "%s-%d", "H3", destinations_left);
            return res;
            break;
        case H004S:
            sprintf(res, "%s-%d", "H4", destinations_left);
            return res;
            break;
        case H005S:
            sprintf(res, "%s-%d", "H5", destinations_left);
            return res;
            break;
        case H006S:
            sprintf(res, "%s-%d", "H6", destinations_left);
            return res;
            break;
        case I001S:
            sprintf(res, "%s-%d", "I1", destinations_left);
            return res;
            break;
        case I002S:
            sprintf(res, "%s-%d", "I2", destinations_left);
            return res;
            break;
        case I003S:
            sprintf(res, "%s-%d", "I3", destinations_left);
            return res;
            break;
        case I004S:
            sprintf(res, "%s-%d", "I4", destinations_left);
            return res;
            break;
        case I005S:
            sprintf(res, "%s-%d", "I5", destinations_left);
            return res;
            break;
        case I006S:
            sprintf(res, "%s-%d", "I6", destinations_left);
            return res;
            break;
        case J001S:
            sprintf(res, "%s-%d", "J1", destinations_left);
            return res;
            break;
        case J002S:
            sprintf(res, "%s-%d", "J2", destinations_left);
            return res;
            break;
        case J003S:
            sprintf(res, "%s-%d", "J3", destinations_left);
            return res;
            break;
        case J004S:
            sprintf(res, "%s-%d", "J4", destinations_left);
            return res;
            break;
        case J005S:
            sprintf(res, "%s-%d", "J5", destinations_left);
            return res;
            break;
        case J006S:
            sprintf(res, "%s-%d", "J6", destinations_left);
            return res;
            break;
        case K001S:
            sprintf(res, "%s-%d", "K1", destinations_left);
            return res;
            break;
        case K002S:
            sprintf(res, "%s-%d", "K2", destinations_left);
            return res;
            break;
        case K003S:
            sprintf(res, "%s-%d", "K3", destinations_left);
            return res;
            break;
        case K004S:
            sprintf(res, "%s-%d", "K4", destinations_left);
            return res;
            break;
        case K005S:
            sprintf(res, "%s-%d", "K5", destinations_left);
            return res;
            break;
        case K006S:
            sprintf(res, "%s-%d", "K6", destinations_left);
            return res;
            break;
        case L001S:
            sprintf(res, "%s-%d", "L1", destinations_left);
            return res;
            break;
        case L002S:
            sprintf(res, "%s-%d", "L2", destinations_left);
            return res;
            break;
        case L003S:
            sprintf(res, "%s-%d", "L3", destinations_left);
            return res;
            break;
        case L004S:
            sprintf(res, "%s-%d", "L4", destinations_left);
            return res;
            break;
        case L005S:
            sprintf(res, "%s-%d", "L5", destinations_left);
            return res;
            break;
        case L006S:
            sprintf(res, "%s-%d", "L6", destinations_left);
            return res;
            break;
        case M001S:
            sprintf(res, "%s-%d", "M1", destinations_left);
            return res;
            break;
        case M002S:
            sprintf(res, "%s-%d", "M2", destinations_left);
            return res;
            break;
        case M003S:
            sprintf(res, "%s-%d", "M3", destinations_left);
            return res;
            break;
        case M004S:
            sprintf(res, "%s-%d", "M4", destinations_left);
            return res;
            break;
        case M005S:
            sprintf(res, "%s-%d", "M5", destinations_left);
            return res;
            break;
        case M006S:
            sprintf(res, "%s-%d", "M6", destinations_left);
            return res;
            break;
        case N001S:
            sprintf(res, "%s-%d", "N1", destinations_left);
            return res;
            break;
        case N002S:
            sprintf(res, "%s-%d", "N2", destinations_left);
            return res;
            break;
        case N003S:
            sprintf(res, "%s-%d", "N3", destinations_left);
            return res;
            break;
        case N004S:
            sprintf(res, "%s-%d", "N4", destinations_left);
            return res;
            break;
        case N005S:
            sprintf(res, "%s-%d", "N5", destinations_left);
            return res;
            break;
        case N006S:
            sprintf(res, "%s-%d", "N6", destinations_left);
            return res;
            break;
        case O001S:
            sprintf(res, "%s-%d", "O1", destinations_left);
            return res;
            break;
        case O002S:
            sprintf(res, "%s-%d", "O2", destinations_left);
            return res;
            break;
        case O003S:
            sprintf(res, "%s-%d", "O3", destinations_left);
            return res;
            break;
        case O004S:
            sprintf(res, "%s-%d", "O4", destinations_left);
            return res;
            break;
        case O005S:
            sprintf(res, "%s-%d", "O5", destinations_left);
            return res;
            break;
        case O006S:
            sprintf(res, "%s-%d", "O6", destinations_left);
            return res;
            break;
        case P001S:
            sprintf(res, "%s-%d", "P1", destinations_left);
            return res;
            break;
        case P002S:
            sprintf(res, "%s-%d", "P2", destinations_left);
            return res;
            break;
        case P003S:
            sprintf(res, "%s-%d", "P3", destinations_left);
            return res;
            break;
        case P004S:
            sprintf(res, "%s-%d", "P4", destinations_left);
            return res;
            break;
        case P005S:
            sprintf(res, "%s-%d", "P5", destinations_left);
            return res;
            break;
        case P006S:
            sprintf(res, "%s-%d", "P6", destinations_left);
            return res;
            break;
        case Q001S:
            sprintf(res, "%s-%d", "Q1", destinations_left);
            return res;
            break;
        case Q002S:
            sprintf(res, "%s-%d", "Q2", destinations_left);
            return res;
            break;
        case Q003S:
            sprintf(res, "%s-%d", "Q3", destinations_left);
            return res;
            break;
        case Q004S:
            sprintf(res, "%s-%d", "Q4", destinations_left);
            return res;
            break;
        case Q005S:
            sprintf(res, "%s-%d", "Q5", destinations_left);
            return res;
            break;
        case Q006S:
            sprintf(res, "%s-%d", "Q6", destinations_left);
            return res;
            break;
        case R001S:
            sprintf(res, "%s-%d", "R1", destinations_left);
            return res;
            break;
        case R002S:
            sprintf(res, "%s-%d", "R2", destinations_left);
            return res;
            break;
        case R003S:
            sprintf(res, "%s-%d", "R3", destinations_left);
            return res;
            break;
        case R004S:
            sprintf(res, "%s-%d", "R4", destinations_left);
            return res;
            break;
        case R005S:
            sprintf(res, "%s-%d", "R5", destinations_left);
            return res;
            break;
        case R006S:
            sprintf(res, "%s-%d", "R6", destinations_left);
            return res;
            break;
        case Z006R:
            sprintf(res, "%s-%d", "Z6", destinations_left);
            return res;
            break;
        default:
            return "";
            break;
    }
}

LinkedList *create_route(int start_point, int end_point) {
    LinkedList *l = create_linked_list();
    int *path = floyd_path(start_point, end_point);
    for (int i = path[0]; i >= 1; --i) {
        push(l, create_node(path[i]));
    }
    free(path);
    return l;
}

void create_bus_route(Vehicle *vehicle) {
    switch (vehicle->vehicleType) {
        case RED_BUS:
            create_route_red(vehicle);
            break;
        case GREEN_BUS:
            create_route_green(vehicle);
            break;
        case BLUE_BUS:
            create_route_blue(vehicle);
            break;
        case WHITE_BUS:
            create_route_white(vehicle);
            break;
        case GRAY_BUS:
            create_route_gray(vehicle);
            break;
        case BLACK_BUS:
            create_route_black(vehicle);
            break;
        case PINK_BUS:
            create_route_pink(vehicle);
            break;
        case LIGHT_BLUE_BUS:
            create_route_light_blue(vehicle);
            break;
        case ORANGE_BUS:
            create_route_orange(vehicle);
            break;
        default:
            break;
    }
}

float getVehicleSpeed(VehicleType type) {
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
            speed = 2.0 / AF_DISTANCE;
            break;
        case PINK_BUS:
        case LIGHT_BLUE_BUS:
        case GREEN_CAR:
            speed = 3.0 / AF_DISTANCE;
            break;
        case WHITE_BUS:
        case GRAY_BUS:
        case BLACK_BUS:
        case BLACK_CAR:
            speed = 4.0 / AF_DISTANCE;
            break;
        case RED_BUS:
        case GREEN_BUS:
        case BLUE_BUS:
        case WHITE_CAR:
            speed = 5.0 / AF_DISTANCE;
            break;
        case YELLOW_CAR:
            speed = 6.0 / AF_DISTANCE;
            break;
        default:
            speed = -1;
            break;
    }
    return speed;
}

Vehicle *create_bus(VehicleType type, VehicleDir dir) {
    Vehicle *v = malloc(sizeof(Vehicle));
    float speed = getVehicleSpeed(type);
    if (speed < 0) {
        return NULL;
    }
    v->speed = speed;
    v->vehicleType = type;
    v->vehicleDir = dir;

    if (is_bus(type)) {
        create_bus_route(v);
    }

    // Starting point is always Y006R
    StreetInfo *info = lookup_street_info(
            map->streetInfoTable,
            v->current_route->first_node->destination_id
    );
    node_t *ui_info = create_object(
            (int) (uintptr_t) v,
            from_vehicle_type(type, info->dir),
            info->x, info->y,
            get_stop_id(
                    v->current_route->first_node->destination_id,
                    get_destinations_size(v->destinations)
            )
    );
    v->ui_info = ui_info;
    return v;
}

Vehicle *create_vehicle(VehicleType type, VehicleDir dir, int *destinations) {
    static int vehicle_id = 0;
    Vehicle *v = malloc(sizeof(Vehicle));
    float speed = getVehicleSpeed(type);
    if (speed < 0) {
        return NULL;
    }
    v->speed = speed;
    v->vehicleType = type;
    v->vehicleDir = dir;
    v->destinations = destinations;
    v->current_route = create_route(Y006R, destinations[0]);

    // Starting point is always Y006R
    StreetInfo *info = lookup_street_info(
            map->streetInfoTable,
            v->current_route->first_node->destination_id
    );
    node_t *ui_info = create_object(
            vehicle_id,
            from_vehicle_type(type, info->dir),
            info->x, info->y,
            get_stop_id(
                    v->current_route->first_node->destination_id,
                    get_destinations_size(v->destinations)
            )
    );
    v->ui_info = ui_info;
    v->vehicle_id = vehicle_id;
    vehicle_id++;
    return v;
}

VehicleThreadInfo *create_vehicle_thread_info(Vehicle *vehicle) {
    VehicleThreadInfo *info = malloc(sizeof(VehicleThreadInfo));
    info->vehicle = vehicle;
    return info;
}

int highway_multiplier(int street_id) {
    return street_id >= 1 && street_id <= 144 ? 2 : 1;
}

int is_bus(VehicleType type) {
    switch (type) {
        case RED_BUS:
        case GREEN_BUS:
        case BLUE_BUS:
        case WHITE_BUS:
        case GRAY_BUS:
        case BLACK_BUS:
        case PINK_BUS:
        case LIGHT_BLUE_BUS:
        case ORANGE_BUS:
            return 1;
        default:
            return 0;
    }
}

int *copy_destinations(int *d) {
    int *destinations = calloc(get_destinations_size(d), sizeof(destinations));
    int index = 0;
    while (d[index] != -1) {
        destinations[index] = d[index];
        index++;
    }
    return destinations;
}

int get_destinations_size(const int *destinations) {
    int index = 0;
    while (destinations[index] != -1) index++;
    return index + 1;
}

void handle_normal_vehicle(Vehicle *vehicle) {
    int startDestination;
    int nextDestination = 0;
    is_bus(vehicle->vehicleType);
    priority_semaphore *currentStreet = NULL;
    while (1) {
        while (vehicle->current_route->first_node != NULL) {
            NodeL *currentNode = vehicle->current_route->first_node;
            currentStreet = lookup(map->map, currentNode->destination_id);
            lock_priority_semaphore(5, currentStreet);
            usleep((vehicle->speed * 1000000) / highway_multiplier(currentNode->destination_id));
            sleep(2);
            StreetInfo *streetInfo = lookup_street_info(map->streetInfoTable, currentNode->destination_id);
            edit_object_with_node(
                    vehicle->ui_info,
                    from_vehicle_type(vehicle->vehicleType, streetInfo->dir),
                    streetInfo->x, streetInfo->y,
                    get_stop_id(vehicle->destinations[nextDestination], 3 - nextDestination)
            );
            if (vehicle->current_route->first_node->next_node == NULL) {
                startDestination = vehicle->current_route->first_node->destination_id;
            }
            pop(vehicle->current_route);
            unlock_priority_semaphore(5, currentStreet);
        }
        priority_semaphore *currentStop = lookup(map->map, vehicle->destinations[nextDestination]);
        lock_priority_semaphore(5, currentStreet);
        sleep(3);
        unlock_priority_semaphore(5, currentStreet);
        nextDestination++;
        if (vehicle->destinations[nextDestination] != -1) {
            vehicle->current_route = create_route(startDestination, vehicle->destinations[nextDestination]);
        } else {
            break;
        }
    }
}

void handle_bus(Vehicle *vehicle) {
    priority_semaphore *currentStreet = NULL;
    priority_semaphore *previousStreet = NULL;
    NodeL *currentNode;
    int currentDestination = 0;
    StreetInfo *streetInfo;
    LinkedList *busRouteCopy = copy_list(vehicle->current_route);
    // TODO MECANISMO PARA DETENER EL BUS
    while (1) {
        while (vehicle->destinations[currentDestination] != -1 && vehicle->current_route->first_node != NULL) {
            currentNode = vehicle->current_route->first_node;
            currentStreet = lookup(map->map, currentNode->destination_id);

            lock_priority_semaphore(5, currentStreet);
            printf("Lock current\n");
            if (previousStreet != NULL) {
                lock_priority_semaphore(0, previousStreet);
                printf("Lock previous\n");
            }

            streetInfo = lookup_street_info(map->streetInfoTable, currentNode->destination_id);
            edit_object_with_node(
                    vehicle->ui_info,
                    from_vehicle_type(vehicle->vehicleType, streetInfo->dir),
                    streetInfo->x, streetInfo->y,
                    get_stop_id(
                            vehicle->destinations[currentDestination],
                            get_destinations_size(vehicle->destinations) - currentDestination - 1
                    )
            );
            if (vehicle->destinations[currentDestination] == currentNode->destination_id) {
                sleep(5);
                currentDestination++;
            } else {
                usleep((vehicle->speed * 1000000) / highway_multiplier(currentNode->destination_id));
                usleep(0.5 * 1000000);
            }
            pop(vehicle->current_route);

            unlock_priority_semaphore(5, currentStreet);
            if (previousStreet != NULL) {
                unlock_priority_semaphore(0, previousStreet);
            }
            previousStreet = currentStreet;
        }
        fflush(stdout);
        currentDestination = 0;
        vehicle->current_route = copy_list(busRouteCopy);
    }
}

void *handle_vehicle(void *arg) {
    VehicleThreadInfo *info = (VehicleThreadInfo *) arg;
    Vehicle *vehicle = info->vehicle;
    switch (vehicle->vehicleType) {
        case RED_BUS:
        case GREEN_BUS:
        case BLUE_BUS:
        case WHITE_BUS:
        case GRAY_BUS:
        case BLACK_BUS:
        case PINK_BUS:
        case LIGHT_BLUE_BUS:
        case ORANGE_BUS:
            handle_bus(vehicle);
            break;
        case AMBULANCE:
            break;
        case RED_CAR:
        case BLUE_CAR:
        case GREEN_CAR:
        case BLACK_CAR:
        case WHITE_CAR:
        case YELLOW_CAR:
            handle_normal_vehicle(vehicle);
            break;
        default:
            break;
    }
    printf("Entrando a posible seg fault\n");
    delete_object(vehicle->vehicle_id);
    printf("Entrando a posible seg fault 2\n");
    free(vehicle);
    printf("Saliendo Thread\n");
    return NULL;
}

