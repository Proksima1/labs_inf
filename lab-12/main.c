#include <stdio.h>


typedef enum _state {
    GET_NUM,
    GET_SHIFT_DIR,
} Estate;

int poww(int x, int power) {
    int total = 1;
    for (int i = 0; i < power; ++i) {
        total *= x;
    }
    return total;
}

int main() {
    Estate state = GET_NUM;
    int ch, num, total = 0, shift_dir = 0, word_length = 0;
    while ((ch = getchar()) != EOF) {
        switch (state) {
            case GET_NUM:
                if (ch != '\n') {
                    num = ch - 48;
                    printf("%d\n", num);
                    total = total * 10 + num;
                    word_length += 1;
                } else {
                    state = GET_SHIFT_DIR;
                }
                break;
            case GET_SHIFT_DIR:
                shift_dir = ch == '>' ? 1 : -1;
                printf("%d\n", shift_dir);
                break;
        }
    }
    int last_n = poww(10, word_length - 1), output;
    if (shift_dir == 1) {
        output = (total % 10 * last_n) + (total / 10);
        printf("%d", output);
    } else {
        output = (total % last_n) * 10 + (total / last_n);
        printf("%d", output);
    }
    return 0;

}
