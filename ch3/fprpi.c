/* fprpi.c */

#include <stdio.h>

int main(void){
     int n1 = 16;
     float n2 = 3.14159;
     FILE *fp;

     if ((fp = fopen( "pi.log", "w" ))== NULL){
             printf("output file unreadable\n");
             exit( 1 );
     }
     fprintf( fp, "  %d   %f\n", n1, n2 ); 
     fclose( fp );
     return 0;
}
