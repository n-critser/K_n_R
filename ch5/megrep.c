#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[]){
        FILE *stream;
        char *line=NULL;
        int found=0;
        size_t len=0;
        ssize_t read;

        stream =argv[2]? (fopen(argv[2], "r")) : stdin;
        if(argc < 2)
                printf("Usage: find pattern \n");
        else
                while((read= getline(&line,&len,stream))!=-1)
                        if(strstr(line,argv[1]) !=NULL){
                                printf("::%s",line);
                                found++;
                        }
        return found;
}
