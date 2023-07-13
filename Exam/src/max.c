#include <stdio.h>

int MAX(int a, int b) { return (a > b) ? a : b; }

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) == 2) {
        printf("%d", MAX(a, b));
    } else {
        printf("n/a");
    }
    return 0;
}