#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define row 25
#define col 80

int count_live_neighbour_cell(int a[row][col], int r, int c);
int row_line();

int row_line() {  //функция рисовки клеток
    printw("\n");
    for (int i = 0; i < col; i++) {
        printw(" ---");
    }
    printw("\n");
    refresh();
    return 0;
}

int count_live_neighbour_cell(int a[row][col], int r, int c) {  //функция счета живых клеток
    int i, j, count = 0;
    for (i = r - 1; i <= r + 1; i++) {
        for (j = c - 1; j <= c + 1; j++) {
            if ((i == r && j == c) || j < 1 || j == 79) {
                if ((i == r && j == c) || i < 1 || i == 24) {
                    continue;
                }
            }
            if (a[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int i, j, speed = 100000, stop = 1, flag = 0, d;
    int a[row][col], b[row][col];
    int neighbour_live_cell;
    char q;
    FILE *myfile;

    printf("Choose your initial scenario: (1 - 5 file.txt and 'r' - for random scenario generation)\n");
    printf("Options: '+' - speed up game, '-' slow down , q/Q - quit the game, \n");

    scanf("%c", &q);
    if (q == '1') {
        myfile = fopen("1.txt", "r");
        flag++;
    } else if (q == '2') {
        myfile = fopen("2.txt", "r");
        flag++;
    } else if (q == '3') {
        myfile = fopen("3.txt", "r");
        flag++;
    } else if (q == '4') {
        myfile = fopen("4.txt", "r");
        flag++;
    } else if (q == '5') {
        myfile = fopen("5.txt", "r");
        flag++;
    } else if (q == 'r') {  // r - means random
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                a[i][j] = rand() % 2;  //заполнение поля начальное
            }
        }
    } else {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                a[i][j] = rand() % 2;
            }
        }
    }

    // read any 1-5 file

    if (flag) {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                fscanf(myfile, "%d", &d);
                a[i][j] = d;
            }
        }
        fclose(myfile);
    }

    for (i = 0; i < row; i++) {
        printf(":");
        for (j = 0; j < col; j++) {
            printf(" %d :", a[i][j]);
        }
    }
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        printf(" ");
    }
    initscr();  //начало работы  библиотеки ncurses
    while (stop == 1) {
        nodelay(stdscr, TRUE);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                neighbour_live_cell = count_live_neighbour_cell(a, i, j);
                if (a[i][j] == 1 && (neighbour_live_cell == 2 ||
                                     neighbour_live_cell == 3)) {  //функция решающая какая клетка будет жить
                    b[i][j] = 1;
                } else if (a[i][j] == 0 && neighbour_live_cell == 3) {  //Заполнение следующего поколения
                    b[i][j] = 1;
                } else {
                    b[i][j] = 0;
                }
            }
        }

        row_line(row);
        for (i = 0; i < row; i++) {
            printw(":");
            for (j = 0; j < col; j++) {
                if (b[i][j] == 0)
                    printw("   :");
                else
                    printw(" o :");
            }
            row_line(row);
        }
        refresh();
        usleep(speed);
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++) a[i][j] = b[i][j];
        int ch;
        ch = getch();
        if (ch == 'q' || ch == 'Q') stop = 0;
        if ((ch == '+') || (ch == '='))  //кнопки, изменяющие скорость
            if (speed > 20001) speed -= 20000;
        if ((ch == '-') || (ch == '_'))
            if (speed < 300000) speed += 20000;
        clear();
    }
    endwin();  //конец работы ncurses
    return 0;
}
