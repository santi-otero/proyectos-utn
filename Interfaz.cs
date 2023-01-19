using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppBancaria
{
    internal class Interfaz
    {
        public Interfaz(ConsoleColor background, ConsoleColor foreground)
        {
            Console.BackgroundColor = background;
            Console.ForegroundColor = foreground;
        }
        public int mostrarMenu()
        {
            Console.WriteLine("***************************************");
            Console.WriteLine("*    Sistema de Gestion de Cuentas    *");
            Console.WriteLine("***************************************");
            Console.WriteLine("\n\n [1] Agregar una cuenta.");
            Console.WriteLine("\n [2] Realizar un deposito.");
            Console.WriteLine("\n [3] Realizar una extraccion.");
            Console.WriteLine("\n [4] Mostrar datos de una cuenta.");
            Console.WriteLine("\n [5] Listar datos de todas las cuentas.");
            Console.WriteLine("\n [6] Remover una cuenta.");
            Console.WriteLine("\n [7] Simular saldo final luego de X meses.");
            Console.WriteLine("\n [8] Salir de la aplicacion.");
            Console.WriteLine("\n***************************************");
            return pedirOpcion();
        }

        public int pedirOpcion()
        {
            int opcion;
            do
            {
                Console.WriteLine("\n Ingrese una opcion entre 1 y 8.");
                opcion = int.Parse(Console.ReadLine());
            } while (opcion < 1 || opcion > 8);
            return opcion;
        }

        public void mostrarMensaje(string mensaje)
        {
            Console.WriteLine(mensaje);
            Console.WriteLine("Presione una tecla para seguir.");
            Console.ReadKey();
            Console.Clear();
        }

        public ulong leerCBU (string mensaje)
        {
            ulong devolucion;
            bool op;
            do
            {
                Console.WriteLine(mensaje);
                op = ulong.TryParse(Console.ReadLine(), out devolucion);
            } while (!op);
            return devolucion;
        }
        public float leerMonto(string mensaje)
        {
            float devolucion;
            bool op;
            do
            {
                Console.WriteLine(mensaje);
                op = float.TryParse(Console.ReadLine(), out devolucion);
            } while (!op);
            return devolucion;
        }

        public int leerMeses(string mensaje)
        {
            int devolucion;
            bool op;
            do
            {
                Console.WriteLine(mensaje);
                op = int.TryParse(Console.ReadLine(), out devolucion);
            } while (!op);
            return devolucion;
        }
        public string leerNombre(string mensaje)
        {
            Console.WriteLine(mensaje);
            return Console.ReadLine();
        }
    }
}
