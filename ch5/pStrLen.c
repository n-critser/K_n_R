#include<stdio.h>

int pstrlen(char *s);
int p2strlen(char *s);

int main(int argc, char*argv){

        /*CHARACTER POINTERS  */
        char amessage[]="now is the array";
        char *pmessage="now is the pointer";

        /* From K N R Ch5
           Individual characters within the array may be changed but
           amessage will always refer to the same storage.
           On the other hand, pmessage is a pointer, initialized to
           point to a string constant; the pointer may subsequently be modified
           to point elsewhere, but the result is undefined if you
           try to modify the string contents.
         */
        char *w = "fancy";
        char y[]="fancy";
        char *foo="supercalafragalistic";
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
        return 0;

}


int pstrlen(char *s){

        int n;
        for (n = 0; *s != '\0'; s++)
                n++;
        return n;
}

/* This only works because p and s work on the same array
   pointer subtraction OK, addition BAD
*/
int p2strlen(char *s){
        char *p = s;
        while(*p != '\0')
              p++;
        return p - s;

}
