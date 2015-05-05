#include<stdio.h>
#define DLEN 10
#define ALEN 26

int main(){
        int c, i ,j , nwhite, nother;
        int ndigit[DLEN];
        int nchar[ALEN];
        nwhite=nother=0;
        for( i=0; i < DLEN; ++i)
                ndigit[i]=0;
        for( i=0; i < ALEN; ++i)
                nchar[i]=0;
        while ((c= getchar()) !=EOF){
                
                if (c >= '0' && c<= '9')
                        ++ndigit[c-'0'];
                else if (c == ' ' || c == '\n' || c =='\t')
                        ++nwhite;
                else if (c >='a' && c<= 'z')
                        ++nchar[c-'a'];
                //else if (c >='A' && c<= 'Z')
                //       ++nchar[c-'A'];
                else
                        ++nother;
        }
        printf("digits=");
        for (i=0; i < DLEN; ++i)
                printf(" %d", ndigit[i]);
        printf("\n");
        for (i=0; i < ALEN; ++i){
                printf("%c : ", 'a'+i);
                for (j=1; j<=nchar[i];j++)
                        printf("*");
                printf("\n");
        }
        printf("\n");        
        printf(", white space = %d, other = %d\n", nwhite,nother);
        
        return 0;
}
