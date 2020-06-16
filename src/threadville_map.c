#include "threadville_map.h"
#include "utils.h"

ThreadvilleMap *create_threadville_map() {
    ThreadvilleMap *threadvilleMap = create_shared_memory(sizeof(ThreadvilleMap));
    threadvilleMap->map = create_table(954);
    threadvilleMap->streetInfoTable = create_table_street_info(954);

    pthread_mutexattr_t mattr = get_mutex_attributes();
    insert_highways(threadvilleMap->map, threadvilleMap->streetInfoTable, &mattr);
    insert_bridges(threadvilleMap->map, threadvilleMap->streetInfoTable, &mattr);
    insert_roundabouts(threadvilleMap->map, threadvilleMap->streetInfoTable, &mattr);
    insert_stops(threadvilleMap->map, threadvilleMap->streetInfoTable, &mattr);
    insert_streets(threadvilleMap->map, threadvilleMap->streetInfoTable, &mattr);
    insert_corners(threadvilleMap->map, threadvilleMap->streetInfoTable, &mattr);
    return threadvilleMap;
}

void insert_highways(Table *table, TableStreetInfo *streetInfo, pthread_mutexattr_t *mattr) {
    for (int i = H001H; i <= H144H; ++i) {
        insert(table, i, get_mutex(mattr));
        insert_street_info_highways(streetInfo, i);
    }
}

void insert_bridges(Table *table, TableStreetInfo *streetInfo, pthread_mutexattr_t *mattr) {
    for (int i = B001B; i <= B030B; ++i) {
        insert(table, i, get_mutex(mattr));
        insert_street_info_bridge(streetInfo, i);
    }
}

void insert_roundabouts(Table *table, TableStreetInfo *streetInfo, pthread_mutexattr_t *mattr) {
    for (int i = Y001R; i <= Z006R; ++i) {
        insert(table, i, get_mutex(mattr));
        insert_street_info_roundabouts(streetInfo, i);
    }
}

void insert_stops(Table *table, TableStreetInfo *streetInfo, pthread_mutexattr_t *mattr) {
    for (int i = A001S; i <= R006S; ++i) {
        insert(table, i, get_mutex(mattr));
        insert_street_info_stops(streetInfo, i);
    }
}

void insert_streets(Table *table, TableStreetInfo *streetInfo, pthread_mutexattr_t *mattr) {
    for (int i = A001P; i <= R018P; ++i) {
        insert(table, i, get_mutex(mattr));
        insert_street_info_streets(streetInfo, i);
    }
}

void insert_corners(Table *table, TableStreetInfo *streetInfo, pthread_mutexattr_t *mattr) {
    for (int i = A001C; i <= X004C; ++i) {
        insert(table, i, get_mutex(mattr));
        insert_street_info_corners(streetInfo, i);
    }
}

