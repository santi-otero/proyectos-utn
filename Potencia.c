#include <stdio.h>
#include <stdlib.h>

long POTENCIA (long, long);

int main (int argc, char * argv[]){


        printf("\n\t %lu", POTENCIA (atol(*(argv+1)), atol(*(argv+2))));

        printf("\n\n");
        return 0;
}

long POTENCIA (long I, long J){

        long VUELTAS, RESULTADO = 0, EXPONENTE = I;

        for (VUELTAS = 1; VUELTAS < J; VUELTAS++){
                I = (I * EXPONENTE);
                RESULTADO = I;
        }

        return RESULTADO;
}
