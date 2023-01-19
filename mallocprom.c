#include <stdio.h>
#include <stdlib.h>

int main(){

        int cant, i, *p;
        float acum = 0, promedio;

        printf("\n\n cuantos numeros desea ingresar?\t");
        scanf("%d", &cant);

        p = malloc(cant * sizeof(int));

        printf("\n\n ingrese los numeros a continuacion");
        for (i = 0; i < cant; i++){
            printf("\n");
            scanf("%d", p+i);
            acum += *(p+i);
        }

        promedio = acum / cant;
        printf("\n\n el promedio es  : %.2f", promedio);

        free(p);
        printf("\n\n\n");
        return 0;
}
