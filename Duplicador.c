#include <stdio.h>
#include <stdlib.h>

struct alumno {

        char name[20];
        char sex;
        int age;
};

int main(){

        struct alumno x;
        FILE * fp, *fpdupli;


        if((fp = fopen("DATABASE", "rb")) == NULL){
            printf("ERROR AL ABRIR ARCHIVO.");
            exit(1);
        }

        if((fpdupli = fopen("DATABASE3", "wb")) == NULL){
            printf("ERROR AL ABRIR ARCHIVO.");
            exit(1);
        }

        fread(&x, sizeof(x), 1, fp);
        while (!(feof(fp))){
                fwrite(&x, sizeof(x), 1, fpdupli);

                fread(&x, sizeof(x), 1, fp);
        }

        fclose(fp);
        fclose(fpdupli);

        printf("\n\n\n");
        return 0;
}
