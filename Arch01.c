#include <stdio.h>
#include <stdlib.h>

int main(){

        char car;
        FILE * FP;

        if((FP = fopen("texto.txt", "w")) == NULL){
            printf("\n Error al iniciar el archivo.");
            exit(1);
        }

        car = getchar();
        while (car != '$'){
            putc(car, FP);
            car = getchar();
        }

        fclose(FP);
        printf("\n\n\n");
        return 0;
}
