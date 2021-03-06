

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Books.h"
#include "Parser.h"

/// @fn int controller_loadBooksFromText(LinkedList*)
/// @brief Funcion que abre un archivo de texto en modo lectura para cargar la informacion del mismo
/// @param pArrayListBooks Puntero a la lista de estructura de libros
/// @return Devuelve -1 si el puntero a la lsta es NULL o 0 si se realizo la carga
int controller_loadBooksFromText(LinkedList* pArrayListBooks);

/// @fn int controller_loadFromText(LinkedList*)
/// @brief Funcion que abre un archivo de texto en modo lectura para cargar la informacion del mismo
/// @param pArrayListEditorials Puntero a la lista de estructura de libros
/// @return Devuelve -1 si el puntero a la lsta es NULL o 0 si se realizo la carga
int controller_loadFromText(LinkedList* pArrayListEditorials);

/// @fn int controller_sortbooks(LinkedList*)
/// @brief Funcion que se encarga de que se realice el ordenamiento de la lista de libros de manera ascendente
/// @param pArrayListBooks Puntero a la lista
/// @return Devuelve -1 si el puntero a la lsta es NULL o 0 si se realizo el ordenamiento
int controller_sortBooks(LinkedList* pArrayListBooks);

/// @fn int controller_ListBooks(LinkedList*, LinkedList*)
/// @brief Funcion que se encarga de recorrer las dos listas para imprimir la informacion de un libro con el nombre de la editorial
/// @param pArrayListBooks Puntero a la lista de libros
/// @param pArrayListEditorials Puntero a la lista de editoriales
/// @return Devuelve -1 si el puntero a la lsta es NULL o 0 si se imprime la informacion
int controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials);

/// @fn int controller_ListEditorials(LinkedList*, LinkedList*)
/// @brief Funcion que crea un archivo para guardar la informacion de los libros que fueron filtrados segun la editorial
/// @param pArrayListBooks Puntero a la lista de libros
/// @param pArrayListEditorials Puntero a la lista de libros filtrados
/// @return Devuelve -1 si los punteros son NULL o 0 si se guardo la lista filtrada en un archivo de texto
int controller_FilteredListByEditorials(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials);

int controller_mapListByEditorials(LinkedList* pArrayListBooks);

int controller_countBooks(LinkedList* pArrayListBooks);

float controller_countPriceByEditorial(LinkedList* pArrayListBooks);

#endif /* CONTROLLER_H_ */
