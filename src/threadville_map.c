#include "threadville_map.h"
#include "utils.h"

ThreadvilleMap *create_threadville_map() {
    ThreadvilleMap *threadvilleMap = create_shared_memory(sizeof(ThreadvilleMap));
    threadvilleMap->map = create_table(954);
    threadvilleMap->streetInfoTable = create_table_street_info(954);

    pthread_mutexattr_t mattr = get_mutex_attributes();
    insert_highways(threadvilleMap->map, &mattr);
    insert_bridges(threadvilleMap->map, &mattr);
    insert_roundabouts(threadvilleMap->map, &mattr);
    insert_stops(threadvilleMap->map, &mattr);
    insert_streets(threadvilleMap->map, &mattr);
    insert_corners(threadvilleMap->map, &mattr);
    return threadvilleMap;
}

void insert_highways(Table *table, pthread_mutexattr_t *mattr) {
    for (int i = H001H; i <= H144H; ++i) {
        insert(table, i, get_mutex(mattr));
    }
}

void insert_bridges(Table *table, pthread_mutexattr_t *mattr) {
    for (int i = B001B; i <= B030B; ++i) {
        insert(table, i, get_mutex(mattr));
    }
}

void insert_roundabouts(Table *table, pthread_mutexattr_t *mattr) {
    for (int i = Y001R; i <= Z006R; ++i) {
        insert(table, i, get_mutex(mattr));
    }
}

void insert_stops(Table *table, pthread_mutexattr_t *mattr) {
    for (int i = A001S; i <= R006S; ++i) {
        insert(table, i, get_mutex(mattr));
    }
}

void insert_streets(Table *table, pthread_mutexattr_t *mattr) {
    for (int i = A001P; i <= R018P; ++i) {
        insert(table, i, get_mutex(mattr));
    }
}

void insert_corners(Table *table, pthread_mutexattr_t *mattr) {
    for (int i = A001C; i <= X004C; ++i) {
        insert(table, i, get_mutex(mattr));
    }
}
