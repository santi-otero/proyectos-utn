#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]){

        float tempk = 0, tempc = 0, tempf = 0;

        if(argc > 3 || argc < 3)
            printf("\n\t Cantidad de argumentos incorrecta");

        if(argc == 3){
            if(strcmpi(*(argv+2), "C") == 0){
                tempk = atof(*(argv+1)) + 273.15;
                tempf = atof(*(argv+1)) + 32;
                printf("\n\t Temperatura en Kelvin: %.1f \n\t Temperatura en Fahrenheit: %.1f", tempk, tempf);
            }
            if(strcmpi(*(argv+2), "F") == 0){
                tempk = atof(*(argv+1)) + 255.372;
                tempc = atof(*(argv+1)) - 17.7778;
                printf("\n\t Temperatura en Kelvin: %.1f \n\t Temperatura en Celsius: %.1f", tempk, tempc);
            }
            if(strcmpi(*(argv+2), "K") == 0){
                tempf = atof(*(argv+1)) - 459.67;
                tempc = atof(*(argv+1)) - 273.15;
                printf("\n\t Temperatura en Fahrenheit: %.1f \n\t Temperatura en Celsius: %.1f", tempf, tempc);
            }
        }

        printf("\n\n");
        return 0;
}
