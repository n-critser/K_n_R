#include<stdio.h>
#define MAXLINE 1000

int ngetline(char line[], int lim);
void copy (char to[], char from []);
void reverse(char start[],int n);

int main(){

        int len;
        char line[MAXLINE];
        char rev[MAXLINE];

        while(( len = ngetline(line,MAXLINE)) > 0){
                copy(rev, line);
                reverse(rev, len);
                 printf("%s\n", rev);
        }

                
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
        /*clear a string buffer ?  */
        
        /*no error checking at all in this strcpy() */
        while ((to[i] = from [i]) != '\0')
                ++i;
}

void reverse(char start[],int n){
        int i;
        char temp[n];
        //printf ("length of start : %d\n",n);
        for (i =0; i < n; i++){
                temp[n-i-1]=start[i];
        }
        temp[n]='\0';
        copy(start,temp);
}
