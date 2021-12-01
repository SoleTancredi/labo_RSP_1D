#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perrito.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PerritoFromText(FILE* pFile , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	char strId[21];
	char strNombre[41];
	char strPeso[21];
	char strEdad[21];
	char strRaza[41];
	int leidos;
	Perrito* pNewPerrito;

	if(pFile != NULL && pArrayListPerrito != NULL)
	{
	    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n" , strId, strNombre,strPeso,strEdad, strRaza);

	    do
	    {
		leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strPeso,strEdad, strRaza);
		if(leidos == 5)
		{
		    pNewPerrito = perrito_newParametros(strId, strNombre, strPeso, strEdad, strRaza);

		    if(pNewPerrito!=NULL)
		    {
		    	retorno = ll_add(pArrayListPerrito,pNewPerrito);
		    }
		}
		else
		{
		    printf("\n »» Error en la lectura.");
		    retorno = -1;
		    break;
		}

	    }while(!feof(pFile));
	}

    return retorno;
}

int parser_PerritoFromTextEspecialito(FILE* pFile , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	char strId[21];
	char strNombre[41];
	char strPeso[21];
	char strEdad[21];
	char strRaza[41];
	char strCantidadComida[41];
	int leidos;
	Perrito* pNewPerrito;

	if(pFile != NULL && pArrayListPerrito != NULL)
	{
	    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" , strId, strNombre,strPeso,strEdad, strRaza, strCantidadComida);

	    do
	    {
	        leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strPeso,strEdad, strRaza, strCantidadComida);
			if(leidos == 6)
			{
				pNewPerrito = perrito_newParametrosEspecialito(strId, strNombre, strPeso, strEdad, strRaza, strCantidadComida);

				if(pNewPerrito!=NULL)
				{
					retorno = ll_add(pArrayListPerrito,pNewPerrito);
				}
			}
			else
			{
				printf("\n »» Error en la lectura.");
				retorno = -1;
				break;
			}

	    }while(!feof(pFile));
	}

    return retorno;
}



