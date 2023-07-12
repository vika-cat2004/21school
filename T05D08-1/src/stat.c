#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0)
    {
        printf("n/a");
        return 0;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != ' ' && c != '\n' || *n > NMAX || *n <= 0)  {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &c) != 2 || c != ' ' && c != '\n') return 0;
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1) {
            printf("%d ", *p);
        } else {
            printf("%d\n", *p);
        }
    }
}
int max(int *a, int n) {
    int b = a[0];  // b-max экстремум
    for (int *p = a; p - a < n; p++)
        if (*p > b) b = *p;
    return b;
}

int min(int *a, int n) {
    int b = a[0];  // b-мин экстремумб др ф-ция не связ с max
    for (int *p = a; p - a < n; p++)
        if (*p < b) b = *p;
    return b;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}