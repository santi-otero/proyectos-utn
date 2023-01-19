/* ORDENAMIENTO DEL INDICE */

#include <stdio.h>
#include <stdlib.h>


struct indice{

        short int art;
        int pos;

};


int main (){

        FILE * fp;
        struct indice x, y;
        int i, j;

        if ((fp = fopen("BDINDICE", "r+b")) == NULL){
            printf("\n\t error al abrir indice");
            exit (1);
        }

        fseek(fp, 0, SEEK_END);

        for(i = 0; i < (ftell(fp)/sizeof(x)) - 1; i++){
            for(j = 0; j < (ftell(fp)/sizeof(x)) - i - 1; j++){
                fseek(fp, j*sizeof(x), SEEK_SET);
                fread(&x, sizeof(x), 1, fp);
                fread(&y, sizeof(x), 1, fp);
                if(x.art > y.art){
                    fseek(fp, j*sizeof(x), SEEK_SET);
                    fwrite(&y, sizeof(x), 1, fp);
                    fwrite(&x, sizeof(x), 1, fp);
                }
                fseek(fp, 0, SEEK_END);
            }
        }

        fclose(fp);
        printf("\n\n\n\n");
        return 0;
}
