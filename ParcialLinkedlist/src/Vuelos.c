#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Vuelos.h"

/**
 * @fn eVuelo vuelo_new*()
 * @brief Crea el espacio para un vuelo
 *
 * @return eVuelo*
 */
eVuelo* vuelo_new()
{
	eVuelo* vuelo=(eVuelo*)malloc(sizeof(eVuelo));
	return vuelo;
}
/**
 * @fn eVuelo vuelo_newParametros*(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*)
 * @brief Guarda los parametros dentro del vuelo
 *
 * @param idVuelo
 * @param idAvion
 * @param idPiloto
 * @param dia
 * @param mes
 * @param anio
 * @param destino
 * @param cantPasajeros
 * @param horaDespegue
 * @param horaLlegada
 * @return eVuelo*
 */
eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto, char* dia, char* mes, char* anio,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
	eVuelo* vuelo = vuelo_new();
	if(idVuelo!=NULL && idAvion!=NULL && idPiloto!=NULL && dia!=NULL && mes!=NULL && anio!=NULL && destino!=NULL && cantPasajeros!=NULL && horaDespegue!=NULL && horaLlegada!=NULL)
	{
		vuelo_setIdVuelo(vuelo,atoi(idVuelo));
		vuelo_setIdAvion(vuelo,atoi(idAvion));
		vuelo_setIdPiloto(vuelo,atoi(idPiloto));
		vuelo_setDia(vuelo,atoi(dia));
		vuelo_setMes(vuelo,atoi(mes));
		vuelo_setAnio(vuelo,atoi(anio));
		vuelo_setDestino(vuelo,destino);
		vuelo_setCantPasajeros(vuelo,atoi(cantPasajeros));
		vuelo_setHoraDespegue(vuelo,atoi(horaDespegue));
		vuelo_setHoraLlegada(vuelo,atoi(horaLlegada));
	}
	return vuelo;
}
/**
 * @fn int vuelo_getIdAvion(eVuelo*, int*)
 * @brief Obtiene el idAvion
 *
 * @param this eVuelo*
 * @param idAvion int*
 * @return error int
 */
