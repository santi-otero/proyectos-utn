#include <stdio.h>
#include <stdlib.h>

struct venta {

        char vendedor [60];
        float monto;
        int codigoprovincia;
};

int main(){

        struct venta x;
        FILE * fp;


        if((fp = fopen("VENTA", "rb")) == NULL){
            printf("ERROR AL ABRIR ARCHIVO.");
            exit(1);
        }

        printf("\n\t %-20s %10s %10s\n", "VENDEDOR", "MONTO", "CODIGO");

        fread(&x, sizeof(x), 1, fp);
        while (!(feof(fp))){
                printf("\n\t %-20s %10.2f %10d",
                        x.vendedor, x.monto, x.codigoprovincia);

                fread(&x, sizeof(x), 1, fp);
        }

        fclose(fp);

        printf("\n\n\n");
        return 0;
}
