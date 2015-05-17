#include<stdio.h>

/*  return lex diff of s compared with t*/
int strcmp(char *s, char *t);
/*  pointer version of return lex diff of s compared with t*/
int pstrcmp(char *s, char *t);

int main(void){
        int res1,res2;
        res1=res2=0;
        char * pstr1="this is a str";
        char * pstr2="this is a diff str";

        res1=strcmp(pstr1,pstr2);
        res2=pstrcmp(pstr1,pstr2);
        printf("res1=%d\n",res1);
        printf("res2=%d\n",res2);
        return res1-res2;

}

int strcmp(char *s, char *t){
        int i;
        for ( i= 0; s[i] == t[i]; i++)
                if(s[i] == '\0')
                        return 0;
        return s[i] - t[i];
}

int pstrcmp(char *s, char *t){
        while(*s++==*t++)
                if (*s=='\0')
                        return 0;
        return *--s - *--t;

}
