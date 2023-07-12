#include "s21_string.h"

#include <stdio.h>

#define SUC "SUCCESS"
#define F "FAIL"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

void printResult(char* str1, char* str2, char* exept, char* result);

int main() {
#ifdef Quest_1
    s21_strlen_test();
#endif

#ifdef Quest_2
    s21_strcmp_test();
#endif

#ifdef Quest_3
    s21_strcpy_test();
#endif

#ifdef Quest_4
    s21_strcat_test();
#endif

#ifdef Quest_5
    s21_strchr_test();
#endif

#ifdef Quest_6
    s21_strstr_test();
#endif

    return 0;
}

void s21_strlen_test() {
    int size_case = 4;

    char string[4][20] = {"Hello, world!", "1234 5 6789", " ", "!(@#$(*H"};
    int result_case[4] = {13, 11, 1, 8};

    for (int i = 0; i < size_case; i++) {
        if (s21_strlenInt(string[i]) == result_case[i]) {
            printf("in: %d  %s out: %d", result_case[i], string[i], s21_strlen(string[i]));
            printf("   SUCCESS\n");
        } else {
            printf("in: %d  %s  out: %d", result_case[i], string[i], s21_strlen(string[i]));
            printf("   FAIL\n");
        }
    }
}

void s21_strcmp_test() {
    char* case1 = "vertopr please me review 100";
    char* case_result1 = "vertopr please me review 100";

    char* case2 = "fhasdklvsbdvajclhdkajfewgfbdhls";
    char* case_result2 = "fhasdklvsbdvajclhdkajfewgfbdhls";

    char* case3 = "Nope";
    char* case_result3 = "\0";

    printf("in: %s %s || ", case1, case_result1);
    if (s21_strcmp(case1, case_result1)) {
        printResult(case1, case_result1, case_result1, SUC);
    } else {
        printResult(case1, case_result1, case_result1, F);
    }

    printf("in: %s %s || ", case2, case_result2);
    if (s21_strcmp(case2, case_result2)) {
        printResult(case2, case_result2, case_result2, SUC);
    } else {
        printResult(case2, case_result2, case_result2, F);
    }
    printf("in: %s %s || ", case3, case_result3);
    if (!s21_strcmp(case3, case_result3)) {
        printResult(case3, case_result3, case_result3, SUC);
    } else {
        printResult(case3, case_result3, case_result3, F);
    }
}

void s21_strcpy_test() {
    char case1[] = "HEllO WORLD";
    char case2[] = "hjadsfg3214321adsf";
    char case3[] = " ";

    char copy1[100];
    char copy2[100];
    char copy3[100];

    printf("in: %s || ", case1);
    s21_strcpy(copy1, case1);
    if (s21_strcmp(case1, copy1)) {
        printf("out: %s %s || %s\n", case1, copy1, SUC);
    } else {
        printf("out: %s %s || %s\n", case1, copy1, F);
    }

    printf("in: %s || ", case2);
    s21_strcpy(copy2, case2);

    if (s21_strcmp(case2, copy2)) {
        printf("out: %s %s || %s\n", case2, copy2, SUC);
    } else {
        printf("out: %s %s || %s\n", case2, copy2, F);
    }

    printf("in: %s || ", case3);
    s21_strcpy(copy3, case3);
    if (s21_strcmp(case3, copy3)) {
        printf("out: %s %s || %s\n", case3, copy3, SUC);
    } else {
        printf("out: %s %s || %s\n", case3, copy3, F);
    }
}

