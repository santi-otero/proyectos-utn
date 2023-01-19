/* CREACION Y VISUALIZACION DEL INDICE */

#include <stdio.h>
#include <stdlib.h>


struct arti{

        short int art;
        char cod[50];
        char desc[100];
        char fabri[50];
        short int stock;

};

struct indice{

        short int art;
        int pos;

};


int main (){

        FILE * fp;
        FILE * index;
        struct arti x;
        struct indice z;
        int i;

        if ((fp = fopen("BDARTICULOS", "rb")) == NULL){
            printf("\n\t error al abrir archivo");
            exit (1);
        }

        if ((index = fopen("BDINDICE", "rb")) == NULL){
            printf("\n\t error al abrir indice");
            exit (1);
        }


        /*fread(&x, sizeof(x), 1, fp);
        for(i = 0; !feof(fp); i++){

            z.art = x.art;
            z.pos = i;
            fwrite(&z, sizeof(z), 1, index);


            fread(&x, sizeof(x), 1, fp);
        }

        printf("%s \t %s\n\n", "N ARTICULO", "POSICION");

        rewind(index); */
        fread(&z, sizeof(z), 1, index);
        while (!feof(index)){

            printf("\n%d \t\t %d", z.art, z.pos);

            fread(&z, sizeof(z), 1, index);
        }




        fclose(fp);
        fclose(index);
        printf("\n\n\n\n");
        return 0;
}
