#include <math.h>
#include <stdio.h>

/*Returns the witch of Agnesi with diameter one for `num` argument.*/
double agnesi(double num);

/*Returns the lemniscate of Bernoulli with a unit interval in the positive half-plane for `num` argument.*/
double bernulli(double num);

/*Returns the quadratic hyperbola for `num` argument.*/
double hyper(double num);

int main(void) {
    // Variables initialization
    double startNum = -M_PI;
    double step = M_PI / 20.5;

    for (int i = 0; i < 42; i++) {
        printf("%.7lf | %.7lf | ", startNum, agnesi(startNum));

        double bernulliRes = bernulli(startNum);

        // Checking the result of lemniscate of Bernoulli for being nan (not a number)
        if (isnan(bernulliRes)) {
            printf("- | ");
        } else {
            printf("%.7lf | ", bernulliRes);
        }

        printf("%.7lf\n", hyper(startNum));

        // Stepping further through the coordinates
        startNum += step;
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
