#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "headers/table.h"
#include "headers/str.h"

int num_length(int num) {
    if (!num) return 1;
    int res = 0;
    while (num) {
        num /= 10;
        res++;
    }
    return res;
}

void spaces(int count) {
    for (int i = 0; i < count; i++)
        printf(" ");
}

Table *new_table() {
    Table *table = (Table *) malloc(sizeof(Table));
    for (int i = 0; i < TABLE_SIZE; i++)
        table->rows[i] = NULL;
    table->size = 0;
    return table;
}

int check_key(int real_part, int imaginary_part, Table *table) {
    if (table->size)
        for (int i = 0; i < table->size; i++)
            if (creal(table->rows[i]->key->z) == real_part && cimag(table->rows[i]->key->z) == imaginary_part) {
                return 1;
            }
    return 0;
}

void add_random_row(Table *table) {
    int rand_real_num = rand() % 100000;
    int rand_im_num = rand() % 100000;
    while (check_key(rand_real_num, rand_im_num, table)) {
        rand_real_num = rand() % 100000;
        rand_im_num = rand() % 100000;
    }
    srand(time(NULL) % rand() % (rand() % 10000));
    Row *row = (Row *) malloc(sizeof(Row));
    row->key = (Key *) malloc(sizeof(Key));
    row->key->z = rand_real_num + rand_im_num * I;
    row->data = random_string(rand() % 15 + 2);
    table->rows[table->size] = row;
    table->size++;
}

String *convert_to_string(void) {
    String *data = create_string();
    char chr = getchar();
    while ((chr = getchar()) != '\n')
        add(chr, data);
    return data;
}

int add_row(Table *table) {
    if (table->size == 10) {
        printf("Table overflow!\n\n ");
        return 0;
    }
    Row *row = (Row *) malloc(sizeof(Row));
    row->key = (Key *) malloc(sizeof(Key));
    printf("Enter real part of key: ");
    double real;
    scanf("%lf", &real);
    printf("Enter imaginary part of key: ");
    double im;
    scanf("%lf", &im);

    if (check_key(real, im, table)) {
        printf("The entered key already exists.\n\n ");
        free(row->key);
        free(row);
        return 0;
    }

    printf("Enter data: ");
    row->key->z = real + im * I;

    String *data = convert_to_string();

    row->data = data;

    table->rows[table->size] = row;
    table->size++;
    return 1;
}

void print_table(Table *table) {
    if (!table->size) {
        printf("EMPTY\n");
        return;
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < table->size; i++) {
        if (num_length(creal(table->rows[i]->key->z)) > a)
            a = num_length(creal(table->rows[i]->key->z));
        if (cimag(table->rows[i]->key->z) > b)
            b = num_length(cimag(table->rows[i]->key->z));
        if (table->rows[i]->data->size > c)
            c = table->rows[i]->data->size;
    }

    printf(" ");
    for (int i = 0; i < table->size; i++) {
        printf(" ");
        printf("| ");
        spaces(a - num_length(creal(table->rows[i]->key->z)));
        printf("%lf - ", creal(table->rows[i]->key->z));
        printf("%lf", cimag(table->rows[i]->key->z));
        spaces(b - num_length(cimag(table->rows[i]->key->z)));
        printf(" | ");
        print(table->rows[i]->data);
        spaces(c - table->rows[i]->data->size);
        printf(" |\n ");
    }
}

void swap(int first, int second, Table *table) {
    Row *temp = table->rows[first];
    table->rows[first] = table->rows[second];
    table->rows[second] = temp;
}

int partition(Table *table, int low, int high) {
    Key *pivot = table->rows[high]->key;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if ((creal(table->rows[j]->key->z) < creal(pivot->z)) ||
            (creal(table->rows[j]->key->z) == creal(pivot->z) &&
             cimag(table->rows[j]->key->z) < cimag(pivot->z))) {
            i++;
            swap(i, j, table);
        }
    }
    swap(i + 1, high, table);
    return i + 1;
}

void quicksort(Table *table, int low, int high) {
    if (low < high) {
        int pivot = partition(table, low, high);
        quicksort(table, low, pivot - 1);
        quicksort(table, pivot + 1, high);
    }
}

void reverse_table(Table *table) {
    if (table->size > 1)
        for (int i = 0; i < table->size / 2; i++)
            swap(i, table->size - i - 1, table);
}

void sort_table(Table *table) {
    quicksort(table, 0, table->size - 1);
}

void clean_table(Table *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->rows[i]->key);
        clean(table->rows[i]->data);
        free(table->rows[i]);
    }
    free(table);
}

void mix_table(Table *table) {
    if (table->size > 1) {
        srand(time(NULL));
        for (int i = rand() % (table->size - 1); i < table->size; i += rand() % 3)
            swap(i, table->size - i - 1, table);
    }
}


int comb_compare(double real_first, double imag_first, double real_second, double imag_second) {
    if ((real_first > real_second) || (real_first == real_second && (imag_first > imag_second)))
        return 1;
    if ((real_first < real_second) || (real_first == real_second && (imag_first < imag_second)))
        return -1;
    return 0;
}

String *bin_search(int real_part, int imag_part, Table *table) {
    if (!table->size)
        return NULL;

    sort_table(table);
    int down = 0, top = table->size;
    int temp_down = down, temp_top = top;

    while (1) {
        if (comb_compare(real_part, imag_part, creal(table->rows[down]->key->z),
                         cimag(table->rows[down]->key->z)) == -1)
            return NULL;

        if (comb_compare(real_part, imag_part, creal(table->rows[top - 1]->key->z),
                         cimag(table->rows[top - 1]->key->z)) == 1)
            return NULL;

        if (!comb_compare(real_part, imag_part, creal(table->rows[down]->key->z),
                          cimag(table->rows[down]->key->z)))
            return table->rows[down]->data;

        if (!comb_compare(real_part, imag_part, creal(table->rows[top - 1]->key->z),
                          cimag(table->rows[top - 1]->key->z)))
            return table->rows[top - 1]->data;

        if (!comb_compare(real_part, imag_part, creal(table->rows[top / 2]->key->z),
                          cimag(table->rows[top / 2]->key->z)))
            return table->rows[top / 2]->data;

        if (comb_compare(real_part, imag_part, creal(table->rows[top / 2]->key->z),
                         cimag(table->rows[top / 2]->key->z)) <= 0 &&
            comb_compare(real_part, imag_part, creal(table->rows[down]->key->z),
                         cimag(table->rows[down]->key->z)) == 1)
            top = top / 2;

        else if (comb_compare(real_part, imag_part, creal(table->rows[top / 2]->key->z),
                              cimag(table->rows[top / 2]->key->z)) >= 0 &&
                 comb_compare(real_part, imag_part, creal(table->rows[top - 1]->key->z),
                              cimag(table->rows[top - 1]->key->z)) == -1)
            down = top / 2 + 1;

        if (top - down < 2 || (temp_down == down && temp_top == top))
            return NULL;

        temp_top = top;
        temp_down = down;
    }
}
