#include<stdio.h>
#include<stdlib.h>
#define MAX 256
#include <time.h>

void show( int v[], int n){
        int i;
        for(i =0; i<n;i++)
                printf("%d%c",v[i],(i<n-1)?',':' ');
        printf("done\n");
}
void shellsort(int v[], int n){
        int gap, i, j, temp;
        for( gap = n/2; gap > 0; gap /=2){
                printf("gap= %d \n",gap);
                for ( i = gap; i< n; i++)
                        for (j = i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                                printf("swapping v[%d] and v[%d]\n",j,j+gap);
                                temp = v[j];
                                v[j] = v[j+gap];
                                v[j+gap] = temp;
                        }
        }
}

int main(int argc, char *argv[]){
        srand(time(NULL));
        
        int i,arr[MAX];
        for (i =0; i< MAX; i++)
                arr[i]=rand()%65537 ;
        //arr[i]=i+4096*32767%65537;
        
        if (argc < 1){
                printf("for no reason you have to include  an argument with this\n");
                exit(EXIT_FAILURE);
        }
        FILE *stream;
        char *line = NULL;
        size_t len=0;
        ssize_t read;

        stream = fopen(argv[1] , "r") ;
        if(stream ==NULL)
                exit(EXIT_FAILURE);
        while((read = getline(&line, &len, stream)) != -1){
                /* read a line, break into integers , and fill an array */
                //shellsort(arr,MAX);
                //printf("sorted array\n");
                //show(arr, sizeof(arr)/sizeof(arr[0]));
                printf("%s\n",line);
        }
        show(arr, sizeof(arr)/sizeof(arr[0]));
        shellsort(arr,MAX);
        printf("sorted array\n");
        show(arr, sizeof(arr)/sizeof(arr[0]));

        free(line);
        fclose(stream);
        exit(EXIT_SUCCESS);
}
