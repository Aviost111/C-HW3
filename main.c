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
    int arr[SIZE] = {0}; // declare array
    getNumbers(arr);
    insertion_sort(arr, SIZE);
    for (int i = 0; i < SIZE-1; i++) // print sort array
    {
        printf("%d,", *(arr + i));
    }
    printf("%d", *(arr + SIZE-1));
    printf("\n");
return 0;
}