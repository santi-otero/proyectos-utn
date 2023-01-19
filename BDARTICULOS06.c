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
        struct arti z;
        struct indice x;
        int bajo, alto, med, flag = 0;
        short int abuscar;

        if ((fp = fopen("BDARTICULOS", "rb")) == NULL){
            printf("\n\t error al abrir archivo");
            exit (1);
        }

        if ((index = fopen("BDINDICE", "rb")) == NULL){
            printf("\n\t error al abrir indice");
            exit (1);
        }

        while (flag == 0){

            fseek(index, 0, SEEK_END);
            bajo = 0;
            alto = ((ftell(index)/sizeof(x)) - 1);
            printf("\t\n ingrese numero de articulo : \t");
            scanf("%d", &abuscar);

            while(bajo <= alto){
                med = (bajo+alto)/2;

                fseek(index, med*sizeof(x), SEEK_SET);
                fread (&x, sizeof(x), 1, index);

                if(x.art == abuscar){
                    fseek(index, med*sizeof(x), SEEK_SET);
                    fread(&x, sizeof(x), 1, index);
                    flag = 1;
                    fseek(fp, (x.pos)*sizeof(z), SEEK_SET);
                    fread(&z, sizeof(z), 1, fp);
                    printf("\n\n%d \t %15s \t %s \t %s \t %d",
                        z.art, z.cod, z.desc, z.fabri, z.stock);
                }

                if(abuscar < x.art)
                    alto = med - 1;
                else
                    bajo = med + 1;
            }

                if(flag == 0)
                    printf("\n\t El articulo no se encuentra en la base de datos.\n");
        }

        fclose(fp);
        fclose(index);
        printf("\n\n\n\n");
        return 0;
}
