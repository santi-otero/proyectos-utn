#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paises {

        char nom [30];
        int cod;
};

struct ventas {

        int cant;
        char nom [20];
        int pais;
};

void cargar (FILE *, FILE *, struct paises, struct ventas);
int repetido (FILE *, struct paises, int);
void mirar (FILE *, FILE *, struct paises, struct ventas);

int main (){

        FILE * fv;
        FILE * fp;
        struct paises x;
        struct ventas z;

        if((fv = fopen("VENTAS","wb")) == NULL){
            printf("\n\t error al abrir archivo de ventas");
            exit(1);
        }

        if((fp = fopen("PAISES","w+b")) == NULL){
            printf("\n\t error al abrir archivo de paises");
            exit(1);
        }

        cargar(fp, fv, x, z);

        fclose(fv);
        fclose(fp);

        if((fv = fopen("VENTAS","rb")) == NULL){
            printf("\n\t error al abrir archivo de ventas");
            exit(1);
        }

        if((fp = fopen("PAISES","rb")) == NULL){
            printf("\n\t error al abrir archivo de paises");
            exit(1);
        }

        mirar(fp, fv, x, z);

        fclose(fv);
        fclose(fp);
        printf("\n\n\n\n");
        return 0;
}

void cargar (FILE * fp, FILE * fv, struct paises x, struct ventas z){

        int ingreso = 0, posicion;

        printf("\n\t cantidad de ventas  : ");
        scanf("%d", &z.cant);
        fflush(stdin);

        x.cod = 0;

        while(z.cant != -1){

            printf("\n\t apellido del vendedor  : ");
            gets(z.nom);
            printf("\n\t pais  : ");
            gets(x.nom);

            if((posicion = repetido(fp, x, ingreso)) == 0){
                x.cod++;
                fseek(fp, 0, SEEK_CUR);
                fwrite(&x, sizeof(x), 1, fp);
                z.pais = x.cod;
            }
            else
                z.pais = posicion;

            fwrite(&z, sizeof(z), 1, fv);

            ingreso++;

            printf("\n\t cantidad de ventas  : ");
            scanf("%d", &z.cant);
            fflush(stdin);
        }
}

int repetido (FILE * f, struct paises x, int pos){

        struct paises y;
        int i, flag = 0;


        for(i = 0; (i < pos) && (flag != 1); i++){
            fseek(f, pos*sizeof(x), SEEK_SET);
            fread(&x, sizeof(x), 1, f);
            fseek(f, i*sizeof(y), SEEK_SET);
            fread(&y, sizeof(y), 1, f);
            if((strcmpi(x.nom, y.nom)) == 0){
                flag = 1;
            }
        }
        if(flag == 0)
            return flag;
        else
            return i;
}

void mirar (FILE * fp, FILE * fv, struct paises x, struct ventas z){

        rewind(fp);
        rewind(fv);

        printf("\n\n\n %40s", "PAISES");
        fread(&x, sizeof(x), 1, fp);
        while(!feof(fp)){
            printf("\n\n %35d %-15s", x.cod, x.nom);

            fread(&x, sizeof(x), 1, fp);
        }

        printf("\n\n\n %40s", "VENTAS");
        fread(&z, sizeof(z), 1, fv);
        while(!feof(fv)){
            printf("\n\n %30d %-20s %15d", z.cant, z.nom, z.pais);

            fread(&z, sizeof(z), 1, fv);
        }
}
