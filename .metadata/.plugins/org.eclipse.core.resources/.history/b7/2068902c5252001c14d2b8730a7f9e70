

#ifndef BOOKS_H_
#define BOOKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editorial.h"

typedef struct
{
	int id;
	char title[128];
	char author[128];
	float price;
	int idEditorial;
}eLibro;

/// @fn eLibro eLibro_new*()
/// @brief Funcion que reserva un espacio en memoria dinamica de un puntero a estructura e inicializa los campos
/// @return retorna una estructura inicializada o NULL si no pudo reservar memoria
eLibro* eLibro_new();

/// @fn eLibro eLibro_newParametros*(char*, char*, char*, char*, char*)
/// @brief Funcion que reserva un espacio en memoria dinamica de un puntero a estructura y carga los campos con los parametros recibidos
/// @param idString Puntero a char
/// @param title Puntero a char
/// @param author Puntero a char
/// @param priceString Puntero a char
/// @param idEditorialString Puntero a char
/// @return Retorna la direccion de memoria de una estructura cargada o NULL si fallo la carga o no hay espacio
eLibro* eLibro_newParametros(char* idString, char* title, char* author, char* priceString, char* idEditorialString);

/// @fn int eLibro_delete(eLibro*)
/// @brief Funcion que libera espacio de la memoria dinamica
/// @param this Puntero a estructura
/// @return Devuelve 0 si se libero la memoria o -1 si el puntero era NULL
int eLibro_delete(eLibro* this);

/// @fn int eLibro_setId(eLibro*, int)
/// @brief  Funcion que carga el campo id a traves del puntero con el parametro recibido
/// @param this Puntero a la estructura de libro
/// @param id Parametro por valor recibido
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eLibro_setId(eLibro* this,int id);

/// @fn int eLibro_getId(eLibro*, int*)
/// @brief Funcion que obtiene el id
/// @param this Puntero a la estructura de libro
/// @param id Puntero a una variable int
/// @return Devuelve 0 si se obtuvo el valor buscado o -1 si el puntero es NULL
int eLibro_getId(eLibro* this,int* id);

/// @fn int eLibro_setTitle(eLibro*, char*)
/// @brief Funcion que carga el campo title a traves del puntero con el parametro por referencia
/// @param this Puntero a la estructura de libro
/// @param title Puntero a una variable char
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eLibro_setTitle(eLibro* this,char* title);

/// @fn int eLibro_getTitle(eLibro*, char*)
/// @brief Funcion que copia el valor de un campo de la estructura al puntero de char
/// @param this Puntero a la estructura de libro
/// @param title Puntero a una variable char
/// @return Devuelve 0 si se obtuvo el valor buscado o -1 si el puntero es NULL
int eLibro_getTitle(eLibro* this,char* title);

/// @fn int eLibro_setAuthor(eLibro*, char*)
/// @brief Funcion que carga el campo author de la estructura con el parametro por referencia
/// @param this Puntero a la estructura de libro
/// @param author Puntero a una variable char
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eLibro_setAuthor(eLibro* this,char* author);

/// @fn int eLibro_getAuthor(eLibro*, char*)
/// @brief funcion que copia el valor de un campo de la estructura al puntero de char
/// @param this Puntero a la estructura de libro
/// @param author Puntero a una variable char
/// @return Devuelve 0 si se obtuvo el valor buscado o -1 si el puntero es NULL
int eLibro_getAuthor(eLibro* this,char* author);

/// @fn int eLibro_setPrice(eLibro*, float)
/// @brief Funcion que carga el campo price de la estructura con el parametro
/// @param this Puntero a la estructura de libro
/// @param price Parametro por valor de tipo float
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eLibro_setPrice(eLibro* this,float price);

/// @fn int eLibro_getPrice(eLibro*, float*)
/// @brief funcion que copia el valor de un campo de la estructura al puntero float
/// @param this Puntero a la estructura de libro
/// @param price Puntero a una variable float
/// @return Devuelve 0 si se obtuvo el valor buscado o -1 si el puntero es NULL
int eLibro_getPrice(eLibro* this,float* price);

/// @fn int eLibro_setIdEditorial(eLibro*, int)
/// @brief Funcion que carga el campo ideditorial de la estructura con el parametro recibido
/// @param this Puntero a la estructura de libro
/// @param idEditorial Parametro por valor de tipo int
/// @return Devuelve 0 si se realizo la carga o -1 si el puntero es NULL
int eLibro_setIdEditorial(eLibro* this,int idEditorial);

/// @fn int eLibro_getIdEditorial(eLibro*, int*)
/// @brief funcion que copia el valor de un campo de la estructura al puntero int
/// @param this Puntero a la estructura de libro
/// @param idEditorial Puntero a variable de tipo int
/// @return Devuelve 0 si se obtuvo el valor buscado o -1 si el puntero es NULL
int eLibro_getIdEditorial(eLibro* this,int* idEditorial);

/// @fn int eLibro_showABook(eLibro*, eEditorial*)
/// @brief Funcion que imprime los datos de un libro
/// @param this Puntero a la estructura de libro
/// @param this2 Puntero a una estructura de editorial
/// @return Devuelve 0 si puede imprimir la informacion o -1 si hubo un error
int eLibro_showABook(eLibro* this, eEditorial* this2);

/// @fn int eLibro_CompareByName(void*, void*)
/// @brief Funcion criterio que compara por nombre los elementos recibidos por parametros
/// @param element1 Puntero a void que sera casteado a un tipo de estructura
/// @param element2 Puntero a void que sera casteado a un tipo de estructura
/// @return Devuelve 0 si la comparacion es igual, -1 si es decreciente o 1 si es creciente
int eLibro_CompareByName(void* element1, void* element2);

/// @fn int eLibros_filterByEditorial(void*)
/// @brief Funcion criterio que se encarga de filtrar informacion
/// @param element Puntero a un elemento
/// @return devuelve 1 si el item cumple el criterio o 0 si no cumple
int eLibros_filterByEditorial(void* element);

int eLibros_mapByEditorial(void* element);

#endif /* BOOKS_H_ */
