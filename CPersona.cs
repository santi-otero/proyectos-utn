using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2doParcial_Otero
{
    internal class CPersona : IComparable<CPersona>, IEquatable<CPersona>
    {
        ulong Legajo;
        string DNI;
        string Nombre;
        string Apellido;

        public CPersona(ulong leg, string dni, string nom, string ape)
        {
            Legajo = leg;
            DNI = dni;
            Nombre = nom;
            Apellido = ape;
        }
        public CPersona()
        {
            Legajo = 0;
            DNI = "";
            Nombre = "";
            Apellido = "";
        }
        public CPersona(ulong leg)
        {
            Legajo = leg;
            DNI = "";
            Nombre = "";
            Apellido = "";
        }

        public void SetLegajo(ulong leg)
        {
            Legajo = leg;
        }
        public ulong GetLegajo()
        {
            return Legajo;
        }

        public virtual string darDatos()
        {
            return "Legajo: " + Legajo.ToString() + "\nDNI: " + DNI + "\nNombre y apellido: " + Nombre + " " + Apellido;
        }

        public int CompareTo(CPersona otro)
        {
            if(otro.GetLegajo() == this.GetLegajo())
            {
                return 0;
            }
            else
            {
                if(this.GetLegajo() > otro.GetLegajo())
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }

        public bool Equals(CPersona otro)
        {
            if(otro != null && otro.GetLegajo() == this.GetLegajo())
            {
                return true;
            }
            return false;
        }
    }
}
