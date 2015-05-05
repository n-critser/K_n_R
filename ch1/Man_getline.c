#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/*
  ssize_t getline(char **lineptr, size_t *n, FILE *stream);
  ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
*/

int
main(void)
{
        FILE *stream;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        
        stream = fopen("hello.c", "r");
        if (stream == NULL)
                exit(EXIT_FAILURE);
        
        while ((read = getline(&line, &len, stream)) != -1) {
                printf("Retrieved line of length %zu :\n", read);
                printf("%s", line);
        }
        
        free(line);
        fclose(stream);
        exit(EXIT_SUCCESS);
}
