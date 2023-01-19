#include <stdio.h>
#include <stdlib.h>

struct alumno {

        int legajo;
        char nombre[30];
        float promedio;


};

int main(){

        int i, cant;
        struct alumno *p, *q;

        printf("\nCuantos alumnos hay en el curso?  ");
        scanf("%d", &cant);

        p = malloc(cant * sizeof(struct alumno));
        q = p;

        for(i = 0; i < cant; i++){
            fflush(stdin);
            printf("\nLegajo  : ");
            scanf("%d", &((p+i)->legajo));
            fflush(stdin);
            printf("\nNombre  : ");
            gets(p[i].nombre);
            printf("\nPromedio  : ");
            scanf("%f", &((p+i)->promedio));
        }

        printf("\n\n\n");

        for(i = 0; i < cant; i++){
            puts((p+i)->nombre);
            if(((p+i)->promedio) > (q->promedio))
                q = (p+i);
        }

        printf("\n\nEl mejor promedio es %s con %.2f", q->nombre, q->promedio);

        free(p);
        printf("\n\n\n");
        return 0;
}
