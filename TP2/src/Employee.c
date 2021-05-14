#include "Employee.h"
#include "Validaciones.h"

int initEmployees(eEmployee listadoEmpleado[], int len)
{
	int i;
	for (i=0;i<len;i++)
	{
		listadoEmpleado[i].isEmpty=EMPTY;
	}
	return 0;
}
int CargaLibre(eEmployee listadoEmpleado[], int len)
{
	int i;
	int index;
	index=-1;
	for (i=0;i<len;i++)
	{
		if (listadoEmpleado[i].isEmpty==EMPTY)
		{
			index=i;
			break;
		}
	}
	return index;
}
int addEmployee(eEmployee listadoEmpleado[], int len)
{
	int index;
	index=CargaLibre(listadoEmpleado,len);

	if (index==-1)
	{
		printf("No hay espacio disponible\n");
	}
	else
	{
		listadoEmpleado[index]=CargarEmpleado(listadoEmpleado,len,index);
	}
	return 0;
}
eEmployee CargarEmpleado(eEmployee listadoEmpleado[],int len,int index)
{
	eEmployee nuevoEmpleado;

	nuevoEmpleado.id=index+1;

	getStringWithNumbers(nuevoEmpleado.name,sizeof(nuevoEmpleado.name),"Ingrese el nombre del empleado: ","ERROR.Ingrese el nombre del empleado: ");

	getStringWithNumbers(nuevoEmpleado.lastName,sizeof(nuevoEmpleado.lastName),"Ingrese el apellido del empleado: ","ERROR.Ingrese el apellido del empleado: ");

	nuevoEmpleado.salary=getFloatNew("Ingrese salario: ","ERROR. Ingrese salario:");

	MostrarSectores();
    nuevoEmpleado.sector=getIntNew("Ingrese un id de sector: \n","ERROR. Ingrese un id de sector: \n");
    nuevoEmpleado.sector=ValidarSector(listadoEmpleado,nuevoEmpleado.sector);

	nuevoEmpleado.isEmpty=OCUPADO;

    return nuevoEmpleado;
}
void MostrarSectores(void)
{
	printf("----ID DE SECTORES----\n");
	for(int i=0;i<4;i++)
	{
		printf("---------%d---------\n",1000+i);
	}
	printf("----------------------\n");
}
int ValidarSector(eEmployee listadoEmpleado[],int sectorEmpleadoID)
{
	int index;
	index=BuscarSectorPorId(listadoEmpleado,sectorEmpleadoID);
	while(index==-1)
	{
		MostrarSectores();
		sectorEmpleadoID=getIntNew("Ingrese un id de sector: \n","ERROR. Ingrese un id de sector: \n");
		index=BuscarSectorPorId(listadoEmpleado,sectorEmpleadoID);
	}
	return sectorEmpleadoID;
}
int BuscarSectorPorId(eEmployee listadoEmpleado[],int sectorEmpleadoID)
{
	int index=1;

	if (sectorEmpleadoID!=1000&&sectorEmpleadoID!=1001&&sectorEmpleadoID!=1002&&sectorEmpleadoID!=1003)
	{
		index=-1;
	}

	return index;
}

