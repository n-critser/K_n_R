#include<stdio.h>

struct point {
        int x;
        int y;
};


struct rect {
        struct point pt1;
        struct point pt2;
};

struct point makepoint(int x, int y){
        struct point temp;
        temp.x = x;
        temp.y = y;
        return temp;
}

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r){
        struct rect temp;
        temp.pt1.x = min(r.pt1.x, r.pt2.x);
        temp.pt1.y = min(r.pt1.y, r.pt2.y);
        temp.pt2.x = max(r.pt1.x, r.pt2.x);
        temp.pt2.y = max(r.pt1.y, r.pt2.y);
        return temp;
}

int main(){
        struct rect box;
        box.pt2=makepoint(0,0);
        box.pt1=makepoint(4,4);

        
        printf ("%d, %d\n", box.pt1.x,box.pt1.y);
        printf ("%d, %d\n", box.pt2.x,box.pt2.y);

        struct rect canon_box;
        canon_box = canonrect(box);
        printf ("%d, %d\n", box.pt1.x,box.pt1.y);
        printf ("%d, %d\n", box.pt2.x,box.pt2.y);
        printf ("%d, %d\n", canon_box.pt1.x,canon_box.pt1.y);
        printf ("%d, %d\n", canon_box.pt2.x,canon_box.pt2.y);
        return 0;
}
