#include <stdio.h>
#include <ctype.h> /*access to isalnum , isalpha, isspace */
#include <string.h>
#include "getch.h"
#define MAXWORD 100

/*
   File: wordTable.c -- K & R Section 6.3 Self-referential Structures
   =====================================================================
   Compile: gcc wordTable.c getch.c
   Input:  enter words on the console then EOF to stop.
   Output: A list of keywords and their counts
   This program depends on the keytab table of keywords being placed
   in sorted order before hand. Otherwise binsearch wont function properly.
   EX: Add sorting so keytab can be in any order 
   EX: Add underscore, comments  and preprocessor calls to getword 
   Linux EOF ==  Ctrl-d
   Hit Ctrl-d any where in the string to send the end signal to getword()
 */



struct key{
        char *word;
        int count;
} keytab[]= {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "define", 0,
        "else", 0,
        "for" , 0,
        "if" , 0,
        "include", 0,
        "int" , 0,
        "return", 0,
        "sizeof", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0
};

/* set the number of keys at compile time using the calculation
   of the size of the array divided by the size of one of the
   elements in the array. This allows for the size of the array
   to be changed without having to keep track of the value by
   hand. :)
*/
# define NKEYS (sizeof keytab / sizeof(struct key))


int getword(char *, int);
int binsearch(char *, struct key*, int);

int main() {
        int n;
        char word[MAXWORD];
        /* getwords until EOF  comes */
        while (getword(word, MAXWORD) !=EOF)
                /* for alphabetic words search the array of key words */
                if (isalpha(word[0]))
                        /* if the keyword is found then increment its count*/
                        if ((n=binsearch(word,keytab,NKEYS)) >=0)
                                keytab[n].count++;
        for (n = 0; n< NKEYS; n++)
                if (keytab[n].count > 0)
                        printf("%4d %s\n", keytab[n].count, keytab[n].word);
        return 0;
}

/* binary search on words in the table keytab */
int binsearch ( char * word, struct key tab[], int n){

        int cond;
        int low,high,mid;

        low = 0;
        high = n-1;
        /* cut the table in half till you find the word or fail */
        while (low <= high){
                mid = (low+high) / 2;
                if ((cond = strcmp(word, tab[mid].word)) < 0)
                        high = mid - 1;
                else if (cond > 0)
                        low = mid+1;
                else
                        return mid;
        }
        /* if you don't find the word return -1*/
        return -1;
}
                        
/* getword: get the next word or character from input
   return the value of the first char or EOF 
*/
int getword( char * word, int lim){
        int c, getch(void);
        void ungetch(int);
        char *w = word;
        /* skip white space */
        while (isspace( c= getch()))
                ;
        /* accept c if not end of file character */
        if (c !=EOF)
                *w++ = c;
        /* if c is not alphabetic then return the char */
        if (!isalpha(c)) {
                *w = '\0';
                return c;
        }
        /* start from the limit word size and count down
           while traversing the string upward
        */
        for ( ; --lim > 0; w++)
                /* if dereferenced w is not  alpha-numeric, unget and break  */
                if (!isalnum(*w = getch())) {
                        ungetch(*w);
                        break;
                }
        *w = '\0';
        return word[0];

}
