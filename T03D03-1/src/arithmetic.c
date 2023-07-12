#include <stdio.h>
int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a");
        return 0;
    }
    printf("%d %d %d ", sum(a, b), sub(a, b), mul(a, b));
    if (b == 0) {
        printf("n/a");
    } else {
        printf("%d\n", div(a, b));
    }
    return 0;
}

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }