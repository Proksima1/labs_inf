#include <stdio.h>

int main() {
    int ch;
    while ((ch = getchar()) != EOF){
        printf("%d", ch);
    }
    return 0;
}
