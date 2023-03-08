#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>

typedef struct hashmap_entry
{
    char *key;
    char *value;
    struct hashmap_entry *next;
} HashmapEntry;

typedef struct hashmap
{
    size_t size;
    size_t capacity;
    HashmapEntry **table;
} Hashmap;

Hashmap *table_create();

void table_push(Hashmap *table, char *key, char *value);

char *table_get(Hashmap *table, char *key);

void table_free(Hashmap *table);

#endif
