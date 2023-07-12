#include "s21_string.h"

#include <stdio.h>
int s21_strlen(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int s21_strcmp(char* str, char* str1) {
    int result = 1;
    while (*str != '\0') {
        if (*str != *str1) {
            result = 0;
        }
        str++;
        str1++;
    }

    return result;
}

char* s21_strcpy(char* str, char* str1) {
    int counter = 0;
    while (*str1 != '\0') {
        *str++ = *str1++;
        counter++;
    }
    *str = '\0';
    return str - counter;
}

char* s21_strcat(char* str, char* str1) {
    char* start = str;
    while (*str != '\0') {
        str++;
    }
    while (*str1 != '\0') {
        *str++ = *str1++;
    }

    return start;
}

char* s21_strchr(char* str, int symb) {
    char* result = "\0";
    while (*str != '\0') {
        if (*str == symb) {
            result = str;
            break;
        }
        str++;
    }

    return result;
}

char* s21_strstr(char* str, char* str2) {
    int isStop = 1;
    int counter = 0;
    while (*str != '\0' && isStop != 2) {
        if (*str == *str2) {
            for (int i = 0; i < s21_strlenInt(str2); i++) {
                counter++;
                if (str[i] != str2[i]) {
                    counter = 0;
                    break;
                }
                if ((s21_strlenInt(str2)) == counter) {
                    isStop = 2;
                }
            }
        }

        str++;
    }

    return isStop == 2 ? str - 1 : str;
}

int s21_strlenInt(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

char *s21_strtok(char *srcString, char *delim) {
    static char *backup_string;
    if (!srcString) {
        srcString = backup_string;
    }
    if (!srcString) {
        return 0;
    }
    while (1) {
        if (is_delim(*srcString, delim)) {
            srcString++;
            continue;
        }
        if (*srcString == '\0') {
            return 0;
        }
        break;
    }
    char *ret = srcString;
    while (1) {
        if (*srcString == '\0') {
            backup_string = srcString;
            return ret;
        }
        if (is_delim(*srcString, delim)) {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
}

