#include <stdio.h>
#include <stdlib.h>

struct venta {

        char vendedor [60];
        float monto;
        int codigoprovincia;
};


int main(int argc, char * argv[]){

        FILE * fv;
        FILE * txt;
        struct venta z;
        int cod;

        if((fv = fopen("VENTA","rb")) == NULL){
            printf("\n\t error al abrir archivo de ventas");
            exit(1);
        }

        if((txt = fopen("MONTOS.TXT","w")) == NULL){
            printf("\n\t error al abrir archivo de montos");
            exit(1);
        }

        if(argc != 2)
            printf("\n\n INGRESO INCORRECTO, INGRESE UN CODIGO DE PROVINCIA");


        cod = atoi(*(argv+1));

        fread(&z, sizeof(z), 1, fv);
        printf("%d, %d \n", cod, z.codigoprovincia);
        while (!feof(fv)){
             printf("%d, %d \n", cod, z.codigoprovincia);

             if(cod == z.codigoprovincia){
                 fprintf(txt, "%.2f \n", z.monto);
             }

             fread(&z, sizeof(z), 1, fv);
        }


        fclose(txt);
        fclose(fv);
        printf("\n\n\n\n\n");
        return 0;
}
