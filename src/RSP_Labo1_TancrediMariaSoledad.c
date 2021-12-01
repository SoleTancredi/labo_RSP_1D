/*
 ============================================================================
 Name        : RSP_Labo1_TancrediMariaSoledad.c
 Author      : Sole Tancredi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Perrito.h"
#include "ePerritoConHogar.h"
#include "BibliotecaUtn2021.h"

int main(void)
{
	//setbuf(stdout,NULL); --> WINDOWS
    LinkedList* perritoList = ll_newLinkedList();
    LinkedList* galgosList  = NULL;
    LinkedList* perritosConHogar = ll_newLinkedList();
    LinkedList* hogaresList = ll_newLinkedList();
    int option;
    int flagCarga = 0;
    int flagMapeo = 0;
    int flagFiltrado=0;

    do
	{
		printf("\n\t\t »»»»» MENU PRINCIPAL «««««\n");
		if (utn_getNumber(&option,
				"\n[1] Cargar datos de perritos desde data.csv (modo texto)."
				"\n[2] Listar perritos ordenados de manera ascedente por nombre."
				"\n[3] Mapeo"
				"\n[4] Perritos con raciones de comida"
				"\n[5] Filter "
				"\n[6] Guardar en un nuevo archivo"
				"\n[7] Cargar nuevas LinkedList."
				"\n[8] Listado de perritos con sus hogares ordenado por direccion descendente."
				"\n[9] Salir. "
				"\n »» INGRESE UNA OPCION:  ", "\n × ERROR. ", 1, 9,1) == 0)
			{
				switch (option)
				{
					case 1:
						if (controller_loadFromText("perritos.csv", perritoList) == 0)
						{
							flagCarga = 1;
							printf("\n »» CARGA DE DATOS EXITOSA ");
						}
						else
						{
							printf("\n x Primero debe cargar los datos.");
						}
						systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 2:
						if (flagCarga == 1)
						{
							if (controller_sortPerritos(perritoList) == 0)
							{
								controller_ListPerritos(perritoList);
							}
							else
							{
								printf("\n x No se ha realizado el ordenamiento.");
							}
						}
						else
						{
							printf("\n x Primero debe cargar los datos.");
						}
						systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 3:
						if (flagCarga == 1)
						{
							if (controller_llMap(perritoList) == 0)
							{
								flagMapeo = 1;
								printf("\n »» MAPEO DE DATOS EXITOSO.");
							}
						}
						else
						{
							printf("\n x Primero debe cargar los datos.");
						}
						systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 4:
						if (flagMapeo == 1)
						{
							if (controller_ListPerritosPunto3(perritoList) != 0)
							{
								printf("\n x Error. No se han podido listar los perritos");
							}
						}
						else
						{
							printf("\n x Primero debe cargar los datos. Y realizar el Mapeo.");
						}
						systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 5:
						if (flagCarga == 1)
						{
							galgosList = ll_filter(perritoList,perrito_laQueFiltra);
							if(galgosList != NULL)
							{
								flagFiltrado =1;
								perrito_showListPunto3(galgosList);
							}
						}
						else
						{
							printf("\n x Primero debe cargar los datos.");
						}
						systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 6:
						if (flagFiltrado != 0)
						{
							if (controller_saveAsTextEspecialita("galgosFlaquitos.csv",galgosList)== 0)
							{
							   printf("\n »» EL ARCHIVO SE GUARDO EXITOSAMENTE.");
							}
							else
							{
							   printf("\n X No se pudo guardar el archivo en modo texto.");
							}
						}
						else
						{
					       printf("\n x Primero debe cargar los datos. Y realizar el Filtrado.");
						}
						systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 7:
                        if(controller_loadFromTextPerritosConHogar("perritosConHogar.csv", perritosConHogar) == 0)
                        {
                        	printf("\n »» CARGA COMPLETA PERRITOS");
                        	if(controller_loadFromTextDireccion("hogares.csv", hogaresList) == 0)
                        	{
                        		puts("\n »» CARGA COMPLETA HOGARES");
                        	}
                        }
                        systemPause("\n »»»» Presione enter para continuar...");
						break;
					case 8:
						//NO LLEGUE
						break;
					case 9:
						printf("\n »»» FIN DEL PROGRAMA ««« ");
						ll_deleteLinkedList(perritoList);
						ll_deleteLinkedList(galgosList);
						break;
				}
			}
	} while (option != 9);

    return EXIT_SUCCESS;
 }
