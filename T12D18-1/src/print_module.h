#ifndef PRINT_MODULE_H
#define PRINT_MODULE_H

#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"
#define WHITESPACE_COUNT 2

/*
    input:  printchar-callback, log message
    output: void
    result: "Log_prefix HH:MM:SS message"
*/
void print_log(char (*print)(char), char *message);

char print_char(char ch);

void print_string(char *a);

#endif  // PRINT_MODULE_H
