#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25
#define LIFE 1
#define DEAD 0

void init(int **matrix);
void step(int **matrix, int **next);
int check(int **matrix, int i, int j);
void output(int **matrix);
void swap(int **new, int **old);
int countLive(int **matrix);

int main() {
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    int **matrix = (int **)malloc(HEIGHT * sizeof(int *));
    int **next = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        matrix[i] = (int *)malloc(WIDTH * sizeof(int));
        next[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    init(matrix);
    if (freopen("/dev/tty", "rw", stdin) == NULL) {
        exit(1);
    }
    int time = 300000;

    while (1) {
        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            break;
        } else if (ch == KEY_UP && time > 30000) {
            time -= 30000;
        } else if (ch == KEY_DOWN && time < 900000) {
            time += 30000;
        }
        step(matrix, next);
        output(matrix);
        usleep(time);
        if (countLive(matrix) == 0) {
            endwin();
            break;
        }
    }

    endwin();

    for (int i = 0; i < HEIGHT; i++) {
        free(matrix[i]);
        free(next[i]);
    }

    free(matrix);
    free(next);
    return 0;
}

void init(int **matrix) {
    char c;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (scanf("%c", &c) == 1 && (c == '0' || c == '1') && c != ' ') {
                matrix[i][j] = c - '0';
            }
        }
    }
}

void step(int **matrix, int **next) {
    swap(next, matrix);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int state = matrix[i][j];
            int neighbors = check(matrix, i, j);

            if (state == DEAD && neighbors == 3) {
                next[i][j] = LIFE;
            } else if (state == LIFE && (neighbors < 2 || neighbors > 3)) {
                next[i][j] = DEAD;
            } else {
                next[i][j] = matrix[i][j];
            }
        }
    }

    swap(matrix, next);
}

void swap(int **new, int **old) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            new[i][j] = old[i][j];
        }
    }
}

void output(int **matrix) {
    clear();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j] == DEAD) {
                printw("·");
            } else {
                printw("o");
            }
        }
        printw("\n");
    }
}

int check(int **matrix, int i, int j) {
    int count_life = 0;
    for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
            int col = (i + k + HEIGHT) % HEIGHT;
            int row = (j + l + WIDTH) % WIDTH;
            count_life += matrix[col][row];
        }
    }
    if (matrix[i][j] == LIFE) {
        count_life--;
    }
    return count_life;
}

int countLive(int **matrix) {
    int count = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j] == LIFE) {
                count++;
            }
        }
    }
    return count;
}