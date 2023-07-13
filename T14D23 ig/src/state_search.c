#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_IO.h"

int main() {
    char* fileName;
    int flag;
    char c;
    flag = 1;
    fileName = (char*)malloc(100 * sizeof(char));
    fgets(fileName, 100, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    int inArr[8];
    if (scanf("%2d%c%2d%c%4d", &inArr[0], &c, &inArr[1], &c, &inArr[2]) != 5) flag = 0;

    if (flag == 1) {
        int key;
        flag = File_search(fileName, inArr, &key);
        if (flag == 1) {
            flag = File_keyWrite(key);
            printf("%d", key);
        }
    }
    if (flag == 0) {
        printf("n/a");
    }
    free(fileName);
    return 0;
}