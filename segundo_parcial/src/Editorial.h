

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int idEditorial;
	char name[128];
}eEditorial;

/// @fn eEditorial eEditorial_new*()
/// @brief Funcion que reserva espacio en memoria dinamica de estructura editorial e inicializa los campos de la misma
/// @return Retorna NULL si no se reservo espacio o el puntero en memoria dinamica
eEditorial* eEditorial_new();

/// @fn eEditorial eEditorial_newParametros*(char*, char*)
/// @brief Funcion que reserva un espacio en memoria dinamica de un puntero a estructura y carga los campos con los parametros recibidos
/// @param idString Puntero a char
/// @param name Puntero a char
/// @return Retorna NULL si no se reservo espacio o hubo un error en la carga -  devuelve el puntero en memoria dinamica si todo fue correcto
eEditorial* eEditorial_newParametros(char* idString, char* name);

/// @fn int eEditorial_delete(eEditorial*)
/// @brief Funcion que libera espacio de la memoria dinamica
/// @param this Puntero a estructura
/// @return Devuelve 0 si se libero la memoria o -1 si el puntero era NULL
int eEditorial_delete(eEditorial* this);

/// @fn int eEditorial_setId(eEditorial*, int)
/// @brief Funcion que carga el valor recibido por parametro a un campo de la estructura a traves de puntero
/// @param this Puntero a la estructura
/// @param id Parametro por valor de una variable int
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eEditorial_setId(eEditorial* this,int id);

/// @fn int eEditorial_getId(eEditorial*, int*)
/// @brief Funcion que obtiene la informacion de un campo de la estructura
/// @param this Puntero a la estructura
/// @param id Puntero a variable int
/// @return Devuelve 0 si se obtuvo la informacion o -1 si el puntero es NULL
int eEditorial_getId(eEditorial* this,int* id);

/// @fn int eEditorial_setName(eEditorial*, char*)
/// @brief Funcion que carga a traves de un parametro por referencia, un campo de la estructura
/// @param this Puntero a la estructura
/// @param name Puntero a char
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eEditorial_setName(eEditorial* this,char* name);

/// @fn int eEditorial_getName(eEditorial*, char*)
/// @brief Funcion que obtiene la informacion de un campo de la estructura a traves de punteros
/// @param this Puntero a la estructura
/// @param name Puntero a char
/// @return Devuelve 0 si se obtuvo la informacion o -1 si el puntero es NULL
int eEditorial_getName(eEditorial* this,char* name);

/// @fn void eEditorial_showAEditorial(eEditorial*)
/// @brief Funcion que muestra la informacion de una editorial
/// @param this Puntero a la estructura
void eEditorial_showAEditorial(eEditorial* this);

#endif /* EDITORIAL_H_ */
