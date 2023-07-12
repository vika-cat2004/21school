#include <math.h>
#include <stdio.h>
#define NMAX 30

int search(int *a, int n);
int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
        return 0;
    }

    printf("%d", search(data, n));
    return 0;
}
int search(int *a, int n) {
    int y = 0;
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean(a, n) && (*p <= mean(a, n) + 3 * sqrt(variance(a, n))) && *p != 0) {
            y = *p;
            break;
        }
    }
    return y;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || (c != ' ' && c != '\n')) {
        return 0;
    }
    if (*n > NMAX || *n <= 0) return 0;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &c) != 2 || (c != ' ' && c != '\n')) return 0;
    }
    return 1;
}

double mean(int *a, int n) {  //сумма всех на колво всех
    double b = 0;
    for (int i = 0; i < n; i++) b += a[i];
    return b / n;
}

double variance(int *a, int n) {
    double b = 0;
    double Mean = mean(a, n);
    for (int i = 0; i < n; i++) b += (a[i] - Mean) * (a[i] - Mean);
    return b / n;
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
