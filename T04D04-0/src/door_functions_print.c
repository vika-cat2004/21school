#include <math.h>
#include <stdio.h>

/*Returns the witch of Agnesi with diameter one for `num` argument.*/
double agnesi(double num);

/*Returns the lemniscate of Bernoulli with a unit interval in the positive half-plane for `num` argument.*/
double bernulli(double num);

/*Returns the quadratic hyperbola for `num` argument.*/
double hyper(double num);

/*Returns 1, if point is between lines, else 0.*/
int checkPointPosition(double y, double step, double iter, double precision);

int main(void) {
    double num = -M_PI;
    double step = M_PI / 20.5;

    // Ordinata steps for each function
    double agnesiStep = 0.9941613;
    double bernulliStep = 0.4996003;
    double hyperStep = 170.3209101;

    // Precisions for each function
    double agnesiPrecision = 0.21;
    double bernulliPrecision = 1.1;
    double hyperPrecision = 0.01;

    // Result init for each function
    double agnesiRes = 0;
    double bernulliRes = 0;
    double hyperRes = 0;

    for (int graph = 0; graph < 3; graph++) {
        printf("-----------------------------------------\n");
        for (int i = 21; i > 0; i--) {
            num = -M_PI;

            for (int j = 0; j < 42; j++) {
                char currentChar = ' ';
                double iter = i;
                switch (graph) {
                    // Agnesi graph
                    case 0:
                        agnesiRes = agnesi(num);
                        if (checkPointPosition(agnesiRes, agnesiStep, iter, agnesiPrecision)) {
                            currentChar = '*';
                        }
                        break;

                    // Bernulli graph
                    case 1:
                        bernulliRes = bernulli(num);
                        if (!isnan(bernulliRes)) {
                            if (checkPointPosition(bernulliRes, bernulliStep, iter, bernulliPrecision)) {
                                currentChar = '*';
                            }
                        }
                        break;

                    // Hyperbola graph
                    case 2:
                        hyperRes = hyper(num);
                        if (checkPointPosition(hyperRes, hyperStep, iter, hyperPrecision)) {
                            currentChar = '*';
                        }

                        break;
                }

                num += step;

                printf("%c", currentChar);
            }
            printf("\n");
        }
    }

    return 0;
}

double agnesi(double num) {
    double res = 1 / (1 + num * num);

    return res;
}

double bernulli(double num) {
    double res = sqrt(sqrt(1 + 4 * num * num) - num * num - 1);

    return res;
}

double hyper(double num) {
    double res = 1 / (num * num);

    return res;
}

int checkPointPosition(double y, double step, double iter, double precision) {
    double iterMax = iter + (step * precision);
    double iterMin = iter - (step * precision);
    double result = y / (step / 21);
    if (result <= iterMax && result >= iterMin) {
        return 1;
    } else {
        return 0;
    }
}
