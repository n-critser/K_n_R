/* cpfile.c https://en.wikibooks.org/wiki/A_Little_C_Primer/C_Command_Line_Arguments */
#include<stdio.h>
#include<stdlib.h>
#define MAX 256

int main( int argc,  char **argv){

        FILE *src, *dst;
        char b[MAX];

        switch(argc){
        case 1:
                src = stdin;
                dst = stdout;
                break;

        case 2:
                if(( src = fopen(argv[1], "r")) == NULL){
                        puts("can't open input file.\n");
                        exit( 0 );
                }
                dst = stdout;
                break;

        case 3:
                if (( src = fopen( argv[1], "r")) == NULL){
                        puts( "can't open input file.\n");
                        exit(0);
                }
                if (( dst = fopen( argv[2], "w")) == NULL){
                        puts(" can't open output file.\n");
                        exit(0);
                }
                break;

        default:
                puts ("too many params.\n");
                exit(0);
                break;
        }

        while( (fgets(b,MAX, src)) !=NULL){
                fputs(b,dst);
        }
        fclose( src );
        fclose( dst );
        return 0;
}
