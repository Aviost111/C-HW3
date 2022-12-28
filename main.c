#include <stdio.h>
#include "functions.h"

#define SIZE 50

// get 50 numbers from the user
void getNumbers(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", (arr + i));
    }
}

int main() {
    int arr[SIZE]={0};// declare array
    getNumbers(arr);
    printf("stop");
    insertion_sort(arr, SIZE);
    for (int i = 0; i < SIZE-1; i++) // print sort array
    {
        printf("%d,", *(arr + i));
    }
    printf("%d", *(arr + SIZE-1));
    printf("hi");
    return 0;
    {75, 43, 28, 29, 70, 76, 23, 96, 26, 2, 40, 21, 55, 13, 32, 56, 5, 64, 14, 77, 40, 70, 67, 38, 48, 59, 42, 42, 28, 6, 79, 46, 81, 26, 64, 66, 78, 58, 9, 1, 14, 44, 8, 31, 46, 25, 8, 32, 49, 93}
}

