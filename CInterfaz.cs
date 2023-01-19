using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Componentes
{
    internal static class CInterfaz
    {
        public static uint MostrarMenu()
        {
            Console.WriteLine("Aplicacion Componentes");
            Console.WriteLine("Menu:");
            Console.WriteLine("1 - Ingresar una placa de video.");
            Console.WriteLine("2 - Ingresar un microprocesador.");
            Console.WriteLine("3 - Mostrar datos de un componente.");
            Console.WriteLine("4 - Mostrar los datos de todos los componentes.");
            Console.WriteLine("5 - Eliminar un componente.");
            Console.WriteLine("6 - Editar la frecuencia de un componente.");
            Console.WriteLine("7 - Salir.\n");
            return leerUInt("Su opcion: ");
        }
        public static void mostrarMensaje(string mensaje)
        {
            Console.WriteLine(mensaje);
            Console.WriteLine("Presione una tecla para seguir.");
            Console.ReadKey();
            Console.Clear();
        }

        public static ulong leerULong(string mensaje)
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

        public static float leerFloat(string mensaje)
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

        public static int leerInt(string mensaje)
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

        public static uint leerUInt(string mensaje)
        {
            uint devolucion;
            bool op;
            do
            {
                Console.WriteLine(mensaje);
                op = uint.TryParse(Console.ReadLine(), out devolucion);
            } while (!op);
            return devolucion;
        }

        public static string leerString(string mensaje)
        {
            Console.WriteLine(mensaje);
            return Console.ReadLine();
        }

        public static string leerMarcaPV(string mensaje)
        {
            string devolucion;
            do
            {
                Console.WriteLine(mensaje);
                devolucion = Console.ReadLine();
            } while (devolucion.ToUpper() != "ATI" && devolucion.ToUpper() != "NVIDIA");
            return devolucion;
        }
        public static string leerMarcaMP(string mensaje)
        {
            string devolucion;
            do
            {
                Console.WriteLine(mensaje);
                devolucion = Console.ReadLine();
            } while (devolucion.ToUpper() != "INTEL" && devolucion.ToUpper() != "AMD");
            return devolucion;
        }
    }
}