void s21_strcat_test() {
    char case1[100] = "HELLO 1234";
    char case2[100] = "1348625fqwuegy183247igwfqahskdkewqig";
    char case3[100] = "Русский текст";

    char cat1[100] = "56789";
    char cat2[100] = "   245hwfiqwiuerh";
    char cat3[100] = "\0";

    char* case_result1 = "HELLO 123456789";
    char* case_result2 = "1348625fqwuegy183247igwfqahskdkewqig   245hwfiqwiuerh";
    char* case_result3 = "Русский текст";

    printf("in %s %s || ", case1, cat1);
    s21_strcat(case1, cat1);
    if (s21_strcmp(case1, case_result1)) {
        printResult(case1, cat1, case_result1, SUC);
    } else {
        printResult(case1, cat1, case_result1, F);
    }

    printf("in %s %s || ", case2, cat2);
    s21_strcat(case2, cat2);
    if (s21_strcmp(case2, case_result2)) {
        printResult(case2, cat2, case_result2, SUC);
    } else {
        printResult(case2, cat2, case_result2, F);
    }

    printf("in %s %s || ", case3, cat3);
    s21_strcat(case3, cat3);
    if (s21_strcmp(case3, case_result3)) {
        printResult(case3, cat3, case_result3, SUC);
    } else {
        printResult(case3, cat3, case_result3, F);
    }
}

void s21_strchr_test() {
    char* case1 = "Search ---->z<----";
    int case_search1 = 'z';
    char* case_result1 = "z<----";

    char* case2 = "Search fhasdklvsbdvajclhdkajfewgfbdhls";
    int case_search2 = 's';
    char* case_result2 = "sdklvsbdvajclhdkajfewgfbdhls";

    char* case3 = "Nope";
    int case_search3 = 'x';
    char* case_result3 = "\0";

    printf("in: %s %c || ", case1, case_search1);
    if (s21_strcmp(s21_strchr(case1, case_search1), case_result1)) {
        printf("out: %s %c  exept: %s || %s\n", case1, case_search1, case_result1, SUC);
    } else {
        printf("out: %s %c  exept: %s || %s\n", case1, case_search1, case_result1, F);
    }

    printf("in: %s %c || ", case2, case_search2);
    if (s21_strcmp(s21_strchr(case2, case_search2), case_result2)) {
        printf("out: %s %c  exept: %s || %s\n", case2, case_search2, case_result2, SUC);
    } else {
        printf("out: %s %c  exept: %s || %s\n", case2, case_search2, case_result2, F);
    }

    printf("in: %s %c || ", case3, case_search3);
    if (s21_strcmp(s21_strchr(case3, case_search3), case_result3)) {
        printf("out: %s %c  exept: %s || %s\n", case3, case_search3, case_result3, SUC);
    } else {
        printf("out: %s %c  exept: %s || %s\n", case3, case_search3, case_result3, F);
    }
}

void s21_strstr_test() {
    char* case1 = "Hello vertopr please me review 100";
    char* case_search1 = "vertor";
    char* case_result1 = "vertopr please me review 100";

    char* case2 = "Search fhasdklvsbdvajclhdkajfewgfbdhls";
    char* case_search2 = "few";
    char* case_result2 = "fewgfbdhls";

    char* case3 = "Nope";
    char* case_search3 = "x";
    char* case_result3 = "\0";

    printf("in: %s %s || ", case1, case_search1);
    if (s21_strcmp(s21_strstr(case1, case_search1), case_result1)) {
        printResult(case1, case_search1, case_result1, SUC);
    } else {
        printResult(case1, case_search1, case_result1, F);
    }

    printf("in: %s %s || ", case2, case_search2);
    if (s21_strcmp(s21_strstr(case2, case_search2), case_result2)) {
        printResult(case2, case_search2, case_result2, SUC);
    } else {
        printResult(case2, case_search2, case_result2, F);
    }

    printf("in: %s %s || ", case3, case_search3);
    if (s21_strcmp(s21_strstr(case3, case_search3), case_result3)) {
        printResult(case3, case_search3, case_result3, SUC);
    } else {
        printResult(case3, case_search3, case_result3, F);
    }
}

void printResult(char* str1, char* str2, char* exept, char* result) {
    printf("out: %s %s  exept: %s || %s\n", str1, str2, exept, result);
}
