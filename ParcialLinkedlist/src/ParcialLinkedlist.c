/*
 ============================================================================
PARTE 1
Una empresa de Aerolíneas debe gestionar los diferentes vuelos que serán efectuados en los próximos días,
para ello cuenta con un registro que presenta el siguiente formato:
idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada Por ejemplo:
49, 3, 3, 28/11/2019, Portugal, 63, 16, 21
Los pilotos que trabajan en la Aerolínea son los siguientes:
ID         Nombre
1          Alex Lifeson
2          Richard Bach
3          John Kerry
4          Erwin Rommel
5          Stephen Coonts

El programa contará con el siguiente menú:
1) Cargar archivo Pilotos: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.
2) Cargar archivo Vuelos: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.
3) Imprimir vuelos: Se imprimirá por pantalla la tabla con los datos de los vuelos indicando el nombre del piloto
(no el número)
4) Cantidad de pasajeros: Cantidad de pasajeros totales
5) Cantidad de pasajeros a China: cantidad de pasajeros a China.
6) Salir.
Para realizar los ejercicios enunciados anteriormente deberá implementar en su biblioteca LinkedList la siguiente funcione:
Detalle de la función “ll_count()”

Prototipo de la función:
int ll_count(LinkedList* this, int (*fn)(void* element))
La función “ll_count” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos de la lista
y pasárselos a la funcion “fn”. La función “fn” devolverá la cantidad que debe contarse segun el criterio.
La función “ll_count” almacenará un acumulador al cual sumará el valor de retorno de “fn” en cada iteración.
Al finalizar las iteraciones, la función “ll_count” devolverá el valor acumulado.
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones
y respetar las reglas de estilo de la cátedra.
Nota 1: Separar en archivos las entidades, parser y generador de informes.
Nota 2: El uso de una biblioteca Controller es obligatoria. Las funciones de la misma deberán nomenclarse
de la siguiente forma:
Apellido_Entidad_NombreFuncion

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
int main(void) {
	int option=0;
	setbuf(stdout,NULL);
    char path[30];
	LinkedList* listaPilotos = ll_newLinkedList();
	LinkedList* listaVuelos = ll_newLinkedList();
	do{
		Menu();
     	option=getIntNew(" ","Error, ingrese un numero:\n");

	        switch(option)
	        {
	            case 1:
                     if(cargarPathPilotos(path)==1)
                     {
                    	 //printf("%s\n",path);
                    	 LopezPodesta_controller_loadFromTextPilotos(path,listaPilotos);
						// printf("%d\n",ll_len(listaPilotos));
						 printf("CORRECTO\n");
                     }
	                break;
	            case 2:
	            	if(cargarPathVuelos(path)==1)
	            	{
	            		//printf("%s\n",path);
						LopezPodesta_controller_loadFromTextVuelos(path,listaVuelos);
						//printf("%d\n",ll_len(listaVuelos));
						printf("CORRECTO\n");
	            	 }
					break;
	            case 3:
	            	LopezPodesta_controller_ListVuelo(listaVuelos,listaPilotos);
	            	break;
	            case 4:
	            	LopezPodesta_controller_CountPasajerosTotales(listaVuelos);
	            	break;
	            case 5:
	            	LopezPodesta_controller_CountPasajerosAChina(listaVuelos);
	            	break;
	            case 6:
	            	printf("ACABA DE SALIR DEL PROGRAMA\n");
	            	break;
	        }
	    }while(option != 6);
	return option;
}
