#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
int
main(void)
{
        FILE *stream;
        char *lineptr[MAXLEN];
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        
        stream = fopen("intArray.txt", "r");
        if (stream == NULL)
                exit(EXIT_FAILURE);
        int i = 0;
        while ((read = getline(&lineptr[i++], &len, stream)) != -1) {
                //printf("Retrieved line of length %zu :\n", read);
                printf("%s", (lineptr[i-1]));
               
                
        }
        printf("%s",(lineptr[1]));
        
        free(line);
        //free(lineptr);
        fclose(stream);
        exit(EXIT_SUCCESS);
}

