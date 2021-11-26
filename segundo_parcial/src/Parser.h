

#ifndef PARSER_H_
#define PARSER_H_
#include "Books.h"
#include "LinkedList.h"

/// @fn int parser_BooksFromText(FILE*, LinkedList*)
/// @brief Funcion encargada de leer la informacion de un archivo y llevar las mismas a memoria dinamica en una lista
/// @param pFile Puntero al archivo
/// @param pArrayListBooks Puntero a la lista de estructura de libros
/// @return Devuelve 0 si se realizo las lecturas de forma correcta, o -1 si los punteros son NULL
int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks);

/// @fn int parser_EditorialsFromText(FILE*, LinkedList*)
/// @brief Funcion encargada de leer la informacion de un archivo y llevar las mismas a memoria dinamica en una lista
/// @param pFile Puntero al archivo
/// @param pArrayListEditoriales Puntero a la lista de estructura de editoriales
/// @return Devuelve 0 si se realizo las lecturas de forma correcta, o -1 si los punteros son NULL
int parser_EditorialsFromText(FILE* pFile , LinkedList* pArrayListEditoriales);

/// @fn int parser_BooksToTextByEditorial(FILE*, LinkedList*)
/// @brief Funcion que se encarga de crear o reemplazar un archivo con la informacion de una lista
/// @param pFile Puntero al archivo
/// @param filteredList Puntero a la lista
/// @return Devuelve 0 si se realizo las lecturas de forma correcta, o -1 si los punteros son NULL
int parser_BooksToTextByEditorial(FILE* pFile, LinkedList* filteredList);

#endif /* PARSER_H_ */
