#include<stdio.h>
#include<ctype.h>

/* linked list used in the hash table*/
struct nlist{
        struct nlist *next;  /* pointer to the next element in the list*/
        char *name;          /* defined name */
        char *defn;          /* replacement text */
};


#define HASHSIZE 101 /* Prime enough 101 */

static struct nlist *hashtab[HASHSIZE]; /* pointer hashtable */

/* hash: create the hash value by scramble add of char values
   unsigned ensure a non-negative value
   returns hashval % HASHSIZE ( reason for 101 and not 100)
*/
unsigned hash( char *s){
        unsigned hashval;
        for (hashval = 0; *s != '\0'; s++)
                hashval = *s + 31 * hashval;
        return hashval % HASHSIZE;
}


/* lookup: find s in hashtable */
struct nlist * lookup(char *s){
        int strcmp(char *,char*);
        //printf("entering lookup\n");
        struct nlist *np;
        /* set np = to the hashtable value and walk the linked list */
        for (np = hashtab[hash(s)]; np != NULL; np = np->next)
                if (strcmp( s,np->name) ==0){
                        return np; /* found s */
                        printf ("found s\n");
                }
        return NULL;
}


struct nlist *lookup(char *);
char * strdup(char *);

/* install: insert (name, defn) into hashtable */
struct nlist *install(char *name, char *defn){
        //printf("entering install\n");
        struct nlist *np;
        unsigned hashval;

        if ((np = lookup(name)) ==NULL) { /* not found */
                /* get the memory for the size of an nlist */
                np = (struct nlist *) malloc(sizeof(*np));
                if (np == NULL || (np->name = strdup(name)) ==NULL)
                        return NULL;
                hashval = hash(name);
                np->next = hashtab[hashval];
                hashtab[hashval] = np;
        } else /* name is already there */
                free ((void *) np->defn); /* free previous defn*/
        if ((np->defn = strdup(defn)) == NULL)
                return NULL;
        return np;
}


int main (){
        char *words[]={
                "hello",
                "mary",
                "lou",
                "good",
                "bye",
                "heart",
        };
        int i;
        struct nlist *result;
        int count = sizeof (words)/sizeof(char *);
        printf ("count = %d\n",count);
        for ( i=0; i < count ;i++)
                install(words[i], words[i]);
        printf ("words added now trying to get the result\n");
        for ( i=0; i < count ;i++){
                if ((result= lookup(words[i])) != NULL)
                        printf("found: %s \n", result->defn);//

                //result = NULL;
        }

        return 0;

}
