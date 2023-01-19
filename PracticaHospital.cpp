#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class Paciente{
    public:
        Paciente(char *);
        ~Paciente();
        char nom[40];
        Paciente * sig;
};

Paciente::Paciente(char * s){

        strcpy(nom, s);
        sig = NULL;
}

Paciente::~Paciente(){

        cout << "\n Eliminando a  : " << nom;
}

class Medico{
    public:
        Medico(char *);
        ~Medico();
        char nom[40];
        Paciente * primerpaciente;
        Medico * sig;
};

Medico::Medico(char * s){

        strcpy(nom, s);
        primerpaciente = NULL;
}

Medico::~Medico(){

        Paciente * pp;

        pp = primerpaciente;

        while (pp){
            Paciente * paux;
            paux = pp;
            delete paux;
            pp = pp->sig;
        }
        primerpaciente = NULL;
}

class Hospital{
    private:
        Medico * inicio;
    public:
        Hospital();
        ~Hospital();
        void medicosDelPaciente(char *);
        Medico * medicoConMenosPacientes();
};

Hospital::Hospital(){

        inicio = NULL;
}

Hospital::~Hospital(){

        Medico * pm;

        pm = inicio;

        while (pm){
            Medico * paux;
            paux = pm;
            delete paux;
            pm = pm->sig;
        }
        inicio = NULL;
}

void Hospital::medicosDelPaciente(char * s){

        cout << "\n\n" << s << " se atiende con :  ";
        Medico * pm;
        Paciente * pp;

        pm = inicio;

        while(pm){
            pp = pm->primerpaciente;
            while(pp){
                if (! strcmp(s, pp->nom)){
                    cout << pm->nom << ", ";
                }
                pp = pp->sig;
            }
            pm = pm->sig;
        }
        cout << ".";
}

Medico * Hospital::medicoConMenosPacientes(){

        Medico * pm, * menor;
        Paciente * pp;
        int cont, minimo, i = 0;

        pm = inicio;

        while (pm){
            pp = pm->primerpaciente;
            cont = 0;
            while(pp){
                cont++;
                pp = pp->sig;
            }
            if (++i == 1)
                minimo = cont;

            if (cont < minimo)
                menor = pm;

            pm = pm->sig;
        }
        return menor;
}

int main (){


}
