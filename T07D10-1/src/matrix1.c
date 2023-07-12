#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
#define MMAX 100

void firstdynamic(int row, int col);
void seconddynamic(int row, int col);
void thirddynamic(int row, int col);
void staticmatrix(int matrix[NMAX][MMAX], int row, int col);
/*void readmatrix(int **a, int row, int col);
void printMatrix(int **a, int row, int col);
void readStaticMatrix(int matrix[NMAX][MMAX], int row, int col);
void printStaticMatrix(int a[NMAX][MMAX], int row, int col);*/

int main() {
    int c, row, col;
    scanf("%d", &c);
    scanf("%d %d", &row, &col);
    int matrix[row][col];
    switch (c) {
        case 1:
            if (row > 100 || col > 100) {
                printf("n/a");
            }
            staticmatrix(matrix, row, col);
            break;
        case 2:
            firstdynamic(row, col);
            break;
        case 3:
            seconddynamic(row, col);
            break;
        case 4:
            thirddynamic(row, col);
            break;
    }
    return 0;
}

void staticmatrix(int matrix[NMAX][MMAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            (scanf("%d", &matrix[i][j]));
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j != col - 1) printf(" ")
        }
        if (i != row - 1) printf("\n");
    }
}

void firstdynamic(int row, int col) int **matrix = maloc(row * col * sizeof(int) + row * sizeof(int *));
int *ptr = (int *)(matrix + row);
int count = 0;

for (int i = 0; i < row; i++):
    matrix[i] = ptr + row * i;
for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
        matrix[i][j] = ++count;
    }
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        (scanf("%d", &matrix[i][j]));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j != col - 1)
                ;
            printf(" ");
        }
        if (i != rows - 1) printf("\n");
    }
    free(matrix);
}

void seconddynamic(int row, int col) {
    int **single_matrix = maloc(row * sizeof(int *);

    for (int i = 0; i < row; i++) {
    single_matrix[i] = malloc(col * sizeof(int);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            single_matrix[i][j] = ++count;
        }
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
        (scanf("%d", &single_matrix[i][j]);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d", single_matrix[i][j]);
                if (j != col - 1)
                    ;
                printf(" ");
            }
            if (i != rows - 1) printf("\n");
        }

        for (int i = 0; i < rows; i++) {
            free(single_matrix[i]);

            free(single_matrix);
        }
        void thirddynamic(int row, int col) {
    int **pointer_array = maloc(row * sizeof(int *);
    int value_arr = malloc(row * col * sizeof(int));
    int count = 0;

    for (int i = 0; i < row; i++) {
                pointer_array[i] = value_arr + row * i;
    }
    for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    pointer_array[i][j] = ++count;
                }
    }
    
    for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
        (scanf("%d", & pointer_array[i][j]);
                }

                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        printf("%d", pointer_array[i][j]);
                        if (j != col - 1)
                            ;
                        printf(" ");
                    }
                    if (i != rows - 1) printf("\n");
                }
    }
    free(pointer_array);
    free(value_arr);
        }
