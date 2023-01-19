/* archivos binarios */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno {

    char name [20];
    char sex;
    int age;
};

int main() {

        FILE * fp;
        struct alumno x;
        int encontrado;

        if((fp = fopen("DATABASE","r+b")) == NULL){
            printf("problema al abrir archivo");
            exit(1);
        }

        encontrado = 0;
        fread(&x, sizeof(x), 1, fp);
        while (!(feof(fp)) && !encontrado){
                if (strcmp("ANA", x.name) == 0){
                    strcpy(x.name, "SANDRA");
                    fseek(fp, -sizeof(x), SEEK_CUR);
                    fwrite(&x, sizeof(x), 1, fp);
                    fseek(fp, 0L, SEEK_CUR);
                    encontrado = 1;
                }

                fread(&x, sizeof(x), 1, fp);
        }

        fclose(fp);

        printf("\n\n\n");
        return 0;
}
