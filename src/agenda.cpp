#include "../include/agenda.h"

struct rep_agenda {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TEvento agenda_arr[MAX_EVENTOS];
    int tope_agenda;
    /****** Fin de parte Parte 5.1 *****/
};

TAgenda crearTAgenda() {
    TAgenda nuevaAgenda = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    nuevaAgenda = new rep_agenda;
    nuevaAgenda->tope_agenda = 0;
    /****** Fin de parte Parte 5.2 *****/
    return nuevaAgenda;
}

void agregarEnAgenda(TAgenda &agenda, TEvento evento) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    bool colocado = false;
    if (agenda->tope_agenda == 0)
    {
        agenda->agenda_arr[agenda->tope_agenda] = evento;
        agenda->tope_agenda++;
    }
    else if (agenda->tope_agenda-1 < MAX_EVENTOS)
    {
        for (int i = 0; i <= (agenda->tope_agenda - 1); i++)
        {
           if (compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->agenda_arr[i])) == 1)
           {
                for (int n = i; n <= (agenda->tope_agenda - 1); n++)
                {
                    if (compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->agenda_arr[n])) == -1)
                    {
                        agenda->tope_agenda++;
                        for (int j = agenda->tope_agenda - 1; j > n; j--)
                        {
                            agenda->agenda_arr[j] = agenda->agenda_arr[j-1];
                        }
                        agenda->agenda_arr[n] = evento;
                        colocado = true;
                        break;
                    }
                    else if (compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->agenda_arr[n])) == 0)
                    {
                        agenda->tope_agenda++;
                        for (int j = (agenda->tope_agenda - 1); j > i + 1; j--)
                        {
                            agenda->agenda_arr[j] = agenda->agenda_arr[j-1];
                        }
                        agenda->agenda_arr[i + 1] = evento;
                        colocado = true;
                        break;
                    }
                    else if (n == (agenda->tope_agenda - 1))
                    {
                        agenda->tope_agenda++;
                        agenda->agenda_arr[agenda->tope_agenda - 1] = evento;
                        colocado = true;
                        break;
                    }
                }
           }
           else if ((compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->agenda_arr[i])) == -1) ||
            (compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->agenda_arr[i])) == 0))
            {
                agenda->tope_agenda++;
                for (int j = (agenda->tope_agenda - 1); j > i; j--)
                {
                    agenda->agenda_arr[j] = agenda->agenda_arr[j-1];
                }
                agenda->agenda_arr[i] = evento;
                colocado = true;
                break;
            }
            if (colocado)
            {
                break;
            }
        }
    }
    
    
    /****** Fin de parte Parte 5.2 *****/
}

