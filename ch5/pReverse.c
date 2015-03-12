#include<stdio.h>
#include<string.h>
int pstrlen(char *s);
int p2strlen(char *s);
void pReverse(char *s, char*t);

#define MAX 80

int main(int argc, char*argv){

        char *w = "fancy";
        char y[]="fancy";
        char *foo="supercalafragalistic";
        char bar[MAX];
        /*seg faults if you don't allocate space for next due to read only memory */
        char next[MAX];
        printf("w = %s\n" ,w);
        printf("y = %s\n" ,y);
        int x=0;
        int z=0;
        int a=0;
        int b=0;
        x = pstrlen(w);
        z = pstrlen(y);

        a = p2strlen(foo);
        
        printf("x = %d\n" ,x);
        printf("z = %d\n" ,z);
        printf("a = %d\n", a);

        /*now start midway in string */
        x = pstrlen(&y[2]);
        printf("x = %d\n" ,x);
        pReverse(w,next);
        printf("LINE \n");
        pReverse(foo,bar);
        printf("bar =%s\n",bar);
                
                
        printf("next =%s\n",next);
        return 0;

}


int pstrlen(char *s){

        int n;
        for (n = 0; *s != '\0'; s++)
                n++;
        return n;
}

int p2strlen(char *s){
        char *p = s;
        while(*p != '\0')
              p++;
        return p - s;

}

void pReverse(char *s,char*t){
        int len,i;
        len = p2strlen(s);
        printf("len = %d\n",len);
        s+=len-1;
        for (i=0;i<=len;i++){
                *t=*s;
                t++;
                s--;
        }
}
