
#ifndef PILOTOS_H_
#define PILOTOS_H_
#include "Linkedlist.h"
typedef struct
{
    int id;
    char nombre[128];
}ePiloto;

ePiloto* piloto_new();
ePiloto* piloto_newParametros(char* idStr,char* nombreStr);

int piloto_getId(ePiloto* this,int* id);
int piloto_setId(ePiloto* this,int id);

int piloto_getNombre(ePiloto* this,char* nombre);
int piloto_setNombre(ePiloto* this,char* nombre);


#endif /* PILOTOS_H_ */
