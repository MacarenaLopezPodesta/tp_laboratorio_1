#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
/**
 * @fn int parser_EmployeeFromTextPilotos(FILE*, LinkedList*)
 * @brief  Parsea los datos de los pilotos desde el archivo Pilotos.csv (modo texto).
 *
 * @param pFile FILE*
 * @param pArrayListPiloto LinkedList*
 * @return error int
 */
int parser_EmployeeFromTextPilotos(FILE* pFile , LinkedList* pArrayListPiloto)
{
	  int error = 0;
	  char id[20];
	  char nombre[128];
	  ePiloto* pPiloto;
	  fscanf(pFile,"%[^,],%[^\n]\n",id,nombre);
	  if(pFile!=NULL && pArrayListPiloto!=NULL)
	  {
		  ll_clear(pArrayListPiloto);
		  while(!feof(pFile))
		  {
			   fscanf(pFile,"%[^,],%[^\n]\n",id,nombre);
			   pPiloto=piloto_newParametros(id,nombre);
		       if(pPiloto!=NULL)
		       {
				 ll_add(pArrayListPiloto,pPiloto);
				 error=1;
		       }
		  }
	  }
	  return error;
}
/**
 * @fn int parser_EmployeeFromTextVuelos(FILE*, LinkedList*)
 * @brief Parsea los datos de los vuelos desde el archivo Vuelos.csv (modo texto).
 *
 * @param pFile FILE*
 * @param pArrayListVuelo LinkedList*
 * @return error int
 */
int parser_EmployeeFromTextVuelos(FILE* pFile , LinkedList* pArrayListVuelo)
{
	  int error = 0;
	  char idVuelo[20];
	  char idAvion[20];
	  char idPiloto[20];
	  char fecha[128];
	  char dia[20];
	  char mes[20];
	  char anio[20];
	  char destino[128];
	  char cantPasajeros[20];
	  char horaDespegue[20];
	  char horaLlegada[20];
	  eVuelo* pVuelo;

	  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,
			                                                            fecha,destino,cantPasajeros,
																		horaDespegue,horaLlegada);
	  if(pFile!=NULL && pArrayListVuelo!=NULL)
	  {
		  ll_clear(pArrayListVuelo);
		  while(!feof(pFile))
		  {
			  fscanf(pFile,"%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,
			  			                                                        dia,mes,anio,destino,cantPasajeros,
			  																	horaDespegue,horaLlegada);
			   pVuelo=vuelo_newParametros(idVuelo,idAvion,idPiloto,
                                    dia,mes,anio,destino,cantPasajeros,
						        	horaDespegue,horaLlegada);
		       if(pVuelo!=NULL)
		       {
				 ll_add(pArrayListVuelo,pVuelo);
				 error=1;
		       }
		  }
	  }
	  return error;
}


