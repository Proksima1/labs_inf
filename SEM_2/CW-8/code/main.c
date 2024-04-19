#include <stdio.h>
#include "headers/list.h"
#include "headers/iterator.h"

#define MENU "Menu:\n1. Add value\n2. Delete value\n3. Get list length\n4. Check sort\n5. Print list\n6. Exit\nInput: "

int main()
{
    int val;
    List *l = list_create();
    long data;
    bool flag = true;
    Iterator *it;
    while (flag)
    {
        printf(MENU);
        scanf("%d", &val);
        switch (val)
        {
        case 1:
            printf("Enter value to add: ");
            scanf("%ld", &data);
            list_insert(l->head, abs(data));
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%ld", &data);
            it = iter_create(l);
            if (iter_get_next_node(it)->data == data)
            {
                list_delete_next(it->node);
                break;
            }
            while (iter_next(it) != NULL)
            {
                if (iter_has_next(it))
                {
                    if (iter_get_next_node(it)->data == data)
                    {
                        list_delete_next(it->node);
                        break;
                    }
                }
            }
            free(it);
            break;
        case 3:
            printf("List length: ");
            it = iter_create(l);
            printf("%d\n", list_length(it));
            free(it);
            break;
        case 4:
            it = iter_create(l);
            if (list_length(it) == 0)
            {
                printf("List has length 0, it can`t be sorted\n");
                break;
            }
            free(it);
            it = iter_create(l);
            printf("List is ");
            if (!check_sort(it))
            {
                printf("not ");
            }
            printf("sorted\n");
            free(it);
            break;
        case 5:
            printf("Printing list: ");
            it = iter_create(l);
            print_list(it);
            printf("\n");
            free(it);
            break;
        case 6:
            flag = false;
            break;
        default:
            printf("Unknown command\n");
        }
    }
    list_destroy(l);
    free(l);
    return 0;
}