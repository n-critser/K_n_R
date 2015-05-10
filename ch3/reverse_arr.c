#include<string.h>
#include<stdio.h>

void reverse(char s[]){
        int c,i,j;

        for( i =0,j=strlen(s)-1; i<j; i++,j--){
                c=s[i];
                s[i]=s[j];
                s[j]=c;
        }
}

int main(void){

        char str1[]="something fancy to say & do";

        printf("%s\n",str1);
        reverse(str1);
        printf("%s\n",str1);
        return 0;
}
                
