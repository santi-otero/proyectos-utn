/* LECTURA DE UN ARCHIVO BINARIO */

#include <stdio.h>
#include <stdlib.h>

struct alumno {

        char name[20];
        char sex;
        int age;
};

int main(){

        struct alumno x;
        FILE * fp;


        if((fp = fopen("DATABASE", "rb")) == NULL){
            printf("ERROR AL ABRIR ARCHIVO.");
            exit(1);
        }

        printf("\n\t %-20s %10s %10s\n", "NOMBRE", "SEXO", "EDAD");

        fread(&x, sizeof(x), 1, fp);
        while (!(feof(fp))){
                printf("\n\t %-20s %10c %10d",
                        x.name, x.sex, x.age);

                fread(&x, sizeof(x), 1, fp);
        }

        fclose(fp);

        printf("\n\n\n");
        return 0;
}
