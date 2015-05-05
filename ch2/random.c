#include<stdio.h>

unsigned long int next =1;
int random(void){
        next = next * 1103515245 + 12345;
        return (unsigned int)(next/65536) % 32768;
}

void srandom(unsigned int seed){
        next = seed;
}


int main(){

        unsigned long int x = 1221212121;
        int value=0;
        srandom(x);
        while(getchar() != EOF)
                printf("%d\n", value=random()); 
        return 0;
}
