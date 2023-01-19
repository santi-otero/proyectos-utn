using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2doParcial_Otero
{
    internal class CControladora
    {
        List<CPersona> personas;

        public CControladora()
        {
            personas = new List<CPersona>();
        }

        public CPersona Buscar(ulong leg)
        {
            int indice = personas.IndexOf(new CPersona(leg));
            if(indice >= 0)
            {
                return personas[indice];
            }
            return null;
        }

        public bool AgregarDocente(ulong leg, string dni, string nom, string ape, string cat)
        {
            if(Buscar(leg) == null)
            {
                personas.Add(new CDocente(cat, leg, dni, nom, ape));
                return true;
            }
            return false;
        }

        public bool AgregarAlumno(ulong leg, string dni, string nom, string ape, string titulo)
        {
            if (Buscar(leg) == null)
            {
                personas.Add(new CAlumno(titulo, leg, dni, nom, ape));
                return true;
            }
            return false;
        }

        public string Listar()
        {
            string lista = "MOSTRANDO LISTA DE ALUMNOS Y DOCENTES \n****************************************\n";
            personas.Sort();
            foreach(CPersona persona in personas)
            {
                lista += persona.darDatos() + "\n\n****************************************\n\n";
            }
            return lista;
        }

        public string mostrarPersona(ulong leg)
        {
            CPersona aux = Buscar(leg);
            if(aux != null)
            {
                return aux.darDatos();
            }
            return "Ocurrio un error. :(";
        }

        public bool Eliminar(ulong leg)
        {
            CPersona aux = Buscar(leg);
            if (aux != null)
            {
                personas.Remove(aux);
                return true;
            }
            return false;
        }
    }
}
