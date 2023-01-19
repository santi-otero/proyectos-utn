/* WEST POINT */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
#define MAX_MAT 12

struct soldado {
        int legajo ;
        char nom[20] ;
        int nota[MAX_MAT] ;
        char disponible ;
};

void ingreso (struct soldado [], int);
void ordenar (struct soldado [], int, int);


int main(){

        struct soldado dato[MAX] ;
        int i, codigo, cantidad, vacantes = MAX ;

        /* INGRESO */
        ingreso(dato, MAX) ;

        while (vacantes){

            /* PEDIDOS */
            printf("\n\nIngrese codigo de asignatura preferencial   ");
            scanf("%d", &codigo);
            codigo--;
            printf("\n\nIngrese la cantidad de comandos solicitada   ");
            scanf("%d", &cantidad);

            /* ORDENAMIENTO */
            ordenar (dato, MAX, codigo);

            /* ASIGNACION */
            if(vacantes < cantidad){
                printf("NO ALCANZAN");
                vacantes = 0;
            }
            else
                vacantes -= cantidad;

            for(i = 0; (i < MAX) && cantidad; i++)
                if(dato[i].disponible){
                    dato[i].disponible = 0;
                    cantidad--;
                    printf("\n\t%d\t%20s\t%d", dato[i].legajo, dato[i].nom, dato[i].nota[codigo]);
                }
        }


        printf("\n\n\n");
        return 0;
}

void ingreso (struct soldado ficha[], int n){

        int i, j;
        srand(time(0));

        for(i = 0; i < n; i++){
            printf("\nLegajo  :  ");
            scanf("%d", &ficha[i].legajo);
            fflush(stdin);
            printf("\nNombre  :  ");
            gets(ficha[i].nom);
            printf("\nNotas   :  ");

            for(j = 0; j < MAX_MAT; j++)
                scanf("%d", &ficha[i].nota[j]);
            ficha[i].disponible = 1;
        }
}

void ordenar (struct soldado ficha[], int n, int codigo){

        int i, j;
        struct soldado aux;

        for(i = 0; i < n-1; i++)
            for(j = 0; j < n - i - 1; j++){
                if( ficha[j].nota[codigo] < ficha[j+1].nota[codigo]){
                    aux = ficha[j];
                    ficha[j] = ficha[j+1];
                    ficha[j+1] = aux;
                }
        }
}
