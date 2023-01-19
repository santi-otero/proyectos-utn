#include <stdio.h>
#include <stdlib.h>

int main(){

        char car;
        FILE * fp;
        FILE * encript;

        fp = fopen("texto.txt","r");
        encript = fopen ("textoencriptado.txt","w");

        for(car = getc(fp); car != EOF;){
            car += 5;
            putc(car, encript);
            car = getc(fp);
        }

        fclose(fp);
        fclose(encript);
        printf("\n\n\n");
        return 0;
}
