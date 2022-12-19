#include "functions.h"
#include <stdio.h>

void shift_element(int*arr,int i){
    int temp=*(arr+2);
    for (int j = 1; j <i+1 ; ++j) {
        *(arr+i)=temp;
        if(j==i){
            break;
        }
        temp=*(arr+i+1);
    }
}
