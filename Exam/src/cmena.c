#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
int y;
int flag = 1;
if (scanf("%d", &y) == 1) { 
    if (y < 0) {
        flag = 0;
        y = -y;
    }
int first = y / 100;
int second = y / 10 % 10; 
int last = y % 10;
if (flag == 1) {
    printf("%d%d%d", last, second, first);}
    else {
     printf("-%d%d%d", last, second, first);}    
return 0;
}
else {
printf ("n/a");
}
}