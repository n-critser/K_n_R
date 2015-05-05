#include<stdio.h>
#define MAXLINE 1000

int ngetline(char line[], int lim);
void copy (char to[], char from []);

int main(){

        int len, max;
        char line[MAXLINE];
        char longest[MAXLINE];

        max = 0;
        while(( len = ngetline(line,MAXLINE)) > 0)
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        if ( max > 0)
                printf("%s", longest);
                
        return 0;
}

/* build a string in a buffer then return the length
   returns int length of the string 
*/
int ngetline(char s[], int lim){

        int c, i;
        for ( i=0; i < lim-1 && (c =getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n'){
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

void copy ( char to [], char from []){
        int i;
        i = 0;
        /*no error checking at all in this strcpy() */
        while ((to[i] = from [i]) != '\0')
                ++i;
}
