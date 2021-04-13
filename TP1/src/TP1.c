/*
 ============================================================================
 Name        : TrabajoPracticoNumero1.c
 Author      : Macarena Lopez Podesta

Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)

• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "OperacionesMatematicas.h"

int main(void)
{
	int opcion;
	float numeroUno;
	float numeroDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialNumeroUno;
	float resultadoFactorialNumeroDos;
	int banderaPrimerNumero;
	int banderaSegundoNumero;
	int contadorCase3;

	banderaPrimerNumero=1;
	banderaSegundoNumero=1;
	contadorCase3=0;

	setbuf(stdout, NULL);

	printf("BIENVENIDO A LA CALCULADORA\n");
	printf("Ingrese un numero del menu para comenzar a operar: \n");
	do
	{
		if(banderaPrimerNumero==1)
		{
		  printf("\n1. Ingresar 1er operando (A=x)\n");
		}else
		{
			printf("\n1. Ingresar 1er operando (A=%.2f)\n",numeroUno);
		}

		if(banderaSegundoNumero==1)
		{
			printf("2. Ingresar 2do operando (B=y)\n");
		}else
		{
			printf("2. Ingresar 2do operando (B=%.2f)\n",numeroDos);
		}
		printf("3. Calcular todas las operaciones \n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5)
		{
			printf("ERROR: Elija una opcion que aparezca en el menu: ");
			scanf("%d", &opcion);
		}

		switch(opcion)
		{
			case 1:
				printf("Ingrese el 1er operando: ");
				scanf("%f",&numeroUno);
				banderaPrimerNumero=0;
			break;

			case 2:
				if(banderaPrimerNumero==1)
				{
					printf("ERROR. PRIMERO TIENE QUE ASIGNAR EL PRIMER OPERANDO\n");
				}else
				{
					printf("Ingrese el 2do operando: ");
					scanf("%f",&numeroDos);
					banderaSegundoNumero=0;
				}
			break;

			case 3:

				if(banderaPrimerNumero==1 || banderaSegundoNumero==1)
				{
					printf("ERROR. PRIMERO TIENE QUE ASIGNAR LOS OPERANDOS\n");
				}else
				{
					contadorCase3++;
					resultadoSuma=OperacionSumar(numeroUno,numeroDos);
					resultadoResta=OperacionRestar(numeroUno,numeroDos);
					resultadoMultiplicacion=OperacionMultiplicar(numeroUno,numeroDos);
					if(numeroDos!=0)
					{
						resultadoDivision=OperacionDividir(numeroUno,numeroDos);
					}
					resultadoFactorialNumeroUno=FactorialNumeroUno(numeroUno);
					resultadoFactorialNumeroDos=FactorialNumeroDos(numeroDos);
					printf("SE HAN CALCULADO LAS OPERACIONES\n");
				}

			break;

			case 4:
				if(contadorCase3==0)
				{
					printf("ERROR. PRIMERO TIENE QUE ASIGNAR AMBOS OPERANDOS, LUEGO INGRESAR EL NUMERO 3 DEL MENU Y DESPUES EL NUMERO 4\n");
				}else
				{
					printf("El resultado de A+B es: %.2f\n",resultadoSuma);
					printf("El resultado de A-B es: %.2f\n",resultadoResta);
					printf("El resultado de A*B es: %.2f\n",resultadoMultiplicacion);
					if(numeroDos!=0)
					{
						printf("El resultado de A/B es: %.2f\n",resultadoDivision);
					}else
					{
						printf("No es posible dividir por cero\n");
					}
					printf("El factorial de A es: %.2f y El factorial de B es: %.2f\n",resultadoFactorialNumeroUno,resultadoFactorialNumeroDos);

					banderaPrimerNumero=1;
					banderaSegundoNumero=1;
				}
			break;

			case 5:
				printf("Acaba de salir de la calculadora");
			break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}

