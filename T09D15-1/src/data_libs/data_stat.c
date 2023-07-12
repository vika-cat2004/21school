#include "data_stat.h"

double max(double *data, int n) {
    double max = data[0];  // max экстремум
    for (int i = 0; i < n; i++)
        if (data[i] > max) max = data[i];
    return max;
}

double min(double *data, int n) {
    double min = data[0];  // min экстремум
    for (int i = 0; i < n; i++)
        if (data[i] < min) min = data[i];
    return min;
}

double mean(double *data, int n) {
    double mean = data[0];  //сумма всех на колво всех
    for (int i = 0; i < n; i++) mean += data[i];
    return mean;
}

double variance(double *data, int n) {
    double variance = data[0];
    double Mean = mean(data, n);
    for (int i = 0; i < n; i++) variance += (data[i] - Mean) * (data[i] - Mean);
    return variance;
}
void sort(double *data, int n) {
    int nn;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                nn = data[j];
                data[j] = data[j + 1];
                data[j + 1] = nn;
            }
        }
    }
}