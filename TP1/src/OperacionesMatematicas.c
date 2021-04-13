/*
 * Funciones.c
 *
 *  Created on: 26 mar. 2021
 *      Author: Begonia
 */

#include <stdio.h>
#include <stdlib.h>

#include "OperacionesMatematicas.h"
/**
 * @fn int OperacionSumar(int, int)
 * @brief Realiza la suma entre el numeroUno y el numeroDos
 *
 * @param numeroUno
 * @param numeroDos
 * @return resultado
 */
float OperacionSumar(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno+numeroDos;
	return resultado;

}

/**
 * @fn int OperacionMultiplicar(int, int)
 * @brief Realiza la multiplicacion entre el numeroUno y el numeroDos
 *
 * @param numeroUno
 * @param numeroDos
 * @return resultado
 */
float OperacionMultiplicar(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno*numeroDos;
	return resultado;

}

/**
 * @fn int OperacionRestar(int, int)
 * @brief Realiza la resta entre el numeroUno y el numeroDos
 *
 * @param numeroUno
 * @param numeroDos
 * @return resultado
 */
float OperacionRestar(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno-numeroDos;
	return resultado;
}

/**
 * @fn float OperacionDividir(int, int)
 * @brief Realiza la divicion entre el numeroUno y el numeroDos
 *
 * @param numeroUno
 * @param numeroDos
 * @return resultado
 */
float OperacionDividir(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno/numeroDos;
	return resultado;
}

/**
 * @fn int FactorialNumeroUno(int)
 * @brief Realiza el Factorial del numeroUno
 *
 * @param numeroUno
 * @return resultado
 */
float FactorialNumeroUno(float numeroUno)
{
	  int i;
	  float factorial;
	  factorial=1;

	  for(i=1;i<=numeroUno;i++)
	  {
	      factorial=factorial*i;
	  }

	  return factorial;
}

/**
 * @fn int FactorialNumeroDos(int)
 * @brief Realiza el Factorial del numeroDos
 *
 * @param numeroDos
 * @return resultado
 */
float FactorialNumeroDos(float numeroDos)
{
	  int i;
	  float factorial;
	  setbuf(stdout,NULL);
	  factorial=1;

	  for(i=1;i<=numeroDos;i++)
	  {
	      factorial=factorial*i;
	  }

	  return factorial;
}
