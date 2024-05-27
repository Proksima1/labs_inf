#include "headers/stack.h"



void push(Stack *stack, char c) {
    stack->items[++stack->top] = c;
}

char pop(Stack *stack) {
    return stack->items[stack->top--];
}