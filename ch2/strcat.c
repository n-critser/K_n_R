#include<stdio.h>
#define MAX 1000

void nstrcat(char s[], char t[]);

int main(){

        char str1[MAX]="hello";
        char str2[]="world";
        printf("str1=%s , str2=%s\n",str1,str2);
        nstrcat(str1,str2);
        printf("str1=%s , str2=%s\n",str1,str2);
        
        return 0;
}

void nstrcat(char s[], char t[]){
        int i,j;
        i = j= 0;

        while(s[i] != '\0')
              i++;
        while ((s[i++] = t[j++]) != '\0')
                ;
}
