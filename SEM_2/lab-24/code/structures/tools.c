#include "headers/tools.h"
#include "headers/stack.h"
#include "ctype.h"
#include "stdio.h"
#include "string.h"

int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];
        if (c == ' ') {
            i++;
            continue;
        } else if (isalnum(c)) {
            postfix[j++] = c;
            while (isalnum(infix[i + 1])) {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = '\1';
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            stack.top--;
        } else {
            while (stack.top != -1 && precedence(c) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
                postfix[j++] = '\1';
            }
            push(&stack, c);
        }

        i++;
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

void printInfix(Node *root) {
    if (root) {
        if (isOperator(root->data))
            printf("(");
        printInfix(root->left);
        printf("%s", root->data);
        printInfix(root->right);
        if (isOperator(root->data))
            printf(")");
    }
}

void printPostfix(char postfix[]) {
    for (int i = 0; i < strlen(postfix); ++i) {
        if (postfix[i] != '\1'){
            printf("%c", postfix[i]);
        }
    }
}


void deleteLastSpace(char data[MAX_SIZE]) {
    if (data[strlen(data) - 1] == '\n') {
        data[strlen(data) - 1] = '\0';
    }
}