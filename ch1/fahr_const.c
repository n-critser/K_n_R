#include<stdio.h>

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

main(){
        float fahr, celsius;
        fahr = LOWER;
        printf("FAHR_CONST\n");
        printf("Fahr\t:\tCelsius\n");
        while (fahr <= UPPER){
                celsius = (5.0/9.0) * (fahr -32.0) ;
                printf("%3.0f\t %6.1f \n", fahr, celsius);
                fahr = fahr + STEP;
        }
        printf("FAHR_CONST\n");        
        printf("Fahr\t:\tCelsius\n");
        for( fahr = LOWER; fahr <=UPPER; fahr=fahr+STEP){
                printf("%3.0f \t %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
        }
        
}
