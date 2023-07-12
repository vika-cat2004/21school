#include <stdio.h>
#include <stdlib.h>
int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void

readMatrix (int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void

printMatrix (int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int **sumMatrix(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

int **multiplyMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int **transposeMatrix(int **matrix, int rows, int cols) {
    int **result = createMatrix(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

int main() {
    int operation;
    scanf("%d", &operation);
    int rows1, cols1;
    scanf("%d %d", &rows1, &cols1);
    int **matrix1 = createMatrix(rows1, cols1);
    readMatrix(matrix1, rows1, cols1);
    if (operation == 1) {
        int rows2, cols2;
        scanf("%d %d", &rows2, &cols2);
        int **matrix2 = createMatrix(rows2, cols2);
        readMatrix(matrix2, rows2, cols2);
        if (rows1 == rows2 && cols1 == cols2) {
            int **result = sumMatrix(matrix1, matrix2, rows1, cols1);
            printMatrix(result, rows1, cols1);
            freeMatrix(result, rows1);
        } else {
            printf("n/a\n");
        }
        freeMatrix(matrix2, rows2);
    } else if (operation == 2) {
        int rows2, cols2;
        scanf("%d %d", &rows2, &cols2);
        int **matrix2 = createMatrix(rows2, cols2);
        readMatrix(matrix2, rows2, cols2);
        if (cols1 == rows2) {
            int **result = multiplyMatrix(matrix1, matrix2, rows1, cols1, cols2);
            printMatrix(result, rows1, cols2);
            freeMatrix(result, rows1);
        } else {
            printf("n/a\n");
        }
        freeMatrix(matrix2, rows2);
    } else if (operation == 3) {
        int **result = transposeMatrix(matrix1, rows1, cols1);
        printMatrix(result, cols1, rows1);
        freeMatrix(result, cols1);
    } else {
        printf("n/a\n");
    }
    freeMatrix(matrix1, rows1);
    return 0;
}
