#ifndef LAB24_TREE_H
#define LAB24_TREE_H
#define MAX_STRING_LENGTH 100

typedef struct node {
    char *data;
    struct node *left, *right;
} Node;

Node *createNode(char *data);

Node *buildExpressionTree(char postfix[MAX_STRING_LENGTH]);

int isOperator(char *c);

void clean_tree(Node *root);

void printExpressionTree(Node *root, int space);

#endif
