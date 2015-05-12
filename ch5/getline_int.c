#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
        
        FILE *stream;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        char *tok;
        int n=0;
        
        stream = fopen("intArray.txt", "r");
        if (stream == NULL)
                exit(EXIT_FAILURE);
        
        while ((read = getline(&line, &len, stream)) != -1) {
                printf("Retrieved line of length %zu :\n", read);
                printf("%s", line);
                /* cool for loop tokenizer  */
                for( tok = strtok( line, "] [:," );
                     tok != NULL;
                     tok = strtok( NULL, ":" ) )
                {
                        printf( "%s\n", tok );
                        // works if n != 0
                        //if( (n=atoi(tok)))
                        //        printf("%d\n",n);
                        n=atoi(tok);
                        printf("%d\n",n);
                }
        }
        
        free(line);
        fclose(stream);
        exit(EXIT_SUCCESS);
}
