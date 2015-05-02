#include <stdio.h>

int main(){
        printf("put_1space.c\n");
        int c,state;
        state=0;
        while(( c = getchar()) != EOF){
                if (c== ' ' && state==0){
                        putchar(c);
                        state=1;
                
                }
                else if (c != ' '){
                        putchar(c);
                        state=0;
                }
        }
        return 0;
}