int findEmployeeById(eEmployee listadoEmpleado[], int len)
{
    int i;
	int idEmpledo;
	int index;
	index=-1;
	printf("Ingrese la id del empleado: ");
	scanf("%d", &idEmpledo);
	for (i=0;i<len;i++)
	{
		if (idEmpledo==listadoEmpleado[i].id && listadoEmpleado[i].isEmpty!=EMPTY)
		{
			index=i;
			break;
		}
	}
	return index;
}
void removeEmployee(eEmployee listadoEmpleado[],int index)
{
    int opcion;
    MostrarUnEmpleadoConIndex(listadoEmpleado,index);
	printf("\nIngrese 1 si desea eliminar el empleado: ");
	scanf("%d", &opcion);
	if (opcion == 1)
	{
		listadoEmpleado[index].isEmpty = EMPTY;
		printf("SE HA ELIMINADO EL EMPLEADO\n");
		MostrarUnEmpleadoConIndex(listadoEmpleado,index);
	}
	else
	{
		printf("HA CANCELADO LA ELIMINACION\n");
	}
}
void ModificarEmpleado(eEmployee listadoEmpleado[], int index)
{
	int opcion;
	MostrarUnEmpleadoConIndex(listadoEmpleado,index);
	printf("\nIngrese para modificar: 1.nombre , 2.apellido, 3.salario, 4.sector o 5.salir : ");
	scanf("%d", &opcion);
	while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5)
	{
		printf("\nERROR.Ingrese para modificar: 1.nombre , 2.apellido, 3.salario, 4.sector o 5.salir : ");
		scanf("%d", &opcion);
	}

	switch(opcion)
	{
		case 1:
			getStringWithNumbers(listadoEmpleado[index].name,sizeof(listadoEmpleado[index].name),"Ingrese el nombre del empleado: ","ERROR.Ingrese el nombre del empleado: ");
			printf("MODIFICACION EXITOSA\n");
			break;
		case 2:
			getStringWithNumbers(listadoEmpleado[index].lastName,sizeof(listadoEmpleado[index].lastName),"Ingrese el apellido del empleado: ","ERROR.Ingrese el apellido del empleado: ");
			printf("MODIFICACION EXITOSA\n");
			break;
		case 3:
			listadoEmpleado[index].salary=getFloatNew("Ingrese salario: ","ERROR. Ingrese salario:");
			printf("MODIFICACION EXITOSA\n");
            break;
		case 4:
			MostrarSectores();
			listadoEmpleado[index].sector=getIntNew("Ingrese un id de sector: \n","ERROR. Ingrese un id de sector: \n");
			listadoEmpleado[index].sector=ValidarSector(listadoEmpleado,listadoEmpleado[index].sector);
			printf("MODIFICACION EXITOSA\n");
			break;
	}


}
void MostrarUnEmpleadoConIndex(eEmployee listadoEmpleado[],int index)
{
	printf("id del empleado: %d, nombre :%s, apellido: %s, salario: %.2f, id sector: %d\n",
			listadoEmpleado[index].id,
			listadoEmpleado[index].name,
			listadoEmpleado[index].lastName,
			listadoEmpleado[index].salary,
			listadoEmpleado[index].sector);
}
int printEmployees(eEmployee listadoEmpleado[],int TamEmpleado)
{
	int i;

	for(i = 0; i < TamEmpleado; i++)
	{
		MostrarUnEmpleadoCompleto(listadoEmpleado[i]);
	}
	return 0;
}
void MostrarUnEmpleadoCompleto(eEmployee listadoEmpleado)
{
	if(listadoEmpleado.isEmpty==OCUPADO)
	{
		printf("id del empleado: %d, nombre :%s, apellido: %s, salario: %.2f, id sector: %d\n",
					listadoEmpleado.id,
					listadoEmpleado.name,
					listadoEmpleado.lastName,
					listadoEmpleado.salary,
					listadoEmpleado.sector);
	}
}
int sortEmployees(eEmployee listadoEmpleado[], int tamEmpleado)
{
	int i;
	int j;
	eEmployee auxiliar;

	for(i=0;i<tamEmpleado-1;i++)
	{
		for (j=i+1;j<tamEmpleado;j++)
		{
			if(strcmp(listadoEmpleado[i].lastName, listadoEmpleado[j].lastName) >0  && listadoEmpleado[j].isEmpty == OCUPADO && listadoEmpleado[i].isEmpty == OCUPADO)
			{
				auxiliar = listadoEmpleado[i];
				listadoEmpleado[i] = listadoEmpleado[j];
				listadoEmpleado[j] = auxiliar;
			}
			else if(strcmp(listadoEmpleado[i].lastName, listadoEmpleado[j].lastName) == 0 && listadoEmpleado[i].sector > listadoEmpleado[j].sector  && listadoEmpleado[j].isEmpty == OCUPADO && listadoEmpleado[i].isEmpty == OCUPADO)
			{
				auxiliar = listadoEmpleado[i];
				listadoEmpleado[i] = listadoEmpleado[j];
				listadoEmpleado[j] = auxiliar;
			}
		}
	}
	return 0;
}
float SalarioTotal(eEmployee listadoEmpleado[], int tamEmpleado)
{
	int i;
	float salarioTotal=0;
	int contadorSalario=0;
    float promedioSalario;
	for(i=0;i<tamEmpleado;i++)
	{
		if(listadoEmpleado[i].isEmpty==OCUPADO)
		{
			salarioTotal=salarioTotal+listadoEmpleado[i].salary;
			contadorSalario++;
		}
	}
	promedioSalario=PromedioSalario(salarioTotal,contadorSalario);
	CantidadDeEmpleadosSuperanPromedio(listadoEmpleado,tamEmpleado,promedioSalario);
	return salarioTotal;
}
void CantidadDeEmpleadosSuperanPromedio(eEmployee listadoEmpleado[], int tamEmpleado,float promedioSalario)
{
	int contador=0;
	int i;
	for(i=0;i<tamEmpleado;i++)
	{
		if(listadoEmpleado[i].salary>promedioSalario &&listadoEmpleado[i].isEmpty==OCUPADO)
		{
			contador++;
		}
	}
	printf("Cantidad de empleados que superan el salario promedio: %d\n",contador);
}
float PromedioSalario(float salarioTotal,int contadorSalario)
{
    float promedioSalario;
    promedioSalario=salarioTotal/contadorSalario;
    printf("Promedio de salario: %.2f\n",promedioSalario);
    return promedioSalario;
}
