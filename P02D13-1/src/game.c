#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define row 3
#define col 3

int count_live_neighbour_cell(int a[row][col], int r, int c);
void row_line(int (*b)[3]);

int main() {
    int b[3][3] = {{1,2,3}, {1,2,3}, {4,5,6}};
    row_line(b);
}

void row_line(int (*b)[3]) {  //функция рисовки клеток
    printf("\n");
    for (int i = 0; i < col; i++) {
        printf(" ---");
    }
    printf("\n");

    for (int i = 1; i < row; i++) {
            printf(":");
            for (int j = 0; j < col; j++) {
                if (b[i][j] == 0)
                    printf("   :");
                else
                    printf(" o :");
            }
            printf("\n");
    }
}

        