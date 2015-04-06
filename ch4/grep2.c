#include <stdio.h>
#define MAXLINE 100

int Ngetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
        char line[MAXLINE];
        int found= 0;

        while (Ngetline(line, MAXLINE) >0)
                if(strindex(line, pattern) >= 0){
                        printf("%s\n", line);
                        found++;
                }
        return found;
        

}

int Ngetline( char s [], int lim){
        int c,i;

        i =0;
        while(--lim > 0 && (c = getchar()) != EOF && c!='\n')
                s[i++] = c;
        if( c== '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

/* strindex: return index of t in s or -1 if not found
   similar to strstr(str1,str2);
 */

int strindex(char s[], char t[]){
        int i,j,k;
        for (i = 0; s[i] != '\0'; i++){
                if (s[i] ==' ' || s[i]=='\n')
                        printf("\n");
                else
                        printf("[%c]",s[i]);
                for (j = i, k=0; t[k] !='\0' && s[j]==t[k]; j++, k++)
                        ;
                if (k > 0 && t[k] == '\0')
                        return i;
                
        }
        printf("\n");
        return -1;
}
