#include <stdio.h>
#include <stdbool.h>


const int I_0 = 0;
const int J_0 = -3;
const int L_0 = -7;


struct step {
    int i;
    int j;
    int l;
    int iteration;
};

int sign(int num) {
    return num > 0 ? 1 : num == 0 ? 0 : -1;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x) {
    return x * x;
}


bool checkStep(struct step now) {
    return (pow(now.i - 10) + pow(now.j - 10) <= 100) && (pow(now.i - 10) + pow(now.j - 10) >= 25);
}

int countI(struct step prev) {
    return (abs(prev.i - prev.j + prev.l) / (3 - sign(prev.i - prev.j + prev.iteration))) + 10;
}

int countJ(struct step prev) {
    return (abs(prev.i + prev.j - prev.l) / (3 - sign(prev.j - prev.i + prev.iteration))) + 10;
}

int countL(struct step prev) {
    return (max(prev.i * prev.j, prev.j * prev.l) * (prev.iteration + 1)) % 40;
}

int main() {
    struct step prev = {I_0, J_0, L_0, 0};
    printf("Step k:   i   k   j\n");
    for (int i = 0; i < 50; ++i) {
        if (checkStep(prev)) {
            printf("Collision on step(k) %d: i=%d j=%d l=%d\n", prev.iteration, prev.i, prev.j, prev.l);
            break;
        } else {
            printf("Step %d: %3d %3d %3d\n", prev.iteration, prev.i, prev.j, prev.l);
        }
        struct step now = {countI(prev), countJ(prev), countL(prev), prev.iteration + 1};
        prev = now;
    }
    return 0;
}
