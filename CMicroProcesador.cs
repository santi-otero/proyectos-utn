using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Componentes
{
    internal sealed class CMicroProcesador : ClaseComponente, IEquatable<CMicroProcesador>
    {
        ulong FrecuenciaReloj;
        uint CantidadNucleos;
        string MarcaProcesador;

        public CMicroProcesador() : base()
        {
            FrecuenciaReloj = 0; 
            CantidadNucleos = 0;
            MarcaProcesador = "";
        }

        public CMicroProcesador(uint nucleos, ulong freq, string marca, ulong num, string descrip, float valorC, float valorMO) : base(num, descrip, valorC, valorMO)
        {
            FrecuenciaReloj = freq;
            CantidadNucleos = nucleos;
            MarcaProcesador = marca;
        }

        public void SetFreq(ulong freq)
        {
            this.FrecuenciaReloj = freq;
        }
        public ulong GetFreq()
        {
            return this.FrecuenciaReloj;
        }

        public override string darDatos()
        {
            return base.darDatos() + "\nFrecuencia del reloj: " + FrecuenciaReloj.ToString() +
            "\nCantidad de Nucleos: " + CantidadNucleos.ToString() + "\nMarca del Microprocesador: " + MarcaProcesador;
        }

        public bool Equals(CMicroProcesador other)
        {
            if (other.GetNumero() == this.GetNumero())
            {
                return true;
            }
            return false;
        }
    }
}
