#include <stdio.h>
#define NMAX 10

int input(int* n, int* data, int* c);
void output(int* data, int n);
void sdvig(int* data, int n, int c);

int main() {
    int n, c, data[NMAX];

    // const int input_result =
    input(&n, data, &c);
    sdvig(data, n, c);

    return 0;
}

int input(int* n, int* data, int* c) {
    char endl;

    int resutl = 1;

    if (scanf("%d%c", n, &endl) != 2 || endl != '\n') {
        resutl = 0;
    }

    for (int i = 0; i < *n; i++) {
        if (i == *n - 1) {
            if (scanf("%d%c", &data[i], &endl) != 2 || endl != '\n') {
                resutl = 0;
            }
        } else {
            if (scanf("%d", &data[i]) != 1) {
                resutl = 0;
            }
        }
    }

    if (scanf("%d%c", c, &endl) != 2 || endl != '\n') {
        resutl = 0;
    }

    return resutl;
}

void sdvig(int* data, int n, int c) {
    // c = c % n;

    // c < 0 ? c += n;
    if (c > 0) {
        for (int i = 0; i < c; i++) {
            for (int j = 1; j < n; j++) {
                int t = data[j];
                data[j] = data[j - 1];
                data[j - 1] = t;
            }
        }
    } else {
        for (int i = 0; i < -c; i++) {
            for (int j = n - 1; j > 0; j--) {
                int t = data[j];
                data[j] = data[j - 1];
                data[j - 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
}
