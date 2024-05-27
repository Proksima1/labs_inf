#ifndef LAB24_STACK_H
#define LAB24_STACK_H

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
void push(Stack *stack, char c);
char pop(Stack *stack);
#endif
