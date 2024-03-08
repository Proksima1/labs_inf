#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} p;


int main() {
    int n, count = 1;
    bool up = true, right_diag = true;
    scanf("%d", &n);
    p Point = {0, n - 1};
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d ", matrix[Point.y][Point.x]);
    while (count != n * n){
        if (up) {
            if (Point.y > 0) {
                Point.y -= 1;
            } else {
                Point.x += 1;
            }
            printf("%d ", matrix[Point.y][Point.x]);
            count += 1;
            up = false;
        } else {
            if (Point.x < n - 1) {
                Point.x += 1;
            } else {
                Point.y -= 1;
            }
            printf("%d ", matrix[Point.y][Point.x]);
            count += 1;
            up = true;
        }
        while (((0 <= Point.x) && (Point.x <= n - 1)) && ((0 <= Point.y) && (Point.y <= n - 1))) {
            if (right_diag) {
                if ((Point.x + 1 > n - 1) || (Point.y + 1 > n - 1)) {
                    break;
                }
                Point.x += 1;
                Point.y += 1;
            } else {
                if ((0 > Point.x - 1) || (0 > Point.y - 1)) {
                    break;
                }
                Point.x -= 1;
                Point.y -= 1;
            }
            printf("%d ", matrix[Point.y][Point.x]);
            count += 1;
        }
        right_diag = !right_diag;
    }
    return 0;
}
