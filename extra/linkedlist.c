/*
    file: linkedlist.c :
    An implementation of singley linkedlist of integers.
    Complexity: O(n)  for insert , delete, print , search , access
    Resources:
            http://www.cs.bu.edu/teaching/c/linked-list/delete/
            https://en.wikipedia.org/wiki/C_dynamic_memory_allocation

 */

#include<stdio.h>
#include<stdlib.h>


struct node {
        int x;
        struct node *next;
};

/* Helper function to allocation the correct size of memory */
struct node *nalloc(void);
struct node *nalloc(void){
        return(struct node *) malloc(sizeof(struct node));
}

struct node * insert(struct node *, int);
void printList( struct node* p);
struct node * deleteAll( struct node*p);
struct node * search( struct node *p , int num);
struct node * access(struct node *p, int num, int change);
struct node * delete( struct node *p, int num); 
int main(){
        struct node *list;
        list=NULL;
 
        int i;
        int num1=25;
        for (i=0 ; i <15;i++ , num1+=15)
                list=insert(list,num1);
        printlist(list);
        
        search(list, 190);
        access(list,190, 15);
        printlist(list);
        search(list,22);
        delete(list,235);
        printlist(list);
        list = deleteAll(list);
        printlist(list);
        return 0;
}


struct node * insert(struct node * nd, int num){
        /* if head is NULL then insert element */
        //printf("calling insert\n");
        if (nd ==NULL){
                nd = nalloc();
                nd->x=num;
                nd->next=NULL;
                /* else call insert until next is null */
        } else{
                //printf("root not null\n");
                nd->next=insert(nd->next,num);
        }
        return nd;
}


void printlist( struct node *p){
        //printf("calling printlist\n");
        if (p==NULL)
                return;
        if (p != NULL){
                printf("Element = %4d\n", p->x); 
                printlist(p->next);
        }
}

struct node * deleteAll( struct node*p){
        //printf("calling delete all\n");
        if (p==NULL)
                return NULL;
         // if a node has a next call delete on next 
        if ( p->next != NULL){
                //printf("calling delete on next\n");
                struct node * tmp;
                tmp = p->next;
                deleteAll( tmp);
        }
       // delete the node
       // printf("deleting node\n");
        p->next = NULL;
        free(p);        
        //p = NULL;
        return NULL;
        
}

struct node * delete( struct node *p, int num){
        //printf("calling delete \n");
        if (p==NULL)
                return NULL;
        if (p->x == num){
                struct node * tmp;
                tmp = p->next;
                free(p);
                /* return the next of deleted node yeehaaw */
                return tmp;
        }
        p->next = delete(p->next,num);
        return p;
}

struct node * search( struct node *p , int num){
        printf("calling search \n");
        while (p!=NULL && p->x != num && p->next!=NULL)
                p= p->next;
        
        if ( p!=NULL && p->x == num){
                printf("found x = %d\n", num);
                return p;
        }
        printf("p == NULL p= end of list \n");
        printf("didn't find the x\n");
        return p;        
}

struct node * access(struct node *p, int num, int change){
        printf("access num:%d change:%d \n", num,change);
        p = search(p,num);
        if (p ==NULL)
                insert(p,change);
        else
                p->x = change;
        return p;
}
