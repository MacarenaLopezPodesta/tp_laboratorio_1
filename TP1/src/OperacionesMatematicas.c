/*
 * Funciones.c
 *
 *  Created on: 26 mar. 2021
 *      Author: Macarena
 */

#include <stdio.h>
#include <stdlib.h>

#include "OperacionesMatematicas.h"
/**
 * @fn float OperacionSumar(float, float)
 * @brief Realiza la suma entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float OperacionSumar(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno+numeroDos;
	return resultado;

}

/**
 * @fn float OperacionMultiplicar(float, float)
 * @brief Realiza la multiplicacion entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float OperacionMultiplicar(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno*numeroDos;
	return resultado;

}

/**
 * @fn float OperacionRestar(float, float)
 * @brief Realiza la resta entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float OperacionRestar(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno-numeroDos;
	return resultado;
}

/**
 * @fn float OperacionDividir(float, float)
 * @brief Realiza la divicion entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float OperacionDividir(float numeroUno , float numeroDos)
{
	float resultado;
	resultado=numeroUno/numeroDos;
	return resultado;
}

/**
 * @fn float FactorialNumeroUno(float)
 * @brief Realiza el Factorial del numeroUno
 *
 * @param float numeroUno
 * @return float resultado
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
 * @fn float FactorialNumeroDos(float)
 * @brief Realiza el Factorial del numeroDos
 *
 * @param float numeroDos
 * @return float resultado
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
