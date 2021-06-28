/*
 * Vuelos.h
 *
 *  Created on: 26 jun. 2021
 *      Author: Begonia
 */

#ifndef VUELOS_H_
#define VUELOS_H_
#include "Fecha.h"
#include "Pilotos.h"
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    eFecha fecha;
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelo;

eVuelo* vuelo_new();
eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto, char* dia, char* mes, char* anio,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);

int vuelo_setIdVuelo(eVuelo* this,int idVuelo);
int vuelo_getIdVuelo(eVuelo* this,int* idVuelo);

int vuelo_setIdAvion(eVuelo* this,int idAvion);
int vuelo_getIdAvion(eVuelo* this,int* idAvion);

int vuelo_setIdPiloto(eVuelo* this,int idPiloto);
int vuelo_getIdPiloto(eVuelo* this,int* idPiloto);

int vuelo_setDia(eVuelo* this,int dia);
int vuelo_getDia(eVuelo* this,int* dia);

int vuelo_setMes(eVuelo* this,int mes);
int vuelo_getMes(eVuelo* this,int* mes);

int vuelo_setAnio(eVuelo* this,int anio);
int vuelo_getAnio(eVuelo* this,int* anio);

int vuelo_setDestino(eVuelo* this,char* destino);
int vuelo_getDestino(eVuelo* this,char* destino);

int vuelo_setCantPasajeros(eVuelo* this,int cantPasajeros);
int vuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros);

int vuelo_setHoraDespegue(eVuelo* this,int horaDespegue);
int vuelo_getHoraDespegue(eVuelo* this,int* horaDespegue);

int vuelo_setHoraLlegada(eVuelo* this,int horaLlegada);
int vuelo_getHoraLlegada(eVuelo* this,int* horaLlegada);

int vuelo_MostarUnVuelo(eVuelo* vuelo,ePiloto* piloto);
ePiloto* vuelo_DameUnPiloto(LinkedList* pArrayListPiloto,eVuelo* vuelo);
#endif /* VUELOS_H_ */
