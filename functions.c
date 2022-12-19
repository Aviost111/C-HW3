#include "functions.h"
#include <stdio.h>

void shift_element(int *arr, int i) {
    int temp=*(arr+1) ,temp2;
    for (int j = 1; j < i + 1; ++j) {
        temp2=*(arr+j+1);
        *(arr + j+1) = temp;
        temp = temp2;
    }
}

void insertion_sort(int *arr, int len){

}
