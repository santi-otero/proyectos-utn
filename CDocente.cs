using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2doParcial_Otero
{
    internal sealed class CDocente : CPersona
    {
        string Categoria;

        public CDocente(string cat, ulong leg, string dni, string nom, string ape) : base(leg, dni, nom, ape)
        {
            Categoria = cat;
        }
        public CDocente() : base()
        {
            Categoria = "";
        }

        public void SetCategoria(string cat)
        {
            Categoria = cat;
        }
        public string GetCategoria()
        {
            return Categoria;
        }

        public override string darDatos()
        {
            return "Condicion: Docente\n" + base.darDatos() + "\nCategoria: " + Categoria;
        }
    }
}
