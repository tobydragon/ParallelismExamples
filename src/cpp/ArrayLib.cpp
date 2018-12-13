//
// Created by Toby Dragon on 9/2/16.
//

#include <stdlib.h>
#include "ArrayLib.h"

int* copyArray(const int* arrayToCopy, int itemCount, int newCap){
    int* arrPtr = new int [newCap];
    for(int i = 0; i < itemCount; i++){
        arrPtr[i] = arrayToCopy[i];
    }
    return arrPtr;
}

int* copyArrayParallel(const int* arrayToCopy, int itemCount, int newCap){
    int* arrPtr = new int [newCap];
#pragma omp parallel for
    for(int i = 0; i < itemCount; i++){
        arrPtr[i] = arrayToCopy[i];
    }
    return arrPtr;
}

int* genRandArray(int size, int min, int max){
    int* randoms = new int[size];
    for (int i = 0; i < size; i++) {
        randoms[i] = genRandInt(min, max);
    }
    return randoms;
}

int* genRandArrayParallel(int size, int min, int max){
    int* randoms = new int[size];
    for (int i = 0; i < size; i++) {
        randoms[i] = genRandInt(min, max);
    }
    return randoms;
}

int find(const int* arrayPtr, int size, int numToFind){
    for (int i=0; i<size; i++){
        if (arrayPtr[i] == numToFind){
            return i;
        }
    }
    return -1;
}

int findParallel(const int* arrayPtr, int size, int numToFind){
    int foundIdx = -1;
    bool found = false;

#pragma omp parallel for reduction (min:foundIdx)
    for (int i=0; i<size; i++){
        if (!found && arrayPtr[i] == numToFind ){
            foundIdx = i;
            found = true;
        }
    }
    return foundIdx;
}

int findMaxIndex(const int* arrayPtr,  int size){
    if (size < 1){
        throw std::invalid_argument("Can't find max on empty array");
    }
    else {
        int foundAt = 0;
        for (int i=0; i<size; i++){
            if (arrayPtr[i] > arrayPtr[foundAt]){
                foundAt = i;
            }
        }
        return foundAt;
    }
}

int findMaxIndexParallel(const int* arrayPtr,  int size){
    if (size < 1){
        throw std::invalid_argument("Can't find max on empty array");
    }
    else {
        int foundAt = 0;
        for (int i=0; i<size; i++){
            if (arrayPtr[i] > arrayPtr[foundAt]){
                foundAt = i;
            }
        }
        return foundAt;
    }
}

int genRandInt(int min, int max){
    if (min > max){
        int temp = min;
        min = max;
        max = temp;
    }
    return (rand() % (max - min + 1)) + min;
}
