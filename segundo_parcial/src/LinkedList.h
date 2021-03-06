/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif


/// @fn LinkedList ll_newLinkedList*(void)
/// @brief Crea un nuevo LinkedList en memoria de manera dinamica
/// @return Retorna (NULL) en el caso de no conseguir espacio en memoria o el puntero al espacio reservado
LinkedList* ll_newLinkedList(void);

/// @fn int ll_len(LinkedList*)
/// @brief Retorna la cantidad de elementos de la lista
/// @param this Puntero a la lista
/// @return Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
int ll_len(LinkedList* this);  //devuelve el valor del campo int size

/// @fn Node* test_getNode(LinkedList*,int)
/// @brief  Permite realizar el test de la funcion getNode la cual es privada
/// @param this Puntero a la lista
/// @param nodeIndex Indice del nodo a obtener
/// @return Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  (pElement) Si funciono correctamente
Node* test_getNode(LinkedList* this, int nodeIndex);

/// @fn int test_addNode(LinkedList*, int, void*)
/// @brief Permite realizar el test de la funcion addNode la cual es privada
/// @param this Puntero a la lista
/// @param nodeIndex Ubicacion donde se agregara el nuevo nodo
/// @param pElement Puntero al elemento a ser contenido por el nuevo nodo
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/// @fn int ll_add(LinkedList*, void*)
/// @brief Agrega un elemento a la lista
/// @param this Puntero a la lista
/// @param pElement Puntero al elemento a ser agregado
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 0) Si funciono correctamente
int ll_add(LinkedList* this, void* pElement);

/// @fn void ll_get*(LinkedList*, int)
/// @brief Permite realizar el test de la funcion addNode la cual es privada
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento a obtener
/// void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  (pElement) Si funciono correctamente
void* ll_get(LinkedList* this, int index);

/// @fn int ll_set(LinkedList*, int, void*)
/// @brief Modifica un elemento de la lista
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento a modificar
/// @param pElement Puntero al nuevo elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int ll_set(LinkedList* this, int index,void* pElement);

/// @fn int ll_remove(LinkedList*, int)
/// @brief Elimina un elemento de la lista
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento a eliminar
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int ll_remove(LinkedList* this,int index);

/// @fn int ll_clear(LinkedList*)
/// @brief Elimina todos los elementos de la lista
/// @param this Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
////                 ( 0) Si funciono correctamente
int ll_clear(LinkedList* this);

/// @fn int ll_deleteLinkedList(LinkedList*)
/// @brief Elimina todos los elementos de la lista y la lista
/// @param this Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 0) Si funciono correctamente
int ll_deleteLinkedList(LinkedList* this);

/// @fn int ll_indexOf(LinkedList*, void*)
/// @brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
/// @param this Puntero a la lista
/// @param pElement Puntero al elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  (indice del elemento) Si funciono correctamente
int ll_indexOf(LinkedList* this, void* pElement);

/// @fn int ll_isEmpty(LinkedList*)
/// @brief Indica si la lista esta vacia o no
/// @param this Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 0) Si la lista NO esta vacia
///                  ( 1) Si la lista esta vacia
int ll_isEmpty(LinkedList* this);

/// @fn int ll_push(LinkedList*, int, void*)
/// @brief Inserta un nuevo elemento en la lista en la posicion indicada
/// @param this Puntero a la lista
/// @param index Ubicacion donde se agregara el nuevo elemento
/// @param pElement Puntero al nuevo elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int ll_push(LinkedList* this, int index, void* pElement);

/// @fn void ll_pop*(LinkedList*, int)
/// @brief Elimina el elemento de la posicion indicada y retorna su puntero
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento eliminar
/// "return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                          (pElement) Si funciono correctamente
void* ll_pop(LinkedList* this,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento

/// @fn int ll_contains(LinkedList*, void*)
/// @brief Determina si la lista contiene o no el elemento pasado como parametro
/// @param this Puntero a la lista
/// @param pElement void* Puntero del elemento a verificar
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 1) Si contiene el elemento
///                  ( 0) si No contiene el elemento
int ll_contains(LinkedList* this, void* pElement);

/// @fn int ll_containsAll(LinkedList*, LinkedList*)
/// @brief Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
/// @param this Puntero a la lista
/// @param this2 Puntero a la lista
/// @return Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
///                  ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
///                  ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
int ll_containsAll(LinkedList* this,LinkedList* this2);

/// @fn LinkedList ll_subList*(LinkedList*, int, int)
/// @brief Crea y retorna una nueva lista con los elementos indicados
/// @param this Puntero a la lista
/// @param from Indice desde el cual se copian los elementos en la nueva lista
/// @param to Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
/// @return Retorna  (NULL) Error: si el puntero a la listas es NULL
///                o (si el indice from es menor a 0 o mayor al len de la lista)
///                o (si el indice to es menor o igual a from o mayor al len de la lista)
///                  (puntero a la nueva lista) Si ok
LinkedList* ll_subList(LinkedList* this,int from,int to);

/// @fn LinkedList ll_clone*(LinkedList*)
/// @brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
/// @param this Puntero a la lista
/// @return Retorna  (NULL) Error: si el puntero a la listas es NULL
///                  (puntero a la nueva lista) Si ok
LinkedList* ll_clone(LinkedList* this);

/// @fn int ll_sort(LinkedList*, int(*)(void*, void*), int)
/// @brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
/// @param this Puntero a la lista
/// @param pFunc Puntero a la funcion criterio
/// @param order [1] Indica orden ascendente - [0] Indica orden descendente
/// @return Retorna  (-1) Error: si el puntero a la listas es NULL
///                  ( 0) Si ok
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/// @fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
/// @brief Funcion que crea una lista al filtrar la lista de libros por editorial
/// @param this Puntero a la lista
/// @param fn Puntero a la funcion criterio
/// @return Devuelve puntero a la lista nueva o NULL si el puntero es NULL
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));

/// @fn int ll_map(LinkedList*, int(*)(void*))
/// @brief Funcion que recorre la lista para realizar la funcion criterio en cada elemento de la lista
/// @param this Puntero a la lista
/// @param pFn Puntero a la funcion criterio
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o el puntero de la funcion
///                  ( 0) Si cumple su funcion
int ll_map (LinkedList* this, int (*fn)(void* element));


float ll_count(LinkedList* this, float (*fn)(void* element));








