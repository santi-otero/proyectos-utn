using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Componentes
{
    internal sealed class CPlacaDeVideo : ClaseComponente, IEquatable<CPlacaDeVideo>
    {
        uint RAM;
        ulong Frecuencia;
        string MarcaPlaca;

        public CPlacaDeVideo(uint ram, ulong freq, string marca, ulong num, string descrip, float valorC, float valorMO) : base(num, descrip, valorC, valorMO)
        {
            RAM = ram;
            Frecuencia = freq;
            MarcaPlaca = marca;
        }

        public CPlacaDeVideo() : base()
        {
            RAM = 0;
            Frecuencia = 0;
            MarcaPlaca = "";
        }

        public void SetFreq(ulong freq)
        {
            this.Frecuencia = freq;
        }
        public ulong GetFreq()
        {
            return this.Frecuencia;
        }
        public override string darDatos()
        {
            return base.darDatos() + "\nRAM dedicada: " + RAM.ToString() + 
            "\nFrecuencia: " + Frecuencia.ToString() + "\nMarca de la Placa: " + MarcaPlaca;
        }

        public bool Equals(CPlacaDeVideo other)
        {
            if(other.GetNumero() == this.GetNumero())
            {
                return true;
            }
            return false;
        }
    }
}