void insert_street_info_highways(TableStreetInfo *t, HighwaysIds id) {
    switch (id) {
        case H072H:
            insert_street_info(t, id, create_street_info(0.143, 0.465, WEST_DIR));
            break;
        case H071H:
            insert_street_info(t, id, create_street_info(0.159, 0.465, WEST_DIR));
            break;
        case H070H:
            insert_street_info(t, id, create_street_info(0.175, 0.465, WEST_DIR));
            break;
        case H069H:
            insert_street_info(t, id, create_street_info(0.191, 0.465, WEST_DIR));
            break;
        case H068H:
            insert_street_info(t, id, create_street_info(0.2335, 0.465, WEST_DIR));
            break;
        case H067H:
            insert_street_info(t, id, create_street_info(0.2525, 0.465, WEST_DIR));
            break;
        case H066H:
            insert_street_info(t, id, create_street_info(0.2685, 0.465, WEST_DIR));
            break;
        case H065H:
            insert_street_info(t, id, create_street_info(0.2845, 0.465, WEST_DIR));
            break;
        case H064H:
            insert_street_info(t, id, create_street_info(0.3005, 0.465, WEST_DIR));
            break;
        case H063H:
            insert_street_info(t, id, create_street_info(0.3165, 0.465, WEST_DIR));
            break;
        case H062H:
            insert_street_info(t, id, create_street_info(0.3325, 0.465, WEST_DIR));
            break;
        case H061H:
            insert_street_info(t, id, create_street_info(0.375, 0.465, WEST_DIR));
            break;
        case H060H:
            insert_street_info(t, id, create_street_info(0.394, 0.465, WEST_DIR));
            break;
        case H059H:
            insert_street_info(t, id, create_street_info(0.410, 0.465, WEST_DIR));
            break;
        case H058H:
            insert_street_info(t, id, create_street_info(0.426, 0.465, WEST_DIR));
            break;
        case H057H:
            insert_street_info(t, id, create_street_info(0.442, 0.465, WEST_DIR));
            break;
        case H056H:
            insert_street_info(t, id, create_street_info(0.458, 0.465, WEST_DIR));
            break;
        case H055H:
            insert_street_info(t, id, create_street_info(0.474, 0.465, WEST_DIR));
            break;
        case H054H:
            insert_street_info(t, id, create_street_info(0.5135, 0.465, WEST_DIR));
            break;
        case H053H:
            insert_street_info(t, id, create_street_info(0.5325, 0.465, WEST_DIR));
            break;
        case H052H:
            insert_street_info(t, id, create_street_info(0.5485, 0.465, WEST_DIR));
            break;
        case H051H:
            insert_street_info(t, id, create_street_info(0.5645, 0.465, WEST_DIR));
            break;
        case H050H:
            insert_street_info(t, id, create_street_info(0.5805, 0.465, WEST_DIR));
            break;
        case H049H:
            insert_street_info(t, id, create_street_info(0.5965, 0.465, WEST_DIR));
            break;
        case H048H:
            insert_street_info(t, id, create_street_info(0.6125, 0.465, WEST_DIR));
            break;
        case H047H:
            insert_street_info(t, id, create_street_info(0.654, 0.465, WEST_DIR));
            break;
        case H046H:
            insert_street_info(t, id, create_street_info(0.673, 0.465, WEST_DIR));
            break;
        case H045H:
            insert_street_info(t, id, create_street_info(0.689, 0.465, WEST_DIR));
            break;
        case H044H:
            insert_street_info(t, id, create_street_info(0.705, 0.465, WEST_DIR));
            break;
        case H043H:
            insert_street_info(t, id, create_street_info(0.721, 0.465, WEST_DIR));
            break;
        case H042H:
            insert_street_info(t, id, create_street_info(0.737, 0.465, WEST_DIR));
            break;
        case H041H:
            insert_street_info(t, id, create_street_info(0.753, 0.465, WEST_DIR));
            break;
        case H040H:
            insert_street_info(t, id, create_street_info(0.795, 0.465, WEST_DIR));
            break;
        case H039H:
            insert_street_info(t, id, create_street_info(0.813, 0.465, WEST_DIR));
            break;
        case H038H:
            insert_street_info(t, id, create_street_info(0.829, 0.465, WEST_DIR));
            break;
        case H037H:
            insert_street_info(t, id, create_street_info(0.844, 0.465, WEST_DIR));
            break;
        case H036H:
            insert_street_info(t, id, create_street_info(0.143, 0.426, WEST_DIR));
            break;
        case H035H:
            insert_street_info(t, id, create_street_info(0.159, 0.426, WEST_DIR));
            break;
        case H034H:
            insert_street_info(t, id, create_street_info(0.175, 0.426, WEST_DIR));
            break;
        case H033H:
            insert_street_info(t, id, create_street_info(0.191, 0.426, WEST_DIR));
            break;
        case H032H:
            insert_street_info(t, id, create_street_info(0.2335, 0.426, WEST_DIR));
            break;
        case H031H:
            insert_street_info(t, id, create_street_info(0.2525, 0.426, WEST_DIR));
            break;
        case H030H:
            insert_street_info(t, id, create_street_info(0.2685, 0.426, WEST_DIR));
            break;
        case H029H:
            insert_street_info(t, id, create_street_info(0.2845, 0.426, WEST_DIR));
            break;
        case H028H:
            insert_street_info(t, id, create_street_info(0.3005, 0.426, WEST_DIR));
            break;
        case H027H:
            insert_street_info(t, id, create_street_info(0.3165, 0.426, WEST_DIR));
            break;
        case H026H:
            insert_street_info(t, id, create_street_info(0.3325, 0.426, WEST_DIR));
            break;
        case H025H:
            insert_street_info(t, id, create_street_info(0.375, 0.426, WEST_DIR));
            break;
        case H024H:
            insert_street_info(t, id, create_street_info(0.394, 0.426, WEST_DIR));
            break;
        case H023H:
            insert_street_info(t, id, create_street_info(0.410, 0.426, WEST_DIR));
            break;
        case H022H:
            insert_street_info(t, id, create_street_info(0.426, 0.426, WEST_DIR));
            break;
        case H021H:
            insert_street_info(t, id, create_street_info(0.442, 0.426, WEST_DIR));
            break;
        case H020H:
            insert_street_info(t, id, create_street_info(0.458, 0.426, WEST_DIR));
            break;
        case H019H:
            insert_street_info(t, id, create_street_info(0.474, 0.426, WEST_DIR));
            break;
        case H018H:
            insert_street_info(t, id, create_street_info(0.5135, 0.426, WEST_DIR));
            break;
        case H017H:
            insert_street_info(t, id, create_street_info(0.5325, 0.426, WEST_DIR));
            break;
        case H016H:
            insert_street_info(t, id, create_street_info(0.5485, 0.426, WEST_DIR));
            break;
        case H015H:
            insert_street_info(t, id, create_street_info(0.5645, 0.426, WEST_DIR));
            break;
        case H014H:
            insert_street_info(t, id, create_street_info(0.5805, 0.426, WEST_DIR));
            break;
        case H013H:
            insert_street_info(t, id, create_street_info(0.5965, 0.426, WEST_DIR));
            break;
        case H012H:
            insert_street_info(t, id, create_street_info(0.6125, 0.426, WEST_DIR));
            break;
        case H011H:
            insert_street_info(t, id, create_street_info(0.654, 0.426, WEST_DIR));
            break;
        case H010H:
            insert_street_info(t, id, create_street_info(0.673, 0.426, WEST_DIR));
            break;
        case H009H:
            insert_street_info(t, id, create_street_info(0.689, 0.426, WEST_DIR));
            break;
        case H008H:
            insert_street_info(t, id, create_street_info(0.705, 0.426, WEST_DIR));
            break;
        case H007H:
            insert_street_info(t, id, create_street_info(0.721, 0.426, WEST_DIR));
            break;
        case H006H:
            insert_street_info(t, id, create_street_info(0.737, 0.426, WEST_DIR));
            break;
        case H005H:
            insert_street_info(t, id, create_street_info(0.753, 0.426, WEST_DIR));
            break;
        case H004H:
            insert_street_info(t, id, create_street_info(0.795, 0.426, WEST_DIR));
            break;
        case H003H:
            insert_street_info(t, id, create_street_info(0.813, 0.426, WEST_DIR));
            break;
        case H002H:
            insert_street_info(t, id, create_street_info(0.829, 0.426, WEST_DIR));
            break;
        case H001H:
            insert_street_info(t, id, create_street_info(0.844, 0.426, WEST_DIR));
            break;
        case H073H:
            insert_street_info(t, id, create_street_info(0.143, 0.512, EAST_DIR));
            break;
        case H074H:
            insert_street_info(t, id, create_street_info(0.159, 0.512, EAST_DIR));
            break;
        case H075H:
            insert_street_info(t, id, create_street_info(0.175, 0.512, EAST_DIR));
            break;
        case H076H:
            insert_street_info(t, id, create_street_info(0.191, 0.512, EAST_DIR));
            break;
        case H077H:
            insert_street_info(t, id, create_street_info(0.2335, 0.512, EAST_DIR));
            break;
        case H078H:
            insert_street_info(t, id, create_street_info(0.2525, 0.512, EAST_DIR));
            break;
        case H079H:
            insert_street_info(t, id, create_street_info(0.2685, 0.512, EAST_DIR));
            break;
        case H080H:
            insert_street_info(t, id, create_street_info(0.2845, 0.512, EAST_DIR));
            break;
        case H081H:
            insert_street_info(t, id, create_street_info(0.3005, 0.512, EAST_DIR));
            break;
        case H082H:
            insert_street_info(t, id, create_street_info(0.3165, 0.512, EAST_DIR));
            break;
        case H083H:
            insert_street_info(t, id, create_street_info(0.3325, 0.512, EAST_DIR));
            break;
        case H084H:
            insert_street_info(t, id, create_street_info(0.375, 0.512, EAST_DIR));
            break;
        case H085H:
            insert_street_info(t, id, create_street_info(0.394, 0.512, EAST_DIR));
            break;
        case H086H:
            insert_street_info(t, id, create_street_info(0.410, 0.512, EAST_DIR));
            break;
        case H087H:
            insert_street_info(t, id, create_street_info(0.426, 0.512, EAST_DIR));
            break;
        case H088H:
            insert_street_info(t, id, create_street_info(0.442, 0.512, EAST_DIR));
            break;
        case H089H:
            insert_street_info(t, id, create_street_info(0.458, 0.512, EAST_DIR));
            break;
        case H090H:
            insert_street_info(t, id, create_street_info(0.474, 0.512, EAST_DIR));
            break;
        case H091H:
            insert_street_info(t, id, create_street_info(0.5135, 0.512, EAST_DIR));
            break;
        case H092H:
            insert_street_info(t, id, create_street_info(0.5325, 0.512, EAST_DIR));
            break;
        case H093H:
            insert_street_info(t, id, create_street_info(0.5485, 0.512, EAST_DIR));
            break;
        case H094H:
            insert_street_info(t, id, create_street_info(0.5645, 0.512, EAST_DIR));
            break;
        case H095H:
            insert_street_info(t, id, create_street_info(0.5805, 0.512, EAST_DIR));
            break;
        case H096H:
            insert_street_info(t, id, create_street_info(0.5965, 0.512, EAST_DIR));
            break;
        case H097H:
            insert_street_info(t, id, create_street_info(0.6125, 0.512, EAST_DIR));
            break;
        case H098H:
            insert_street_info(t, id, create_street_info(0.654, 0.512, EAST_DIR));
            break;
        case H099H:
            insert_street_info(t, id, create_street_info(0.673, 0.512, EAST_DIR));
            break;
        case H100H:
            insert_street_info(t, id, create_street_info(0.689, 0.512, EAST_DIR));
            break;
        case H101H:
            insert_street_info(t, id, create_street_info(0.705, 0.512, EAST_DIR));
            break;
        case H102H:
            insert_street_info(t, id, create_street_info(0.721, 0.512, EAST_DIR));
            break;
        case H103H:
            insert_street_info(t, id, create_street_info(0.737, 0.512, EAST_DIR));
            break;
        case H104H:
            insert_street_info(t, id, create_street_info(0.753, 0.512, EAST_DIR));
            break;
        case H105H:
            insert_street_info(t, id, create_street_info(0.795, 0.512, EAST_DIR));
            break;
        case H106H:
            insert_street_info(t, id, create_street_info(0.813, 0.512, EAST_DIR));
            break;
        case H107H:
            insert_street_info(t, id, create_street_info(0.829, 0.512, EAST_DIR));
            break;
        case H108H:
            insert_street_info(t, id, create_street_info(0.844, 0.512, EAST_DIR));
            break;
        case H109H:
            insert_street_info(t, id, create_street_info(0.143, 0.55, EAST_DIR));
            break;
        case H110H:
            insert_street_info(t, id, create_street_info(0.159, 0.55, EAST_DIR));
            break;
        case H111H:
            insert_street_info(t, id, create_street_info(0.175, 0.55, EAST_DIR));
            break;
        case H112H:
            insert_street_info(t, id, create_street_info(0.191, 0.55, EAST_DIR));
            break;
        case H113H:
            insert_street_info(t, id, create_street_info(0.2335, 0.55, EAST_DIR));
            break;
        case H114H:
            insert_street_info(t, id, create_street_info(0.2525, 0.55, EAST_DIR));
            break;
        case H115H:
            insert_street_info(t, id, create_street_info(0.2685, 0.55, EAST_DIR));
            break;
        case H116H:
            insert_street_info(t, id, create_street_info(0.2845, 0.55, EAST_DIR));
            break;
        case H117H:
            insert_street_info(t, id, create_street_info(0.3005, 0.55, EAST_DIR));
            break;
        case H118H:
            insert_street_info(t, id, create_street_info(0.3165, 0.55, EAST_DIR));
            break;
        case H119H:
            insert_street_info(t, id, create_street_info(0.3325, 0.55, EAST_DIR));
            break;
        case H120H:
            insert_street_info(t, id, create_street_info(0.375, 0.55, EAST_DIR));
            break;
        case H121H:
            insert_street_info(t, id, create_street_info(0.394, 0.55, EAST_DIR));
            break;
        case H122H:
            insert_street_info(t, id, create_street_info(0.410, 0.55, EAST_DIR));
            break;
        case H123H:
            insert_street_info(t, id, create_street_info(0.426, 0.55, EAST_DIR));
            break;
        case H124H:
            insert_street_info(t, id, create_street_info(0.442, 0.55, EAST_DIR));
            break;
        case H125H:
            insert_street_info(t, id, create_street_info(0.458, 0.55, EAST_DIR));
            break;
        case H126H:
            insert_street_info(t, id, create_street_info(0.474, 0.55, EAST_DIR));
            break;
        case H127H:
            insert_street_info(t, id, create_street_info(0.5135, 0.55, EAST_DIR));
            break;
        case H128H:
            insert_street_info(t, id, create_street_info(0.5325, 0.55, EAST_DIR));
            break;
        case H129H:
            insert_street_info(t, id, create_street_info(0.5485, 0.55, EAST_DIR));
            break;
        case H130H:
            insert_street_info(t, id, create_street_info(0.5645, 0.55, EAST_DIR));
            break;
        case H131H:
            insert_street_info(t, id, create_street_info(0.5805, 0.55, EAST_DIR));
            break;
        case H132H:
            insert_street_info(t, id, create_street_info(0.5965, 0.55, EAST_DIR));
            break;
        case H133H:
            insert_street_info(t, id, create_street_info(0.6125, 0.55, EAST_DIR));
            break;
        case H134H:
            insert_street_info(t, id, create_street_info(0.654, 0.55, EAST_DIR));
            break;
        case H135H:
            insert_street_info(t, id, create_street_info(0.673, 0.55, EAST_DIR));
            break;
        case H136H:
            insert_street_info(t, id, create_street_info(0.689, 0.55, EAST_DIR));
            break;
        case H137H:
            insert_street_info(t, id, create_street_info(0.705, 0.55, EAST_DIR));
            break;
        case H138H:
            insert_street_info(t, id, create_street_info(0.721, 0.55, EAST_DIR));
            break;
        case H139H:
            insert_street_info(t, id, create_street_info(0.737, 0.55, EAST_DIR));
            break;
        case H140H:
            insert_street_info(t, id, create_street_info(0.753, 0.55, EAST_DIR));
            break;
        case H141H:
            insert_street_info(t, id, create_street_info(0.795, 0.55, EAST_DIR));
            break;
        case H142H:
            insert_street_info(t, id, create_street_info(0.813, 0.55, EAST_DIR));
            break;
        case H143H:
            insert_street_info(t, id, create_street_info(0.829, 0.55, EAST_DIR));
            break;
        case H144H:
            insert_street_info(t, id, create_street_info(0.844, 0.55, EAST_DIR));
            break;
    }
}

