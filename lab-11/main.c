#include <stdio.h>
#include <ctype.h>

typedef enum _state {
    START,
    READING,
    PASSING,
} Estate;
const int LENGTH_WORD = 2;

int main() {
    Estate state = START;
    char ch;
    int count = 0, now_word = 0;
    while ((ch = getchar()) != EOF) {
        switch (state) {
            case START:
            case READING:
                if (ch == ' ' || ch == '\n') {
                    if (now_word <= LENGTH_WORD && now_word != 0){
                        count += 1;
                    }
                    now_word = 0;
                    state = PASSING;
                } else {
                    if (isalpha(ch)){
                        now_word += 1;
                    }
                }
                break;
            case PASSING:
                if (ch != ' ') {
                    if (isalpha(ch)){
                        now_word += 1;
                    }
                    state = READING;
                }
                break;
        }
    }
    if (now_word <= LENGTH_WORD && now_word != 0){
        count += 1;
    }
    printf("%d", count);
    return 0;

}
