#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Validaciones.h"
/**
 * @brief Imprime el Menu
 * \param void
 *
 */
void Menu()
{
	printf("\nMenu:\n");
	printf("1.Cargar archivo Pilotos: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.\n");
	printf("2.Cargar archivo Vuelos: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.\n");
	printf("3.Imprimir vuelos\n");
	printf("4.Cantidad de pasajeros: Cantidad de pasajeros totales\n");
	printf("5.Cantidad de pasajeros a China: cantidad de pasajeros a China.\n");
	printf("6.Salir\n");
}
/**
 * @fn int cargarPathVuelos(char*)
 * @brief Determina el path
 *
 * @param path
 * @return error
 */
int cargarPathVuelos(char* path)
{
	int error=0;
	printf("Ingrese el nombre del archivo de vuelo que quiere cargar sin el .csv: \n ARCHIVO DISPONIBLE: Vuelos.csv");
	getString(path,strlen(path),"","");
    if(strcmp(path,"Vuelos")==0)
    {
    	 strcat(path,".csv");
    	 error=1;
    }
	return error;
}
/**
 * @fn int cargarPathPilotos(char*)
 * @brief Determina el path
 *
 * @param path
 * @return error
 */
int cargarPathPilotos(char* path)
{
	int error=0;
	printf("Ingrese el nombre del archivo de pilotos que quiere cargar sin el .csv: \n ARCHIVO DISPONIBLE: Pilotos.csv");
	getString(path,strlen(path),"","");
    if(strcmp(path,"Pilotos")==0)
    {
    	 strcat(path,".csv");
    	 error=1;
    }
	return error;
}
