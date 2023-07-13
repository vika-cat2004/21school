#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
int radian; 
float gradus;
if (scanf("%d", & radian) == 1) {
gradus = 57.29 * radian;
printf("%.0f", round(gradus));
}
else {
printf ("n/a");
}
return 0;
}