int vuelo_getIdAvion(eVuelo* this,int* idAvion)
{
	int error=0;
	if(this!=NULL)
	  {
		*idAvion = this->idAvion;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getIdVuelo(eVuelo*, int*)
 * @brief Obtiene el idVuelo
 *
 * @param this eVuelo*
 * @param idVuelo int*
 * @return error int
 */
int vuelo_getIdVuelo(eVuelo* this,int* idVuelo)
{
	int error=0;
	if(this!=NULL)
	{
	   *idVuelo = this->idVuelo;
	   error=1;
	}
	return error;
}
/**
 * @fn int vuelo_getIdPiloto(eVuelo*, int*)
 * @brief Obtiene el idPiloto
 *
 * @param this eVuelo*
 * @param idPiloto int*
 * @return error int
 */
int vuelo_getIdPiloto(eVuelo* this,int* idPiloto)
{
	int error=0;
	if(this!=NULL)
	  {
		*idPiloto = this->idPiloto;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getDia(eVuelo*, int*)
 * @brief Obtiene el di
 *
 * @param this eVuelo*
 * @param dia int*
 * @return error int
 */
int vuelo_getDia(eVuelo* this,int* dia)
{
	int error=0;
	if(this!=NULL)
	  {
		*dia = this->fecha.dia;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getMes(eVuelo*, int*)
 * @brief Obtiene el mes
 *
 * @param this eVuelo*
 * @param mes int*
 * @return error int
 */
int vuelo_getMes(eVuelo* this,int* mes)
{
	int error=0;
	if(this!=NULL)
	  {
		*mes = this->fecha.mes;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getAnio(eVuelo*, int*)
 * @brief Obtiene el anio
 *
 * @param this eVuelo*
 * @param anio int*
 * @return error int
 */
int vuelo_getAnio(eVuelo* this,int* anio)
{
	int error=0;
	if(this!=NULL)
	  {
		*anio = this->fecha.anio;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getCantPasajeros(eVuelo*, int*)
 * @brief Obtiene la cantPasajeros
 *
 * @param this eVuelo*
 * @param cantPasajeros int*
 * @return error int
 */
int vuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros)
{
	int error=0;
	if(this!=NULL)
	{
		*cantPasajeros = this->cantPasajeros;
		 error=1;
	}
	return error;
}
/**
 * @fn int vuelo_getHoraDespegue(eVuelo*, int*)
 * @brief Obtiene la horaDespegue
 *
 * @param this eVuelo*
 * @param horaDespegue int*
 * @return error int
 */
int vuelo_getHoraDespegue(eVuelo* this,int* horaDespegue)
{
	int error=0;
	if(this!=NULL)
	  {
		*horaDespegue = this->horaDespegue;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getHoraLlegada(eVuelo*, int*)
 * @brief Obtiene la horaLlegada
 *
 * @param this eVuelo*
 * @param horaLlegada int*
 * @return error int
 */
int vuelo_getHoraLlegada(eVuelo* this,int* horaLlegada)
{
	int error=0;
	if(this!=NULL)
	  {
		*horaLlegada = this->horaLlegada;
		 error=1;
	  }
	return error;
}
/**
 * @fn int vuelo_getDestino(eVuelo*, char*)
 * @brief Obtiene el destino
 *
 * @param this eVuelo*
 * @param destino char*
 * @return error int
 */
int vuelo_getDestino(eVuelo* this,char* destino)
{
	int error = 0;
	if (this != NULL && destino != NULL)
	{
		strcpy(destino, this->destino);
		error = 1;
	}
	return error;
}
/**
 * @fn int vuelo_setDia(eVuelo*, int)
 * @brief Establece el dia
 *
 * @param this eVuelo*
 * @param dia int
 * @return error int
 */
int vuelo_setDia(eVuelo* this,int dia)
{
	int error=0;
	if(this!=NULL)
	{
		this->fecha.dia = dia;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setMes(eVuelo*, int)
 * @brief Establece el mes
 *
 * @param this eVuelo*
 * @param mes int
 * @return error int
 */
int vuelo_setMes(eVuelo* this,int mes)
{
	int error=0;
	if(this!=NULL)
	{
		this->fecha.mes = mes;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setAnio(eVuelo*, int)
 * @brief Establece el anio
 *
 * @param this eVuelo*
 * @param anio int
 * @return error int
 */
int vuelo_setAnio(eVuelo* this,int anio)
{
	int error=0;
	if(this!=NULL)
	{
		this->fecha.anio = anio;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setIdVuelo(eVuelo*, int)
 * @brief Establece el idVuelo
 *
 * @param this eVuelo*
 * @param idVuelo int
 * @return error int
 */
int vuelo_setIdVuelo(eVuelo* this,int idVuelo)
{
	int error=0;
	if(this!=NULL)
	{
		this->idVuelo = idVuelo;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setIdAvion(eVuelo*, int)
 * @brief Establece el idAvion
 *
 * @param this eVuelo*
 * @param idAvion int
 * @return error int
 */
int vuelo_setIdAvion(eVuelo* this,int idAvion)
{
	int error=0;
	if(this!=NULL)
	{
		this->idAvion = idAvion;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setIdPiloto(eVuelo*, int)
 * @brief Establece el idPiloto
 *
 * @param this int
 * @param idPiloto eVuelo*
 * @return error int
 */
int vuelo_setIdPiloto(eVuelo* this,int idPiloto)
{
	int error=0;
	if(this!=NULL)
	{
		this->idPiloto = idPiloto;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setDestino(eVuelo*, char*)
 * @brief Establece el destino
 *
 * @param this eVuelo*
 * @param destino char*
 * @return error int
 */
int vuelo_setDestino(eVuelo* this,char* destino)
{
	int error=0;
	if(this!=NULL)
	{
		strcpy(this->destino,destino);
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setCantPasajeros(eVuelo*, int)
 * @brief Establece la cantPasajeros
 *
 * @param this eVuelo*
 * @param cantPasajeros int
 * @return error int
 */
int vuelo_setCantPasajeros(eVuelo* this,int cantPasajeros)
{
	int error=0;
	if(this!=NULL)
	{
		this->cantPasajeros = cantPasajeros;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setHoraDespegue(eVuelo*, int)
 * @brief Establece la horaDespegue
 *
 * @param this eVuelo*
 * @param horaDespegue int
 * @return error int
 */
int vuelo_setHoraDespegue(eVuelo* this,int horaDespegue)
{
	int error=0;
	if(this!=NULL)
	{
		this->horaDespegue = horaDespegue;
		error=1;
	}
	return error;
}
/**
 * @fn int vuelo_setHoraLlegada(eVuelo*, int)
 * @brief Establece la horaLlegada
 *
 * @param this eVuelo*
 * @param horaLlegada int
 * @return error int
 */
int vuelo_setHoraLlegada(eVuelo* this,int horaLlegada)
{
	int error=0;
	if(this!=NULL)
	{
		this->horaLlegada = horaLlegada;
		error=1;
	}
	return error;
}


/**
 * @fn int vuelo_MostarUnVuelo(eVuelo*, ePiloto*)
 * @brief Imprime un vuelo
 *
 * @param vuelo eVuelo*
 * @param piloto ePiloto*
 * @return error int
 */
int vuelo_MostarUnVuelo(eVuelo* vuelo,ePiloto* piloto)
{
	int error=0;
	int idVuelo;
	int idAvion;
	char nombre[128];
	int dia;
	int mes;
	int anio;
	char destino[128];
	int horaDespegue;
	int cantPasajeros;
	int horaLlegada;
    if(vuelo!=NULL && piloto!=NULL)
    {
    	vuelo_getIdVuelo(vuelo,&idVuelo);
		vuelo_getIdAvion(vuelo,&idAvion);
		piloto_getNombre(piloto,nombre);
		vuelo_getDia(vuelo,&dia);
		vuelo_getMes(vuelo,&mes);
		vuelo_getAnio(vuelo,&anio);
		vuelo_getDestino(vuelo,destino);
		vuelo_getCantPasajeros(vuelo,&cantPasajeros);
		vuelo_getHoraDespegue(vuelo,&horaDespegue);
		vuelo_getHoraLlegada(vuelo,&horaLlegada);

		printf("\n%15d %15d %25s %10d/%d/%d %20s %15d %15d %15d\n",idVuelo,idAvion,nombre,dia,mes,anio,destino,cantPasajeros,horaDespegue,horaLlegada);
        error=1;
    }
	return error;
}
/**
 * @fn ePiloto vuelo_DameUnPiloto*(LinkedList*, eVuelo*)
 * @brief Busca un piloto en base a el vuelo
 *
 * @param pArrayListPiloto LinkedList*
 * @param vuelo eVuelo*
 * @return ePiloto*
 */
ePiloto* vuelo_DameUnPiloto(LinkedList* pArrayListPiloto,eVuelo* vuelo)
{
	int lenPiloto=ll_len(pArrayListPiloto);
    void* valor=NULL;
    ePiloto* piloto;
    int vuelo_idPiloto;
    int piloto_id;

    if(pArrayListPiloto!=NULL && vuelo!=NULL)
    {
    	for(int i=0;i<lenPiloto;i++)
    		{
    			piloto=(ePiloto*)ll_get(pArrayListPiloto,i);
    			piloto_getId(piloto,&piloto_id);
    			vuelo_getIdPiloto(vuelo,&vuelo_idPiloto);
    			if(vuelo_idPiloto==piloto_id)
    			{
    				valor=piloto;
    				break;
    			}
    		}
    }
		return valor;
}
