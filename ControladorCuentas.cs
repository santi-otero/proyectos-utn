using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppBancaria
{
    internal class ControladorCuentas
    {
        private List<Cuenta> cuentas;

        public ControladorCuentas()
        {
            cuentas = new List<Cuenta>();
        }

        public Cuenta buscar(ulong CBU)
        {
            Cuenta aux = new Cuenta();
            aux.setCBU(CBU);
            int indice = cuentas.IndexOf(aux);
            if(indice != -1)
            {
                return cuentas[indice];
            }
            return null;
        }

        public bool agregar(ulong cbu, string nombre, float saldo)
        {
            if (buscar(cbu) == null)
            {
                cuentas.Add(new Cuenta(cbu, nombre, saldo));
                return true;
            }    
            return false;
        }

        public bool depositar(ulong cbu, float monto)
        {
            Cuenta aux = buscar(cbu);
            if(aux is Cuenta)
            {
                aux.depositar(monto);
                return true;
            }
            return false;
        }
        public bool extraer(ulong cbu, float monto)
        {
            Cuenta aux = buscar(cbu);
            if (aux is Cuenta)
            {
                aux.extraer(monto);
                return true;
            }
            return false;
        }

        public string mostrarDatos(ulong cbu)
        {
            Cuenta aux = buscar(cbu);
            if (aux is Cuenta)
            {
                return aux.darDatos();
            }
            return null;    
        }

        public string listar()
        {
            string lista = "";
            cuentas.Sort();
            foreach(Cuenta cuenta in cuentas)
            {
                lista += cuenta.darDatos() + "\n";
            }
            return lista;
        }

        public bool remover(ulong cbu)
        {
            Cuenta aux = buscar(cbu);
            if(aux is Cuenta)
            {
                cuentas.Remove(aux);
                return true;
            }
            else
            {
                return false;
            }
        }

        public float saldoFinal(ulong cbu, int meses, float interes)
        {
            Cuenta aux = buscar(cbu);
            if (aux is Cuenta) 
            {
                float saldo = aux.getSaldo();
                for (int i = 0; i < meses; i++)
                {
                    saldo += saldo * interes / 100;
                }
                return saldo;
            }
            return float.MaxValue;
        }
    }
}
