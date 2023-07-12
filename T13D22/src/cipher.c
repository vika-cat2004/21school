#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "work_with_file.h"

void shifr_file();

int main() {
    FILE *file = NULL;
    char path[SIZE];
    int mode = 0;
    int result = 1;
    while (mode != -1) {
        if (scanf("%d", &mode) == 1) {
            if (mode < -1 || mode > 2 || mode == 0) result = !result;
            if (mode == 1) {
                result = read_file(file, path);
            }
            if (mode == 2) {
                result = write_in_file(file, path);
            }
            if (mode == 3) {
                shifr_file();
            }
        } else {
            result = !result;
            scanf("%*s");
        }
        if (!result) {
            printf("n/a\n");
            result = !result;
        }
    }
    return 0;
}

void shifr_file() {
    int i, j = 0, sd = 0;
    char f_name[100] = "";
    FILE *ptrFile;
    DIR *dir;
    scanf("%d", &sd);
    struct dirent *de;
    dir = opendir("../src/ai_modules");
    while (j < 100) {
        de = readdir(dir);
        if (de) {
            if (de->d_type == 8) {
                char f2_name[100] = "../src/ai_modules/";
                int len = strlen(de[0].d_name);
                if (de[0].d_name[len - 1] == 'h' && de[0].d_name[len - 2] == '.') {
                    for (i = 0; i < len; i++) {
                        f_name[i] = de[0].d_name[i];
                    }
                    strncat(f2_name, f_name, 99);
                    ptrFile = fopen(f2_name, "w");
                    fclose(ptrFile);
                }
                if (de[0].d_name[len - 1] == 'c' && de[0].d_name[len - 2] == '.') {
                    for (i = 0; i < len; i++) {
                        f_name[i] = de[0].d_name[i];
                    }
                    char *str2;
                    strncat(f2_name, f_name, 99);
                    ptrFile = fopen(f2_name, "r");
                    j = 0;
                    while (fgetc(ptrFile) != EOF) {
                        j++;
                    }
                    fclose(ptrFile);
                    int lenf = j;
                    str2 = (char *)malloc(lenf * sizeof(char));
                    j = 0;
                    char c;
                    FILE *ptrFile2 = fopen(f2_name, "r");
                    while ((str2[j] = fgetc(ptrFile2)) != EOF) {
                        j++;
                    }
                    for (i = 0; i < lenf; i++) {
                        if (str2[i] >= 65 && str2[i] <= 122) {
                            c = str2[i];
                            c = c + sd;
                            str2[i] = c;
                        }
                    }
                    fclose(ptrFile2);
                    ptrFile = fopen(f2_name, "w");
                    j = 0;
                    while (j < lenf) {
                        fputc(str2[j], ptrFile);
                        j++;
                    }
                    free(str2);
                    fclose(ptrFile);
                }
            }
        }
        j++;
    }
    closedir(dir);
}