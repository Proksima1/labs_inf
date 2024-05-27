#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#include "stdio.h"
#include "headers/tree.h"
#include "stdbool.h"


Node *createNode(char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void clean_tree(Node *root) {
    if (root->left != NULL) {
        clean_tree(root->left);
        clean_tree(root->right);
    }
    free(root->data);
    free(root);
}

int isOperator(char *c) {
    if (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0 || strcmp(c, "^") == 0)
        return 1;
    return 0;
}

Node *buildExpressionTree(char postfix[MAX_STRING_LENGTH]) {
    Node *stack[100];
    int top = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        char *newData = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
        newData[0] = postfix[i];
        newData[1] = '\0';

        Node *newNode = createNode(newData);

        if (isdigit(postfix[i])) {
            int j = 0;
            while (postfix[i] != '\1') {
                newData[j++] = postfix[i++];
            }
            newData[j] = '\0';
            newNode->data = newData;
        } else {
            i++;
        }
        if (!isOperator(newData)) {
            stack[++top] = newNode;
        } else {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

void printExpressionTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    printExpressionTree(root->right, space);
    for (int i = 5; i < space; i++) {
        printf("-");
    }
    printf(" ");
    printf("%s\n", root->data);
    printExpressionTree(root->left, space);
}