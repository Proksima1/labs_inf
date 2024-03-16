#pragma once

#include "stdbool.h"
#include "headers.h"
#include "stdlib.h"

struct _node
{
    double value;
    struct _node *left;
    struct _node *right;
};

Node *createNode(double value)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = value;
    return root;
}

Node *insertNode(Node *node, double value)
{
    if (node == NULL)
    {
        return createNode(value);
    }
    else
    {
        if (node->value < value)
        {
            if (node->right != NULL)
            {
                node->right = insertNode(node->right, value);
                return node;
            }
            else
            {
                node->right = createNode(value);
                return node;
            }
        }
        if (node->value > value)
        {
            if (node->left != NULL)
            {
                node->left = insertNode(node->left, value);
                return node;
            }
            else
            {
                node->left = createNode(value);
                return node;
            }
        }
        if (node->value == value)
        {
            return node;
        }
    }
}

bool checkIfLinear(Node *node)
{
    // If tree is linear, then True, else False
    node = _checkIfLinear(node);
    return node->left != NULL ? false : true;
}

Node *_checkIfLinear(Node *node)
{
    if ((node->left == NULL && node->right == NULL) || (node->left != NULL && node->right != NULL))
    {
        return node;
    }
    else
    {
        if (node->left != NULL && node->right == NULL)
        {
            return _checkIfLinear(node->left);
        }
        else if (node->left == NULL && node->right != NULL)
        {
            return _checkIfLinear(node->right);
        }
    }
}

Node *freeNode(Node *node)
{
    free(node);
    node = NULL;
    return node;
}

Node *deleteNode(Node *node, double value)
{
    if (node == NULL)
    {
        return node;
    }
    if (node->value < value)
    {
        Node *output = deleteNode(node->right, value);
        node->right = output;
        return node;
    }
    else if (node->value > value)
    {
        Node *output = deleteNode(node->left, value);
        node->left = output;
        return node;
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            node = freeNode(node);
            return node;
        }
        else if (node->left == NULL)
        {
            Node *temp = node->right;
            freeNode(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            freeNode(node);
            return temp;
        }
        else
        {
            Node *temp_left = node->left;
            Node *temp_right = node->right;
            freeNode(node);
            Node *lowestLeaf = _getLowestRightLeaf(temp_left);
            lowestLeaf->right = temp_right;
            return temp_left;
        }
    }
}

Node *_getLowestRightLeaf(Node *node)
{
    if (node->right == NULL && node->left == NULL)
    {
        return node;
    }
    return _getLowestRightLeaf(node->right);
}

void printTree(struct _node *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%.2lf\n", root->value);
    printTree(root->left, space);
}