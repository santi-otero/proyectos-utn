#include <stdio.h>
#include <stdlib.h>


struct arti{

        short int art;
        char cod[50];
        char desc[100];
        char fabri[50];
        short int stock;

};

int main (){

        FILE * fp;
        struct arti x;

        if ((fp = fopen("BDARTICULOS", "rb")) == NULL){
            printf("\n\t error al abrir archivo");
            exit (1);
        }

        printf("\n%s \t %s \t %s \t\t %20s \t\t %s", "ARTICULO","CODIGO","DESCRIPCION","FABRICANTE","STOCK");

        fread(&x, sizeof(x), 1, fp);
        while (!feof(fp)){

            printf("\n\n%d \t %15s \t %s \t %s \t %d",
                    x.art, x.cod, x.desc, x.fabri, x.stock);

            fread(&x, sizeof(x), 1, fp);
        }


        fclose(fp);
        printf("\n\n\n  FIN DEL ARCHIVO \n\n\n");
        return 0;
}
