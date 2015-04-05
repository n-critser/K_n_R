#include <stdio.h>
#include <ctype.h> /*access to isalnum , isalpha, isspace */
#include <string.h>
#include "getch.h"
#define MAXWORD 100

/*
   File: wordTablePointer.c -- K & R Section 6.4 Pointers to Structures
   =====================================================================
   Compile: gcc wordTablePointer.c getch.c
   Input:  enter words on the console then EOF to stop.
   Output: A list of keywords and their counts
   This program depends on the keytab table of keywords being placed
   in sorted order before hand. Otherwise binsearch wont function properly.
   EX: Add sorting so keytab can be in any order 
   EX: Add underscore, comments  and preprocessor calls to getword 
   Linux EOF ==  Ctrl-d
   Hit Ctrl-d any where in the string to send the end signal to getword()
 */


/* key: gives us 2 variable members
   keytab: creates an array of keys like an associated array 
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
struct key * binsearch(char *, struct key*, int);

/* */
int main() {
        
        char word[MAXWORD];

        /* pointer to a key instance  */
        struct key *p;
        /* getwords until EOF  comes */
        while (getword(word, MAXWORD) !=EOF)
                /* for alphabetic words search the array of key words */
                if (isalpha(word[0]))
                        /* if the keyword is found then increment its count*/
                        if ((p=binsearch(word,keytab,NKEYS)) !=NULL)
                                p->count++;
        /* pointer math instead of indexing */
        for (p  = keytab; p< keytab + NKEYS; p++)
                if (p->count > 0)
                        printf("%4d %s\n", p->count, p->word);
        return 0;
}

/* binary search: find word between tab[0] to tab[n-1] */
struct key * binsearch ( char * word, struct key *tab, int n){

        int cond;
        struct key *low = &tab[0];
        struct key *high= &tab[n]; /* tab[n] is a valid pointer address!  */
        struct key *mid;

        /* cut the table in half till you find the word or fail */
        while (low < high){
                /* you can not add pointers to get an integer
                   but you can subtract them
                   parens added to show order of operations
                   low + x (adds the right amount of memory addresses to
                            get the middle element in array )
                */
                mid = low + ((high - low)/ 2);
                if ((cond = strcmp(word, mid->word)) < 0)
                        high = mid;
                else if (cond > 0)
                        low = mid+1;
                else
                        //printf("found a word");
                        return mid;
        }
        /* if you don't find the word return NULL */
        //printf ("didn't find a word");
        return NULL;
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
