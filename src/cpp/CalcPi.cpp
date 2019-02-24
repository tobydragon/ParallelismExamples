#include "CalcPi.h"

double f(double a) {
    return (2.0 / (1.0 + a * a));
}

double calcPiSerial(int interval){
    int i;
    double w, x, sum;
    /* calculate the interval size */
    w = 1.0;
    sum = 0.0;
    for (i = 1; i <= interval; i++) {
        x = w * (i - 0.5);
        sum = sum + f(x);
    }
    return w * sum;

}

double calcPiParallel(int interval){
    int i;
    double w, x, sum;
    /* calculate the interval size */
    w = 1.0;
    sum = 0.0;
#pragma omp parallel for private(x), shared(w), reduction(+: sum)
    for (i = 1; i <= interval; i++) {
        x = w * (i - 0.5);
        sum = sum + f(x);
    }
    return w * sum;

}
