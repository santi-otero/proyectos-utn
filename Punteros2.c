/* PUNTEROS A ESTRUCTURAS Y PASAJE A FUNCION */

#include <stdio.h>

struct fecha{

        int dia;
        int mes;
        int anio;
};

void corregir (struct fecha *);

int main(){

        struct fecha hoy;
        int i;

        printf("\n\n\t\t");
        scanf("%d/%d/%d", &hoy.dia, &hoy.mes, &hoy.anio);

        corregir (&hoy);

        printf("\n\n\t\t%02d/%02d/%d", hoy.dia, hoy.mes, hoy.anio);

        printf("\n\n\n");
        return 0;
}

void corregir (struct fecha *p){

        if(p->dia == 29 && p->mes == 2){
            p->dia = 1;
            p->mes = 3;
        }
}
