#include <stdio.h>
#define NMAX 10

int input(int *a);
void bubble_sort(int *a);
void output(int *a);

int main() {
    int n, data[NMAX];
    if (input(data) == 1 && getchar() == '\n') {
        bubble_sort(data);
        output(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {

    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    return 1;
}

void bubble_sort(int *a) {
    int nn;
    int i, j;
    for (i = 0; i < NMAX; i++) {
        for (j = 0; j < NMAX - i; j++) {
            if (a[j] > a[j + 1]) {
                nn = a[j];
                a[j] = a[j + 1];
                a[j + 1] = nn;
            }
        }
    }
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        if (p - a != NMAX - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}
