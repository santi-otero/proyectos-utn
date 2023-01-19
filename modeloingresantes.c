#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ingreso{

        int legajo;
        char carrera[20];
};

struct examen{

        int legajo;
        float nota;
};

void cargar (FILE *, FILE *, struct ingreso, struct examen);
void mirar (FILE *, FILE *, struct ingreso, struct examen);
int inscriptos (FILE *, struct ingreso);
int presentados (FILE *, FILE *, struct ingreso, struct examen);
int aprobados (FILE *, FILE *, struct ingreso, struct examen);

int main(){

        struct ingreso x;
        struct examen z;
        FILE * fi;
        FILE * fe;

        if((fi = fopen("INGRESOS", "w+b")) == NULL){
            printf("\n\t error al abrir archivo de ingresos");
            exit (1);
        }

        if((fe = fopen("EXAMEN", "w+b")) == NULL){
            printf("\n\t error al abrir archivo de examen");
            exit (1);
        }

        cargar(fi, fe, x, z);

        mirar(fi, fe, x, z);

        getchar();

        printf("\n\n\n\n\t De los %d inscriptos a la carrera de ingenieria, %d se presentaron al examen y %d lo aprobaron",
                        inscriptos(fi, x), presentados(fi, fe, x, z), aprobados(fi, fe, x, z));


        fclose(fe);
        fclose(fi);
        printf("\n\n\n\n");
        return 0;
}

void cargar (FILE * fi, FILE * fe, struct ingreso x, struct examen z){

        char flag[5];

        printf("\n\t\t INGRESANTES \n\n");

        strcpy(flag, "SI");
        while((strcmpi(flag, "SI")) == 0){

            printf("\n\t Legajo  : ");
            scanf("%d", &x.legajo);
            fflush(stdin);
            printf("\n\t Carrera  : ");
            gets(x.carrera);

            fwrite(&x, sizeof(x), 1, fi);

            printf("\n\t Continuamos?\t");
            gets(flag);
        }

        printf("\n\t\t EXAMEN DE INGRESO \n\n");

        strcpy(flag, "SI");
        while((strcmpi(flag, "SI")) == 0){

            printf("\n\t Legajo  : ");
            scanf("%d", &z.legajo);
            fflush(stdin);
            printf("\n\t Nota  : ");
            scanf("%f", &z.nota);
            fflush(stdin);

            fwrite(&z, sizeof(z), 1, fe);

            printf("\n\t Continuamos?\t");
            gets(flag);
        }
}

void mirar (FILE * fi, FILE * fe, struct ingreso x, struct examen z){

        rewind(fi);
        rewind(fe);


        printf("\n\n %s \t %s", "LEGAJO", "CARRERA");

        fread(&x, sizeof(x), 1, fi);
        while(!feof(fi)){
            printf("\n\n %d \t %s", x.legajo, x.carrera);

            fread(&x, sizeof(x), 1, fi);
        }

        printf("\n\n %s \t %s", "LEGAJO", "NOTA");

        fread(&z, sizeof(z), 1, fe);
        while(!feof(fe)){
            printf("\n\n %d \t %.2f", z.legajo, z.nota);

            fread(&z, sizeof(z), 1, fe);
        }
}

int inscriptos (FILE * f, struct ingreso x){

        int i = 0;

        rewind(f);

        fread(&x, sizeof(x), 1, f);
        while(!feof(f)){
            if((strcmpi(x.carrera, "ING")) == 0)
                i++;

            fread(&x, sizeof(x), 1, f);
        }

        return i;
}

int presentados (FILE * fi, FILE * fe, struct ingreso x, struct examen z){

        rewind(fi);
        rewind(fe);

        int i = 0;

        fread(&x, sizeof(x), 1, fi);
        while(!feof(fi)){

            if((strcmpi(x.carrera, "ING")) == 0){
                fread(&z, sizeof(z), 1, fe);
                while(!feof(fe)){
                    if(x.legajo == z.legajo)
                        i++;

                    fread(&z, sizeof(z), 1, fe);
                }

                fseek(fe, 0, SEEK_SET);
            }

            fread(&x, sizeof(x), 1, fi);
        }

        return i;
}

int aprobados (FILE * fi, FILE * fe, struct ingreso x, struct examen z){

        rewind(fi);
        rewind(fe);

        int i = 0;

        fread(&x, sizeof(x), 1, fi);
        while(!feof(fi)){

            if((strcmpi(x.carrera, "ING")) == 0){
                fread(&z, sizeof(z), 1, fe);
                while(!feof(fe)){
                    if(x.legajo == z.legajo)
                        if(z.nota >= 6)
                            i++;

                    fread(&z, sizeof(z), 1, fe);
                }

                fseek(fe, 0, SEEK_SET);
            }

            fread(&x, sizeof(x), 1, fi);
        }

        return i;
}
