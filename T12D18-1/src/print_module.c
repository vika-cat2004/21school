#include "print_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char print_char(char ch) { return (char)putchar(ch); }

char *current_time() {
    char format[] = "%H:%M:%S";
    size_t size = strlen(format) + 1;
    char *result = calloc(size, sizeof(char));
    time_t current = time(0);
    struct tm *tm_time = localtime(&current);
    strftime(result, size, format, tm_time);
    return result;
}

void print_log(char (*print)(char), char *message) {
    if (print != NULL) {
        size_t log_size = strlen(Log_prefix);
        char *t = current_time();
        size_t time_size = strlen(t);
        size_t message_size = strlen(message);
        size_t final_size = log_size + time_size + message_size + WHITESPACE_COUNT;
        char result[final_size];
        sprintf(result, "%s %s %s", Log_prefix, current_time(), message);
        for (char *p = result; *p != '\0'; p++) {
            print(*p);
        }
        free(t);
    }
}

void print_string(char *a) {
    for (char *p = a; *p != '\0'; p++) {
        print_char(*p);
    }
}