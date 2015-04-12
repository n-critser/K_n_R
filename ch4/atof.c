#include <ctype.h>
#include <stdio.h>
double atof(char s[]){
        double val, power;
        int i, sign;
        /* skip white space  */
        for ( i = 0; isspace(s[i]); i++)
                ;
        /*set sign to value */
        sign = (s[i] == '-') ? -1 : 1;
        /*skip character for sign*/
        if (s[i] == '+' || s[i] == '-')
                i++;
        /*integer portion */
        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] -'0');
        /*skip the period */
        if (s[i] == '.')
                i++;
        /*decimal portion needs power of 10 to shift decimal in val */
        for (power = 1.0; isdigit(s[i]); i++){
                val = 10.0 * val + (s[i] - '0');
                power *=10;
                printf("val= %f , power= %f \n", val,power);
        }
        return sign * val/ power;
}


#define MAXLINE 100

int main(){
        double sum , atof(char []);
        char line[MAXLINE];
        int Ngetline(char line[], int max);

        sum = 0;
        while (Ngetline(line, MAXLINE ) >0){
                printf("\t%g\n", sum+=atof(line));
        }
        return 0;
}


int Ngetline(char s[], int lim){
        int c, i;
        i = 0;
        while (--lim > 0 && (c=getchar()) != EOF && c!= '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i ;
}
