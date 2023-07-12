// Copyright 2022 colerobe & marlokat

#include <stdio.h>

void Draw(int left_score, int right_score, int left_racket_top,
          int left_racket_mid, int left_racket_bot, int right_racket_top,
          int right_racket_mid, int right_racket_bot, int ball_X, int ball_Y,
          int goal);

void Clear(void) {
    printf("\033[2J");
    printf("\033[0;0f");
}

int main() {
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

    Clear();

    Draw(left_score, right_score, left_racket_top, left_racket_mid,
         left_racket_bot, right_racket_top, right_racket_mid, right_racket_bot,
         ball_X, ball_Y, goal);

    while (left_score != 21 && right_score != 21) {
        char move = getchar();
        goal = 0;
        if (move == 'A' || move == 'a' || move == 'Z' || move == 'z' ||
            move == 'K' || move == 'k' || move == 'M' || move == 'm' ||
            move == ' ') {
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

            //? Check goal to the right (no intersection with the right racket,
            // but x is above rackets' one)
            if ((!right_racket_intersection) && (ball_X == 76)) {
                left_score++;
                goal = 'l';
            } else if ((!left_racket_intersection) && (ball_X == 3)) {
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

            Clear();

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
        }
    }

    Clear();

    if (left_score == 21) {
        printf("                 Player 1 won. Congratulations!");
    } else if (right_score == 21) {
        printf("                 Player 2 won. Congratulations!");
    }

    return 0;
}

void Draw(int left_score, int right_score, int left_racket_top,
          int left_racket_mid, int left_racket_bot, int right_racket_top,
          int right_racket_mid, int right_racket_bot, int ball_X, int ball_Y,
          int goal) {
    printf(
        "First Player: %.02d                                               "
        "Second Player: %.02d\n",
        left_score, right_score);

    // Top border draw
    if (goal == 'l') {
        printf(
            "==================GOAL============================================"
            "==============");
    } else if (goal == 'r') {
        printf(
            "==========================================================GOAL===="
            "==============");
    } else {
        printf(
            "=================================================================="
            "==============");
    }

    printf("\n");

    for (int y = 1; y < 24; ++y) {
        for (int x = 0; x < 80; ++x) {
            if (x == 2) {
                if (y == left_racket_top || y == left_racket_mid ||
                    y == left_racket_bot) {
                    printf("|");
                } else {
                    printf(" ");
                }
            } else if (x == 77) {
                if (y == right_racket_top || y == right_racket_mid ||
                    y == right_racket_bot) {
                    printf("|");
                } else {
                    printf(" ");
                }
            } else if (x == ball_X && y == ball_Y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int j = 0; j < 80; ++j) {
        printf("=");
    }
}
