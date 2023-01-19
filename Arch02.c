#include <stdio.h>
#include <stdlib.h>

int main(){

        char car;
        FILE * fp;
        FILE * dupli;

        fp = fopen("texto.txt","r");
        dupli = fopen("textoduplicado.txt","w");

        car = getc(fp);
        while(car != EOF){
            putc(car, dupli);
            car = getc(fp);
        }


        fclose(fp);
        fclose(dupli);
        printf("\n\n\n");
        return 0;
}
