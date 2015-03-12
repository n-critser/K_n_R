#include <stdio.h>

#define MAXLINE 40

int main(){
        int c;
        int count;
        count = 0;
        
        c = getchar();
        ++count;
        while (c != EOF) {
                putchar(c);
                if ((c = getchar()) =='\n')
                        count =0;
                ++count;
                if (count > MAXLINE){
                        printf("count = %d",count);
                        putchar('\n');
                        count = 0;
                }
                
        }
}
                   
