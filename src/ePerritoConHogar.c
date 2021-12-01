/*
 * ePerritoConHogar.c
 *
 *  Created on: 1 dic. 2021
 *      Author: sole
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "BibliotecaUtn2021.h"
#include "ePerritoConHogar.h"


ePerritoConHogar* perritoHogar_new()
{
	ePerritoConHogar *pBufferPerrito=NULL;
	pBufferPerrito = (ePerritoConHogar*)malloc(sizeof(ePerritoConHogar));

	return pBufferPerrito;
}

ePerritoConHogar* perritoHogar_newParametros(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr, char* idHogarStr)
{
	ePerritoConHogar* pBufferPerrito;

	pBufferPerrito = perritoHogar_new();

	if(pBufferPerrito != NULL)
	{
	   (*pBufferPerrito).id = atoi(idStr);
	   strcpy((*pBufferPerrito).nombre, nombreStr);
	   (*pBufferPerrito).peso = atof(pesoStr);
	   (*pBufferPerrito).edad = atoi(edadStr);
	   strcpy((*pBufferPerrito).raza, razaStr);
	 //  (*pBufferPerrito).raza[strlen(razaStr)-1]='\0';//ESTA LINEA ES SOLO PARA LINUX

	   (*pBufferPerrito).datosHogar.id = atoi(idHogarStr);

	   return pBufferPerrito;
	}
       return NULL;
}

ePerritoConHogar* perritoHogar_newParametrosEspecialito(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr, char* cantComidaStr)
{
	ePerritoConHogar* pBufferPerrito;

	pBufferPerrito = perritoHogar_new();

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


void perritoHogar_delete(ePerritoConHogar* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int perritoHogar_setId(ePerritoConHogar* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		(*this).id = id;
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_getId(ePerritoConHogar* this,int* id)
{
   int retorno = -1;

   if(this != NULL && id != NULL)
   {
	   *id = (*this).id;
	   retorno = 0;
   }

   return retorno;
}

int perritoHogar_setNombre(ePerritoConHogar* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy((*this).nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int perritoHogar_getNombre(ePerritoConHogar* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, (*this).nombre);
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_setPeso(ePerritoConHogar* this,float peso)
{
	int retorno = -1;

	if(this != NULL && peso > 0)
	{
		(*this).peso = peso;
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_getPeso(ePerritoConHogar* this,float* peso)
{
	int retorno = -1;

	if(this != NULL && peso != NULL)
	{
		*peso = (*this).peso;
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_setEdad(ePerritoConHogar* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		(*this).edad = edad;
		retorno = 0;
	}

	return retorno;

}


int perritoHogar_getEdad(ePerritoConHogar* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = (*this).edad;
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_setRaza(ePerritoConHogar* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy((*this).raza, raza);
		retorno = 0;
	}
	return retorno;
}

int perritoHogar_getRaza(ePerritoConHogar* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, (*this).raza);
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_setCantidadComida(ePerritoConHogar* this,float cantidadComida)
{
	int retorno = -1;

	if(this != NULL && cantidadComida > 0)
	{
		(*this).cantidadComidaRacion = cantidadComida;
		retorno = 0;
	}

	return retorno;
}

int perritoHogar_getCantidadComida(ePerritoConHogar* this,float* cantidadComida)
{
	int retorno = -1;

	if(this != NULL && cantidadComida != NULL)
	{
		*cantidadComida = (*this).cantidadComidaRacion;
		retorno = 0;
	}

	return retorno;
}

void perritoHogar_showUnitPunto3(ePerritoConHogar* this)
{
	int id;
	char nombre[41];
	float peso;
	int edad;
	char raza[41];
	float cantidadComida;

	if(this != NULL)
	{
		if(perritoHogar_getId(this, &id) == 0
		&& perritoHogar_getNombre(this, nombre) == 0
		&& perritoHogar_getPeso(this, &peso) == 0
		&& perritoHogar_getEdad(this, &edad) == 0
		&& perritoHogar_getCantidadComida(this, &cantidadComida) == 0
		&& perritoHogar_getRaza(this, raza) == 0
		&& perritoHogar_getCantidadComida(this, &cantidadComida) == 0)


		{
			printf("\n  %-6d|    %-16s %-10.2f    %-8d %-25s    %-25.2f \n ", id, nombre, peso, edad, raza, cantidadComida);
		}
		else
		{
			puts("\n aca hay un error en unit");
		}
	}
}

int perritoHogar_showListPunto3(LinkedList* this)
{
	int retorno = -1,cont=0;
	ePerritoConHogar* pAuxPerrito;

	if(this != NULL)
	{
		perritoHogar_posterListPunto3();
	    for(int i = 0; i < ll_len(this); i++)
	    {
		pAuxPerrito = ll_get(this, i);
		perritoHogar_showUnitPunto3(pAuxPerrito);
		cont++;
		retorno = 0;
	    }
	    printf("\n\t\t\t Cantidad de perritos: %d",cont);
	}

	return retorno;
}


int perritoHogar_showList(LinkedList* this)
{
    int retorno = -1,cont=0;
    ePerritoConHogar* pAuxPerrito;

    if(this != NULL)
    {
    	perritoHogar_posterList();
	for(int i = 0; i < ll_len(this); i++)
	{
	    pAuxPerrito = ll_get(this, i);
	    perritoHogar_showUnit(pAuxPerrito);
	    cont++;
	    retorno = 0;
	}
	printf("\n\t\t\t Cantidad de perritos: %d",cont);
    }

    return retorno;
}

void perritoHogar_posterList()
{
	printf("\n\t  ## LISTADO DE PERRITOS ##");
	printf("\n_____________________________________________________________________\n");
	printf("\n  %-6s     %-14s%-10s  %-15s  %-10s \n","ID ","NOMBRE "," PESO    ","EDAD  ", " RAZA  ");
	printf("______________________________________________________________________\n");
}
void perritoHogar_posterListPunto3()
{
	printf("\n\t\t  ## LISTADO DE PERRITOS FLAQUITOS ##");
	printf("\n______________________________________________________________________________________________\n");
	printf("\n  %-6s     %-14s  %-10s    %-15s%-10s        %-10s \n","ID ","NOMBRE "," PESO ","EDAD  ", " RAZA  ", "RACION DE COMIDA   ");
	printf("_______________________________________________________________________________________________\n");
}

int perritoHogar_sortNames(void* thisOne, void* thisTwo)
{
	int retorno = 0;
	ePerritoConHogar* pBuffer1;
	ePerritoConHogar* pBuffer2;

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

int perritoHogar_laQueMapea(void* pElement)
{
	int retorno = -1;
	ePerritoConHogar* pPerrito = (ePerritoConHogar*) pElement;

	if(pElement != NULL)
	{
		(*pPerrito).cantidadComidaRacion = (*pPerrito).peso * 23;
		retorno = 0;
	}

	return retorno;
}

void perritoHogar_showUnit(ePerritoConHogar* this)
{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];

	if(this != NULL)
	{
		if(perritoHogar_getId(this, &id) == 0
		&& perritoHogar_getNombre(this, nombre) == 0
		&& perritoHogar_getPeso(this, &peso) == 0
		&& perritoHogar_getEdad(this, &edad) == 0
		&& perritoHogar_getRaza(this, raza) == 0)


		{
			printf("\n  %-10d|   %-10s  %-10.2f  %-10d  %-8s %-8d\n  ", id, nombre, peso, edad,raza, this->datosHogar.id);
		}
		else
		{
			puts("\n aca hay un error en unit");
		}
	}
}

int perritoHogar_laQueFiltra(void* pElement)
{
	int retorno = -1;
	ePerritoConHogar* pBuffer = (ePerritoConHogar*) pElement;

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




