#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define dprint(expr) printf(#expr " = %g\n", expr)

#define MAX 33

void nqsort(int v[], int left, int right);
void show(int v[], int n);
void show( int v[], int n){
        int i;
        for(i =0; i<n;i++)
                printf("%d%c",v[i],(i<n-1)?',':' ');
        printf("Lenght of array: %d\n\n",n);
}


int main(void){
        srand(time(NULL));
        int i,arr[MAX];
        for (i =0; i< MAX; i++)
                arr[i]=rand()%257 ;
                //arr[i]=rand()%65537 ;
        //arr[i]=i+4096*32767%65537;
        show(arr,MAX);
        nqsort(arr,0,MAX);
        show(arr, MAX);

        return 0;
}




void nqsort(int v[], int left, int right){

        int i, last;
        void swap(int v[], int i, int j);

        if( left >=right)
                return;
        swap(v,left,(left+right)/2);
        last = left;
        printf("last=left=%d\n",left);
        printf("right=%d\n",right);
        for(i = left+1; i<=right; i++){
                if (v[i] < v[left])
                        swap(v, ++last,i);
        }
        swap(v,left,last);
        nqsort(v,left,last-1);
        nqsort(v,last+1,right);
}

void swap(int v[], int i, int j){
        //if (i == j)
        //        return;
        int temp;
        printf("swapping:v[%d]: %d with v[%d]:%d\n",i,v[i],j,v[j]);
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;

}
