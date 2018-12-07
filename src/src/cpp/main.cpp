#include <stdio.h>
#include <ctime>
#include <chrono>
#include <iostream>

double f(double);

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

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    double pi=calcPiSerial(1000000000);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    std::cout << time/1000.0 << " seconds serial, pi = "<<pi<<std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    pi=calcPiParallel(1000000000);
    t2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    std::cout << time/1000.0 << " seconds Parallel, pi = "<<pi<<std::endl;
}

/* function to integrate */
double f(double a) {
    return (2.0 / (1.0 + a * a));
}
