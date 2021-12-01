/*
 * ePerritoConHogar.h
 *
 *  Created on: 1 dic. 2021
 *      Author: sole
 */

#ifndef EPERRITOCONHOGAR_H_
#define EPERRITOCONHOGAR_H_
#define TAM_CHAR 21
#include "LinkedList.h"
#include "eHogar.h"

typedef struct
{
	int id;
	char nombre[TAM_CHAR];
	float peso;
	int edad;
	char raza[TAM_CHAR];
	float cantidadComidaRacion;
	int idHogar;

}ePerritoConHogar;

ePerritoConHogar* perritoHogar_new();
ePerritoConHogar* perritoHogar_newParametros(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr, char* idHogarStr);
ePerritoConHogar* perritoHogar_newParametrosEspecialito(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr, char* cantComidaStr);
void perritoHogar_delete(ePerritoConHogar* this);
int perritoHogar_setId(ePerritoConHogar* this,int id);
int perritoHogar_getId(ePerritoConHogar* this,int* id);
int perritoHogar_setNombre(ePerritoConHogar* this,char* nombre);
int perritoHogar_getNombre(ePerritoConHogar* this,char* nombre);
int perritoHogar_setPeso(ePerritoConHogar* this,float peso);
int perritoHogar_getPeso(ePerritoConHogar* this,float* peso);
int perritoHogar_setEdad(ePerritoConHogar* this,int edad);
int perritoHogar_getEdad(ePerritoConHogar* this,int* edad);
int perritoHogar_setRaza(ePerritoConHogar* this,char* raza);
int perritoHogar_getRaza(ePerritoConHogar* this,char* raza);
int perritoHogar_setCantidadComida(ePerritoConHogar* this,float cantidadComida);
int perritoHogar_getCantidadComida(ePerritoConHogar* this,float* cantidadComida);
void perritoHogar_showUnitPunto3(ePerritoConHogar* this);
int perritoHogar_showListPunto3(LinkedList* this);
int perritoHogar_showList(LinkedList* this);
void perritoHogar_posterList();
void perritoHogar_posterListPunto3();
int perritoHogar_sortNames(void* thisOne, void* thisTwo);
int perritoHogar_laQueMapea(void* pElement);
void perritoHogar_showUnit(ePerritoConHogar* this);
int perritoHogar_laQueFiltra(void* pElement);
int perritoHogar_getIdHogar(ePerritoConHogar* this,int* idHogar);


#endif /* EPERRITOCONHOGAR_H_ */
