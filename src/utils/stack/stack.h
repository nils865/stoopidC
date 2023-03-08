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

Stack *stack_create();

void stack_push(Stack *stack, char *value);

char *stack_pop(Stack *stack);

void stack_free(Stack *stack);

int stack_isEmpty(Stack *stack);

#endif
