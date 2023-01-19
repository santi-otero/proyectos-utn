#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class Final {

    public :
        Final(char *, int);
        ~Final();
        char nom[50];
        int nota;
        Final * sig;
};

Final::Final(char * nombre, int num){

        strcpy(nom, nombre);
        nota = num;
        sig = NULL;
}

Final::~Final(){

        cout << "\n\n matando a " << nom;
}

class Materia{

    public :
        Materia(char *);
        ~Materia();
        char nom[30];
        Final * ex;
        Materia * sig;
};

Materia::Materia(char * s){

        strcpy(nom, s);
        ex = NULL;
}

Materia::~Materia(){

        Final * pf;

        pf = ex;

        while (pf){
            Final * paux;
            paux = pf;
            cout << "\n\n matando a " << paux->nom;
            pf = pf->sig;
            delete paux;
        }

        ex = NULL;
}

class TUP {

    private :
        Materia * INICIO;
    public :
        TUP();
        ~TUP();
        void crearMateria(char *);
        void inscribirFinal(char *, char *, int);
        void imprimePromedios();

};

TUP::TUP(){

        INICIO = NULL;
}

TUP::~TUP(){

        Materia * pmat;

        pmat = INICIO;

        while(pmat){
            Materia * paux;
            paux = pmat;
            pmat = pmat->sig;
            delete paux;

        }
        INICIO = NULL;
}

void TUP::crearMateria(char * s){

        Materia * mat, * matant;

        mat = INICIO;
        if (!INICIO){ // Lista vacia
            mat = new Materia(s);
            mat->sig = INICIO;
            INICIO = mat;
            return;
        }
        // Lista no vacia
        while (mat){
            matant = mat;
            mat = mat->sig;
        }
        mat = new Materia(s);
        matant->sig = mat;
}

void TUP::inscribirFinal(char * estudiante, char * asignatura, int calificacion){

        Final * examen;
        Materia * mat;

        mat = INICIO;

        while(mat){

            if(! strcmp(asignatura, mat->nom)){
                examen = new Final (estudiante, calificacion);
                examen->sig = mat->ex;
                mat->ex = examen;
                return;
            }
            mat = mat->sig;
        }
}

void TUP::imprimePromedios(){

        float promedio;
        int cont, cant;
        Final * pf;
        Materia * pm;

        pm = INICIO;

        while(pm){

            pf = pm->ex;
            cont = 0;
            cant = 0;

            while(pf){
                cont = pf->nota + cont;
                cant++;
                pf = pf->sig;
            }
            if(cant > 0){
                promedio = (float)cont/cant;
                cout << "\n\t promedio en " << pm->nom << " =  " << promedio << "\n";
            }
            pm = pm->sig;
        }
}

int main() {

	TUP * tup = new TUP;

	tup->crearMateria("Matematica");
	tup->crearMateria("Programacion 1");
	tup->crearMateria("Materia fantasma");

	tup->inscribirFinal("Pepe Gomez", "Matematica", 2);
	tup->inscribirFinal("Maria Lopez", "Matematica", 8);
	tup->inscribirFinal("Bart Simpson", "Programacion 1", 8);

	tup->imprimePromedios();
	// debe imprimir:
	//
	// Matematica: 5
	// Programacion 1: 8
}
