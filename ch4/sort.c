#include <stdio.h>
#include "qsort.h"

int main(){
        int numbers[]={ 1,2, 44,55,23,43,23,22,7,5,4,7,8,};
        int size= sizeof(numbers)/sizeof(int);

        int i =0 ;
        for ( ; i < size; i++)
                printf("num[%d] = %d\n", i , numbers[i]);
        qsort(numbers, 0,size);
        for (i =0 ; i < size; i++)
                printf("num[%d] = %d\n", i , numbers[i]);
        
        
}
