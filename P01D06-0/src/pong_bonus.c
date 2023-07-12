// Copyright 2022 colerobe & marlokat

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void Draw(int left_score, int right_score, int left_racket_top,
          int left_racket_mid, int left_racket_bot, int right_racket_top,
          int right_racket_mid, int right_racket_bot, int ball_X, int ball_Y,
          int goal);

void WinScreen(int player_number, int left_score, int right_score);

int main() {
    //* ncurses terminal manager
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    int left_racket_top = 11, left_racket_mid = 12, left_racket_bot = 13;
    int right_racket_top = 11, right_racket_mid = 12, right_racket_bot = 13;
    int ball_X = 40, ball_Y = 12;
    int left_score = 20, right_score = 20;

    int left_racket_intersection;
    int right_racket_intersection;
    int goal = 0;

    /*  BALL STATES
        ---------------------------
        0: ← (to the left)
        1: → (to the right)
        2: ↖ (to the left-top)
        3: ↗ (to the right-bottom)
        4: ↗ (to the right-top)
        5: ↙ (to the left-bottom)
    */
    int ball_state = 0;

    printw("b_s: %d  ", ball_state);
    Draw(left_score, right_score, left_racket_top, left_racket_mid,
         left_racket_bot, right_racket_top, right_racket_mid, right_racket_bot,
         ball_X, ball_Y, goal);
    system("/bin/stty -icanon");

    while (left_score != 21 && right_score != 21) {
        clear();
        char move = getch();
        goal = 0;

        //? Check ball's intersection with the left racket
        if ((ball_Y == left_racket_top || ball_Y == left_racket_mid ||
             ball_Y == left_racket_bot) &&
            ball_X == 3) {
            left_racket_intersection = 1;
        } else {
            left_racket_intersection = 0;
        }

        //? Check ball's intersection with the right racket
        if ((ball_Y == right_racket_top || ball_Y == right_racket_mid ||
             ball_Y == right_racket_bot) &&
            ball_X == 76) {
            right_racket_intersection = 1;
        } else {
            right_racket_intersection = 0;
        }

        //? Check goal to the right (no intersection with the right racket, but
        // x is above rackets' one)
        if ((!right_racket_intersection) && (ball_X == 79)) {
            left_score++;
            goal = 'l';
        } else if ((!left_racket_intersection) && (ball_X == 0)) {
            right_score++;
            goal = 'r';
        }

        //! Ball intersections with the rackets
        if (ball_state == 0) {
            //* TO THE LEFT
            //* Game start, ball flies on the left from the middle
            if (ball_X == 3) {
                // Touches first player's racket
                if (ball_Y == left_racket_top) {
                    ball_state = 3;
                } else if (ball_Y == left_racket_mid) {
                    ball_state = 1;
                } else if (ball_Y == left_racket_bot) {
                    ball_state = 4;
                }
            }
        } else if (ball_state == 1) {
            //* TO THE RIGHT
            if (ball_X == 76) {
                if (ball_Y == right_racket_top) {
                    ball_state = 5;
                } else if (ball_Y == right_racket_mid) {
                    ball_state = 0;
                } else if (ball_Y == right_racket_bot) {
                    ball_state = 2;
                }
            }
        } else if (ball_state == 2) {
            //* TO THE LEFT-TOP
            if (left_racket_intersection) {
                ball_state = 4;
            }

            //* Jump from the top
            if (ball_Y == 1) {
                ball_state = 5;
            }
        } else if (ball_state == 3) {
            //* TO THE RIGHT-BOTTOM
            if (right_racket_intersection) {
                ball_state = 5;
            }

            //* Jump from the bottom
            if (ball_Y == 23) {
                ball_state = 4;
            }
        } else if (ball_state == 4) {
            //* TO THE RIGHT-TOP
            if (right_racket_intersection) {
                ball_state = 2;
            }
            //* Jump from the top
            if (ball_Y == 1) {
                ball_state = 3;
            }
        } else if (ball_state == 5) {
            //* TO THE LEFT-BOTTOM
            if (left_racket_intersection) {
                ball_state = 3;
            }

            //* Jump from the bottom
            if (ball_Y == 23) {
                ball_state = 2;
            }
        }

        //! Ball movement
        if (ball_state == 0) {
            ball_X--;
        } else if (ball_state == 1) {
            ball_X++;
        } else if (ball_state == 2) {
            ball_X--;
            ball_Y--;
        } else if (ball_state == 3) {
            ball_X++;
            ball_Y++;
        } else if (ball_state == 4) {
            ball_X++;
            ball_Y--;
        } else if (ball_state == 5) {
            ball_X--;
            ball_Y++;
        }

        //! Racket controls (bordered)
        if ((move == 'A' || move == 'a') && left_racket_top >= 2) {
            left_racket_top--;
            left_racket_mid--;
            left_racket_bot--;
        } else if ((move == 'Z' || move == 'z') && left_racket_bot <= 22) {
            left_racket_top++;
            left_racket_mid++;
            left_racket_bot++;
        } else if ((move == 'K' || move == 'k') && right_racket_top >= 2) {
            right_racket_top--;
            right_racket_mid--;
            right_racket_bot--;
        } else if ((move == 'M' || move == 'm') && right_racket_bot <= 22) {
            right_racket_top++;
            right_racket_mid++;
            right_racket_bot++;
        }

        //! Goal management
        if (goal) {
            // If somebody goaled, reset all the game variables to defaults
            ball_X = 40;
            ball_Y = 12;
            left_racket_top = 11;
            left_racket_mid = 12;
            left_racket_bot = 13;
            right_racket_top = 11;
            right_racket_mid = 12;
            right_racket_bot = 13;
        }

        if (goal == 'l') {
            // If left player won, ball is moving to him
            ball_state = 0;

        } else if (goal == 'r') {
            // If right player won, ball is moving to him
            ball_state = 1;
        }

        Draw(left_score, right_score, left_racket_top, left_racket_mid,
             left_racket_bot, right_racket_top, right_racket_mid,
             right_racket_bot, ball_X, ball_Y, goal);
        refresh();
        curs_set(0);
        usleep(75000);
    }

    clear();

    if (left_score == 21) {
        WinScreen(1, left_score, right_score);
    } else if (right_score == 21) {
        WinScreen(2, left_score, right_score);
    }

    endwin();
    return 0;
}

