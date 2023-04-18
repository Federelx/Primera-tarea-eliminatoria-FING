#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    delete fecha;
    fecha = NULL;
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n",fecha->dia,fecha->mes,fecha->anio);

    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/

nat diasMes(nat mes,nat anio){
    nat dias = 0;
    if ((anio % 4 == 0) || ((anio % 100 == 0) && (anio % 400 == 0)) )
    {
        switch (mes)
        {
        case 2:
            dias = 29;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        default:
            dias = 31;
            break;
        }
    }
    else{
        switch (mes)
        {
        case 2:
            dias = 28;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        default:
            dias = 31;
            break;
        }
    }
    return dias;
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio))
    {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
        
    }
    
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    if (fecha1->anio > fecha2->anio)
    {
        res = 1;
    }
    else if (fecha1->anio < fecha2->anio)
    {
        res = -1;
    }
    else if (fecha1->mes > fecha2->mes)
    {
        res = 1;
    }
    else if (fecha1->mes < fecha2->mes)  
    {
        res = -1;
    }
    else if (fecha1->dia > fecha2->dia)
    {
        res = 1;
    }
    else if (fecha1->dia < fecha2->dia)
    {
        res = -1;
    }
    
    /****** Fin de parte Parte 3.10 *****/
    return res;
}
