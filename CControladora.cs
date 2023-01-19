using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Componentes
{
    internal class CControladora
    {
        List<CMicroProcesador> microProcesadores;
        List<CPlacaDeVideo> placasDeVideo;

        public CControladora()
        {
            microProcesadores = new List<CMicroProcesador>();
            placasDeVideo = new List<CPlacaDeVideo>();
        }

        public CMicroProcesador buscarMP(ulong numeroSerie)
        {
            CMicroProcesador aux = new CMicroProcesador();
            aux.SetNumero(numeroSerie);
            int indice = microProcesadores.IndexOf(aux);
            if (indice != -1)
            {
                return microProcesadores[indice];
            }
            return null;
        }
        public CPlacaDeVideo buscarPV(ulong numeroSerie)
        {
            CPlacaDeVideo aux = new CPlacaDeVideo();
            aux.SetNumero(numeroSerie);
            int indice = placasDeVideo.IndexOf(aux);
            if (indice != -1)
            {
                return placasDeVideo[indice];
            }
            return null;
        }

        public bool AgregarMP(uint nucleos, ulong freq, string marca, ulong num, string descrip, float valorC, float valorMO)
        {
            if(buscarMP(num) == null)
            {
                microProcesadores.Add(new CMicroProcesador(nucleos, freq, marca, num, descrip, valorC, valorMO));
                return true;
            }
            return false;
        }
        public bool AgregarPV(uint ram, ulong freq, string marca, ulong num, string descrip, float valorC, float valorMO)
        {
            if(buscarPV(num) == null)
            {
                placasDeVideo.Add(new CPlacaDeVideo(ram, freq, marca, num, descrip, valorC, valorMO));
                return true;
            }
            return false;
        }

        public string MostrarComponente(ulong numeroSerie)
        {
            CMicroProcesador auxMP = buscarMP(numeroSerie);
            if(auxMP != null)
            {
                return auxMP.darDatos();
            }
            else
            {
                CPlacaDeVideo auxPV = buscarPV(numeroSerie);
                if(auxPV != null)
                {
                    return auxPV.darDatos();
                }
            }
            return "Error!! Numero de serie no existente.";
        }

        public string Listar()
        {
            string lista = "PLACAS DE VIDEO\n\n\n";
            foreach(CPlacaDeVideo placa in placasDeVideo)
            {
                lista += placa.darDatos() + "\n\n*************************************************\n\n";
            }
            lista += "\nMICRO PROCESADORES\n\n\n";
            foreach(CMicroProcesador micro in microProcesadores)
            {
                lista += micro.darDatos() + "\n\n*************************************************\n\n";
            }
            return lista;
        }

        public bool EliminarComponente(ulong numeroSerie)
        {
            CMicroProcesador auxMP = buscarMP(numeroSerie);
            if (auxMP != null)
            {
                microProcesadores.Remove(auxMP);
                return true;
            }
            else
            {
                CPlacaDeVideo auxPV = buscarPV(numeroSerie);
                if (auxPV != null)
                {
                    placasDeVideo.Remove(auxPV);
                    return true;
                }
            }
            return false;
        }

        public bool EditarComponente(ulong numeroSerie, ulong freq)
        {
            CMicroProcesador auxMP = buscarMP(numeroSerie);
            if (auxMP != null)
            {
                auxMP.SetFreq(freq);
                return true;
            }
            else
            {
                CPlacaDeVideo auxPV = buscarPV(numeroSerie);
                if (auxPV != null)
                {
                    auxPV.SetFreq(freq);
                    return true;
                }
            }
            return false;
        }
    }
}
