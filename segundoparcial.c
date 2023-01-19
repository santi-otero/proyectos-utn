/* los flujos los abro en modo lectura porque yo ya cargué los datos y para no tener que hacerlo cada vez que ejecuto.
   Igual dejo la funcion cargar y la llamada a la función comentada. Originalmente los archivos se abrian como "w+b". */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha {

        int dia;
        int mes;
        int anio;
};

struct serv{

        char servicio[20];
        int id;
        struct fecha hoy;
};

struct precio{

        char servicio[20];
        int costo;
};

void cargar (FILE *, FILE *, struct precio, struct serv);
int servicios (FILE *, FILE *, struct precio, struct serv);
void mostrar (FILE *, FILE *, struct precio, struct serv, int);

int main(){

        FILE * fp;
        FILE * fs;
        struct precio x;
        struct serv z;
        int abuscar;

        if((fp = fopen("LISTA DE PRECIOS", "rb")) == NULL){
            printf("\n\t error al abrir lista de precios");
            exit (1);
        }

        if((fs = fopen("SERVICIOS", "rb")) == NULL){
            printf("\n\t error al abrir lista de servicios");
            exit (1);
        }

        //cargar(fp, fs, x, z);

        fseek(fp, servicios(fp, fs, x, z)*sizeof(x), SEEK_SET);
        fread(&x, sizeof(x), 1, fp);
        printf("\n\n\n\t\t El servicio que mas beneficios le dejo al hotel ha sido el %s", x.servicio);

        printf("\n\n\n\t Ingrese ID de huesped  : ");
        scanf("%d", &abuscar);

        mostrar(fp, fs, x, z, abuscar);

        fclose(fp);
        fclose(fs);
        printf("\n\n\n\n");
        return 0;
}

void cargar (FILE * fi, FILE * fe, struct precio x, struct serv z){

        char flag[5];

        printf("\n\t\t LISTA DE PRECIOS \n\n");

        strcpy(flag, "SI");
        while((strcmpi(flag, "SI")) == 0){

            printf("\n\t Servicio  : ");
            scanf("%s", &x.servicio);
            fflush(stdin);
            printf("\n\t Costo (en U$D)  : ");
            scanf("%d", &x.costo);
            fflush(stdin);

            fwrite(&x, sizeof(x), 1, fi);

            printf("\n\t Continuamos?\t");
            gets(flag);
        }

        printf("\n\n\t\t LISTA DE SERVICIOS \n\n");

        strcpy(flag, "SI");
        while((strcmpi(flag, "SI")) == 0){

            printf("\n\t Servicio  : ");
            scanf("%s", &z.servicio);
            fflush(stdin);
            printf("\n\t ID de Huesped  : ");
            scanf("%d", &z.id);
            fflush(stdin);
            printf("\n\t Fecha de hoy (DD/MM/AAAA)  : ");
            scanf("%d/%d/%d", &z.hoy.dia, &z.hoy.mes, &z.hoy.anio);
            fflush(stdin);

            fwrite(&z, sizeof(z), 1, fe);

            printf("\n\t Continuamos?\t");
            gets(flag);
        }
}

int servicios (FILE * fp, FILE * fs, struct precio x, struct serv z){

        int acum = 0, maximo = 0, i = 0, valor;


        rewind(fp);
        rewind(fs);

        fread(&x, sizeof(x), 1, fp);
        while(!feof(fp)){

            fread(&z, sizeof(z), 1, fs);
            while(!feof(fs)){

                if((strcmpi(x.servicio, z.servicio)) == 0)
                    acum += x.costo;

                fread(&z, sizeof(z), 1, fs);
            }
            if(acum > maximo){
                maximo = acum;
                valor = i;
            }

            rewind(fs);
            acum = 0;
            i++;
            fread(&x, sizeof(x), 1, fp);
        }

        return valor;
}

void mostrar (FILE * fp, FILE * fs, struct precio x, struct serv z, int objetivo){

        rewind(fp);
        rewind(fs);

        int total = 0, flag = 0;

        printf("\n\n\n %-15s \t\t %s \t\t\t %s", "SERVICIO", "FECHA", "COSTO (U$D)");

        fread(&z, sizeof(z), 1, fs);
        while(!feof(fs)){

            if(z.id == objetivo){

                fread(&x, sizeof(x), 1, fp);
                while(!feof(fp) && flag == 0){

                    if((strcmpi(z.servicio, x.servicio)) == 0){
                        total += x.costo;
                        flag = 1;
                        printf("\n\n %-15s \t\t %02d/%02d/%d \t\t\t %d",
                                z.servicio, z.hoy.dia, z.hoy.mes, z.hoy.anio, x.costo);
                    }
                    fread(&x, sizeof(x), 1, fp);
                }
                rewind(fp);
                flag = 0;
            }
            fread(&z, sizeof(z), 1, fs);
        }

        printf("\n\n\n\t Cuenta del huesped N %d  : %d U$D", objetivo, total);
}
