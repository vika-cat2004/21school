#include <math.h>
#include <stdio.h>

double red(double x);

int main() {
    double x;
    if (scanf("%lf", &x) == 1) {
        printf("%.1f\n", red(x));

    } else {
        printf("n/a\n");
        return 0;
    }
}

double red(double x) {
    double a;
    a = ((7e-3) + ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x), (2 / x)) - 1.01);
    return a;
}