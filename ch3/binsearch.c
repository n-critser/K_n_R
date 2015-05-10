#include<stdio.h>
#define MAX 50

/* search for x in array v of size n*/
int binsearch(int x, int v[], int n);

int main(){

        int arr[MAX],i,search,result;
        search = 993;
        for (i=0;i<MAX;i++){
                arr[i]=1+i*31;
        }
        for (i=0;i<MAX;i++){
                printf("%d%c", arr[i],(i<MAX-1?',':'\n'));
        }
        result=binsearch(search,arr,MAX);
        printf("found: %d at arr[%d]\n",search,result);
        return 0;
}


int binsearch(int x, int v[], int n){
        int low, high, mid;
        low =0;
        high = n-1;
        while (low <= high){
                mid = (high+low)/2;
                if (x ==v[mid])
                        return mid;
                else if (x < v[mid])
                        high = mid-1;
                else
                        low=mid+1;
        }
        return -1;
        

}
