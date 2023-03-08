#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack_entry
{
    char *value;
    struct stack_entry *next;
} StackEntry;

typedef struct stack
{
    size_t size;
    StackEntry *top;
} Stack;

#endif
