#include <stdio.h>

void printd( int n){
        if ( n < 0 ) {
                putchar('-');
                n = -n;
        }
        if (n / 10)
                printd(n / 10);
        putchar( n % 10 + '0');
}

int main (void) {
        printf("running printd\n");
        int d = 23499;
        printd(d);
        printf("\n");
        return 0;
}
