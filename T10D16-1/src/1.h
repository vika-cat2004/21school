#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char *str);
int s21_strlenInt(const char *str);
int s21_strcmp(char *str, char *str1);
char *s21_strcpy(char *str, char *str1);
char *s21_strcat(char *str, char *str1);
char *s21_strchr(char *str, int symb);
char *s21_strstr(char *str, char *str2);
int s21_strlenInt(const char *str);

char *s21_strtok(char *srcString, char *delim);

#endif
