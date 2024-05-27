#ifndef LAB24_TOOLS_H
#define LAB24_TOOLS_H

#include "tree.h"
#define MAX_SIZE 100
int precedence(char op);

void infix_to_postfix(char *infix, char *postfix);

void printInfix(Node *root);
void deleteLastSpace(char data[MAX_SIZE]);
void printPostfix(char postfix[]);

#endif
