#include <stdio.h>
#include <stdlib.h>

int main(){

        char car;
        FILE * fp;
        FILE * desencript;

        fp = fopen("textoencriptado.txt","r");
        desencript = fopen ("textodesencriptado.txt","w");

        for(car = getc(fp); car != EOF;){
            car -= 5;
            putc(car, desencript);
            car = getc(fp);
        }

        fclose(fp);
        fclose(desencript);
        printf("\n\n\n");
        return 0;
}
