#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, char* ultimoId);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int OrdenamientoPorNombre(void* empleadoI, void* empleadoJ);
int OrdenamientoPorHsTrabajadas(void* empleadoI, void* empleadoJ);
int OrdenamientoPorSueldo(void* empleadoI, void* empleadoJ);
int OrdenamientoPorId(void* empleadoI, void* empleadoJ);
int controller_CargaUltimoId(char* path);
int controller_leerUltimoId(char* path, char* id);
