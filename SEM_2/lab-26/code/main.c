#include <stdio.h>
#include "headers/stack.h"

#define MENU "1. Add stack node(s)\n2. Delete stack node(s)\n3. Print stack\n4. Sort stack\n5. Exit\nInput: "
#define ADD_MENU "Enter value to insert in stack or 0 to quit: "
#define DELETE_MENU "Enter 1 to delete head node or 0 to quit: "

int main() {
    Stack *stack = create_stack();
    int input;
    system("clear");
    while (true) {
        printf(MENU);
        scanf("%d", &input);
        if (input == 1) {
            system("clear");
            printf(ADD_MENU);
            scanf("%d", &input);
            while (input != 0) {
                stack_push(stack, input);
                printf(ADD_MENU);
                scanf("%d", &input);
            }

            system("clear");
        }
        if (input == 2) {
            system("clear");
            printf(DELETE_MENU);
            scanf("%d", &input);
            while (input != 0) {
                if (stack_is_empty(stack)) {
                    system("clear");
                    printf("Stack is empty\n");
                    break;
                }
                printf("Poped %d\n", stack_pop(stack));
                printf(DELETE_MENU);
                scanf("%d", &input);
            }
        }
        if (input == 3) {
            printStack(stack);
        }
        if (input == 4) {
            system("clear");
            stack = sort_linear_selection(stack);
            printf("Sorted\n");
        }
        if (input == 5) {
            stack_destroy(stack);
            break;
        }
    }
    // free(stack);
    stack = NULL;
    return 0;
}
