#include <stdio.h>

int main(){
        printf("put_2space.c\n");
        int c;
        while(( c = getchar()) != EOF){
                if (c== ' '){
                        putchar(c);
                        putchar(c);
                }
                else
                        putchar(c);
        }
        return 0;
}
