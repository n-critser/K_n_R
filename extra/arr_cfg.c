#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100


void push(int f,int  val[], int *sp){
        //printf(" stack f= %d\n",f);
        if (*sp < MAXSTACK){
                val[(*sp)++]= f;                
        }
        else
                printf("error: stack full, can't push %d\n",f);
}

int pop(int val[], int *sp){
        if (*sp > 0){
                //printf("*sp = %d\n",*sp);
                return val[--(*sp)];
        }
        else
             printf("error: stack empty, can't pop\n");
        return 0;
}   


int main(){
        int result;
        printf("what the f$!@\n");
        int val[MAXSTACK];
        int p=0;
        int *sp=&p;
        printf("*sp = %d\n",*sp);
        push (1,val,sp);
        push (5, val, sp);
        result = pop(val,sp);
        printf("result = %d\n",result);
        result = pop(val,sp);
        printf("result = %d\n",result);
        result = pop(val,sp);
        printf("result = %d\n",result);
        return 0;
}
