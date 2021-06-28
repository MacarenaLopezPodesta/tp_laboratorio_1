#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Pilotos.h"

/**
 * @fn ePiloto piloto_new*()
 * @brief Crea el espacio para un piloto
 *
 * @return ePiloto*
 */
ePiloto* piloto_new()
{
	ePiloto* piloto=(ePiloto*)malloc(sizeof(ePiloto));
	return piloto;
}
/**
 * @fn ePiloto piloto_newParametros*(char*, char*)
 * @brief Guarda los parametros dentro del piloto
 *
 * @param idStr char*
 * @param nombreStr char*
 * @return ePiloto*
 */
ePiloto* piloto_newParametros(char* idStr,char* nombreStr)
{
	ePiloto* piloto = piloto_new();
	if(idStr!=NULL && nombreStr!=NULL)
	{
		piloto_setId(piloto,atoi(idStr));
		piloto_setNombre(piloto,nombreStr);
	}
	return piloto;
}
/**
 * @fn int piloto_setId(ePiloto*, int)
 * @brief Establece el id
 *
 * @param this ePiloto*
 * @param id int
 * @return error int
 */
int piloto_setId(ePiloto* this,int id)
{
	int error=0;
	if(this!=NULL)
	{
		this->id = id;
		error=1;
	}
	return error;
}
/**
 * @fn int piloto_getId(ePiloto*, int*)
 * @brief Obtiene el Id
 *
 * @param this ePiloto*
 * @param id int*
 * @return error int
 */
int piloto_getId(ePiloto* this,int* id)
{
	int error=0;
	if(this!=NULL)
	  {
		*id = this->id;
		 error=1;
	  }
	return error;
}
/**
 * @fn int piloto_setNombre(ePiloto*, char*)
 * @brief Establece el Nombre
 *
 * @param this ePiloto*
 * @param nombre char*
 * @return error int
 */
int piloto_setNombre(ePiloto* this,char* nombre)
{
	int error=0;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		error=1;
	}
	return error;
}
/**
 * @fn int piloto_getNombre(ePiloto*, char*)
 * @brief Obtiene el nombre
 *
 * @param this ePiloto*
 * @param nombre char*
 * @return error int
 */
int piloto_getNombre(ePiloto* this,char* nombre)
{
	int error = 0;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		error = 1;
	}
	return error;
}

