/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input_int_array(int *buffer, int *length, int *flag);
void output_array(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, /*int number,*/ int *numbers);

/* void output_array(int *a, int count);*/

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, buffer[NMAX], flag = 0;
    int /*number,*/ numbers[NMAX];
    //int length;

    if (scanf("%d", &n) == 1 && getchar() == '\n' && input_int_array(buffer, &n, &flag) == n && n <=NMAX) {
        // printf("num = %d\n", *numbers);
        int sum = sum_numbers(buffer, n);
        int a = find_numbers(buffer, n, /*sum,*/ numbers);
        if (find_numbers(buffer, n, /*sum,*/ numbers) < 0) {
            return printf("n/a");
        } else {
            printf("%d\n", sum);
            for (int i = 0; i < a; i++) {
                printf("%d ", numbers[i]);
            }
            printf("\n");
        }

    } else {
        printf("n/a");
        return 0;
    }
}

int input_int_array(int *buffer, int *n, int *flag) {
    for (int *p = buffer; p - buffer < *n; p++) {
        if (scanf("%d", p) != 1) {
            return *flag;
        }
        *flag += 1;
    }
    return *flag;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0 && buffer[i] != 0) {
            sum += buffer[i];
        }
    }
    return sum;
}
/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, /*int number,*/ int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) continue;
        if (sum_numbers(buffer, length) % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}

void output_array(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (p - buffer != length - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}