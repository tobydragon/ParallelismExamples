//
// Created by Toby Dragon on 9/10/18.
//

#ifndef COMP220LAB_ARRAYLIB_H
#define COMP220LAB_ARRAYLIB_H

#include <string>

/**
 * generates a copy of a given array
 * @return a pointer to the copy array, which must be deleted by the user, or nullptr, if size < 1
 */
int* copyArray(const int* arrayToCopy, int itemCount, int newCap);
int* copyArrayParallel(const int* arrayToCopy, int itemCount, int newCap);

/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int* genRandArray(int size, int min, int max);
int* genRandArrayParallel(int size, int min, int max);

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(const int* arrayPtr, int size, int numToFind);
int findParallel(const int* arrayPtr, int size, int numToFind);

/**
* finds the index of largest value in the array
* @throws an std::invalid_argument exception if size < 1
* @post numLinesRun is updated to add the number of lines run by this function
* @return the first index of the maximum value
*/
int findMaxIndex(const int* arrayPtr, int size);
int findMaxIndexParallel(const int* arrayPtr, int size);

/**
 * generates a random integer. If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @return an integer between min and max inclusive (i.e., including both min and max)
 */
int genRandInt(int min, int max);

#endif //COMP220LAB_ARRAYLIB_H
