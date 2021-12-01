/*
 * eHogar.c
 *
 *  Created on: 1 dic. 2021
 *      Author: sole
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "BibliotecaUtn2021.h"
#include "eHogar.h"

eHogar* Hogar_newParametros(char* idStr,char* direccionStr)
{
	eHogar* pBuffer;

	pBuffer = Hogar_new();

	if(pBuffer != NULL)
	{
	   (*pBuffer).id = atoi(idStr);
	   strcpy((*pBuffer).direccion, direccionStr);

	   return pBuffer;
	}
       return NULL;
}
eHogar* Hogar_new()
{
	eHogar *pBuffer=NULL;
	pBuffer= (eHogar*)malloc(sizeof(eHogar));

	return pBuffer;
}
