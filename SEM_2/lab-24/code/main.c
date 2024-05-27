#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ctype.h"
#include "structures/headers/tools.h"

#define MENU "Menu:\n1. Enter infix\n2. Print infix\n3. Print tree\n4. Execute transformation\n5. Exit\nInput: "
#define MAX_SIZE 100


int get_plus_polynom(Node *tree) {
    int count = 0;
    if (tree->left == NULL && tree->right == NULL) {
        return count;
    }
    if (strcmp(tree->data, "+") == 0) {
        count += 1;
    }

    count += get_plus_polynom(tree->left);
    count += get_plus_polynom(tree->right);
    return count;
}

//Node *get_last_node_not_replaced(Node *tree, Node *last_replaced) {
//    Node *copy_tree = tree;
//    if (last_replaced == NULL) {
//        while (copy_tree->left != last_replaced) {
//            copy_tree = copy_tree->left;
//        }
//        return copy_tree;
//    } else {
//        while (copy_tree->left->right->left != last_replaced) {
//            copy_tree = copy_tree->left;
//            if (strcmp(copy_tree->left->data, "*") == 0) {
//                return copy_tree->right->left;
//            }
//        }
//        return copy_tree->right->left;
//    }
//}

Node *get_last_node(Node *tree, int count, char *last_data) {
    Node *copy_tree = tree;
    for (int i = 0; i < count; ++i) {
        copy_tree = copy_tree->left;
    }
    if (last_data == NULL){
        last_data = "";
    }
    if (isOperator(copy_tree->data)) {
        if (isdigit(copy_tree->left->data[0]) && strcmp(copy_tree->left->data, last_data) != 0) {
            return copy_tree->left;
        } else {
            if (isdigit(copy_tree->right->left->data[0])){
                return copy_tree->right->left;
            }
            else {
                return copy_tree->right->right;
            }
        }

    }
    return copy_tree;
}

void execute(Node *tree, int iterations_left, char *last_replaced) {
    if (iterations_left == -1) {
        int plus_count = get_plus_polynom(tree);
        iterations_left = (plus_count + 1) / 2;
    }
    if (iterations_left == 0) {
        return;
    }
    char *temp_koef = tree->right->left->data;
    Node *deepest_node = get_last_node(tree, get_plus_polynom(tree) - 1, last_replaced);
    tree->right->left->data = deepest_node->data;
    deepest_node->data = temp_koef;

    last_replaced = deepest_node->data;
    execute(tree->left, iterations_left - 1, last_replaced);
}

void proceedMenu() {
    int val;
    bool flag = true;
    char postfix[MAX_SIZE];
    Node *root = NULL;
    while (flag) {
        printf(MENU);
        scanf("%d", &val);
        switch (val) {
            case 1:
                printf("Enter infix: ");
                char infix[MAX_SIZE];
                do {
                    fgets(infix, MAX_SIZE, stdin);
                } while (strcmp(infix, "\n") == 0);
                infix_to_postfix(infix, postfix);
                deleteLastSpace(postfix);
                root = buildExpressionTree(postfix);
                break;
            case 2:
                printf("Infix expression: ");
                printInfix(root);
                printf("\n");
                break;
            case 3:
                printExpressionTree(root, 1);
                break;
            case 4:
                execute(root, -1, NULL);
                printf("OK\n");
                break;
            case 5:
                flag = false;
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }
    clean_tree(root);
}

int main() {
    proceedMenu();

    return 0;
}

