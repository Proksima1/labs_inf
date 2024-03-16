#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tree.c"

int main()
{
    Node *root = NULL;
    printf("%s", USAGE);
    char command[25];
    printf("%s", "Your input: ");
    scanf("%s", command);
    while (strcmp(command, "exit") != 0)
    {
        if (strcmp(command, "insertNode") == 0)
        {
            double value;
            scanf("%lf", &value);
            root = insertNode(root, value);
        }
        if (strcmp(command, "checkLinear") == 0)
        {
            bool value = checkIfLinear(root);
            if (value)
            {
                printf("Tree is a linear list of nodes\n");
            }
            else
            {
                printf("Tree is NOT a linear list of nodes\n");
            }
        }
        if (strcmp(command, "deleteNode") == 0)
        {
            double value;
            scanf("%lf", &value);
            root = deleteNode(root, value);
        }
        if (strcmp(command, "printTree") == 0)
        {
            printTree(root, 0);
        }
        printf("%s", "Your input: ");
        scanf("%s", command);
    }
}
