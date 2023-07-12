#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define XL 80
#define YL 25

void print(int ***a, int speed);
void creating_arr(int ***pointer_arr);
void GUI(int ***Xtr);
void cleaner(int ***a);

int main() {
    char c = '0';
    int **a = NULL;
    creating_arr(&a);
    int i, j;
    if (isatty(0)) {
        while (c != 's') {
            scanf("%d%d", &i, &j);
            a[i][j] = 1;
            c = getchar();
        }
    } else
        while (scanf("%d %d", &i, &j) != EOF) a[i][j] = 1;
    FILE *tty = freopen("/dev/tty", "r", stdin);
    if (tty != NULL) {
        initscr();
        int speed = 10000;
        nodelay(stdscr, 1);
        while (c != 'q') {
            usleep(speed);
            GUI(&a);
            print(&a, speed);
            if (c == '-') {
                if (speed < 210000) speed += 25000;
            } else if (c == '+') {
                if ((speed > 10000)) speed -= 25000;
            }
            c = getch();
        }
        endwin();
        clear();
        refresh();
    }
    cleaner(&a);
    a = NULL;
    endwin();
    return 0;
}

void print(int ***a, int speed) {
    clear();
    for (int i = -1; i < 26; i++) {
        for (int j = -1; j < 81; j++) {
            if (i == -1 || i == 25)
                printw("-");
            else if (j == -1 || j == 80)
                printw("|");
            else {
                if ((*a)[i][j] == 1)
                    printw("*");
                else
                    printw(" ");
            }
        }
        printw("\n");
    }
    printw("Current speed: %d", speed);
}

void GUI(int ***Xtr) {
    int i, i1, j, j1, counter, tr_i, tr_j, Xnew[YL][XL] = {0};
    for (i = 0; i < YL; i++) {
        for (j = 0; j < XL; j++) {
            counter = 0;
            for (i1 = i - 1; i1 <= i + 1; i1++) {
                for (j1 = j - 1; j1 <= j + 1; j1++) {
                    tr_i = tr_j = 0;
                    if (i1 < 0) tr_i = YL;
                    if (j1 < 0) tr_j = XL;
                    if (i1 > YL - 1) tr_i = -YL;
                    if (j1 > XL - 1) tr_j = -XL;
                    if ((*Xtr)[i1 + tr_i][j1 + tr_j] == 1) counter++;
                }
                if (counter == 3 && (*Xtr)[i][j] != 1)
                    Xnew[i][j] = 1;
                else if ((counter == 4 || counter == 3) && (*Xtr)[i][j] == 1)
                    Xnew[i][j] = 1;
                else
                    Xnew[i][j] = 0;
            }
        }
    }
    for (i = 0; i < YL; i++)
        for (j = 0; j < XL; j++) (*Xtr)[i][j] = Xnew[i][j];
}

void creating_arr(int ***pointer_arr) {
    (*pointer_arr) = malloc(YL * sizeof(int *));
    for (int i = 0; i < YL; i++) (*pointer_arr)[i] = malloc(XL * sizeof(int));
    for (int i = 0; i < YL; i++)
        for (int j = 0; j < XL; j++) (*pointer_arr)[i][j] = 0;
}

void cleaner(int ***a) {
    for (int i = 0; i < YL; i++) free((*a)[i]);
    free((*a));
}