void insert_street_info_stops(TableStreetInfo *t, StopIds id) {
    switch (id) {
        case A001S:
            insert_street_info(t, id, create_street_info(0.117, 0.040,NORTH_DIR));
            break;
        case A002S:
            insert_street_info(t, id, create_street_info(0.165, 0.040,NORTH_DIR));
            break;
        case A003S:
            insert_street_info(t, id, create_street_info(0.181, 0.067,NORTH_DIR));
            break;
        case A004S:
            insert_street_info(t, id, create_street_info(0.181, 0.135,NORTH_DIR));
            break;
        case A005S:
            insert_street_info(t, id, create_street_info(0.165, 0.162,NORTH_DIR));
            break;
        case A006S:
            insert_street_info(t, id, create_street_info(0.117, 0.162,NORTH_DIR));
            break;
        case A007S:
            insert_street_info(t, id, create_street_info(0.104, 0.135,NORTH_DIR));
            break;
        case A008S:
            insert_street_info(t, id, create_street_info(0.104, 0.067,NORTH_DIR));
            break;

        case B001S:
            insert_street_info(t, id, create_street_info(0.2585, 0.040,NORTH_DIR));
            break;
        case B002S:
            insert_street_info(t, id, create_street_info(0.3065, 0.040,NORTH_DIR));
            break;
        case B003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.067,NORTH_DIR));
            break;
        case B004S:
            insert_street_info(t, id, create_street_info(0.3215, 0.135,NORTH_DIR));
            break;
        case B005S:
            insert_street_info(t, id, create_street_info(0.3065, 0.162,NORTH_DIR));
            break;
        case B006S:
            insert_street_info(t, id, create_street_info(0.2585, 0.162,NORTH_DIR));
            break;
        case B007S:
            insert_street_info(t, id, create_street_info(0.2455, 0.135,NORTH_DIR));
            break;
        case B008S:
            insert_street_info(t, id, create_street_info(0.2455, 0.067,NORTH_DIR));
            break;

        case C001S:
            insert_street_info(t, id, create_street_info(0.400, 0.040,NORTH_DIR));
            break;
        case C002S:
            insert_street_info(t, id, create_street_info(0.448, 0.040,NORTH_DIR));
            break;
        case C003S:
            insert_street_info(t, id, create_street_info(0.462, 0.067,NORTH_DIR));
            break;
        case C004S:
            insert_street_info(t, id, create_street_info(0.462, 0.135,NORTH_DIR));
            break;
        case C005S:
            insert_street_info(t, id, create_street_info(0.448, 0.162,NORTH_DIR));
            break;
        case C006S:
            insert_street_info(t, id, create_street_info(0.400, 0.162,NORTH_DIR));
            break;
        case C007S:
            insert_street_info(t, id, create_street_info(0.386, 0.135,NORTH_DIR));
            break;
        case C008S:
            insert_street_info(t, id, create_street_info(0.386, 0.067,NORTH_DIR));
            break;

        case D001S:
            insert_street_info(t, id, create_street_info(0.5385, 0.040,NORTH_DIR));
            break;
        case D002S:
            insert_street_info(t, id, create_street_info(0.5865, 0.040,NORTH_DIR));
            break;
        case D003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.066,NORTH_DIR));
            break;
        case D004S:
            insert_street_info(t, id, create_street_info(0.6025, 0.134,NORTH_DIR));
            break;
        case D005S:
            insert_street_info(t, id, create_street_info(0.5865, 0.162,NORTH_DIR));
            break;
        case D006S:
            insert_street_info(t, id, create_street_info(0.5385, 0.162,NORTH_DIR));
            break;
        case D007S:
            insert_street_info(t, id, create_street_info(0.5255, 0.135,NORTH_DIR));
            break;
        case D008S:
            insert_street_info(t, id, create_street_info(0.5255, 0.067,NORTH_DIR));
            break;

        case E001S:
            insert_street_info(t, id, create_street_info(0.679, 0.040,NORTH_DIR));
            break;
        case E002S:
            insert_street_info(t, id, create_street_info(0.727, 0.040,NORTH_DIR));
            break;
        case E003S:
            insert_street_info(t, id, create_street_info(0.743, 0.067,NORTH_DIR));
            break;
        case E004S:
            insert_street_info(t, id, create_street_info(0.743, 0.135,NORTH_DIR));
            break;
        case E005S:
            insert_street_info(t, id, create_street_info(0.727, 0.162,NORTH_DIR));
            break;
        case E006S:
            insert_street_info(t, id, create_street_info(0.679, 0.162,NORTH_DIR));
            break;
        case E007S:
            insert_street_info(t, id, create_street_info(0.666, 0.135,NORTH_DIR));
            break;
        case E008S:
            insert_street_info(t, id, create_street_info(0.666, 0.067,NORTH_DIR));
            break;

        case F001S:
            insert_street_info(t, id, create_street_info(0.819, 0.040,NORTH_DIR));
            break;
        case F002S:
            insert_street_info(t, id, create_street_info(0.867, 0.040,NORTH_DIR));
            break;
        case F003S:
            insert_street_info(t, id, create_street_info(0.883, 0.067,NORTH_DIR));
            break;
        case F004S:
            insert_street_info(t, id, create_street_info(0.883, 0.135,NORTH_DIR));
            break;
        case F005S:
            insert_street_info(t, id, create_street_info(0.867, 0.162,NORTH_DIR));
            break;
        case F006S:
            insert_street_info(t, id, create_street_info(0.819, 0.162,NORTH_DIR));
            break;
        case F007S:
            insert_street_info(t, id, create_street_info(0.806, 0.135,NORTH_DIR));
            break;
        case F008S:
            insert_street_info(t, id, create_street_info(0.806, 0.067,NORTH_DIR));
            break;

        case G001S:
            insert_street_info(t, id, create_street_info(0.117, 0.226,NORTH_DIR));
            break;
        case G002S:
            insert_street_info(t, id, create_street_info(0.165, 0.226,NORTH_DIR));
            break;
        case G003S:
            insert_street_info(t, id, create_street_info(0.181, 0.253,NORTH_DIR));
            break;
        case G004S:
            insert_street_info(t, id, create_street_info(0.181, 0.321,NORTH_DIR));
            break;
        case G005S:
            insert_street_info(t, id, create_street_info(0.104, 0.321,NORTH_DIR));
            break;
        case G006S:
            insert_street_info(t, id, create_street_info(0.104, 0.253,NORTH_DIR));
            break;

        case H001S:
            insert_street_info(t, id, create_street_info(0.2585, 0.226,NORTH_DIR));
            break;
        case H002S:
            insert_street_info(t, id, create_street_info(0.3065, 0.226,NORTH_DIR));
            break;
        case H003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.253,NORTH_DIR));
            break;
        case H004S:
            insert_street_info(t, id, create_street_info(0.3215, 0.321,NORTH_DIR));
            break;
        case H005S:
            insert_street_info(t, id, create_street_info(0.2455, 0.321,NORTH_DIR));
            break;
        case H006S:
            insert_street_info(t, id, create_street_info(0.2455, 0.253,NORTH_DIR));
            break;

        case I001S:
            insert_street_info(t, id, create_street_info(0.400, 0.226,NORTH_DIR));
            break;
        case I002S:
            insert_street_info(t, id, create_street_info(0.448, 0.226,NORTH_DIR));
            break;
        case I003S:
            insert_street_info(t, id, create_street_info(0.462, 0.253,NORTH_DIR));
            break;
        case I004S:
            insert_street_info(t, id, create_street_info(0.462, 0.321,NORTH_DIR));
            break;
        case I005S:
            insert_street_info(t, id, create_street_info(0.386, 0.321,NORTH_DIR));
            break;
        case I006S:
            insert_street_info(t, id, create_street_info(0.386, 0.253,NORTH_DIR));
            break;

        case J001S:
            insert_street_info(t, id, create_street_info(0.5385, 0.226,NORTH_DIR));
            break;
        case J002S:
            insert_street_info(t, id, create_street_info(0.5865, 0.226,NORTH_DIR));
            break;
        case J003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.252,NORTH_DIR));
            break;
        case J004S:
            insert_street_info(t, id, create_street_info(0.6025, 0.32,NORTH_DIR));
            break;
        case J005S:
            insert_street_info(t, id, create_street_info(0.5255, 0.321,NORTH_DIR));
            break;
        case J006S:
            insert_street_info(t, id, create_street_info(0.5255, 0.253,NORTH_DIR));
            break;

        case K001S:
            insert_street_info(t, id, create_street_info(0.679, 0.226,NORTH_DIR));
            break;
        case K002S:
            insert_street_info(t, id, create_street_info(0.727, 0.226,NORTH_DIR));
            break;
        case K003S:
            insert_street_info(t, id, create_street_info(0.743, 0.253,NORTH_DIR));
            break;
        case K004S:
            insert_street_info(t, id, create_street_info(0.743, 0.321,NORTH_DIR));
            break;
        case K005S:
            insert_street_info(t, id, create_street_info(0.666, 0.321,NORTH_DIR));
            break;
        case K006S:
            insert_street_info(t, id, create_street_info(0.666, 0.253,NORTH_DIR));
            break;

        case L001S:
            insert_street_info(t, id, create_street_info(0.819, 0.226,NORTH_DIR));
            break;
        case L002S:
            insert_street_info(t, id, create_street_info(0.867, 0.226,NORTH_DIR));
            break;
        case L003S:
            insert_street_info(t, id, create_street_info(0.883, 0.253,NORTH_DIR));
            break;
        case L004S:
            insert_street_info(t, id, create_street_info(0.883, 0.321,NORTH_DIR));
            break;
        case L005S:
            insert_street_info(t, id, create_street_info(0.806, 0.321,NORTH_DIR));
            break;
        case L006S:
            insert_street_info(t, id, create_street_info(0.806, 0.253,NORTH_DIR));
            break;

        case M001S:
            insert_street_info(t, id, create_street_info(0.181, 0.655,NORTH_DIR));
            break;
        case M002S:
            insert_street_info(t, id, create_street_info(0.181, 0.723,NORTH_DIR));
            break;
        case M003S:
            insert_street_info(t, id, create_street_info(0.165, 0.75,NORTH_DIR));
            break;
        case M004S:
            insert_street_info(t, id, create_street_info(0.117, 0.75,NORTH_DIR));
            break;
        case M005S:
            insert_street_info(t, id, create_street_info(0.104, 0.723,NORTH_DIR));
            break;
        case M006S:
            insert_street_info(t, id, create_street_info(0.104, 0.655,NORTH_DIR));
            break;

        case N001S:
            insert_street_info(t, id, create_street_info(0.3215, 0.655,NORTH_DIR));
            break;
        case N002S:
            insert_street_info(t, id, create_street_info(0.3215, 0.723,NORTH_DIR));
            break;
        case N003S:
            insert_street_info(t, id, create_street_info(0.3065, 0.75,NORTH_DIR));
            break;
        case N004S:
            insert_street_info(t, id, create_street_info(0.2585, 0.75,NORTH_DIR));
            break;
        case N005S:
            insert_street_info(t, id, create_street_info(0.2455, 0.723,NORTH_DIR));
            break;
        case N006S:
            insert_street_info(t, id, create_street_info(0.2455, 0.655,NORTH_DIR));
            break;

        case O001S:
            insert_street_info(t, id, create_street_info(0.462, 0.655,NORTH_DIR));
            break;
        case O002S:
            insert_street_info(t, id, create_street_info(0.462, 0.723,NORTH_DIR));
            break;
        case O003S:
            insert_street_info(t, id, create_street_info(0.448, 0.75,NORTH_DIR));
            break;
        case O004S:
            insert_street_info(t, id, create_street_info(0.400, 0.75,NORTH_DIR));
            break;
        case O005S:
            insert_street_info(t, id, create_street_info(0.386, 0.723,NORTH_DIR));
            break;
        case O006S:
            insert_street_info(t, id, create_street_info(0.386, 0.655,NORTH_DIR));
            break;

        case P001S:
            insert_street_info(t, id, create_street_info(0.6025, 0.654,NORTH_DIR));
            break;
        case P002S:
            insert_street_info(t, id, create_street_info(0.6025, 0.722,NORTH_DIR));
            break;
        case P003S:
            insert_street_info(t, id, create_street_info(0.5865, 0.75,NORTH_DIR));
            break;
        case P004S:
            insert_street_info(t, id, create_street_info(0.5385, 0.75,NORTH_DIR));
            break;
        case P005S:
            insert_street_info(t, id, create_street_info(0.5255, 0.723,NORTH_DIR));
            break;
        case P006S:
            insert_street_info(t, id, create_street_info(0.5255, 0.655,NORTH_DIR));
            break;

        case Q001S:
            insert_street_info(t, id, create_street_info(0.743, 0.655,NORTH_DIR));
            break;
        case Q002S:
            insert_street_info(t, id, create_street_info(0.743, 0.723,NORTH_DIR));
            break;
        case Q003S:
            insert_street_info(t, id, create_street_info(0.727, 0.75,NORTH_DIR));
            break;
        case Q004S:
            insert_street_info(t, id, create_street_info(0.679, 0.75,NORTH_DIR));
            break;
        case Q005S:
            insert_street_info(t, id, create_street_info(0.666, 0.723,NORTH_DIR));
            break;
        case Q006S:
            insert_street_info(t, id, create_street_info(0.666, 0.655,NORTH_DIR));
            break;

        case R001S:
            insert_street_info(t, id, create_street_info(0.883, 0.655,NORTH_DIR));
            break;
        case R002S:
            insert_street_info(t, id, create_street_info(0.883, 0.723,NORTH_DIR));
            break;
        case R003S:
            insert_street_info(t, id, create_street_info(0.867, 0.75,NORTH_DIR));
            break;
        case R004S:
            insert_street_info(t, id, create_street_info(0.819, 0.75,NORTH_DIR));
            break;
        case R005S:
            insert_street_info(t, id, create_street_info(0.806, 0.723,NORTH_DIR));
            break;
        case R006S:
            insert_street_info(t, id, create_street_info(0.806, 0.655,NORTH_DIR));
            break;

        case S001S:
            insert_street_info(t, id, create_street_info(0.117, 0.815,NORTH_DIR));
            break;
        case S002S:
            insert_street_info(t, id, create_street_info(0.165, 0.815,NORTH_DIR));
            break;
        case S003S:
            insert_street_info(t, id, create_street_info(0.181, 0.842,NORTH_DIR));
            break;
        case S004S:
            insert_street_info(t, id, create_street_info(0.181, 0.907,NORTH_DIR));
            break;
        case S005S:
            insert_street_info(t, id, create_street_info(0.165, 0.935,NORTH_DIR));
            break;
        case S006S:
            insert_street_info(t, id, create_street_info(0.117, 0.935,NORTH_DIR));
            break;
        case S007S:
            insert_street_info(t, id, create_street_info(0.104, 0.907,NORTH_DIR));
            break;
        case S008S:
            insert_street_info(t, id, create_street_info(0.104, 0.842,NORTH_DIR));
            break;

        case T001S:
            insert_street_info(t, id, create_street_info(0.2585, 0.815,NORTH_DIR));
            break;
        case T002S:
            insert_street_info(t, id, create_street_info(0.3065, 0.815,NORTH_DIR));
            break;
        case T003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.842,NORTH_DIR));
            break;
        case T004S:
            insert_street_info(t, id, create_street_info(0.3215, 0.907,NORTH_DIR));
            break;
        case T005S:
            insert_street_info(t, id, create_street_info(0.3065, 0.935,NORTH_DIR));
            break;
        case T006S:
            insert_street_info(t, id, create_street_info(0.2585, 0.935,NORTH_DIR));
            break;
        case T007S:
            insert_street_info(t, id, create_street_info(0.2455, 0.907,NORTH_DIR));
            break;
        case T008S:
            insert_street_info(t, id, create_street_info(0.2455, 0.842,NORTH_DIR));
            break;

        case U001S:
            insert_street_info(t, id, create_street_info(0.400, 0.815,NORTH_DIR));
            break;
        case U002S:
            insert_street_info(t, id, create_street_info(0.448, 0.815,NORTH_DIR));
            break;
        case U003S:
            insert_street_info(t, id, create_street_info(0.462, 0.842,NORTH_DIR));
            break;
        case U004S:
            insert_street_info(t, id, create_street_info(0.462, 0.907,NORTH_DIR));
            break;
        case U005S:
            insert_street_info(t, id, create_street_info(0.448, 0.935,NORTH_DIR));
            break;
        case U006S:
            insert_street_info(t, id, create_street_info(0.400, 0.935,NORTH_DIR));
            break;
        case U007S:
            insert_street_info(t, id, create_street_info(0.386, 0.907,NORTH_DIR));
            break;
        case U008S:
            insert_street_info(t, id, create_street_info(0.386, 0.842,NORTH_DIR));
            break;

        case V001S:
            insert_street_info(t, id, create_street_info(0.5385, 0.815,NORTH_DIR));
            break;
        case V002S:
            insert_street_info(t, id, create_street_info(0.5865, 0.815,NORTH_DIR));
            break;
        case V003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.841,NORTH_DIR));
            break;
        case V004S:
            insert_street_info(t, id, create_street_info(0.6025, 0.909,NORTH_DIR));
            break;
        case V005S:
            insert_street_info(t, id, create_street_info(0.5865, 0.935,NORTH_DIR));
            break;
        case V006S:
            insert_street_info(t, id, create_street_info(0.5385, 0.935,NORTH_DIR));
            break;
        case V007S:
            insert_street_info(t, id, create_street_info(0.5255, 0.907,NORTH_DIR));
            break;
        case V008S:
            insert_street_info(t, id, create_street_info(0.5255, 0.842,NORTH_DIR));
            break;

        case W001S:
            insert_street_info(t, id, create_street_info(0.679, 0.815,NORTH_DIR));
            break;
        case W002S:
            insert_street_info(t, id, create_street_info(0.727, 0.815,NORTH_DIR));
            break;
        case W003S:
            insert_street_info(t, id, create_street_info(0.743, 0.842,NORTH_DIR));
            break;
        case W004S:
            insert_street_info(t, id, create_street_info(0.743, 0.907,NORTH_DIR));
            break;
        case W005S:
            insert_street_info(t, id, create_street_info(0.727, 0.935,NORTH_DIR));
            break;
        case W006S:
            insert_street_info(t, id, create_street_info(0.679, 0.935,NORTH_DIR));
            break;
        case W007S:
            insert_street_info(t, id, create_street_info(0.666, 0.907,NORTH_DIR));
            break;
        case W008S:
            insert_street_info(t, id, create_street_info(0.666, 0.842, NORTH_DIR));
            break;

        case X001S:
            insert_street_info(t, id, create_street_info(0.819, 0.815,NORTH_DIR));
            break;
        case X002S:
            insert_street_info(t, id, create_street_info(0.867, 0.815,NORTH_DIR));
            break;
        case X003S:
            insert_street_info(t, id, create_street_info(0.883, 0.842,NORTH_DIR));
            break;
        case X004S:
            insert_street_info(t, id, create_street_info(0.883, 0.907,NORTH_DIR));
            break;
        case X005S:
            insert_street_info(t, id, create_street_info(0.867, 0.935,NORTH_DIR));
            break;
        case X006S:
            insert_street_info(t, id, create_street_info(0.819, 0.935,NORTH_DIR));
            break;
        case X007S:
            insert_street_info(t, id, create_street_info(0.806, 0.907,NORTH_DIR));
            break;
        case X008S:
            insert_street_info(t, id, create_street_info(0.806, 0.842,NORTH_DIR));
            break;

    }
}

