#include "headers/stack.h"
#include "stdio.h"


Stack *create_stack()
{
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->head = NULL;
    return s;
}

StackNode *insert_stack_node(StackNode *parent, int value)
{
    StackNode *new_node = (StackNode *) malloc(sizeof(StackNode));

    new_node->element = value;
    new_node->next = parent;
    if (parent == NULL){
        new_node->maxLower = value;
    } else {
        int parent_max = parent->maxLower;
        new_node->maxLower = parent_max;
        if (parent_max <= value){
            new_node->maxLower = value;
        }
    }

    return new_node;
}

void stack_push(Stack *s, int value)
{
    s->head = insert_stack_node(s->head, value);
}

int stack_pop(Stack *s)
{
    int data = s->head->element;

    StackNode *tmp = s->head->next;
    free(s->head);
    s->head = tmp;

    return data;
}

bool stack_is_empty(Stack *s)
{
    return (s->head == NULL);
}

void stack_destroy(Stack *s)
{
    while (!stack_is_empty(s))
        stack_pop(s);
    free(s);
}

int get_max_in_stack(Stack *s){
    Stack *second_stack = create_stack();
    while (s->head->element != s->head->maxLower){
        stack_push(second_stack, stack_pop(s));
    }
    int max = stack_pop(s);
    while (!stack_is_empty(second_stack)){
        stack_push(s, stack_pop(second_stack));
    }
    stack_destroy(second_stack);
    second_stack = NULL;
    return max;
}

Stack *sort_linear_selection(Stack *s) {
    Stack *sorted_stack = create_stack();
    while (!stack_is_empty(s)){
        stack_push(sorted_stack, get_max_in_stack(s));
    }
    free(s);
    return sorted_stack;
}

void printStack(Stack *s){
    system("clear");
    if (stack_is_empty(s)) return;
    StackNode *now = s->head;
    printf("Stack head\n");
    printf("%d\n", now->element);
    while (now->next){
        now = now->next;
        printf("%d\n", now->element);
    }
}