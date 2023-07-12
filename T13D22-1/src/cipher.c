#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readfile(char text[100]);
int writefile(char text[100]);

int main() {
    char text[100];
    int decision;
    do {
        scanf("%d", &decision);
        switch (decision) {
            case -1:
                break;

            case 1:
                readfile(text);
                break;

            case 2:
                writefile(text);
                break;

            default:
                if ((decision != 1) && (decision != -1)) printf("n/a\n");
                break;
        }
    } while (decision != -1);
}

void readfile(char text[100]) {
    scanf("%s", text);
    char buffer[256];               // буфер для считавания данных из файла
    FILE *name = fopen(text, "r");  // чтение из файла
    int count = 0;
    if (name != NULL) {
        while ((fgets(buffer, 256, name)) != NULL) {  // пока не дойдем до конца, считываем по 256 байт
            count++;
            printf("%s", buffer);
        }
        if (count == 0) {
            printf("n/a\n");
        }
        fclose(name);
    } else {
        printf("n/a\n");
    }
}

int writefile(char text[100]) {
    char *buffer = (char *)malloc(1000 * (sizeof(char)));
    scanf("%s", buffer);
    FILE *name = NULL;
    name = fopen(text, "a+");
    if (name != NULL) {
        char c = buffer[0];
        putc(c, name);
        int count = 1;
        while (buffer[count] != '\0') {
            c = buffer[count];
            fputc(c, name);
            count++;
        }
    } else {
        printf("n/a\n");
    }
    fclose(name);
    free(buffer);
    return 0;
}
