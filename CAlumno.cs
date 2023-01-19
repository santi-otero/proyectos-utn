using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2doParcial_Otero
{
    internal sealed class CAlumno : CPersona
    {
        string TituloSecundario;

        public CAlumno(string titulo, ulong leg, string dni, string nom, string ape) : base(leg, dni, nom, ape)
        {
            TituloSecundario = titulo;
        }
        public CAlumno() : base()
        {
            TituloSecundario = "";
        }

        public void SetTitulo(string titulo)
        {
            TituloSecundario = titulo;
        }
        public string GetTitulo()
        {
            return TituloSecundario;
        }

        public override string darDatos()
        {
            return "Condicion: Alumno\n" + base.darDatos() + "\nTitulo secundario: " + TituloSecundario;
        }
    }
}