void insert_street_info_roundabouts(TableStreetInfo *t, RoundaboutIds id) {
    switch (id) {
        case Y001R:
            insert_street_info(t, id, create_street_info(0.111, 0.45,NORTH_DIR));
            break;
        case Y002R:
            insert_street_info(t, id, create_street_info(0.111, 0.53,NORTH_DIR));
            break;
        case Y003R:
            insert_street_info(t, id, create_street_info(0.059, 0.59,NORTH_DIR));
            break;
        case Y004R:
            insert_street_info(t, id, create_street_info(0.009, 0.53,NORTH_DIR));
            break;
        case Y005R:
            insert_street_info(t, id, create_street_info(0.009, 0.45,NORTH_DIR));
            break;
        case Y006R:
            insert_street_info(t, id, create_street_info(0.059, 0.39,NORTH_DIR));
            break;
        case Z001R:
            insert_street_info(t, id, create_street_info(0.874, 0.45,NORTH_DIR));
            break;
        case Z002R:
            insert_street_info(t, id, create_street_info(0.874, 0.53,NORTH_DIR));
            break;
        case Z003R:
            insert_street_info(t, id, create_street_info(0.924, 0.59,NORTH_DIR));
            break;
        case Z004R:
            insert_street_info(t, id, create_street_info(0.976, 0.53,NORTH_DIR));
            break;
        case Z005R:
            insert_street_info(t, id, create_street_info(0.976, 0.45,NORTH_DIR));
            break;
        case Z006R:
            insert_street_info(t, id, create_street_info(0.924, 0.39,NORTH_DIR));
            break;
    }
}

