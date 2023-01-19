/* PRUEBA DE ARGUMENTOS DEL MAIN CON ATOI */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]){

        int i;

        for(i = 0; i < atoi(argv[1]); i++)
            printf("\n\t %s", *(argv+2));

        printf("\n\n\n");
        return 0;
}
