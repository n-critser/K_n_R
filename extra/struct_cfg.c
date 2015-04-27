#include <stdio.h>

#define MAXSTACK 100


struct stack {
        int sp;
        int val[MAXSTACK];
};

void push(int f, struct stack * s1){
        printf("s1.sp = %d\n",s1->sp);
        if ((s1->sp) < MAXSTACK)
                (s1->val)[s1->sp++] = f;
        else
                printf("error: stack full, can't push %d\n",f);
}

int pop(struct stack *s1){
        printf("s1.sp = %d\n",s1->sp);
        if ((s1->sp) > 0)
                return (s1->val)[--s1->sp];
        else {
                printf ("error: stack empty\n");
                return 0;
        }
}

int main(){
        struct stack *stack1;
        stack1->sp=0;
        int result;
        push(1,stack1);
        push(5,stack1);
        result = pop(stack1);
        printf("result = %d\n",result);
        return 0;
        
}
