#include<stdio.h>

void squeeze(char s[], int c);

int main(){

        char  str[]="flexibility";
        printf("%s\n",str);
        squeeze(str, 'i');
        printf("%s\n",str);
        
        return 0;
}

void squeeze(char s[], int c){
        int i, j;
        for (i = j = 0; s[i] != '\0'; i++)
                if(s[i] !=c)
                        s[j++] = s[i];
        s[j] = '\0';
}
        
