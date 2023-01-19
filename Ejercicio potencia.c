#include <stdio.h>
#include <stdlib.h>

unsigned long POTENCIA (unsigned long, unsigned long);

int main(){

    unsigned long i = 0, j = 0;
    printf("\n\t Ingrese un numero entero positivo y su exponente: ");
    scanf("%lu %lu", &i, &j);

    POTENCIA (i, j);
    printf("\n\t El resultado es: %lu", POTENCIA(i, j));
}

unsigned long POTENCIA (unsigned long I, unsigned long J){

        unsigned long VUELTAS, RESULTADO = 0, EXPONENTE = I;
        for (VUELTAS = 1; VUELTAS < J; VUELTAS++){
                I = (I * EXPONENTE);
                RESULTADO = I;
        }
        return RESULTADO;
}



