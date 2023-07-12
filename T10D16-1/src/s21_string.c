#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *str) {
    int lenght = 0;
    while (*str != '\0') {
        lenght++;
        str++;
    }
    return lenght;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res;
    while ((*str1 && *str2) && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    if (*str1 < *str2) {
        res = -1;
    } else if (*str1 > *str2) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}

/*int s21_strcpy(const char* str1, const char* str2) {
    for (int i = 0; i <= (int)s21_strlen(str2); i++) {
        str1[i] = str2[i];
    }
    return 0;
}