#pragma once

#include "stdio.h"
#include "stdbool.h"

#define USAGE "Commands:\nInsert Node - insertNode <value>\nDelete Node - deleteNode <value>\nPrint Tree - printTree\nCheck for linear list - checkLinear\n"

typedef struct _node Node;

static Node *createNode(double value);

static Node *insertNode(Node *node, double value);

static Node *deleteNode(Node *node, double value);

static Node *_checkIfLinear(Node *node);

static Node *freeNode(Node *node);

static Node *_getLowestRightLeaf(Node *node);

static bool checkIfLinear(Node *node);

static void printTree(Node *root, int level);