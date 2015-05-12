#include <stdio.h>
#include <string.h>

int trim(char s[]){
        int n;
        for (n =strlen(s)-1; n>= 0; n--)
                if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
                        break;
        s[n+1]='\0';
        return n;
}

int main(int argc, char**argv){

        int len = 0;
        char str1[]= "what the hell   \t   \n";
        len=strlen(str1);
        printf ("len(st1): %d , st1: %s\n",len,str1);
        len=trim(str1);
        printf ("len(st1): %d , st1: %s\n",len,str1);
        return 0;
}
