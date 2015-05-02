#include<stdio.h>
main(){
        float fahr, celsius;
        float lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;
        /*while (fahr <= upper){
                celsius = (5.0/9.0) * (fahr -32.0) ;
                printf("%3.0f\t %6.1f \n", fahr, celsius);
                fahr = fahr + step;
        }
        */
        for( celsius = 0.0; celsius <=300.0; celsius=celsius+20.0){
                printf("%3.0f \t %6.1f\n", celsius, ((celsius *(5.0/9.0)+32)));
        }
        
}
