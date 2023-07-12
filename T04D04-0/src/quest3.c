#include <stdio.h>

/*Returns num'st number from Fibonacci sequence.*/
int fibonacci(int num);

int main() {
    // Variables initialization
    int num = 0;
    char term = '\0';

    //! Edge case: program will fail in case of input float num or string
    if (scanf("%d%c", &num, &term) != 2 || term != '\n' || num <= 0) {
        printf("n/a");
        return 1;
    }

    // Outputting the result
    printf("%d\n", fibonacci(num));

    return 0;
}

int fibonacci(int num) {
    // There is no point to run algo on nums < 3
    // Also this is end condition for the recursion
    if (num < 3) {
        return 1;
    }

    // Tail recursion
    return fibonacci(num - 1) + fibonacci(num - 2);
}
