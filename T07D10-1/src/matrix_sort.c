#include <stdio.h>
#include <stdlib.h>
int main() {
    int omg;
    int N, M;
    scanf("%d %d %d", &omg, &N, &M);
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int *sums = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
        for (int j = 0; j < M; j++) {
            sums[i] += matrix[i][j];
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (sums[j] > sums[j + 1]) {
                int *temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
                int tempSum = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = tempSum;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(sums);
    return 0;
}
