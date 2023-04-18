#include "../include/evento.h"
#include <ctype.h>
struct rep_evento {
    /************ Parte 4.1 ************/
    /*Escriba el código a continuación */
    int id_evento;
    TFecha fecha_evento;
    char descr_evento[MAX_DESCRIPCION];
    /****** Fin de parte Parte 4.1 *****/
};

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha) {
    TEvento nuevoEvento = NULL;
    /************ Parte 4.2 ************/
    /*Escriba el código a continuación */
    nuevoEvento = new rep_evento;
    nuevoEvento->id_evento = id;
    strcpy(nuevoEvento->descr_evento,descripcion);
    nuevoEvento->fecha_evento = fecha;
    /****** Fin de parte Parte 4.2 *****/
    return nuevoEvento;
}

void imprimirTEvento(TEvento evento) {
    /************ Parte 4.3 ************/
    /*Escriba el código a continuación */
    int largo;
    printf("Evento %d: ",evento->id_evento);
    largo = strlen(evento->descr_evento);
    for (int i = 0; (i < largo); i++)
    {
        printf("%c",evento->descr_evento[i]);
    }
    printf("\n");
    printf("Fecha: ");
    imprimirTFecha(evento->fecha_evento);
    /****** Fin de parte Parte 4.3 *****/
}
void liberarTEvento(TEvento &evento) {
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    liberarTFecha(evento->fecha_evento);
    delete evento;
    evento = NULL;
    /****** Fin de parte Parte 4.4 *****/
}

int idTEvento(TEvento evento) {
    int res = 0;
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    res = evento->id_evento;
    /****** Fin de parte Parte 4.4 *****/
    return res;
}

TFecha fechaTEvento(TEvento evento) {
    TFecha fecha = NULL;
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    fecha = evento->fecha_evento;
    /****** Fin de parte Parte 4.4 *****/
    return fecha;
}

void posponerTEvento(TEvento &evento, int dias) {
    /************ Parte 4.5 ************/
    /*Escriba el código a continuación */
    aumentarTFecha(evento->fecha_evento,dias);
    /****** Fin de parte Parte 4.5 *****/
}
