#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class Producto{
        char nombre[50];
        int stock;
        int ptoreposicion;
        Producto * sig;
    public:
        Producto(char *, int, int);
        ~Producto();
        friend class Marca;
        friend class Comercio;
};

Producto::Producto(char * s, int stk, int repo){

        strcpy(nombre, s);
        stock = stk;
        ptoreposicion = repo;
        sig = NULL;
}

Producto::~Producto(){

}

class Marca{
    private:
        char nom[50];
        Producto * productos;
        Marca * sig;
    public:
        Marca(char *);
        ~Marca();
        friend class Comercio;
};

Marca::Marca(char * s){

        strcpy(nom, s);
        productos = NULL;
}

Marca::~Marca(){

        Producto * pp;

        pp = productos;

        while (pp){
            Producto * paux;
            paux = pp;
            pp = pp->sig;
            delete paux;

        }
        productos = NULL;
}

class Comercio{
    private:
        Marca * marcas;
    public:
        Comercio();
        ~Comercio();
        Marca * buscar(char *);
        void ingresar(char *, char *, int, int);
        void venderUno(char *, char *);
        void imprimirMarcasConProductosAReponer();
};

Comercio::Comercio(){

        marcas = NULL;
}

Comercio::~Comercio(){

        Marca * pm;

        pm = marcas;

        while(pm){
            Marca * paux;
            paux = pm;
            pm = pm->sig;
            delete paux;
        }
        marcas = NULL;
}

Marca * Comercio::buscar(char * s){

        Marca * pm;
		pm = marcas;
		while (pm) {
				if ( ! strcmp(pm->nom, s) )
						return pm;
				pm = pm->sig;
		}
		return NULL ;
}

void Comercio::ingresar(char * m, char * p, int s, int r){

        Marca * pm;
        Producto * pprod;

        pm = buscar(m);

        if(!pm){ // LA MARCA NO EXISTE AUN.
            pm = new Marca(m);
            pm->sig = marcas;
            marcas = pm;
            pprod = new Producto(p, s, r);
            pprod->sig = pm->productos;
            pm->productos = pprod;
            return;
        }
        else{ // LA MARCA YA EXISTE.
            while(pm){
                if(!strcmp(m, pm->nom)){
                    pprod = pm->productos;
                    while (pprod){
                        if(!strcmp(pprod->nombre, p)){  // LA MARCA Y EL PRODUCTO YA EXISTEN
                            pprod->stock += s;          //  ENTONCES SE INCREMENTA EL STOCK.
                            return;
                        }
                        pprod = pprod->sig;
                    }
                    pprod = new Producto(p, s, r);      // LA MARCA EXISTE Y EL PRODUCTO NO.
                    pprod->sig = pm->productos;
                    pm->productos = pprod;
                    return;
                }
                pm = pm->sig;
            }
        }
}

void Comercio::venderUno(char * mar, char * modelo){

        Marca * pm;
        Producto * pp;

        pm = marcas;

        while(pm){
            if(!strcmp(mar, pm->nom)){
                pp = pm->productos;
                while(pp){
                    if(!strcmp(modelo, pp->nombre)){
                        pp->stock--;
                        return;
                    }
                    pp = pp->sig;
                }
            }
            pm = pm->sig;
        }
}

void Comercio::imprimirMarcasConProductosAReponer(){

        Marca * pm;
        Producto * pp;
        int i;

        pm = marcas;

        while(pm){
            pp = pm->productos;
            i = 0;
            while(pp){
                if(pp->stock <= pp->ptoreposicion)
                    i++;
                pp = pp->sig;
            }
            if(i > 0)
                printf("\n\n%s (%d productos a reponer)", pm->nom, i);
            pm = pm->sig;
        }
}

int main(void) {
	Comercio c;
	c.ingresar("Samsung", "S10", 10, 2); //marca, producto, stock, punto de reposicion
	c.ingresar("Samsung", "A12", 20, 0);
	c.ingresar("iPhone", "12", 5, 4);
	c.ingresar("iPhone", "12Pro", 0, 2);
	c.ingresar("LG", "Moto Z", 20, 5);

	c.venderUno("iPhone", "12");   //resta 1

	printf("Se debe llamar a estos fabricantes: ");
	c.imprimirMarcasConProductosAReponer();   //mostrar las marcas con faltantes, sin repetir!
											//para el ejemplo debe verse iphone (una sola vez)
}
