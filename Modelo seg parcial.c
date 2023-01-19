#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAMIONES 4

struct fecha {

        int dia;
        int mes;
        int anio;
};

struct viajecamion {

        char patente[10];
        char ciudad_origen[50];
        char ciudad_destino[50];
        float peso_transportado;
        struct fecha fecha_viaje;
};

int ingresar (struct viajecamion [], int);
void mostrar_patentes (struct viajecamion [], int);
void mas_viajes (struct viajecamion [], int);
void ordenar (struct viajecamion [], int);

int main (){

        struct viajecamion dato[CAMIONES];

        ingresar (dato, CAMIONES);
        mostrar_patentes(dato, CAMIONES);



        printf("\n\n\n");
        return 0;
}

int ingresar (struct viajecamion ficha[], int n){

        int i, flag, cont = 0;

        printf("\n\n\tINGRESE LOS VIAJES QUE DESEE PARA 4 CAMIONES\n\n");

        for(i = 0; i < n; i++){
            printf("\n\nIngrese patente del camion  : ");
            gets(ficha[i].patente);
            printf("\nCiudad de origen  : ");
            gets(ficha[i].ciudad_origen);
            printf("\nCiudad de destino : ");
            gets(ficha[i].ciudad_destino);
            printf("\nPeso transportado (en Tn) : ");
            scanf("%f", &ficha[i].peso_transportado);
            fflush(stdin);
            printf("\nFecha del viaje (formato dd/mm/aaaa) : ");
            scanf("%d/%d/%d", &ficha[i].fecha_viaje.dia, &ficha[i].fecha_viaje.mes, &ficha[i].fecha_viaje.anio);
            fflush(stdin);
            cont++;
            printf("\nSi ya termino de ingresar viajes para este camion, ingrese -1, si desea continuar ingrese 1 : ");
            scanf("%d", &flag);
            fflush(stdin);
           }

        return cont;
}

void mostrar_patentes (struct viajecamion ficha[], int n){

        int i;

        printf("\n\n\tPATENTES DE CAMIONES");
        for(i = 0; i < n; i++)
            printf("\nPatente camion %d  : %s", i+1, ficha[i].patente);
}
