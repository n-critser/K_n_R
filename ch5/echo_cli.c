#include<stdio.h>

int main(int argc, char*argv[]){
        int i;
        printf("argc=%d\n",argc);
        for( i=0; i<argc; i++){
               
                printf("%s%s", argv[i], (i < argc-1) ? " ": "");
        }
        printf("\n");
        printf("POINTER VERSION\n");
        while(--argc > 0)
                 printf("%s%s", *++argv, (argc> 1) ? " ": "");
        printf("\n");
        return 0;
}
