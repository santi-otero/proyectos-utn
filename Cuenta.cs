using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AppBancaria
{
    class Cuenta : IEquatable<Cuenta> , IComparable
    {

        static float interesMensual;
        public static void SetInteres(float porcentaje)
        {
            interesMensual = porcentaje;
        }
        public static float getInteres()
        {
            return interesMensual;
        }
        
        ulong CBU;
        string cliente;
        float saldo;

        /*CONSTUCTORES*/
        public Cuenta(ulong CBU, string cliente, float saldo)
        {
            this.CBU = CBU;
            this.cliente = cliente;
            this.saldo = saldo;
        }

        public Cuenta(ulong CBU, string cliente)
        {
            this.cliente = cliente;
            this.CBU = CBU;
            this.saldo = 0.0F;
        }
        public Cuenta()
        {
            cliente = "";
            CBU = 0;
            saldo = 0;
        }

        /*getters y setters*/
        public void setCBU(ulong CBU)
        {
            if (CBU >= 100 && CBU < 100000)
            {
                this.CBU = CBU;
            }
            else
            {
                this.CBU = 0;
            }
        }
        public void setCliente(string nombre)
        {
            cliente = nombre;
        }

        public void setSaldo(float saldo)
        {
            this.saldo = saldo;
        }

        public ulong getCBU()
        {
            return this.CBU;
        }
        public string getCliente()
        {
            return this.cliente;
        }
        public float getSaldo()
        {
            return this.saldo;
        }

         
        public bool depositar(float monto){
            if (monto <= 0)
            {
                return false;
            }
            else
            {
                this.saldo += monto;
            }
            return true;
        }

        public bool extraer(float monto)
        {
            if (saldo < monto)
            {
                return false;
            }
            else
            {
                this.saldo -= monto;
                return true;
            }
            
        }

        public string darDatos()
        {
            return "Nombre: " + this.cliente + ", CBU: " + this.CBU.ToString() + ", Saldo en cuenta: " + this.saldo.ToString(); 
        }

        public int CompareTo(object obj)
        {
            if(obj is Cuenta)
            {
                Cuenta aux = (Cuenta)obj;
                if(this.CBU > aux.CBU)
                {
                    return 1;
                }
                if(this.CBU < aux.CBU)
                {
                    return -1;
                }
                return 0;
            }
            return int.MaxValue;
        }
        public bool Equals(Cuenta other)
        {
            if(other == null)
            {
                return false;
            }
            
            if(this.CBU == other.CBU)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
