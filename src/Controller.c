#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Perrito.h"
#include "parser.h"
#include "BibliotecaUtn2021.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	FILE* pFile  = fopen(path, "r");
	if(pFile != NULL)
	{
	    if(parser_PerritoFromText(pFile, pArrayListPerrito) == 0)
	    {
		    retorno = 0;
	    }
	}

	fclose(pFile);

    return retorno;
}

int controller_loadFromTextEspecialita(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	FILE* pFile  = fopen(path, "r");
	if(pFile != NULL)
	{
	    if(parser_PerritoFromTextEspecialito(pFile, pArrayListPerrito) == 0)
	    {
		    retorno = 0;
	    }
	}

	fclose(pFile);

    return retorno;
}

int controller_loadFromTextPerritosConHogar(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	FILE* pFile  = fopen(path, "r");
	if(pFile != NULL)
	{
	    if(parser_PerritoHogarFromText(pFile, pArrayListPerrito) == 0)
	    {

		    retorno = 0;
	    }
	    else
	    {
	    	printf("\n rompe parser");
	    }
	}

	fclose(pFile);

    return retorno;
}

int controller_loadFromTextDireccion(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	FILE* pFile  = fopen(path, "r");
	if(pFile != NULL)
	{
	    if(parser_HogarFromText(pFile, pArrayListPerrito) == 0)
	    {

		    retorno = 0;
	    }
	    else
	    {
	    	printf("\n rompe parser");
	    }
	}

	fclose(pFile);

    return retorno;
}



/** \brief Listar perritos
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListPerritos(LinkedList* pArrayListPerritos)
{
    int retorno = -1;

    if(pArrayListPerritos != NULL)
    {
		if(perrito_showList(pArrayListPerritos) == 0)
		{
			retorno = 0;
		}
    }

    return retorno;
}

int controller_ListPerritosPunto3(LinkedList* pArrayListPerritos)
{
    int retorno = -1;

    if(pArrayListPerritos != NULL)
    {
		if(perrito_showListPunto3(pArrayListPerritos) == 0)
		{
			retorno = 0;
		}
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortPerritos(LinkedList* pArrayListPerritos)
{
	int retorno = -1;

	if(pArrayListPerritos != NULL)
	{

		if(ll_sort(pArrayListPerritos, perrito_sortNames, 1) == 0)
		{

			retorno = 0;
		}
	}

    return retorno;
}
/** \brief Guarda los datos de los perritos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 * normalita
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPerritos)
{
    int retorno = -1;
    int id;
    char nombre[41];
    float peso;
    int edad;
    char raza[41];
    Perrito* pBuffer;

    if(path != NULL && pArrayListPerritos != NULL)
    {
		FILE* pFile= fopen(path,"w");

		if(pFile != NULL)
		{
			fprintf(pFile, "ID, NOMBRE, PESO, EDAD, RAZA\n");

			for(int i = 0; i < ll_len(pArrayListPerritos)  ; i++)
			{

				pBuffer = ll_get(pArrayListPerritos, i);
				perrito_getId(pBuffer, &id);
				perrito_getNombre(pBuffer, nombre);
				perrito_getPeso(pBuffer, &peso);
				perrito_getEdad(pBuffer, &edad);
				perrito_getRaza(pBuffer, raza);
				//perrito_showUnit(pBuffer);
				fprintf(pFile, "%d, %s, %.2f, %d, %s\n", id,nombre,peso, edad, raza);
				retorno = 0;
			}
	}
	else
	{
	    puts("\n error en fopen ");
	}

		fclose(pFile);
    }

    return retorno;
}

int controller_saveAsTextEspecialita(char* path , LinkedList* pArrayListPerritos)
{
    int retorno = -1;
    int id;
    char nombre[41];
    float peso;
    int edad;
    char raza[41];
    float cantidadComida;
    Perrito* pBuffer;

    if(path != NULL && pArrayListPerritos != NULL)
    {
		FILE* pFile= fopen(path,"w");

		if(pFile != NULL)
		{
			fprintf(pFile, "Id, Nombre, Peso, Edad, Raza, Racion de comida\n");

			for(int i = 0; i < ll_len(pArrayListPerritos)  ; i++)
			{

				pBuffer = ll_get(pArrayListPerritos, i);
				perrito_getId(pBuffer, &id);
				perrito_getNombre(pBuffer, nombre);
				perrito_getPeso(pBuffer, &peso);
				perrito_getEdad(pBuffer, &edad);
				perrito_getRaza(pBuffer, raza);
				perrito_getCantidadComida(pBuffer, &cantidadComida);
				fprintf(pFile, "%d, %s, %.2f, %d, %s, %.2f\n", id,nombre,peso, edad, raza,cantidadComida);
				retorno = 0;
			}
	}
	else
	{
	    puts("\n error en fopen ");
	}

		fclose(pFile);
    }

    return retorno;
}

int controller_llMap(LinkedList* this)
{
   int retorno = -1;

   if(this != NULL)
   {
	  if( ll_map(this, perrito_laQueMapea) == 0)
	  {
		  retorno = 0;
	  }
   }

   return retorno;
}






