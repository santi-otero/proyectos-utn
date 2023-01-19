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
        short int flag = 0, abuscar;

        if ((fp = fopen("BDARTICULOS", "rb")) == NULL){
            printf("\n\t error al abrir archivo");
            exit (1);
        }

        printf("\n\t ingrese numero de articulo a buscar  : ");
        scanf("%d", &abuscar);

        fread(&x, sizeof(x), 1, fp);

        while (flag == 0 && (!feof(fp))){
                if(x.art == abuscar){
                    printf("\n\n%d \t %15s \t %s \t %s \t %d",
                    x.art, x.cod, x.desc, x.fabri, x.stock);

                    flag = 1;
                }
                fread(&x, sizeof(x), 1, fp);
        }
        if(flag == 0)
            printf("\n\t el articulo solicitado no se encuentra en la base de datos");

        fclose(fp);
        printf("\n\n\n\n");
        return 0;
}
