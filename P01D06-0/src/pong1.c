#include <stdio.h>

/*
way 0 - right
way 1 - left
way 2 - right down
way 3 - left down
way 4 - right up
way 5 - left up
*/

void Clear(void);
void Draw(int score_left, int score_right, int left_racket, int right_racket, int ball_X, int ball_Y);
void Racket_move(char move);

int main() {
    int ball_X = 40;
    int ball_Y = 12;
    int left_racket = 12;
    int right_racket = 12;

    int score_left = 0;
    int score_right = 0;
    char goal = 0;
    int way = 0;
    int left_racket_intersection = 0, right_racket_intersection = 0, up_intersection = 0,
        down_intersection = 0;
    Draw(score_left, score_right, left_racket, right_racket, ball_X, ball_Y);

    while (score_left < 21 && score_right < 21) {
        char move = getchar();
        if (move == 'A' || move == 'a' || move == 'Z' || move == 'z' || move == 'K' || move == 'k' ||
            move == 'M' || move == 'm' || move == ' ') {
            if ((move == 'A' || move == 'a') && left_racket > 2) {
                left_racket--;
            } else if ((move == 'Z' || move == 'z') && left_racket < 22) {
                left_racket++;
            } else if ((move == 'K' || move == 'k') && right_racket > 2) {
                right_racket--;
            } else if ((move == 'M' || move == 'm') && right_racket < 22) {
                right_racket++;
            }

            if (ball_X == 78 &&
                (ball_Y == right_racket || ball_Y == right_racket - 1 || ball_Y == right_racket + 1)) {
                right_racket_intersection = 1;
            } else if (ball_X == 1 &&
                       (ball_Y == left_racket || ball_Y == left_racket - 1 || ball_Y == left_racket + 1)) {
                left_racket_intersection = 1;
            } else if (ball_X == 80 &&
                       (ball_Y != right_racket || ball_Y != right_racket - 1 || ball_Y != right_racket + 1)) {
                goal = 'l';
                right_racket_intersection = 0;
                left_racket_intersection = 0;
            } else if (ball_X == 0 &&
                       (ball_Y != left_racket || ball_Y != left_racket - 1 || ball_Y != left_racket + 1)) {
                goal = 'r';
                right_racket_intersection = 0;
                left_racket_intersection = 0;
            } else {
                right_racket_intersection = 0;
                left_racket_intersection = 0;
            }

            if (ball_Y == 23) {
                down_intersection = 1;
            } else if (ball_Y == 1) {
                up_intersection = 1;
            } else {
                down_intersection = 0;
                up_intersection = 0;
            }

            if (way == 0) {
                if (right_racket_intersection == 1 && ball_Y == right_racket) {
                    way = 1;
                } else if (right_racket_intersection == 1 && ball_Y == right_racket - 1) {
                    way = 4;
                } else if (right_racket_intersection == 1 && ball_Y == right_racket + 1) {
                    way = 3;
                } else {
                    way = 0;
                }
            } else if (way == 1) {
                if (left_racket_intersection == 1 && ball_Y == left_racket) {
                    way = 0;
                } else if (left_racket_intersection == 1 && ball_Y == left_racket - 1) {
                    way = 5;
                } else if (left_racket_intersection == 1 && ball_Y == left_racket + 1) {
                    way = 2;
                } else {
                    way = 1;
                }
            } else if (way == 2) {
                if (right_racket_intersection == 1 && down_intersection == 1) {
                    way = 4;
                } else if (right_racket_intersection == 1 && down_intersection != 1) {
                    way = 3;
                } else if (right_racket_intersection != 1 && down_intersection == 1) {
                    way = 5;
                } else {
                    way = 2;
                }
            } else if (way == 3) {
                if (left_racket_intersection == 1 && down_intersection == 1) {
                    way = 5;
                } else if (left_racket_intersection == 1 && down_intersection != 1) {
                    way = 2;
                } else if (left_racket_intersection != 1 && down_intersection == 1) {
                    way = 4;
                } else {
                    way = 3;
                }
            } else if (way == 4) {
                if (left_racket_intersection == 1 && up_intersection == 1) {
                    way = 2;
                } else if (left_racket_intersection == 1 && up_intersection != 1) {
                    way = 5;
                } else if (left_racket_intersection != 1 && up_intersection == 1) {
                    way = 3;
                } else {
                    way = 4;
                }
            } else if (way == 5) {
                if (right_racket_intersection == 1 && up_intersection == 1) {
                    way = 3;
                } else if (right_racket_intersection == 1 && up_intersection != 1) {
                    way = 4;
                } else if (right_racket_intersection != 1 && up_intersection == 1) {
                    way = 2;
                } else {
                    way = 5;
                }
            }

            if (way == 0) {  // right
                ball_X++;
            } else if (way == 1) {  // left
                ball_X--;
            } else if (way == 2) {  // right down
                ball_X++;
                ball_Y++;
            } else if (way == 3) {  // left down
                ball_X--;
                ball_Y++;
            } else if (way == 4) {  // left up
                ball_X--;
                ball_Y--;
            } else if (way == 5) {  // right up
                ball_X++;
                ball_Y--;
            }

            if (goal == 'l') {
                score_left++;
                ball_X = 40;
                ball_Y = 12;
                left_racket = 12;
                right_racket = 12;
                goal = 0;
                Draw(score_left, score_right, left_racket, right_racket, ball_X, ball_Y);
            } else if (goal == 'r') {
                score_right++;
                ball_X = 40;
                ball_Y = 12;
                left_racket = 12;
                right_racket = 12;
                goal = 0;
                Draw(score_left, score_right, left_racket, right_racket, ball_X, ball_Y);
            }
            Draw(score_left, score_right, left_racket, right_racket, ball_X, ball_Y);
        }
    }
    Clear();
    if (score_left == 21) {
        printf("Player 1 won!\n");
    } else if (score_right == 21) {
        printf("Player 2 won!\n");
    }

    return 0;
}

void Clear(void) {
    printf("\033[2J");
    printf("\033[0;0f");
}

void Draw(int score_left, int score_right, int left_racket, int right_racket, int ball_X, int ball_Y) {
    Clear();

    printf("\t\t%2d\t\t\t\t\t\t%2d\n", score_left, score_right);

    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if (y == 0 || y == 24) {
                printf("-");
            } else if ((x == ball_X) && (y == ball_Y)) {
                printf("*");
            } else if ((x == 0) && (y == left_racket || y == left_racket + 1 || y == left_racket - 1) &&
                       (left_racket > 1) && (left_racket < 24)) {
                printf("|");
            } else if ((x == 79) && (y == right_racket || y == right_racket + 1 || y == right_racket - 1) &&
                       (right_racket > 1) && (right_racket < 24)) {
                printf("|");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return;
}
