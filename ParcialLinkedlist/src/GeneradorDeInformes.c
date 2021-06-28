#include "GeneradorDeInformes.h"
#include "Vuelos.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/**
 * @fn int vuelo_ContarPasajerosTotales(void*)
 * @brief devuelve la cantidad de pasajeros
 *
 * @param elemento void*
 * @return cantPasajeros int
 */
int GeneradorDeInformes_ContarPasajerosTotales(void* elemento)
{
	int cantPasajeros;
	vuelo_getCantPasajeros(((eVuelo*)elemento),&cantPasajeros);
	return cantPasajeros;
}

/**
 * @fn int vuelo_ContarPasajerosAChina(void*)
 * @brief  si el vuelo va a china, devuelve la cantidad de pasajeros
 *
 * @param elemento void*
 * @return cantidad de pasajeros
 */
int GeneradorDeInformes_ContarPasajerosAChina(void* elemento)
{
	int valor=0;
	int cantPasajeros;
	char destino[128];
	vuelo_getDestino((eVuelo*)elemento,destino);
	if( strcmp(destino,"China")==0)
	{
		vuelo_getCantPasajeros(((eVuelo*)elemento),&cantPasajeros);
		valor=cantPasajeros;
	}
	return valor;
}


