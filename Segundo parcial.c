#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD 4

struct cancion {
	char nombre[50];
	char autor[50];
	int reproducciones[12];
};

void autores(struct cancion[], int);
void autor_totales(struct cancion[], int, char autor[]);

int main (){

        int i, j;
        srand(time(0));
        struct cancion playlist[CANTIDAD];
        char autor[50];

        for(i = 0; i < CANTIDAD; i++){
            printf("\n\nCancion  : ");
            gets(playlist[i].nombre);
            printf("\nAutor  : ");
            gets(playlist[i].autor);
            printf("\nReproducciones mensuales (en miles)  : ");
            for(j = 0; j < 12; j++){
                playlist[i].reproducciones[j] = 20 + rand() % 81;
                printf("%4d", playlist[i].reproducciones[j]);
            }
        }

        autores(playlist, CANTIDAD);

        printf("\n\nIngrese artista  : ");
        gets(autor);

        autor_totales(playlist, CANTIDAD, autor);


        printf("\n\n\n\n");
        return 0;
}

void autores (struct cancion lista[], int n){

        int i, j, flag;

        printf("\n\n\n%-15s\n", "AUTORES");
        printf("\n%-15s", lista[0].autor);

        for(i = 1; i < n; i++){
            flag = 0;
            for(j = 0; j < i; j++)
                if(strcmpi(lista[i].autor, lista[j].autor) == 0)
                    flag = 1;
            if(flag == 0)
                printf("\n%-15s", lista[i].autor);
        }

}

void autor_totales (struct cancion lista[], int n, char autor[]){

        int i, j, acum = 0;

        for(i = 0; i < n; i++){
            if(strcmpi(lista[i].autor, autor) == 0)
                for(j = 0; j < 12; j++)
                    acum += lista[i].reproducciones[j];
        }
        printf("\n\nReproducciones totales de %s : %d", autor, acum * 1000);
}
