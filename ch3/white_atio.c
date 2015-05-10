#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int watoi(char s[]){
        int i, n, sign;
        for( i=0; isspace(s[i]); i++)
                ;
        sign = (s[i] =='-')?-1:1;
        if(s[i] == '+' || s[i] == '-')
                i++;
        for( n=0; isdigit(s[i]); i++)
                n = 10 * n + (s[i] - '0');
        return sign *n ;
}

int main(void) {

        int num;
        FILE *stream;
        char *line = NULL;
        size_t len=0;
        ssize_t read;

        stream =fopen("data.org","r");
        if(stream ==NULL){
                printf("exit failure\n");
                exit(EXIT_FAILURE);
        }
        while((read = getline(&line, &len, stream)) != -1){
                num = watoi(line);
                printf("found digit: %d\n",num);
        }

        free(line);
        fclose(stream);
        exit(EXIT_SUCCESS);
}
        
