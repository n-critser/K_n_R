#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
/* KNR p.91 */

#define MAXLINES 5000
char *lineptr[MAXLINES];
// FIXME:  
int readlines(char *lineptrp[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void){
        int nlines;
        if ((nlines = readlines(lineptr, MAXLINES)) >=0){
                qsort(lineptr, 0 , nlines-1);
                writelines(lineptr,nlines);
                return 0;
        } else {
                printf("error: input too big to sort \n");
                return 1;
        }
}






int readlines(char *lineptr[], int maxlines){
        FILE *stream;
        int nlines;
        //char *p, line[maxlines];

        size_t len=0;
        ssize_t read;
        stream = fopen("intArray.txt","r");
        if(stream ==NULL)
               return -1;
        
        nlines=0;
        while((read = getline(&lineptr[nlines++],&len,stream))!= -1){
                printf("%s",(lineptr[nlines-1]));
                ;
        }
        printf("nlines=%d",nlines);
        return nlines;
}



void writelines(char *lineptr[], int nlines){
        int i;
        for (i=0; i<nlines; i++)
                printf("%s\n", lineptr[i]);
}


void qsort(char*v[], int left, int right){
        int i, last;
        void swap(char *v[], int i, int j);
        if (left >= right)
                return;
        swap(v, left, (left + right)/2);
        last = left;
        for ( i = left+1; i <=right; i++)
                if (strcmp(v[i], v[left]) < 0)
                        swap(v, ++last, i);
        swap(v, left,last);
        qsort(v, left, last-1);
        qsort(v,last+1,right);
}

void swap (char *v[], int i, int j){
        char *temp;
        temp = v[i];
        v[i] = v[j];
        v[j]=temp;
}
