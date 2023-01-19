using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2doParcial_Otero
{
    internal static class CInterfaz
    {
        public static uint MostrarMenu()
        {
            Console.WriteLine("MENU DE ALUMNOS Y DOCENTES");
            Console.WriteLine("**************************");
            Console.WriteLine("1 - Ingresar un docente");
            Console.WriteLine("2 - Ingresar un alumno");
            Console.WriteLine("3 - Mostrar toda la lista");
            Console.WriteLine("4 - Mostrar datos de un alumno o docente");
            Console.WriteLine("5 - Eliminar un alumno o docente de la lista");
            Console.WriteLine("6 - Salir");
            return LeerOpcion("Su opcion: ");
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
        
        public static uint LeerOpcion(string mensaje)
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
    }
}
