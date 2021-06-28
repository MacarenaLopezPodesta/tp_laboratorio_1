#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
/**
 * @fn int LopezPodesta_controller_loadFromTextVuelos(char*, LinkedList*)
 * @brief Carga los datos de los vuelos desde el archivo Vuelos.csv (modo texto).
 *
 * @param path char*
 * @param pArrayListVuelos LinkedList*
 * @return int
 */
int LopezPodesta_controller_loadFromTextVuelos(char* path , LinkedList* pArrayListVuelos)
{
	int error = 0;
	FILE* pArchivo;
	pArchivo=fopen(path,"r");
	if(path!=NULL && pArrayListVuelos!=NULL && pArchivo!=NULL)
	{
		  if(parser_EmployeeFromTextVuelos(pArchivo,pArrayListVuelos)==1)
		  {
			  printf("\nSe cargo correctamente\n");
			  error = 1;
		  }else
		  {
			  printf("\nArchivo vacio\n");
		  }
	}
	fclose(pArchivo);
    return error;
}
/**
 * @fn int LopezPodesta_controller_loadFromTextPilotos(char*, LinkedList*)
 * @brief Carga los datos de los pilotos desde el archivo Pilotos.csv (modo texto).
 *
 * @param path char*
 * @param pArrayListPilotos LinkedList*
 * @return error int
 */
int LopezPodesta_controller_loadFromTextPilotos(char* path , LinkedList* pArrayListPilotos)
{
	int error = 0;
	FILE* pArchivo;
	pArchivo=fopen(path,"r");
	if(path!=NULL && pArrayListPilotos!=NULL && pArchivo!=NULL)
	{
		  if(parser_EmployeeFromTextPilotos(pArchivo,pArrayListPilotos)==1)
		  {
			  printf("\nSe cargo correctamente\n");
			  error = 1;
		  }else
		  {
			  printf("\nArchivo vacio\n");
		  }
	}
	fclose(pArchivo);
    return error;
}
/**
 * @fn int LopezPodesta_controller_CountPasajerosTotales(LinkedList*)
 * @brief Muestra los pasajeros totales que hay cargados, llamando a ll_count
 *
 * @param listaVuelos LinkedList*
 * @return int error
 */
int LopezPodesta_controller_CountPasajerosTotales(LinkedList* listaVuelos)
{
	int pasajerosTotales;
	int error=0;
	if(listaVuelos!=NULL)
	{
		pasajerosTotales=ll_count(listaVuelos,GeneradorDeInformes_ContarPasajerosTotales);
		printf("\nPASAJEROS TOTALES: %d\n",pasajerosTotales);
		error=1;
	}
	return error;
}
/**
 * @fn int LopezPodesta_controller_CountPasajerosAChina(LinkedList*)
 * @brief Muestra los pasajeros que van a China, llamando a ll_count
 *
 * @param listaVuelos LinkedList*
 * @return error int
 */
int LopezPodesta_controller_CountPasajerosAChina(LinkedList* listaVuelos)
{
	int pasajerosTotales;
	int error=0;
	if(listaVuelos!=NULL)
	{
		pasajerosTotales=ll_count(listaVuelos,GeneradorDeInformes_ContarPasajerosAChina);
		printf("\nPASAJEROS A CHINA: %d\n",pasajerosTotales);
		error=1;
	}
	return error;
}
/**
 * @fn int LopezPodesta_controller_ListVuelo(LinkedList*, LinkedList*)
 * @brief Lista todos los vuelos
 *
 * @param pArrayListVuelo LinkedList*
 * @param pArrayListPiloto LinkedList*
 * @return error int
 */
int LopezPodesta_controller_ListVuelo(LinkedList* pArrayListVuelo,LinkedList* pArrayListPiloto)
{
	int error=1;
	int i;
	eVuelo* vuelo;
	ePiloto* piloto;
	int lenVuelo=ll_len(pArrayListVuelo);
	if(pArrayListVuelo!=NULL && pArrayListPiloto!=NULL)
	 {
		printf("\n%15s %15s %25s %15s %20s %15s %15s %15s\n","idVuelo","idAvion","piloto","fecha","destino","cantPasajeros","horaDespegue","horaLlegada");
		for(i=0;i<lenVuelo;i++)
	    {
			vuelo = (eVuelo*)ll_get(pArrayListVuelo,i);
			piloto=vuelo_DameUnPiloto(pArrayListPiloto,vuelo);
			if(piloto!=NULL)
			{
				vuelo_MostarUnVuelo(vuelo,piloto);
			}
		    error=0;
	    }
	  }
	return error;
}
