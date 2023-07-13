#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
float x = 3.14;
int i, result;
scanf ("%d", &i);
result = round (x) * i;
printf("%d\n", result);   
return 0;
}