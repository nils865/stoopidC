#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

Hashmap *table_create()
{
    Hashmap *table = malloc(sizeof(Hashmap));
    table->size = 0;
    table->capacity = 64;

    table->table = calloc(table->capacity, sizeof(HashmapEntry *));

    return table;
}

size_t hash(char *str)
{
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

void table_push(Hashmap *table, char *key, char *value)
{
    size_t index = hash(key) % table->capacity;

    HashmapEntry *entry = table->table[index];

    if (entry == NULL)
    {
        entry = malloc(sizeof(HashmapEntry));
        entry->key = key;
        entry->value = value;
        entry->next = NULL;

        table->table[index] = entry;
        table->size++;
    }
    else
    {
        HashmapEntry *prev;

        while (entry != NULL)
        {
            if (strcmp(entry->key, key) == 0)
            {
                entry->value = value;
                return;
            }

            prev = entry;
            entry = prev->next;
        }

        entry = malloc(sizeof(HashmapEntry));
        entry->key = key;
        entry->value = value;
        entry->next = NULL;

        prev->next = entry;
        table->size++;
    }
}

char *table_get(Hashmap *table, char *key)
{
    size_t index = hash(key) % table->capacity;

    HashmapEntry *entry = table->table[index];

    if (entry == NULL)
    {
        return NULL;
    }
    else
    {
        while (entry != NULL)
        {
            if (strcmp(entry->key, key) == 0)
            {
                return entry->value;
            }

            entry = entry->next;
        }

        return NULL;
    }
}

void table_free(Hashmap *table)
{
    for (size_t i = 0; i < table->capacity; i++)
    {
        HashmapEntry *entry = table->table[i];

        while (entry != NULL)
        {
            HashmapEntry *next = entry->next;
            free(entry);
            entry = next;
        }
    }

    free(table->table);
    free(table);
}
