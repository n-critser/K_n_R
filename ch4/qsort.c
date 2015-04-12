/*qsort.c  sort v[left] ..v[right] into increasing order */
//#include <stdio.h>
void qsort(int v[], int left, int right){
        int i, last;
        void swap(int v[], int i, int j);

        if (left >= right) /*single element array */
                return;
        //printf ("left = %d : v[left] = %d\n", left, v[left]);
        swap(v, left, (left + right)/2); /*move partition to v[0] */
        //printf ("partition = %d : v[partition] = %d\n", (left+right)/2, v[left]);
        last = left; /* marker for end of unsorted left portion*/
        for ( i = left + 1; i <= right; i++){
                /* compare elements  */
                if( v[i] < v[left])
                        /* swap elements, increment  */
                        swap(v, ++last, i);
                //printf ("last = %d : v[last] = %d\n", last, v[last]);
        }
        swap(v, left, last);
        qsort(v, left, last-1);
        qsort(v, last+1, right);
}

/*swap */
void swap ( int v[], int i, int j){
        int temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}
