#include<stdio.h>

main(){
        float fahr, celsius;
        float lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;
        printf("Fahr\t:\tCelsius\n");
        while (fahr <= upper){
                celsius = (5.0/9.0) * (fahr -32.0) ;
                printf("%3.0f\t %6.1f \n", fahr, celsius);
                fahr = fahr + step;
        }
        printf("Fahr\t:\tCelsius\n");
        for( fahr = 0.0; fahr <=300.0; fahr=fahr+20.0){
                printf("%3.0f \t %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
        }
        
}
