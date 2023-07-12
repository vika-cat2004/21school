#include <stdio.h>
#include <stdlib.h>

int input(int **arr, int *n);
void bubble_sort(int *a, int lengt);
void output(int *a, int lengt);

int main() {
    int *a, n;
    if (input(&a, &n) == 1) {
        bubble_sort(a, n);
        output(a, n);
        free(a);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int **arr, int *n) {
    if (scanf("%d", n) == 1 && *n > 0) {
        *arr = malloc(*n * sizeof(int));
        for (int *p = *arr; p - *arr < *n; p++) {
            if (scanf("%d", p) != 1) return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

void bubble_sort(int *a, int lengt) {
    int nn;
    int i, j;
    for (i = 0; i < lengt - 1; i++) {
        for (j = 0; j < lengt - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                nn = a[j];
                a[j] = a[j + 1];
                a[j + 1] = nn;
            }
        }
    }
}

void output(int *a, int lengt) {
    for (int *p = a; p - a < lengt; p++) {
        if (p - a != lengt - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}