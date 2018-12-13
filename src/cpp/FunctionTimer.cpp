//
// Created by Toby Dragon on 12/11/18.
//


#include <chrono>
#include <iostream>
#include "ArrayLib.h"

int main() {
    srand(time(NULL));
    int size = 1000000000;

    int* randArray = genRandArray(size, 0, size/4);
    int valToFind = genRandInt(0, size);

    auto t1 = std::chrono::high_resolution_clock::now();
    int* copy = copyArray(randArray, size, size);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    std::cout << time/1000.0 << " seconds serial, size = " << size << std::endl;
    delete[] copy;
    copy = nullptr;

    t1 = std::chrono::high_resolution_clock::now();
    int* copyParallel = copyArrayParallel(randArray, size, size);
    t2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    std::cout << time/1000.0 << " seconds Parallel, size = "<<size<<std::endl;
    delete[] copyParallel;
    copyParallel=nullptr;



    delete[] randArray;
    randArray = nullptr;
}