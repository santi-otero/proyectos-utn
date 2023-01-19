#include <stdio.h>
#include <stdlib.h>

struct alumno{

        char nom[20];
        char sexo;
        float promedio;
};

int main(){

        int cant, i;
        float acum = 0;
        struct alumno * p;

        printf("\n cuantos alumnos hay en el curso?\t");
        scanf("%d", &cant);

        p = malloc(cant * sizeof(struct alumno));

        for(i = 0; i < cant; i++){
            fflush(stdin);
            printf("\n Nombre  : ");
            gets((p+i)->nom);
            printf("\n Sexo  : ");
            scanf("%c", &(p+i)->sexo);
            printf("\n Promedio  : ");
            scanf("%f", &(p+i)->promedio);
        }

        for(i = 0;  i < cant; i++)
            acum += (p+i)->promedio;

        acum = acum/(float)cant;
        printf("\n\n el promedio de todos los alumnos es  : %.2f", acum);

        free(p);
        printf("\n\n\n");
        return 0;
}
