#include <stdio.h>



int main() {
    int N;
    scanf("%d\n", &N);
    printf("%d", N);
    int matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int maxSum = -1;
    int minSum = N * N * N;
    int maxCol = -1;
    int minCol = -1;

    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxCol = j;
        }
        if (sum < minSum) {
            minSum = sum;
            minCol = j;
        }
    }

    printf("Max sum column: %d\n", maxCol + 1);
    printf("Min sum column: %d\n", minCol + 2);

    printf("Matrix before swapping columns:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        int temp = matrix[i][maxCol];
        matrix[i][maxCol] = matrix[i][minCol];
        matrix[i][minCol] = temp;
    }
    printf("Matrix after swapping columns:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
