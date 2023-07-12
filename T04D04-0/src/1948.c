#include <math.h>
#include <stdio.h>

/*Returns absolute value of the num argument.*/
int abs(int num);

/*Returns 1 if a is divisible by b, and 0 if it isn't.*/
int isDivider(int a, int b);

/*Returns 1 if num argument is prime, and 0 if it isn't.*/
int isPrime(int num);

/*Returns greatest prive divider of num argument.*/
int greatestPrimeDivisor(int num);

int main() {
    // Variables initialization
    int a = 0;
    char term = '\0';

    //! Edge case: program will fail in case of input float num or string,
    //!            also values 0, 1 and -1 will lead to result 0 => fail
    if (scanf("%d%c", &a, &term) != 2 || term != '\n' || a == 0 || a == 1 || a == -1) {
        printf("n/a");
        return 1;
    }

    // Outputting the result
    printf("%d\n", greatestPrimeDivisor(abs(a)));

    return 0;
}

int abs(int num) { return (int)fabs((double)num); }

int isDivider(int a, int b) {
    int buf = a;

    // Performing (a - b) to check if a is divisible by b
    while (buf > 0) {
        buf -= b;
    }

    // If buf == 0 after substraction, then b is divider
    if (buf == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isPrime(int num) {
    for (int i = num - 1; i > 0; i--) {
        if (isDivider(num, i)) {
            if (i > 1) {
                return 0;
            } else if (i == 1) {
                return 1;
            }
        } else {
            continue;
        }
    }

    return 0;
}

int greatestPrimeDivisor(int num) {
    for (int i = num; i > 0; i--) {
        if (isDivider(num, i) && isPrime(i)) {
            return i;
        }
    }

    return 0;
}
