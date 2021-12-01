/*
 * Perrito.c
 *
 *  Created on: 26 nov. 2021
 *      Author: sole
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perrito.h"
#include "LinkedList.h"
#include "BibliotecaUtn2021.h"

Perrito* perrito_new()
{
	Perrito *pBufferPerrito=NULL;
	pBufferPerrito = (Perrito*)malloc(sizeof(Perrito));

	return pBufferPerrito;
}

Perrito* perrito_newParametros(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr)
{
	Perrito* pBufferPerrito;

	pBufferPerrito = perrito_new();

	if(pBufferPerrito != NULL)
	{
	   (*pBufferPerrito).id = atoi(idStr);
	   strcpy((*pBufferPerrito).nombre, nombreStr);
	   (*pBufferPerrito).peso = atof(pesoStr);
	   (*pBufferPerrito).edad = atoi(edadStr);

	   strcpy((*pBufferPerrito).raza, razaStr);
	  // (*pBufferPerrito).raza[strlen(razaStr)-1]='\0';//ESTA LINEA ES SOLO PARA LINUX
	   return pBufferPerrito;
	}
       return NULL;
}

Perrito* perrito_newParametrosEspecialito(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr, char* cantComidaStr)
{
	Perrito* pBufferPerrito;

	pBufferPerrito = perrito_new();

	if(pBufferPerrito != NULL)
	{
       (*pBufferPerrito).id = atoi(idStr);
       strcpy((*pBufferPerrito).nombre, nombreStr);
       (*pBufferPerrito).peso = atof(pesoStr);
       (*pBufferPerrito).edad = atoi(edadStr);
       strcpy((*pBufferPerrito).raza, razaStr);
       (*pBufferPerrito).cantidadComidaRacion = atof(cantComidaStr);

       return pBufferPerrito;
   	}
       return NULL;
}


void perrito_delete(Perrito* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int perrito_setId(Perrito* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		(*this).id = id;
		retorno = 0;
	}

	return retorno;
}

int perrito_getId(Perrito* this,int* id)
{
   int retorno = -1;

   if(this != NULL && id != NULL)
   {
	   *id = (*this).id;
	   retorno = 0;
   }

   return retorno;
}

int perrito_setNombre(Perrito* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy((*this).nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int perrito_getNombre(Perrito* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, (*this).nombre);
		retorno = 0;
	}

	return retorno;
}

int perrito_setPeso(Perrito* this,float peso)
{
	int retorno = -1;

	if(this != NULL && peso > 0)
	{
		(*this).peso = peso;
		retorno = 0;
	}

	return retorno;
}

int perrito_getPeso(Perrito* this,float* peso)
{
	int retorno = -1;

	if(this != NULL && peso != NULL)
	{
		*peso = (*this).peso;
		retorno = 0;
	}

	return retorno;
}

int perrito_setEdad(Perrito* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		(*this).edad = edad;
		retorno = 0;
	}

	return retorno;

}


int perrito_getEdad(Perrito* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = (*this).edad;
		retorno = 0;
	}

	return retorno;
}

int perrito_setRaza(Perrito* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy((*this).raza, raza);
		retorno = 0;
	}
	return retorno;
}

int perrito_getRaza(Perrito* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, (*this).raza);
		retorno = 0;
	}

	return retorno;
}

int perrito_setCantidadComida(Perrito* this,float cantidadComida)
{
	int retorno = -1;

	if(this != NULL && cantidadComida > 0)
	{
		(*this).cantidadComidaRacion = cantidadComida;
		retorno = 0;
	}

	return retorno;
}

int perrito_getCantidadComida(Perrito* this,float* cantidadComida)
{
	int retorno = -1;

	if(this != NULL && cantidadComida != NULL)
	{
		*cantidadComida = (*this).cantidadComidaRacion;
		retorno = 0;
	}

	return retorno;
}

void perrito_showUnitPunto3(Perrito* this)
{
	int id;
	char nombre[41];
	float peso;
	int edad;
	char raza[41];
	float cantidadComida;

	if(this != NULL)
	{
		if(perrito_getId(this, &id) == 0
		&& perrito_getNombre(this, nombre) == 0
		&& perrito_getPeso(this, &peso) == 0
		&& perrito_getEdad(this, &edad) == 0
		&& perrito_getCantidadComida(this, &cantidadComida) == 0
		&& perrito_getRaza(this, raza) == 0
		&& perrito_getCantidadComida(this, &cantidadComida) == 0)


		{
			printf("\n  %-6d|    %-16s %-10.2f    %-8d %-25s    %-25.2f \n ", id, nombre, peso, edad, raza, cantidadComida);
		}
		else
		{
			puts("\n aca hay un error en unit");
		}
	}
}

int perrito_showListPunto3(LinkedList* this)
{
	int retorno = -1,cont=0;
	Perrito* pAuxPerrito;

	if(this != NULL)
	{
	    perrito_posterListPunto3();
	    for(int i = 0; i < ll_len(this); i++)
	    {
		pAuxPerrito = ll_get(this, i);
		perrito_showUnitPunto3(pAuxPerrito);
		cont++;
		retorno = 0;
	    }
	    printf("\n\t\t\t Cantidad de perritos: %d",cont);
	}

	return retorno;
}


int perrito_showList(LinkedList* this)
{
    int retorno = -1,cont=0;
    Perrito* pAuxPerrito;

    if(this != NULL)
    {
	perrito_posterList();
	for(int i = 0; i < ll_len(this); i++)
	{
	    pAuxPerrito = ll_get(this, i);
	    perrito_showUnit(pAuxPerrito);
	    cont++;
	    retorno = 0;
	}
	printf("\n\t\t\t Cantidad de perritos: %d",cont);
    }

    return retorno;
}

void perrito_posterList()
{
	printf("\n\t  ## LISTADO DE PERRITOS ##");
	printf("\n_____________________________________________________________________\n");
	printf("\n  %-6s     %-14s%-10s  %-15s  %-10s \n","ID ","NOMBRE "," PESO    ","EDAD  ", " RAZA  ");
	printf("______________________________________________________________________\n");
}
void perrito_posterListPunto3()
{
	printf("\n\t\t  ## LISTADO DE PERRITOS FLAQUITOS ##");
	printf("\n______________________________________________________________________________________________\n");
	printf("\n  %-6s     %-14s  %-10s    %-15s%-10s        %-10s \n","ID ","NOMBRE "," PESO ","EDAD  ", " RAZA  ", "RACION DE COMIDA   ");
	printf("_______________________________________________________________________________________________\n");
}

int perrito_sortNames(void* thisOne, void* thisTwo)
{
	int retorno = 0;
	Perrito* pBuffer1;
	Perrito* pBuffer2;

	pBuffer1 = thisOne;
	pBuffer2 = thisTwo;


	if(thisOne != NULL && thisTwo != NULL)
	{
		if(strcmp((*pBuffer1).nombre, (*pBuffer2).nombre) < 0)
		{
			retorno = -1;
		}
		else
		{
			if(strcmp((*pBuffer1).nombre, (*pBuffer2).nombre) > 0)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int perrito_laQueMapea(void* pElement)
{
	int retorno = -1;
	Perrito* pPerrito = (Perrito*) pElement;

	if(pElement != NULL)
	{
		(*pPerrito).cantidadComidaRacion = (*pPerrito).peso * 23;
		retorno = 0;
	}

	return retorno;
}

void perrito_showUnit(Perrito* this)
{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];

	if(this != NULL)
	{
		if(perrito_getId(this, &id) == 0
		&& perrito_getNombre(this, nombre) == 0
		&& perrito_getPeso(this, &peso) == 0
		&& perrito_getEdad(this, &edad) == 0
		&& perrito_getRaza(this, raza) == 0)


		{
			printf("\n  %-10d|   %-10s  %-10.2f  %-10d  %-8s \n  ", id, nombre, peso, edad,raza );
		}
		else
		{
			puts("\n aca hay un error en unit");
		}
	}
}

int perrito_laQueFiltra(void* pElement)
{
	int retorno = -1;
	Perrito* pBuffer = (Perrito*) pElement;

	if(pElement != NULL)
	{
		retorno = 2;

		if(strcmp(pBuffer->raza, "Galgo") == 0 &&
				(*pBuffer).edad > 10 &&
				(*pBuffer).cantidadComidaRacion < 200.00)
		{
			retorno = 0;
		}
	}
	return retorno;
}



