/*
    Write a C program to sort an array of integers entered by the user. 
    Ask the user for the number of elements they want to sort, then read array elements into the dynamically created array.
    The sorting should be done in a separate function.
      – Write a Makefile for the program.
      – Compile using optimized and debug modes.
      – Set breakpoint in the sorting function, and run the program step by step using GDB.
      – Intentionally make a memory leak and detect it using Valgrind.
      – Document code using Doxygen format and generate documentation for it.
*/

#include <stdio.h>
#include <stdlib.h>
#include "modules/bubbleSort.h"

/**
    * @brief Creats array of integers
    *
    * @param n Length of array
    * @return Pointer to array
*/
int* getIntegers(const short n); 


int main() {
    short n = 0;
    printf("Enter array length: ");
    scanf("%hd", &n);
    
    int* array = getIntegers(n);
    if(!array)
        return 1;
    
    bubbleSort(n, array);

    for(int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }

    // free(array);
    return 0;
}

int* getIntegers(const short n) {
    int* array = (int*)malloc(n * sizeof(int));
    if(!array)
        return NULL;
    for(int i = 0; i < n; ++i) {
        printf("Enter array element [%d]: ", i);
        scanf("%d", array + i);
    }
    return array;
}
