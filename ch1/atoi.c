#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000

int natoi(char s[]);

int main(){

        /* use stdlib getline */
        size_t len=0;
        int n =0;
        char *line;
        while ( (getline(&line,&len,stdin)) != EOF){
                n = natoi(line);
                printf("n= %d\n",n);
        }
        return 0;
}

int natoi(char s[]){
        int i,n;
        n=0;

        for ( i= 0; s[i] >= '0' && s[i] <= '9'; ++i)
                n = 10 * n+ (s[i] - '0');
        return n;
}
