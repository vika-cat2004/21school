#ifndef SRC_MASS_FILE_H_
#define SRC_MASS_FILE_H_
#include <stdio.h>
int fRead(FILE* fp, int ind);
void swap(FILE* fp, int i, int j);
int arrCmp(FILE* fp, int i, int j);
void fWrite(FILE* fp, int ind, int* arr);
int fRead(FILE* fp, int ind);

#endif