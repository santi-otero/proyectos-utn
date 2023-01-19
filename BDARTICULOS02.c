#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arti{

        short int art;
        char cod[50];
        char desc[100];
        char fabri[50];
        short int stock;

};

int main(){

        FILE * fp;
        struct arti x, *p;
        char proveedor[50];
        int cont, cant, max, i;
        long n;

        if ((fp = fopen("BDARTICULOS", "rb")) == NULL){
            printf("\n\t error al abrir archivo");
            exit (1);
        }

        fseek(fp, 0, SEEK_END);
        n = ftell(fp);
        p = malloc (n);

        fseek(fp, 0, SEEK_SET);
        fread(&x, sizeof(x), 1, fp);
        for(i = 0; !feof(fp); i++){

            (p+i)->art = x.art;
            strcpy((p+i)->cod, x.cod);
            strcpy((p+i)->desc, x.desc);
            strcpy((p+i)->fabri, x.fabri);
            (p+i)->stock = x.stock;

            fread(&x, sizeof(x), 1, fp);
        }
        fclose(fp);

        cant = 0;
        cont = 0;
        max = 0;

        while(cont < (n/sizeof(x))){

            for(i = 0; i < cont; i++){
                if((strcmpi((p+cont)->fabri, (p+i)->fabri)) == 0){
                    cant++;
                    if(cant > max){
                        max = cant;
                        strcpy(proveedor, (p+cont)->fabri);
                    }
                }
            }
            cant = 0;
            cont++;
        }

        printf("\t\n El proveedor que mas articulos suministra es :  %s", proveedor);

        free(p);
        printf("\n\n\n");
        return 0;
}

