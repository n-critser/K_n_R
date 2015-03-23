#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "bTree.h"

/*
   File: binTree.c -- K & R Section 6.5 Self-referential Structures
   =====================================================================
   Compile: gcc binTree.c getch.c
   Input:  enter words on the console then EOF to stop.
   Output: the sorted order (binary tree)  with counts for each word 
   Linux EOF ==  Ctrl-d
   Hit Ctrl-d any where in the string to send the end signal to getword()
 */

struct tnode {
        char *word;
        int count;
        struct tnode *left;
        struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint( struct tnode*);
int getword(char *, int);

int main(){

        struct tnode *root;
        char word[MAXWORD];

        root = NULL;
        while (getword(word, MAXWORD) != EOF  )
                if (isalpha(word[0])){
                        root = addtree(root,word);
                }
        treeprint(root);
        return 0;
}

int getword(char *word, int lim){
        int c, getch(void);
        void ungetch(int);
        char *w = word;
        while (isspace (c = getch()))
                ;
        if (c != EOF)
                *w++=c;
        /*This should be EOF */
        if (!isalpha(c)){
                *w = '\0';
                return c;
        }
        for (; --lim > 0; w++)
                if (!isalnum(*w = getch())){
                        ungetch(*w);
                        break;
                }
        *w = '\0';
        return c;      
}


struct tnode *talloc(void);
char *Tstrdup(char *s);

struct tnode *addtree(struct tnode *p, char *w){
        int cond;

        if (p==NULL){
                p = talloc();
                p->word=strdup(w);
                p->count =1;
                p->left = p->right = NULL;
        } else if ((cond = strcmp(w,p->word))==0)
                p->count++;
        else if (cond <0)
                p->left = addtree(p->left, w);
        else
                p->right = addtree(p->right,w);
        return p;
}


void treeprint( struct tnode *p){
        if (p != NULL){
                treeprint(p->left);
                printf("%4d %s\n", p->count, p->word);
                treeprint(p->right);
        }
}

#include <stdlib.h>
struct tnode *talloc(void){
        return (struct tnode *) malloc(sizeof(struct tnode));
}

char *Tstrdup(char *s){
        char *p;
        p = (char *) malloc(strlen(s)+1);
        if( p!= NULL)
                strcpy(p,s);
        return p;
}