void insert_street_info_bridge(TableStreetInfo *t, BridgeIds id) {
    switch (id) {
        case B001B:
            insert_street_info(t, id, create_street_info(0.213, 0.420,SOUTH_DIR));
            break;
        case B002B:
            insert_street_info(t, id, create_street_info(0.213, 0.447,SOUTH_DIR));
            break;
        case B003B:
            insert_street_info(t, id, create_street_info(0.213, 0.475,SOUTH_DIR));
            break;
        case B004B:
            insert_street_info(t, id, create_street_info(0.213, 0.501,SOUTH_DIR));
            break;
        case B005B:
            insert_street_info(t, id, create_street_info(0.213, 0.528,SOUTH_DIR));
            break;
        case B006B:
            insert_street_info(t, id, create_street_info(0.213, 0.555,SOUTH_DIR));
            break;

        case B007B:
            insert_street_info(t, id, create_street_info(0.353, 0.420,SOUTH_DIR));
            break;
        case B008B:
            insert_street_info(t, id, create_street_info(0.353, 0.447,SOUTH_DIR));
            break;
        case B009B:
            insert_street_info(t, id, create_street_info(0.353, 0.475,SOUTH_DIR));
            break;
        case B010B:
            insert_street_info(t, id, create_street_info(0.353, 0.501,SOUTH_DIR));
            break;
        case B011B:
            insert_street_info(t, id, create_street_info(0.353, 0.528,SOUTH_DIR));
            break;
        case B012B:
            insert_street_info(t, id, create_street_info(0.353, 0.555,SOUTH_DIR));
            break;

        case B013B:
            insert_street_info(t, id, create_street_info(0.493, 0.420,SOUTH_DIR));
            break;
        case B014B:
            insert_street_info(t, id, create_street_info(0.493, 0.447,SOUTH_DIR));
            break;
        case B015B:
            insert_street_info(t, id, create_street_info(0.493, 0.475,SOUTH_DIR));
            break;
        case B016B:
            insert_street_info(t, id, create_street_info(0.493, 0.501,SOUTH_DIR));
            break;
        case B017B:
            insert_street_info(t, id, create_street_info(0.493, 0.528,SOUTH_DIR));
            break;
        case B018B:
            insert_street_info(t, id, create_street_info(0.493, 0.555,SOUTH_DIR));
            break;

        case B019B:
            insert_street_info(t, id, create_street_info(0.634, 0.420,SOUTH_DIR));
            break;
        case B020B:
            insert_street_info(t, id, create_street_info(0.634, 0.447,SOUTH_DIR));
            break;
        case B021B:
            insert_street_info(t, id, create_street_info(0.634, 0.475,SOUTH_DIR));
            break;
        case B022B:
            insert_street_info(t, id, create_street_info(0.634, 0.501,SOUTH_DIR));
            break;
        case B023B:
            insert_street_info(t, id, create_street_info(0.634, 0.528,SOUTH_DIR));
            break;
        case B024B:
            insert_street_info(t, id, create_street_info(0.634, 0.555,SOUTH_DIR));
            break;

        case B025B:
            insert_street_info(t, id, create_street_info(0.775, 0.420,SOUTH_DIR));
            break;
        case B026B:
            insert_street_info(t, id, create_street_info(0.775, 0.447,SOUTH_DIR));
            break;
        case B027B:
            insert_street_info(t, id, create_street_info(0.775, 0.475,SOUTH_DIR));
            break;
        case B028B:
            insert_street_info(t, id, create_street_info(0.775, 0.501,SOUTH_DIR));
            break;
        case B029B:
            insert_street_info(t, id, create_street_info(0.775, 0.528,SOUTH_DIR));
            break;
        case B030B:
            insert_street_info(t, id, create_street_info(0.775, 0.555,SOUTH_DIR));
            break;
    }
}

