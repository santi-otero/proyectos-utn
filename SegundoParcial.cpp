struct fecha{
    int dia;
    int mes;
    int anio;
};

class Postulante{
    public:
        Postulante(char *, struct fecha, int, char *);
        ~Postulante();
        char mail[60];
        struct fecha * presentacionoferta;
        int ingles; // 1 si sabe, 0 si no sabe.
        char preferencia[20];
        Postulante * sig;
};


class OfertaLaboral{
    public:
        OfertaLaboral(char *, struct fecha, int, char *);
        ~OfertaLaboral();
        char puesto[30];
        struct fecha * cierre;
        int demandaingles; // 1 si demanda, 0 si no demanda.
        char tipo[20];
        OfertaLaboral * sig;
        Postulante * primerpostulante;
};


class Empresa{
    private:
        OfertaLaboral * primeraoferta;
    public:
        Empresa();
        ~Empresa();
        void BorrarSinIngles();
        void FueraDeFecha(char *);
        OfertaLaboral * buscarpuesto(char *);
};

void Empresa::BorrarSinIngles(){

        OfertaLaboral * pof;
        Postulante * ppos, * postulanteanterior;

        pof = primeraoferta;

        while(pof){
            if(pof->demandaingles == 1){
                postulanteanterior = NULL;
                ppos = pof->primerpostulante;
                while(ppos){
                    if(ppos->ingles == 0){
                        // HAY QUE ELIMINARLO... BUSCAMOS SI ESTÁ AL PRINCIPIO, EN EL MEDIO O AL FINAL
                        if(!postulanteanterior){
                            Postulante * paux;
                            paux = ppos;
                            pof->primerpostulante = ppos->sig;
                            ppos = ppos->sig;
                            delete paux;
                        }
                        if(postulanteanterior && ppos->sig){
                            Postulante * paux;
                            paux = ppos;
                            postulanteanterior->sig = ppos->sig;
                            ppos = ppos->sig;
                            delete paux;
                        }
                        if(!ppos->sig && postulanteanterior){
                            Postulante * paux;
                            paux = ppos;
                            postulanteanterior->sig = NULL;
                            ppos = ppos->sig;
                            delete paux;
                        }
                    }
                    else{
                        postulanteanterior = ppos;
                        ppos = ppos->sig;
                    }
                }
            }
            pof = pof->sig;
        }
}

void Empresa::FueraDeFecha(char * titulo){

        OfertaLaboral * pof;
        Postulante * ppos;

        if (pof = buscarpuesto(titulo)){
            ppos = pof->primerpostulante;

            while (ppos){
                if((ppos->presentacionoferta->anio > pof->cierre->anio) || (ppos->presentacionoferta->anio == pof->cierre->anio &&
                    ppos->presentacionoferta->mes > pof->cierre->mes) ||   (ppos->presentacionoferta->anio == pof->cierre->anio &&
                    ppos->presentacionoferta->mes == pof->cierre->mes &&  ppos->presentacionoferta->dia > pof->cierre->dia))
                        cout << "\n" << ppos->mail;
                ppos = ppos->sig;
            }
        }
        else{
            cout << "\n\n\t\t\t No se ha encontrado el puesto solicitado";
        }
}

OfertaLaboral * Empresa::buscarpuesto(char * s){

        OfertaLaboral * pof;
		pof = primeraoferta;
		while (pof) {
				if ( ! strcmp(pof->puesto, s) )
						return pof;
				pof = pof->sig;
		}
		return NULL ;
}
