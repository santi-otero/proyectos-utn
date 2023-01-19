using System;

namespace _2doParcial_Otero
{
    internal class Program
    {
        static void Main(string[] args)
        {
            CControladora controladora = new CControladora();
            ulong legajo;
            string dNI, Nom, Ape, Cat, Titulo;
            bool operacion;

            uint opcion = CInterfaz.MostrarMenu();
            while(opcion != 6)
            {
                switch (opcion)
                {
                    case 1:
                        CInterfaz.mostrarMensaje("Usted eligio ingresar un docente");
                        legajo = CInterfaz.leerULong("Ingrese el legajo del docente");
                        dNI = CInterfaz.leerString("Ingrese el dni del docente");
                        Nom = CInterfaz.leerString("Ingrese el nombre del docente");
                        Ape = CInterfaz.leerString("Ingrese el apellido del docente");
                        Cat = CInterfaz.leerString("Ingrese la categoria del docente");
                        operacion = controladora.AgregarDocente(legajo, dNI, Nom, Ape, Cat);
                        if (operacion)
                        {
                            CInterfaz.mostrarMensaje("Docente registrado");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                        break;
                    case 2:
                        CInterfaz.mostrarMensaje("Usted eligio ingresar un alumno");
                        legajo = CInterfaz.leerULong("Ingrese el legajo del alumno");
                        dNI = CInterfaz.leerString("Ingrese el dni del alumno");
                        Nom = CInterfaz.leerString("Ingrese el nombre del alumno");
                        Ape = CInterfaz.leerString("Ingrese el apellido del alumno");
                        Titulo = CInterfaz.leerString("Ingrese el titulo secundario del alumno");
                        operacion = controladora.AgregarAlumno(legajo, dNI, Nom, Ape, Titulo);
                        if (operacion)
                        {
                            CInterfaz.mostrarMensaje("Alumno registrado");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                        break;
                    case 3:
                        CInterfaz.mostrarMensaje("Usted eligio listar todos los datos");
                        CInterfaz.mostrarMensaje(controladora.Listar());
                        break;
                    case 4:
                        CInterfaz.mostrarMensaje("Usted eligio mostrar los datos de un alumno o docente");
                        legajo = CInterfaz.leerULong("Ingrese el legajo a buscar");
                        CInterfaz.mostrarMensaje(controladora.mostrarPersona(legajo));
                        break;
                    case 5:
                        CInterfaz.mostrarMensaje("Usted eligio eliminar un alumno o docente");
                        legajo = CInterfaz.leerULong("Ingrese el legajo a buscar");
                        operacion = controladora.Eliminar(legajo);
                        if (operacion)
                        {
                            CInterfaz.mostrarMensaje("Realizado");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                        break;
                    default:
                        CInterfaz.mostrarMensaje("Por favor, ingrese una opcion valida");
                        break;
                }
                opcion = CInterfaz.MostrarMenu();
            }
            CInterfaz.mostrarMensaje("Hasta luego!");
        }
    }
}
