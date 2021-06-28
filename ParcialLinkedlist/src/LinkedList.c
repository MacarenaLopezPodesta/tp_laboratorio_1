#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo=NULL;
	int len=ll_len(this);
	if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
	{
		pNodo=this->pFirstNode;
		for(int i=0;i<nodeIndex;i++)
		{
		  pNodo=pNodo->pNextNode;
		}
	}
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* NuevoNodo=NULL;
	Node* aux = NULL;
	int len=ll_len(this);

	if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
	  {
		NuevoNodo=(Node*)malloc(sizeof(Node));
		if(NuevoNodo!=NULL)
		{
			NuevoNodo->pElement = pElement; //guardo el elemento en el nodo

			if(nodeIndex==0)//quiere agregar el elemento a el primer nodo
			{
				NuevoNodo->pNextNode= this->pFirstNode;// al nodo siguiente le agregas el valor que estaba en la primer posicion
				this->pFirstNode=NuevoNodo;// y el primer nodo es el nuevo nodo
			}else
			{
				if(nodeIndex==len)// si quiere agregar uno al final
				{
					aux = getNode(this,nodeIndex-1);//busco el nodo anterior a el index
					aux->pNextNode = NuevoNodo;// y el nodo siguiente es el nuevo nodo
					NuevoNodo->pNextNode = NULL;//el siguiente a el nuevo nodo lo pongo en NULL
				}else  //se usa cuando haces un pop o un push
				{
					aux = getNode(this,nodeIndex-1);//busco el nodo anterior a el index
					NuevoNodo->pNextNode=aux->pNextNode;// el nodo siguiente al nuevo nodo, es el que estaba en esa posicion
					aux->pNextNode = NuevoNodo;// y el nuevo nodo toma el lugar
				}
			 }
		}
		this->size++;//Agranda el size
		returnAux = 0;
	  }

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux= -1;
    int len= ll_len(this);
    if(this!=NULL)
    {
    	addNode(this,len,pElement);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
/**
 * @fn void ll_get*(LinkedList*, int)
 * @brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento
 *
 * @param this
 * @param index
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    Node* nodo;
    if(this!=NULL && index>=0 && index<len)
    {
    	nodo=getNode(this,index);//busca el nodo con el index
    	returnAux = nodo->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/**
 * @fn int ll_set(LinkedList*, int, void*)
 * @brief Inserta un elemento en el LinkedList, en el índice especificado. Verificando que el puntero this
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0)
 *
 * @param this
 * @param index
 * @param pElement
 * @return
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux=-1;
    int len=ll_len(this);
    Node* nodo;
    if(this!=NULL && index>=0 && index<len)
    {
    	nodo=getNode(this,index);
    	nodo->pElement=pElement;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* nodo;
    Node* nodoAnterior;

    if(this!=NULL && index>=0 && index<len)
    {
    	nodo = getNode(this,index);
    	nodoAnterior=getNode(this,(index-1));
    	if(nodo!=NULL)
    	{
			if(index==len)// si el nodo esta a el final
			{
				nodo=NULL;// se pone en null //PREGUNTAR
			}else
			{
				if(index==0)// primero
				{
					this->pFirstNode = nodo->pNextNode;// El nodo 2, pasa a ser el primero
				}else
				{
					nodoAnterior->pNextNode=nodo->pNextNode;// El nodo del index, le da su lugar a el siguiente nodo
				}
			}
			free(nodo);
			this->size--;
    	}

    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);
    if(this!=NULL && len>0)
    {
    	for(int i=(len-1);i>=0;i--)
		{
			ll_remove(this,i);//ELIMINO DE ATRAS PARA ADELANTE
		}
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)//corregido
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(ll_clear(this)==0)
    	{
    		free(this);
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
	if(this!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(ll_get(this,i)==pElement)
			{
				returnAux=i;
				break;
			}
		}
	}
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=0;
    	if(ll_len(this)==0)// esta vacia
    	{
    		returnAux=1;
    	}
    }
    return returnAux;
}
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
  	if(this!=NULL && index>=0 && index<=len)
   	{
   		addNode(this,index,pElement);
        returnAux=0;
   	}
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
    	returnAux=ll_get(this,index);
    	if(ll_remove(this,index)==-1)
    	{
    		returnAux=NULL;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux=-1;
    if(this!=NULL)
    {
		returnAux=0;
		if(ll_indexOf(this,pElement)!=-1)
		{
			returnAux=1;
		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int lenThis2=ll_len(this2);
    if(this!=NULL && this2!=NULL)
    {
    	returnAux=1;
    	for(int i=0;i<lenThis2;i++)
		{
			if(ll_contains(this,ll_get(this2,i))==0)//SI NO ESTA EL ELEMENTO
			{
				returnAux=0;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray=NULL;
    int i;
    int len=ll_len(this);
    if(this!=NULL && from>=0 && from<len && to>from && to<=len)
    {
    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
			for(i=from;i<to;i++)
			{
			    ll_add(cloneArray,ll_get(this,i));
			}
    	}
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	void* aux;
	void* ElementoEnI;
	void* ElementoEnJ;
	int i;
	int j;
	if(this!=NULL && pFunc!=NULL && (order==1 || order==0))
	{
		for(i=0;i<this->size-1;i++)
		{
			for(j=i+1;j<this->size;j++)
			{
				ElementoEnI=ll_get(this,i);//ELEMENTO EN I
				ElementoEnJ=ll_get(this,j);// ELEMENTO EN J
				if((order==0 &&  pFunc(ElementoEnI,ElementoEnJ)==-1) || (order==1 && pFunc(ElementoEnI,ElementoEnJ)==1))
				{
					aux = ElementoEnI; //AUX = ELEMENTO EN I
					ll_set(this,i,ElementoEnJ);// ELEMENTO EN I = ELEMENTO EN J
					ll_set(this,j,aux);// ELEMENTO EN J = AUX

					returnAux= 0;
				}
		    }
		  }
	  }
	    return returnAux;

}
/**
La función “ll_count” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos de la lista
y pasárselos a la funcion “fn”. La función “fn” devolverá la cantidad que debe contarse segun el criterio.
La función “ll_count” almacenará un acumulador al cual sumará el valor de retorno de “fn” en cada iteración.
Al finalizar las iteraciones, la función “ll_count” devolverá el valor acumulado.
 */
/**
 * @fn int ll_count(LinkedList*, int(*)(void*))
 * @brief Acumula el valor de retorno de "fn" en cada iteracion
 *
 * @param this LinkedList*
 * @param fn int (*fn)(void* element)
 * @return acumulador int
 */
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int len=ll_len(this);
	int acumulador=0;
	void* elemento;
	if(this!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			elemento=ll_get(this,i);
			acumulador+=fn(elemento);
		}
	}
	return acumulador;
}

