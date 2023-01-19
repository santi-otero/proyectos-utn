#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;


class Visitante {
    public:
        Visitante(char *);
        ~Visitante();
        char nom[40];
        Visitante * sig;
};
Visitante::Visitante(char * s){

        strcpy(nom, s);
        sig = NULL;
}

Visitante::~Visitante(){

        cout << "\n\n Eliminando visita de " << nom << "\n";
}

class Museo {
    public:
        Museo(char * s);
        ~Museo();
        char nom[40];
        Visitante * primervis;
        Museo * sig;
};

Museo::Museo(char * s){

        strcpy(nom, s);
        primervis = NULL;
}

Museo::~Museo(){

        Visitante * pv;

        pv = primervis;

        while(pv){
            Visitante * paux;
            paux = pv;
            delete paux;
            pv = pv->sig;
        }
        primervis = NULL;
}

class RegistroVisitas {
    private:
        Museo * inicio;
    public:
        RegistroVisitas();
        void nuevoMuseo(char *);
        void registrarVisita(char *, char *);
        void mirar();
        void borrarMuseosPocoVisitados();
};

RegistroVisitas::RegistroVisitas(){

        inicio = NULL;
}

void RegistroVisitas::nuevoMuseo(char * s){

        Museo * pm = new Museo(s);
        pm->sig = inicio;
        inicio = pm;
}

void RegistroVisitas::registrarVisita(char * mus, char * vis){

        Museo * pm;
        Visitante * pv;

        pm = inicio;

        while (pm){
            if(! strcmp(mus, pm->nom)){
                pv = new Visitante(vis);
                pv->sig = pm->primervis;
                pm->primervis = pv;
                return ;
            }
            pm = pm->sig;
        }
}

void RegistroVisitas::mirar(){

        Visitante * pv;
        Museo * pm;

        pm = inicio;

        while(pm){
            cout << "\n Visitantes del " << pm->nom << " :  ";
            pv = pm->primervis;
            while(pv){
                cout << pv->nom << "; ";
                pv = pv->sig;
            }
            cout << "\n";
            pm = pm->sig;
        }
}

void RegistroVisitas::borrarMuseosPocoVisitados(){

        Museo * pm, * museoanterior;
        Visitante * pv;
        int i;

        museoanterior = NULL;
        pm = inicio;

        while(pm){
            i = 0;
            pv = pm->primervis;
            while(pv){
                i++;
                pv = pv->sig;
            }
            if(i < 2){
                if(!museoanterior){
                    inicio = pm->sig;
                    delete pm;
                }
                if(museoanterior && pm->sig){
                    museoanterior->sig = pm->sig;
                    delete pm;
                }
                if(!pm->sig && museoanterior){
                    museoanterior = NULL;
                    delete pm;
                }
            }
            museoanterior = pm;
            pm = pm->sig;
        }
}

int main() {

	RegistroVisitas * lista = new RegistroVisitas;

	lista->nuevoMuseo("MALBA");
    lista->nuevoMuseo("Museo Historico Nacional");
    lista->nuevoMuseo("Museo de Ciencias Naturales");

	lista->registrarVisita("MALBA", "Pepe Gomez");
	lista->registrarVisita("Museo Historico Nacional", "Pepe Gomez");
	lista->registrarVisita("MALBA", "Maria Alvarez");
	lista->registrarVisita("Museo de Ciencias Naturales", "Pepe Gomez");
    lista->registrarVisita("Museo de Ciencias Naturales", "Roberto Sanchez");

    printf("Antes de borrar: \n");
    lista->mirar();

	lista->borrarMuseosPocoVisitados();  //borra de la lista a los museos con menos de 2 visitas, para este ejemplo es unicamente el M. Hist. Nac.

    printf("\n\nDespues de borrar: \n");
	lista->mirar();
}
