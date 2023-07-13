#ifndef SRC_FILE_IO_H_
#define SRC_FILE_IO_H_
#include <stdio.h>
int File_read(char* fileName);
int File_sort(char* fileName);

int File_endWrite(char* fileName, int* arr);
int File_search(char* fileName, int* arr, int* key);
char* filePath(char* fileName);
int check(int* a, int* b);

int File_keyWrite(int key);

#endif