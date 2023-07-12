#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

int input(int **matrix, int *n, int *m);
int inputSize(int *n, int *m);
void output(int **matrix, int n, int m);
void swap(int *a, int *b);
void quick_sort(int *a, int first, int last);
void oneArray(int **matrix, int *array, int n, int m);
void myFree(int **a, int n);

int main() {
    int **matrix, **result;
    int n, m, flag = 0;

    flag = inputSize(&n, &m);

    if (!flag) {
        matrix = (int **)malloc(n * sizeof(int *));
        result = (int **)malloc(n * sizeof(int *));
        if (input(matrix, &n, &m)) flag = 1;
        if (!flag) {
            sort_vertical(matrix, n, m, result);
            output(result, n, m);

            printf("\n\n");
            result = (int **)malloc(n * sizeof(int *));
            sort_horizontal(matrix, n, m, result);
            output(result, n, m);

            myFree(matrix, n);
        } else
            free(result);
    }

    return flag;
}

int inputSize(int *n, int *m) {
    char enter;
    int flag = 0;
    if (scanf("%d%c", n, &enter) != 1 && enter != ' ') {
        printf("n/a");
        flag = 1;
    } else if (scanf("%d%c", m, &enter) != 1 && enter != '\n') {
        printf("n/a");
        flag = 1;
    }
    if (!flag && ((*n) <= 0 || (*m) <= 0)) {
        printf("n/a");
        flag = 1;
    }
    return flag;
}

int input(int **matrix, int *n, int *m) {
    char enter;
    int flag = 0, exit_ind = 0;
    // проверка на ввод матрицы
    for (int i = 0; i < *n; i++) {
        if (flag) break;
        matrix[i] = malloc((*m) * sizeof(int));
        for (int j = 0; j < *m - 1; j++) {
            if (scanf("%d%c", &matrix[i][j], &enter) != 1 && enter != ' ') {
                printf("n/a");
                flag = 1;
                exit_ind = i;
                break;
            }
        }
        if (!flag) {
            if (scanf("%d%c", &matrix[i][*m - 1], &enter) != 1 && enter != '\n') {
                printf("n/a");
                flag = 1;
                exit_ind = i;
            }
        }
    }
    if (flag) {
        for (int i = 0; i <= exit_ind; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
    return flag;
}

void oneArray(int **matrix, int *array, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[count++] = matrix[i][j];
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\b");
        if (i != n - 1) printf("\n");
        free(matrix[i]);
    }
    free(matrix);
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int i, j, pivot;
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (i < last && a[i] <= a[pivot]) i++;
            while (a[j] > a[pivot]) j--;
            if (i < j) {
                swap(a + i, a + j);
            }
        }

        swap(a + pivot, a + j);
        quick_sort(a, first, j - 1);
        quick_sort(a, j + 1, last);
    }
}

void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

void reverse(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(a + i, a + n - 1 - i);
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *buf = malloc(n * m * (sizeof(int)));
    oneArray(matrix, buf, n, m);
    quick_sort(buf, 0, n * m - 1);
    for (int i = 0; i < n; i++) {
        result_matrix[i] = malloc(m * sizeof(int));
    }
    int count = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][j] = buf[count++];
            }
        } else {
            for (int i = n - 1; i > -1; i--) {
                result_matrix[i][j] = buf[count++];
            }
        }
    }
    free(buf);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *buf = malloc(n * m * (sizeof(int)));
    oneArray(matrix, buf, n, m);
    quick_sort(buf, 0, n * m - 1);
    for (int i = 0; i < n; i++) {
        result_matrix[i] = malloc(m * sizeof(int));
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = buf[count++];
            }
        } else {
            for (int j = m - 1; j > -1; j--) {
                result_matrix[i][j] = buf[count++];
            }
        }
    }
    free(buf);
}

void myFree(int **a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}
