#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();

int main() {
#ifdef QUEST1_STRLEN
    s21_strlen_test();
#endif
#ifdef QUEST2_STRCMP
    s21_strcmp_test();
#endif
#ifdef QUEST2_STRLCPY
    s21_strcpy_test();
#endif

}

void s21_strlen_test() {
    char *test_data[] = {"Hello, world!", "", "6", "TEST", "Test"};
    int test_data_expected[] = {13, 0, 1, 4, 4};
    for (int i = 0; i < 5; i++) {
        printf("%s\n", test_data[i]);
        printf("%d\n", s21_strlen(test_data[i]));
        if (s21_strlen(test_data[i]) != test_data_expected[i]) {
            printf("FAIL");
        } else {
            printf("SUCCESS");
        }
    }
}

void s21_strcmp_test() {
    char *test_data1[] = {"Hello, world!", "P", "6", "TEST", "Test", "11111111111111111"};
    char *test_data2[] = {"Hello, world!", "Prive", "5", "TEST", "Test", "11115553"};
    int test_data_result[] = {0, -1, 1, 0, 0, 1};
    int count = 6;
    for (int i = 0; i < count; i++) {
        printf("%s | %s\n", test_data1[i], test_data2[i]);
        int res = s21_strcmp(test_data1[i], test_data2[i]);
        printf("%d\n", res);
    
    if (res == test_data_result[i]) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
}

/*void s21_strcpy_test(const char* str1, const char* str2) {
    char *test_data1[] = {"Novikov", "Sidorov", "", "5g", "%&!"};
    char *test_data2[] = {"Privet", "Dobroe ytro", "5", "!!!!", "df5yj"};
    for (int i = 0; i < 5, i++); {
        printf("%s, %s-", test_data1[i], test_data1[2]);}
        if (s21_strcpy(test_data1[i], test_data2[i]) == 0); {
            printf("%s-", test_data2[i]);
            if (i != 2)
                printf("SUCCESS");
            } else {
                printf("FAIL");
        }
}
