#include "bubbleSort.h"

void bubbleSort(int arr_len, int* arr_v) {
    int isSorted = 0;
    while (isSorted != 1) {
        isSorted = 1;
        for(int i = 0; i < arr_len - 1; ++i) {
            int tmp = *(arr_v + i);
            if(*(arr_v + i) > *(arr_v + i + 1)) {
                isSorted = 0;
                *(arr_v + i) = *(arr_v + i + 1);
                *(arr_v + i + 1) = tmp;
            }
        }
    }
}
