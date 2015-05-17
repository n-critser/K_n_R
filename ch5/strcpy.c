#include<stdio.h>
#define MAX 500
/* copy t into s  */
void strcpyA( char *s, char *t){
        int i;
        i = 0;
        while((s[i] = t[i]) != '\0')
              i++;
}

void strcpyP1( char *s, char *t){
        while((*s++=*t++)!='\0')
                ;
}


int main(void){

        char amessage[]="now is the array";
        char *pmessage="then is the pointer message thats a little longer";

        char *empty;
        /* calling print on a string buffer prints to the next null byte*/
        char strbuff[MAX];
        empty = strbuff;
        strcpyA(strbuff,amessage);
        printf("%s\n",strbuff);

        /* overwriting amessage with pmessage since strbuff starts at 0 pos */
        strcpyP1(strbuff,pmessage);
        printf("%s\n",strbuff);
        printf("%s\n",empty);
        int i;
        for (i=0;i<MAX;i++)
                printf("%c",strbuff[i]);
        
        return 0;
}
