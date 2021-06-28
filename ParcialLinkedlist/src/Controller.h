#include "Vuelos.h"
#include "Pilotos.h"
#include "LinkedList.h"
#include "parser.h"
#include "Validaciones.h"
#include "GeneradorDeInformes.h"

int LopezPodesta_controller_loadFromTextVuelos(char* path , LinkedList* pArrayListVuelos);
int LopezPodesta_controller_loadFromTextPilotos(char* path , LinkedList* pArrayListPilotos);
int LopezPodesta_controller_ListVuelo(LinkedList* pArrayListVuelo,LinkedList* pArrayListPiloto);
int LopezPodesta_controller_CountPasajerosTotales(LinkedList* listaVuelos);
int LopezPodesta_controller_CountPasajerosAChina(LinkedList* listaVuelos);


