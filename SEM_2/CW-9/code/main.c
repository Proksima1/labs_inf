#include "stdbool.h"
#include "headers/table.h"

#define MENU "Menu:\n1. Fill table by hand\n2. Fill table randomly\n3. Clear table\n4. Sort\n5. Search by key\n6. Reverse table\n7. Mix table\n8. Print table\n9. Exit\nInput: "


// Вариант 11 - 9 - комплексное число, быстрая сортировка хоара
int main() {
    int val, data;
    double real, imag;
    bool flag = true;
    Table *table = new_table();
    while (flag) {
        printf(MENU);
        scanf("%d", &val);
        switch (val) {
            case 1:
                printf("Enter count of rows(<=10): ");
                scanf("%d", &data);
                while (data > 10) {
                    printf("Entered number > 10. Enter count of rows(<=10): ");
                    scanf("%d", &data);
                }
                for (int i = 0; i < data; ++i) {
                    add_row(table);
                }
                break;
            case 2:
                printf("Enter count of rows(<=10): ");
                scanf("%d", &data);
                while (data > 10) {
                    printf("Entered number > 10. Enter count of rows(<=10): ");
                    scanf("%d", &data);
                }
                for (int i = 0; i < data; ++i) {
                    add_random_row(table);
                }
                break;
            case 3:
                if (!table->size)
                    printf("Table already cleared.\n");
                else {
                    clean_table(table);
                    table = new_table();
                    printf("OK\n");
                }
                break;
            case 4:
                sort_table(table);
                printf("OK\n");
                break;
            case 5:
                printf("Real part of key: ");
                scanf("%lf", &real);
                printf("Imaginary part of key: ");
                scanf("%lf", &imag);
                String *res = bin_search(real, imag, table);
                if (res == NULL) {
                    printf("Not found!\n");
                } else {
                    print(res);
                    printf("\n");
                }
                break;
            case 6:
                reverse_table(table);
                printf("OK\n");
                break;
            case 7:
                mix_table(table);
                printf("OK\n");
                break;
            case 8:
                print_table(table);
                break;
            case 9:
                flag = false;
                break;
            default:
                printf("Unknown command\n");
        }
    }
    clean_table(table);
    return 0;
}