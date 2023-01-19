/* CARGA DE UN ARCHIVO BINARIO */

#include <stdio.h>
#include <stdlib.h>

struct alumno {

        char name[20];
        char sex;
        int age;
};

#define N 4

int main (){

        struct alumno x;
        FILE * fp;
        int i;

        if((fp = fopen("DATABASE","ab")) == NULL){
            printf("ERROR AL ABRIR ARCHIVO.");
            exit(1);
        }

        for (i = 0; i < N; i++){
                fflush(stdin);
                printf("\n\t NOMBRE  : ");
                gets(x.name);
                printf("\t SEXO    : ");
                x.sex = getchar();
                printf("\t EDAD    : ");
                scanf("%d", &(x.age));

                fwrite(&x, sizeof(x), 1, fp);
        }

        fclose(fp);

        printf("\n\n\n");
        return 0;
}
