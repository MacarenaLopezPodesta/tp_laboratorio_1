#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}eEmployee;

#define EMPTY 0
#define OCUPADO 1
void MostrarSectores(void);
int initEmployees(eEmployee listadoEmpleado[], int len);
int CargaLibre(eEmployee listadoEmpleado[], int len);
int addEmployee(eEmployee listadoEmpleado[], int len);
eEmployee CargarEmpleado(eEmployee listadoEmpleado[],int len,int index);
int ValidarSector(eEmployee listadoEmpleado[],int sectorEmpleadoID);
int BuscarSectorPorId(eEmployee listadoEmpleado[],int sectorEmpleadoID);
int findEmployeeById(eEmployee listadoEmpleado[], int len);
void removeEmployee(eEmployee listadoEmpleado[],int index);
void ModificarEmpleado(eEmployee listadoEmpleado[], int index);
void MostrarUnEmpleadoConIndex(eEmployee listadoEmpleado[],int index);
int printEmployees(eEmployee listadoEmpleado[],int TamEmpleado);
void MostrarUnEmpleadoCompleto(eEmployee listadoEmpleado);
int sortEmployees(eEmployee listadoEmpleado[], int tamEmpleado);
float SalarioTotal(eEmployee listadoEmpleado[], int tamEmpleado);
void CantidadDeEmpleadosSuperanPromedio(eEmployee listadoEmpleado[], int tamEmpleado,float promedioSalario);
float PromedioSalario(float salarioTotal,int contadorSalario);
#endif /* EMPLOYEE_H_ */
