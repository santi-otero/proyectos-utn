using System;

namespace Componentes
{
    internal class Program
    {
        static void Main(string[] args)
        {
            CControladora controladora = new CControladora();
            uint opcion, ram, cantidadNucleos;
            ulong NumeroSerie, frecuencia;
            string detalle, marcaPlaca, marcaProcesador;
            float costoDeComponente, costoDeManoDeObra;
            bool operacion;

            opcion = CInterfaz.MostrarMenu();
            while(opcion != 7)
            {
                switch (opcion)
                {
                    case 1:
                        CInterfaz.mostrarMensaje("Eligio ingresar una placa de video.");
                        NumeroSerie = CInterfaz.leerULong("Ingrese numero de serie para la placa de video: ");
                        detalle = CInterfaz.leerString("Ingrese el detalle: ");
                        costoDeComponente = CInterfaz.leerFloat("Ingrese el costo del componente: ");
                        costoDeManoDeObra = CInterfaz.leerFloat("Ingrese el costo de la mano de obra: ");
                        ram = CInterfaz.leerUInt("Ingrese la cantidad de RAM de la placa de video: ");
                        frecuencia = CInterfaz.leerULong("Ingrese la frecuencia de la placa de video: ");
                        marcaPlaca = CInterfaz.leerMarcaPV("Ingrese la marca (ATI o Nvidia): ");
                        operacion = controladora.AgregarPV(ram, frecuencia, marcaPlaca, NumeroSerie, detalle, costoDeComponente, costoDeManoDeObra);
                        if (operacion == true)
                        {
                            CInterfaz.mostrarMensaje("Placa de video ingresada correctamente.");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                    break;
                    case 2:
                        CInterfaz.mostrarMensaje("Eligio ingresar un microprocesador.");
                        NumeroSerie = CInterfaz.leerULong("Ingrese numero de serie para el microprocesador: ");
                        detalle = CInterfaz.leerString("Ingrese el detalle: ");
                        costoDeComponente = CInterfaz.leerFloat("Ingrese el costo del componente: ");
                        costoDeManoDeObra = CInterfaz.leerFloat("Ingrese el costo de la mano de obra: ");
                        cantidadNucleos = CInterfaz.leerUInt("Ingrese la cantidad de nucleos del microprocesador: ");
                        frecuencia = CInterfaz.leerULong("Ingrese la frecuencia del reloj: ");
                        marcaProcesador = CInterfaz.leerMarcaMP("Ingrese la marca (Intel o AMD): ");
                        operacion = controladora.AgregarMP(cantidadNucleos, frecuencia, marcaProcesador, NumeroSerie, detalle, costoDeComponente, costoDeManoDeObra);
                        if (operacion == true)
                        {
                            CInterfaz.mostrarMensaje("Microprocesador ingresado correctamente.");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                    break;
                    case 3:
                        CInterfaz.mostrarMensaje("Eligio mostrar los datos de un componente.");
                        NumeroSerie = CInterfaz.leerULong("Ingrese el numero de serie del componente a mostrar: ");
                        CInterfaz.mostrarMensaje(controladora.MostrarComponente(NumeroSerie));
                    break;
                    case 4:
                        CInterfaz.mostrarMensaje("Eligio mostrar los datos de todos los componentes.");
                        CInterfaz.mostrarMensaje(controladora.Listar());
                    break;
                    case 5:
                        CInterfaz.mostrarMensaje("ELigio eliminar un componente.");
                        NumeroSerie = CInterfaz.leerULong("Ingrese el numero de serie del componente a eliminar: ");
                        operacion = controladora.EliminarComponente(NumeroSerie);
                        if(operacion == true)
                        {
                            CInterfaz.mostrarMensaje("Componente eliminado correctamente.");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                    break;
                    case 6:
                        CInterfaz.mostrarMensaje("Eligio editar la frecuencia de un componente");
                        NumeroSerie = CInterfaz.leerULong("Ingrese el numero de serie del componente a modificar: ");
                        frecuencia = CInterfaz.leerULong("Ingrese la nueva frecuencia: ");
                        operacion = controladora.EditarComponente(NumeroSerie, frecuencia);
                        if(operacion == true)
                        {
                            CInterfaz.mostrarMensaje("Componente modificado correctamente.");
                        }
                        else
                        {
                            CInterfaz.mostrarMensaje("Ocurrio un error. :(");
                        }
                    break;
                    default:
                        CInterfaz.mostrarMensaje("Opcion no valida.");
                    break;
                }
                opcion = CInterfaz.MostrarMenu();
            }
            CInterfaz.mostrarMensaje("Hasta luego.");
        }
    }
}