void Draw(int left_score, int right_score, int left_racket_top,
          int left_racket_mid, int left_racket_bot, int right_racket_top,
          int right_racket_mid, int right_racket_bot, int ball_X, int ball_Y,
          int goal) {
    printw(
        "First Player: %.02d                                               "
        "Second Player: %.02d\n",
        left_score, right_score);
    // Top border draw
    if (goal == 'l') {
        printw(
            "==================GOAL============================================"
            "==============");
    } else if (goal == 'r') {
        printw(
            "==========================================================GOAL===="
            "==============");
    } else {
        printw(
            "=================================================================="
            "==============");
    }

    printw("\n");

    for (int y = 1; y < 24; ++y) {
        for (int x = 0; x < 80; ++x) {
            if (x == ball_X && y == ball_Y) {
                printw("*");
            } else if (x == 2) {
                if (y == left_racket_top || y == left_racket_mid ||
                    y == left_racket_bot) {
                    printw("|");
                } else {
                    printw(" ");
                }
            } else if (x == 77) {
                if (y == right_racket_top || y == right_racket_mid ||
                    y == right_racket_bot) {
                    printw("|");
                } else {
                    printw(" ");
                }
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    for (int j = 0; j < 80; ++j) {
        printw("=");
    }
}

void WinScreen(int player_number, int left_score, int right_score) {
    if (player_number == 1) {
        printw(
            "                       ____  _    __        _____  _   _          "
            "              \n");
        printw(
            "                      |  _ \\/ |   \\ \\      / / _ \\| \\ | |    "
            "                   \n");
        printw(
            "                      | |_) | |    \\ \\ /\\ / | | | |  \\| |     "
            "                  \n");
        printw(
            "                      |  __/| |     \\ V  V /| |_| | |\\  |       "
            "                \n");
        printw(
            "                      |_|   |_|      \\_/\\_/  \\___/|_| \\_|     "
            "                  \n\n");
    } else if (player_number == 2) {
        printw(
            "                     ____ ____     __        _____  _   _         "
            "            \n");
        printw(
            "                    |  _ |___ \\    \\ \\      / / _ \\| \\ | |   "
            "                 \n");
        printw(
            "                    | |_) |__) |    \\ \\ /\\ / | | | |  \\| |    "
            "                \n");
        printw(
            "                    |  __// __/      \\ V  V /| |_| | |\\  |      "
            "              \n");
        printw(
            "                    |_|  |_____|      \\_/\\_/  \\___/|_| \\_|    "
            "                \n\n");
    }
    printw("                                   %d - %d\n", left_score,
           right_score);
    printw("                          press space to exit game\n");

    while (1) {
        char term = getch();

        if (term == ' ') {
            break;
        }
    }
}
