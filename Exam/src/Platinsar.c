#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
double R, m, result;
if (scanf("%lf", &R)) {
    m = 21500 * (4.0 / 3.0) * M_PI * pow (R, 3);
    result =  round(m);
    printf("%.0f", result);}
    else {
        printf ("n/a");
    }
return 0;
}