void liberarTAgenda(TAgenda &agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    for (int i = 0; i <= (agenda->tope_agenda - 1); i++)
    {
        liberarTEvento(agenda->agenda_arr[i]);
    }
    agenda->tope_agenda = 0;
    delete agenda;
    agenda = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

void imprimirTAgenda(TAgenda agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (agenda->tope_agenda > 0)
    {
        for (int i = 0; i <= (agenda->tope_agenda - 1); i++)
        {
            imprimirTEvento(agenda->agenda_arr[i]);
        }
    }
    
    /****** Fin de parte Parte 5.2 *****/
}

bool estaEnAgenda(TAgenda agenda, int id) {
    bool res = false;
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    if (agenda->tope_agenda > 0)
    {
        for (int i = 0; i <= (agenda->tope_agenda - 1); i++)
        {
            if (idTEvento(agenda->agenda_arr[i]) == id)
            {
                res = true;
                break;
            }
            
        }
        
    }
    /****** Fin de parte Parte 5.4 *****/
    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id) {
    TEvento res = NULL;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    if (estaEnAgenda(agenda,id))
    {
         for (int i = 0; i <= (agenda->tope_agenda - 1); i++)
        {
            if (idTEvento(agenda->agenda_arr[i]) == id)
            {
                res = agenda->agenda_arr[i];
                break;
            }
        }
    }
    /****** Fin de parte Parte 5.5 *****/
    return res;
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    if (estaEnAgenda(agenda,id))
    {
        int indice = 0;
        TEvento even = NULL;
        even = obtenerDeAgenda(agenda,id);
        posponerTEvento(even,n);
        for (int i = 0; i <= (agenda->tope_agenda - 1); i++)
        {
            if (idTEvento(agenda->agenda_arr[i]) == id)
            {
                indice = i;
                break;
            }
        }
        if (indice < agenda->tope_agenda - 1)
        {
            int j = indice + 1;
            while ((j <= agenda->tope_agenda - 1) && compararTFechas(fechaTEvento(even),fechaTEvento(agenda->agenda_arr[j])) == 1)
            {
                j++;
            }
            for (int i = indice; i < j-1; i++)
            {
                agenda->agenda_arr[i] = agenda->agenda_arr[i+1];
            }
            agenda->agenda_arr[j-1] = even;
        }
    }
    
    /****** Fin de parte Parte 5.5 *****/
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha) {
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    if (agenda->tope_agenda > 0)
    {
        int j = 0;
        bool sigue = false;
        for (j = 0; j <= (agenda->tope_agenda - 1); j++)
        {
            if ((compararTFechas(fechaTEvento(agenda->agenda_arr[j]),fecha) == 0))
            {
                sigue = true;
                break;
            }
        }
        if (sigue)
        {
            for (j = j ; ((j <= agenda->tope_agenda - 1) && ((compararTFechas(fechaTEvento(agenda->agenda_arr[j]),fecha) == 0))) ; j++)
            {
                imprimirTEvento(agenda->agenda_arr[j]);
            }
        }
    }
    /****** Fin de parte Parte 5.7 *****/
}
bool busquedaBinaria(TAgenda agenda, TFecha fecha){
    int abajo,arriba,medio;
    abajo = 0;
    arriba = agenda->tope_agenda - 1;
    while (arriba ==! abajo){
        medio = (abajo + arriba) / 2;
        if (compararTFechas(fechaTEvento(agenda->agenda_arr[medio]),fecha) == 0)
        {
            return true;
        }
        else if ((compararTFechas(fechaTEvento(agenda->agenda_arr[medio]),fecha) == 1))
        {
            arriba = medio - 1;
        }
        else if ((compararTFechas(fechaTEvento(agenda->agenda_arr[medio]),fecha) == -1))
        {
            abajo = medio + 1;
        }
    }
    return false;
}
bool hayEventosFecha(TAgenda agenda, TFecha fecha) {
    bool res = false;
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    /*La función debe ejecutar una versión */
    /*Iterativa del algoritmo de búsqueda  */
    /*binaria.                              */
    if (agenda->tope_agenda > 0)
    {
        res = busquedaBinaria(agenda,fecha);
    }
    /****** Fin de parte Parte 5.7 *****/
    return res;
}

void removerDeAgenda(TAgenda &agenda, int id) {
    /************ Parte 5.8 ************/
    /*Escriba el código a continuación */
    if (agenda->tope_agenda > 0)
    {
        if (estaEnAgenda(agenda,id))
        {
            int i = 0;
            for (i = 0; i <= (agenda->tope_agenda - 1); i++)
            {
                if (idTEvento(agenda->agenda_arr[i]) == id)
                {
                    break;
                }
            }
            if (i == 0)
            {
                liberarTEvento(agenda->agenda_arr[i]);
                for (i = 0; i < (agenda->tope_agenda - 1) ; i++)
                {
                    agenda->agenda_arr[i] = agenda->agenda_arr[i+1];
                }
                agenda->tope_agenda--;
            }
            else if (i == (agenda->tope_agenda - 1))
            {
                liberarTEvento(agenda->agenda_arr[i]);
                agenda->tope_agenda--;
            }
            else 
            {
                liberarTEvento(agenda->agenda_arr[i]);
                for (i = i; i <= (agenda->tope_agenda - 1); i++)
                {
                    agenda->agenda_arr[i] = agenda->agenda_arr[i+1];
                }
                agenda->tope_agenda--;
            }
            
        }
    }   
    /****** Fin de parte Parte 5.8 *****/
}