void insert_street_info_streets(TableStreetInfo *t, StreetIds id) {
    switch (id) {
        case A001P:
            break;
        case A002P:
            break;
        case A003P:
            break;
        case A004P:
            break;
        case A005P:
            break;
        case A006P:
            break;
        case A007P:
            break;
        case A008P:
            break;
        case A009P:
            break;
        case A010P:
            break;
        case A011P:
            break;
        case A012P:
            break;
        case A013P:
            break;
        case A014P:
            break;
        case A015P:
            break;
        case A016P:
            break;
        case A017P:
            break;
        case A018P:
            break;
        case A019P:
            break;
        case A020P:
            break;
        case A021P:
            break;
        case A022P:
            break;
        case A023P:
            break;
        case A024P:
            break;
        case B001P:
            break;
        case B002P:
            break;
        case B003P:
            break;
        case B004P:
            break;
        case B005P:
            break;
        case B006P:
            break;
        case B007P:
            break;
        case B008P:
            break;
        case B009P:
            break;
        case B010P:
            break;
        case B011P:
            break;
        case B012P:
            break;
        case B013P:
            break;
        case B014P:
            break;
        case B015P:
            break;
        case B016P:
            break;
        case B017P:
            break;
        case B018P:
            break;
        case B019P:
            break;
        case B020P:
            break;
        case B021P:
            break;
        case B022P:
            break;
        case B023P:
            break;
        case B024P:
            break;
        case C001P:
            break;
        case C002P:
            break;
        case C003P:
            break;
        case C004P:
            break;
        case C005P:
            break;
        case C006P:
            break;
        case C007P:
            break;
        case C008P:
            break;
        case C009P:
            break;
        case C010P:
            break;
        case C011P:
            break;
        case C012P:
            break;
        case C013P:
            break;
        case C014P:
            break;
        case C015P:
            break;
        case C016P:
            break;
        case C017P:
            break;
        case C018P:
            break;
        case C019P:
            break;
        case C020P:
            break;
        case C021P:
            break;
        case C022P:
            break;
        case C023P:
            break;
        case C024P:
            break;
        case D001P:
            break;
        case D002P:
            break;
        case D003P:
            break;
        case D004P:
            break;
        case D005P:
            break;
        case D006P:
            break;
        case D007P:
            break;
        case D008P:
            break;
        case D009P:
            break;
        case D010P:
            break;
        case D011P:
            break;
        case D012P:
            break;
        case D013P:
            break;
        case D014P:
            break;
        case D015P:
            break;
        case D016P:
            break;
        case D017P:
            break;
        case D018P:
            break;
        case D019P:
            break;
        case D020P:
            break;
        case D021P:
            break;
        case D022P:
            break;
        case D023P:
            break;
        case D024P:
            break;
        case E001P:
            break;
        case E002P:
            break;
        case E003P:
            break;
        case E004P:
            break;
        case E005P:
            break;
        case E006P:
            break;
        case E007P:
            break;
        case E008P:
            break;
        case E009P:
            break;
        case E010P:
            break;
        case E011P:
            break;
        case E012P:
            break;
        case E013P:
            break;
        case E014P:
            break;
        case E015P:
            break;
        case E016P:
            break;
        case E017P:
            break;
        case E018P:
            break;
        case E019P:
            break;
        case E020P:
            break;
        case E021P:
            break;
        case E022P:
            break;
        case E023P:
            break;
        case E024P:
            break;
        case F001P:
            break;
        case F002P:
            break;
        case F003P:
            break;
        case F004P:
            break;
        case F005P:
            break;
        case F006P:
            break;
        case F007P:
            break;
        case F008P:
            break;
        case F009P:
            break;
        case F010P:
            break;
        case F011P:
            break;
        case F012P:
            break;
        case F013P:
            break;
        case F014P:
            break;
        case F015P:
            break;
        case F016P:
            break;
        case F017P:
            break;
        case F018P:
            break;
        case F019P:
            break;
        case F020P:
            break;
        case F021P:
            break;
        case F022P:
            break;
        case F023P:
            break;
        case F024P:
            break;
        case S001P:
            break;
        case S002P:
            break;
        case S003P:
            break;
        case S004P:
            break;
        case S005P:
            break;
        case S006P:
            break;
        case S007P:
            break;
        case S008P:
            break;
        case S009P:
            break;
        case S010P:
            break;
        case S011P:
            break;
        case S012P:
            break;
        case S013P:
            break;
        case S014P:
            break;
        case S015P:
            break;
        case S016P:
            break;
        case S017P:
            break;
        case S018P:
            break;
        case S019P:
            break;
        case S020P:
            break;
        case S021P:
            break;
        case S022P:
            break;
        case S023P:
            break;
        case S024P:
            break;
        case T001P:
            break;
        case T002P:
            break;
        case T003P:
            break;
        case T004P:
            break;
        case T005P:
            break;
        case T006P:
            break;
        case T007P:
            break;
        case T008P:
            break;
        case T009P:
            break;
        case T010P:
            break;
        case T011P:
            break;
        case T012P:
            break;
        case T013P:
            break;
        case T014P:
            break;
        case T015P:
            break;
        case T016P:
            break;
        case T017P:
            break;
        case T018P:
            break;
        case T019P:
            break;
        case T020P:
            break;
        case T021P:
            break;
        case T022P:
            break;
        case T023P:
            break;
        case T024P:
            break;
        case U001P:
            break;
        case U002P:
            break;
        case U003P:
            break;
        case U004P:
            break;
        case U005P:
            break;
        case U006P:
            break;
        case U007P:
            break;
        case U008P:
            break;
        case U009P:
            break;
        case U010P:
            break;
        case U011P:
            break;
        case U012P:
            break;
        case U013P:
            break;
        case U014P:
            break;
        case U015P:
            break;
        case U016P:
            break;
        case U017P:
            break;
        case U018P:
            break;
        case U019P:
            break;
        case U020P:
            break;
        case U021P:
            break;
        case U022P:
            break;
        case U023P:
            break;
        case U024P:
            break;
        case V001P:
            break;
        case V002P:
            break;
        case V003P:
            break;
        case V004P:
            break;
        case V005P:
            break;
        case V006P:
            break;
        case V007P:
            break;
        case V008P:
            break;
        case V009P:
            break;
        case V010P:
            break;
        case V011P:
            break;
        case V012P:
            break;
        case V013P:
            break;
        case V014P:
            break;
        case V015P:
            break;
        case V016P:
            break;
        case V017P:
            break;
        case V018P:
            break;
        case V019P:
            break;
        case V020P:
            break;
        case V021P:
            break;
        case V022P:
            break;
        case V023P:
            break;
        case V024P:
            break;
        case W001P:
            break;
        case W002P:
            break;
        case W003P:
            break;
        case W004P:
            break;
        case W005P:
            break;
        case W006P:
            break;
        case W007P:
            break;
        case W008P:
            break;
        case W009P:
            break;
        case W010P:
            break;
        case W011P:
            break;
        case W012P:
            break;
        case W013P:
            break;
        case W014P:
            break;
        case W015P:
            break;
        case W016P:
            break;
        case W017P:
            break;
        case W018P:
            break;
        case W019P:
            break;
        case W020P:
            break;
        case W021P:
            break;
        case W022P:
            break;
        case W023P:
            break;
        case W024P:
            break;
        case X001P:
            break;
        case X002P:
            break;
        case X003P:
            break;
        case X004P:
            break;
        case X005P:
            break;
        case X006P:
            break;
        case X007P:
            break;
        case X008P:
            break;
        case X009P:
            break;
        case X010P:
            break;
        case X011P:
            break;
        case X012P:
            break;
        case X013P:
            break;
        case X014P:
            break;
        case X015P:
            break;
        case X016P:
            break;
        case X017P:
            break;
        case X018P:
            break;
        case X019P:
            break;
        case X020P:
            break;
        case X021P:
            break;
        case X022P:
            break;
        case X023P:
            break;
        case X024P:
            break;
        case G007P:
            break;
        case G008P:
            break;
        case G009P:
            break;
        case G010P:
            break;
        case G011P:
            break;
        case G012P:
            break;
        case G013P:
            break;
        case G014P:
            break;
        case G015P:
            break;
        case G016P:
            break;
        case G017P:
            break;
        case G018P:
            break;
        case H007P:
            break;
        case H008P:
            break;
        case H009P:
            break;
        case H010P:
            break;
        case H011P:
            break;
        case H012P:
            break;
        case H013P:
            break;
        case H014P:
            break;
        case H015P:
            break;
        case H016P:
            break;
        case H017P:
            break;
        case H018P:
            break;
        case I007P:
            break;
        case I008P:
            break;
        case I009P:
            break;
        case I010P:
            break;
        case I011P:
            break;
        case I012P:
            break;
        case I013P:
            break;
        case I014P:
            break;
        case I015P:
            break;
        case I016P:
            break;
        case I017P:
            break;
        case I018P:
            break;
        case J007P:
            break;
        case J008P:
            break;
        case J009P:
            break;
        case J010P:
            break;
        case J011P:
            break;
        case J012P:
            break;
        case J013P:
            break;
        case J014P:
            break;
        case J015P:
            break;
        case J016P:
            break;
        case J017P:
            break;
        case J018P:
            break;
        case K007P:
            break;
        case K008P:
            break;
        case K009P:
            break;
        case K010P:
            break;
        case K011P:
            break;
        case K012P:
            break;
        case K013P:
            break;
        case K014P:
            break;
        case K015P:
            break;
        case K016P:
            break;
        case K017P:
            break;
        case K018P:
            break;
        case L007P:
            break;
        case L008P:
            break;
        case L009P:
            break;
        case L010P:
            break;
        case L011P:
            break;
        case L012P:
            break;
        case L013P:
            break;
        case L014P:
            break;
        case L015P:
            break;
        case L016P:
            break;
        case L017P:
            break;
        case L018P:
            break;
        case M001P:
            break;
        case M002P:
            break;
        case M003P:
            break;
        case M004P:
            break;
        case M005P:
            break;
        case M006P:
            break;
        case M013P:
            break;
        case M014P:
            break;
        case M015P:
            break;
        case M016P:
            break;
        case M017P:
            break;
        case M018P:
            break;
        case N001P:
            break;
        case N002P:
            break;
        case N003P:
            break;
        case N004P:
            break;
        case N005P:
            break;
        case N006P:
            break;
        case N013P:
            break;
        case N014P:
            break;
        case N015P:
            break;
        case N016P:
            break;
        case N017P:
            break;
        case N018P:
            break;
        case O001P:
            break;
        case O002P:
            break;
        case O003P:
            break;
        case O004P:
            break;
        case O005P:
            break;
        case O006P:
            break;
        case O013P:
            break;
        case O014P:
            break;
        case O015P:
            break;
        case O016P:
            break;
        case O017P:
            break;
        case O018P:
            break;
        case P001P:
            break;
        case P002P:
            break;
        case P003P:
            break;
        case P004P:
            break;
        case P005P:
            break;
        case P006P:
            break;
        case P013P:
            break;
        case P014P:
            break;
        case P015P:
            break;
        case P016P:
            break;
        case P017P:
            break;
        case P018P:
            break;
        case Q001P:
            break;
        case Q002P:
            break;
        case Q003P:
            break;
        case Q004P:
            break;
        case Q005P:
            break;
        case Q006P:
            break;
        case Q013P:
            break;
        case Q014P:
            break;
        case Q015P:
            break;
        case Q016P:
            break;
        case Q017P:
            break;
        case Q018P:
            break;
        case R001P:
            break;
        case R002P:
            break;
        case R003P:
            break;
        case R004P:
            break;
        case R005P:
            break;
        case R006P:
            break;
        case R013P:
            break;
        case R014P:
            break;
        case R015P:
            break;
        case R016P:
            break;
        case R017P:
            break;
        case R018P:
            break;
    }
}

