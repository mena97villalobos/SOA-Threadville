#ifndef PROYECTO3_HASH_TABLE_H
#define PROYECTO3_HASH_TABLE_H

#include <pthread.h>

typedef struct Node {
    int key;
    pthread_mutex_t *val;
    struct Node *next;
} Node;

typedef struct Table {
    int size;
    Node **list;
} Table;

Table *create_table(int size);

int hash_code(Table*, int);

void insert(Table*, int, pthread_mutex_t*);

pthread_mutex_t *lookup(Table *t, int);

#endif //PROYECTO3_HASH_TABLE_H
