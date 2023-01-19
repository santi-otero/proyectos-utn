#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class Auto {
    public:
    Auto(char *, int);
    ~Auto();
    char modelo[30];
    int anio;
    Auto * sig;

};

Auto::Auto(char * s, int n){

        strcpy(modelo, s);
        anio = n;
        sig = NULL;
}

Auto::~Auto(){

        cout << "\n Matando a  : " << modelo << ", " << anio;
}

class Cliente {
    public:
    Cliente(char *, char *);
    ~Cliente();
    char nombre[30];
    char telefono[20];
    Cliente * sig;
    Auto * primerauto;
    void agregarAuto(char *, int);
    int cantAutos();
    void vaciarAutos();

};

Cliente::Cliente(char * s, char * t){

        strcpy(nombre, s);
        strcpy(telefono, t);
        primerauto = NULL;
}

Cliente::~Cliente(){

        Auto * pa;

        pa = primerauto;

        while(pa){
            Auto * paux;
            paux = pa;
            cout << "\n\n matando a " << paux->modelo;
            delete paux;
            pa = pa->sig;
        }
        primerauto = NULL;
}

void Cliente::agregarAuto(char * s, int n){

        Auto * pa = new Auto(s, n);
        pa->sig = primerauto;
        primerauto = pa;

}

int Cliente::cantAutos(){

        Auto * pa;
        int cont = 0;

        pa = primerauto;

        while(pa){
            cont++;
            pa = pa->sig;
        }
        return cont;
}

void Cliente::vaciarAutos(){

        Auto * pa;

        while (pa){
            Auto * paux;
            paux = pa;
            delete paux;
            pa = pa->sig;
        }
        primerauto = NULL;
}


class ListaClientes {
    private:
        Cliente * inicio;
    public:
        ListaClientes();
        ~ListaClientes();
        Cliente * buscar (char *);
        void agregar(char *, char *);
        int cantClientes();
};

ListaClientes::ListaClientes(){

        inicio = NULL;
}

ListaClientes::~ListaClientes(){

        Cliente * pc;

        pc = inicio;

        while (pc){
            Cliente * paux;
            paux = pc;
            delete paux;
            pc = pc->sig;
        }
        inicio = NULL;
}

Cliente * ListaClientes::buscar(char * s){

        Cliente * pc;

        pc = inicio;

        while (pc){
            if (! strcmp(s, pc->nombre)){
                return pc;
            }
            pc = pc->sig;
        }
        return NULL;
}

void ListaClientes::agregar(char * s, char * t){

        Cliente * pc = new Cliente(s, t);
        pc->sig = inicio;
        inicio = pc;

}

int ListaClientes::cantClientes(){

        Cliente * pc;
        int cant = 0;

        pc = inicio;

        while (pc){
            cant++;
            pc = pc->sig;
        }
        return cant;
}

int main() {
    ListaClientes * lc = new ListaClientes;  // la guirnalda en sí

    lc->agregar("Pepe", "4555-6565");  //agrega Cliente (lista principal)
    lc->agregar("Maria", "4444-3232");
    lc->agregar("Carlos", "5460-1111");

    lc->buscar("Pepe")->agregarAuto("Renault 12", 1980);  //agrega Auto a un Cliente (lista secundaria)
    lc->buscar("Pepe")->agregarAuto("Renault Fluence", 2013);

    printf("\n Pepe tiene %d autos" , lc->buscar("Pepe")->cantAutos() );  //debe dar 2

    lc->buscar("Pepe")->vaciarAutos();

    printf("\n Pepe tiene %d autos" , lc->buscar("Pepe")->cantAutos() );  //debe dar 0

    printf("\n La guirnalda tiene %d clientes \n\n" , lc->cantClientes() );  //debe dar 3

}
