#include<stdio.h>

/*  Determine the size of an integer programatically
    This program prints the powers of 2 using the shift left logical
    command on an unsigned integer.  Since the value flips to
    negative after its apex the loop ends at that point. Interesting that
    printf output for the final value casts the unsigned int as a 2's
    complement and outputs the negative value -2147483648. 
 */
int main(){
        unsigned int int_size, counter;
        int_size=0;
        counter=1;
        while ( counter > 0 ){
                printf("counter = %d\n", counter);
                counter=counter<<1;
                int_size++;
                
        }
        printf("int_size= %d\n" , int_size);
        return 0;
}
