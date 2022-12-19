#include <stdio.h>

#define SIZE 50

//fuction that get 50 numbers from the user
void getNumbers(int *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr + i);
    }
}

int main()
{
    int arr[SIZE]; // declare array
    getNumbers(arr);

    return 0;
}