void insert_street_info_corners(TableStreetInfo *t, CornersIds id) {
    switch (id) {
        case A001C:
            break;
        case A002C:
            break;
        case A003C:
            break;
        case A004C:
            break;
        case B001C:
            break;
        case B002C:
            break;
        case B003C:
            break;
        case B004C:
            break;
        case C001C:
            break;
        case C002C:
            break;
        case C003C:
            break;
        case C004C:
            break;
        case D001C:
            break;
        case D002C:
            break;
        case D003C:
            break;
        case D004C:
            break;
        case E001C:
            break;
        case E002C:
            break;
        case E003C:
            break;
        case E004C:
            break;
        case F001C:
            break;
        case F002C:
            break;
        case F003C:
            break;
        case F004C:
            break;
        case G003C:
            break;
        case G004C:
            break;
        case H003C:
            break;
        case H004C:
            break;
        case I003C:
            break;
        case I004C:
            break;
        case J003C:
            break;
        case J004C:
            break;
        case K003C:
            break;
        case K004C:
            break;
        case L003C:
            break;
        case L004C:
            break;
        case M001C:
            break;
        case M002C:
            break;
        case M003C:
            break;
        case M004C:
            break;
        case N001C:
            break;
        case N002C:
            break;
        case N003C:
            break;
        case N004C:
            break;
        case O001C:
            break;
        case O002C:
            break;
        case O003C:
            break;
        case O004C:
            break;
        case P001C:
            break;
        case P002C:
            break;
        case P003C:
            break;
        case P004C:
            break;
        case Q001C:
            break;
        case Q002C:
            break;
        case Q003C:
            break;
        case Q004C:
            break;
        case R001C:
            break;
        case R002C:
            break;
        case R003C:
            break;
        case R004C:
            break;
        case S003C:
            break;
        case S004C:
            break;
        case T003C:
            break;
        case T004C:
            break;
        case U003C:
            break;
        case U004C:
            break;
        case V003C:
            break;
        case V004C:
            break;
        case W003C:
            break;
        case W004C:
            break;
        case X002C:
            break;
        case X003C:
            break;
        case X004C:
            break;
    }
}

