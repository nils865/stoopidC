#include "stack.h"

Stack *stack_create()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;

    return stack;
}

void stack_push(Stack *stack, char *value)
{
    StackEntry *entry = malloc(sizeof(StackEntry));
    entry->value = value;
    entry->next = stack->top;

    stack->top = entry;
}

char *stack_pop(Stack *stack)
{
    if (stack->top == NULL)
        return NULL;

    StackEntry *entry = stack->top;
    stack->top = entry->next;

    char *value = entry->value;
    free(entry);

    return value;
}

void stack_free(Stack *stack)
{
    StackEntry *entry = stack->top;
    StackEntry *next;

    while (entry != NULL)
    {
        next = entry->next;
        free(entry);
        entry = next;
    }

    free(stack);
}

int stack_isEmpty(Stack *stack)
{
    return stack->top == NULL;
}
