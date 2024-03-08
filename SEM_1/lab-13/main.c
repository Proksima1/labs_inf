#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define CONSONANTS (1 << (225 - 224) | 1 << (226 - 224) | 1 << (227 - 224) | 1 << (228 - 224) | 1 << (231 - 224) | 1 << (230 - 224) | 1 << (235 - 224) | 1 << (236 - 224) | 1 << (237 - 224) | 1 << (240 - 224) | 1 << (233 - 224) | 1 << (239 - 224) | 1 << (244 - 224) | 1 << (234 - 224) | 1 << (242 - 224) | 1 << (241 - 224) | 1 << (248 - 224) | 1 << (245 - 224) | 1 << (246 - 224) | 1 << (247 - 224))
//бвгдзжлмнрй
#define RINGING_SET (1 << (225 - 224) | 1 << (226 - 224) | 1 << (227 - 224) | 1 << (228 - 224) | 1 << (231 - 224) | 1 << (230 - 224) | 1 << (235 - 224) | 1 << (236 - 224) | 1 << (237 - 224) | 1 << (240 - 224) | 1 << (233 - 224))
//пфктсшчцхщ
#define DULL_SET (1 << (239 - 224) | 1 << (244 - 224) | 1 << (234 - 224) | 1 << (242 - 224) | 1 << (241 - 224) | 1 << (248 - 224) | 1 << (245 - 224) | 1 << (246 - 224) | 1 << (247 - 224) )
//зсц
#define SIBILANT_SET (1 << (231 - 224) | 1 << (241 - 224) | 1 << (246 - 224))
//жшчщ
#define HISSING_SET (1 << (247 - 224) | 1 << (230 - 224) | 1 << (248 - 224) | 1 << (249 - 224))
typedef enum _state{
    RINGING = RINGING_SET,
    DULL = DULL_SET,
    SIBILANT = SIBILANT_SET,
    HISSING = HISSING_SET
} var;
typedef enum _state2{
    READING,
    PASSING
} kState;
const var Variant = RINGING;
int main(void) {
//    for (int i = 0; i < 256; ++i) {
//        printf("%c %d\n", (char) i, i);
//    }
    setlocale(LC_ALL, ".866");
    kState now = READING;
    int ch;
    bool nowWord = true;
    bool isWord = false;
    while ((ch = getchar()) != EOF) {
//        printf("%d %c\n", ch, (char) ch);
        switch (now) {
            case READING:
                if ((ch == 32) | (ch == 10)){
                    if (nowWord){
                        isWord = true;
                    }
                    now = PASSING;
                }
                if ((192 <= ch) && (ch <= 255)){ // русские символы
                    unsigned long set = 1 << (ch - 224);
                    if ((CONSONANTS & set)){
                        if ((ch >= 192) && (ch <= 223)){
                            ch += 32;
                        }

                        if (!(Variant & set)){
                            nowWord = false;
                        }
                    }
                }
                break;
            case PASSING:
                nowWord = true;
                if (ch != 32){
                    now = READING;
                    if ((192 <= ch) && (ch <= 255)){ // русские символы
                        unsigned long set = 1 << (ch - 224);
                        if ((CONSONANTS & set)){
                            if ((ch >= 192) && (ch <= 223)){
                                ch += 32;
                            }

                            if (!(Variant & set)){
                                nowWord = false;
                            }
                        }
                    }
                }
                break;
        }
    }
    if (isWord | nowWord){
        printf("YES");
    } else {
        printf("NO");
    }
    // А - 192 Я - 223
    return 0;
}
