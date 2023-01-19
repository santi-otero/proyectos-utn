using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Componentes
{
    internal abstract class ClaseComponente
    {
        ulong NumeroDeSerie;
        string Detalle;
        float CostoDeComponente;
        float CostoDeManoDeObra;

        public ClaseComponente(ulong num, string descrip, float valorC, float valorMO)
        {
            NumeroDeSerie = num;
            Detalle = descrip;
            CostoDeComponente = valorC;
            CostoDeManoDeObra = valorMO;
        }

        public ClaseComponente()
        {
            NumeroDeSerie = 0;
            Detalle = "A Definir";
            CostoDeComponente = 0F;
            CostoDeManoDeObra = 0F;
        }

        /* INICIO GETTERS Y SETTERS */
        public void SetNumero(ulong num)
        {
            NumeroDeSerie = num;
        }

        public void SetDetalle(string det)
        {
            Detalle = det;
        }

        public void SetCostoC(float valorC)
        {
            CostoDeComponente = valorC;
        }

        public void SetCostoMO(float valorMO)
        {
            CostoDeManoDeObra = valorMO;
        }

        public ulong GetNumero()
        {
            return NumeroDeSerie;
        }

        public string GetDetalle()
        {
            return Detalle;
        }

        public float GetCostoC()
        {
            return CostoDeComponente;
        }

        public float GetCostoMO()
        {
            return CostoDeManoDeObra;
        }
        /* FIN GETTERS Y SETTERS */

        public float darPrecio()
        {
            return CostoDeComponente + CostoDeManoDeObra;
        }

        public virtual string darDatos()
        {
            string Datos = "Numero de Serie: " + NumeroDeSerie.ToString() + "\nDetalle: " + Detalle +
            "\nCosto de componente: $" + CostoDeComponente.ToString() + "\nCosto de mano de obra: $" + 
            CostoDeManoDeObra.ToString() + "\nPrecio final: $" + darPrecio();
            return Datos;
        }
    }
}
