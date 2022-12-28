#include "functions.h"
#include <stdio.h>

void shift_element(int *arr, int i) {
    int temp = *(arr), temp2;
    for (int j = 0; j < i; ++j) {
        temp2 = *(arr + j + 1);
        *(arr + j + 1) = temp;
        temp = temp2;
    }
}

void insertion_sort(int *arr, int len) {
    int i, j, value;
    for (i = 1; i < len; i++) {
        value = *(arr + i);
        for (j = i - 1; j >= 0; j--) {
            if (value >= *(arr + j)) {
                shift_element((arr + j+1), i - j-1);
                *(arr+j+1)=value;
                break;
            }
            if((j==0)&&(value <= *(arr + j))){
                shift_element(arr, i);
                *(arr)=value;
            }
        }
    }
}
