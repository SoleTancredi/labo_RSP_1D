/*
 * eHogar.h
 *
 *  Created on: 1 dic. 2021
 *      Author: sole
 */

#ifndef EHOGAR_H_
#define EHOGAR_H_
#define TAM_DIRECCION 31

typedef struct
{
   int id;
   char direccion[TAM_DIRECCION];

}eHogar;

eHogar* Hogar_newParametros(char* idStr,char* direccionStr);

eHogar* Hogar_new();
#endif /* EHOGAR_H_ */
