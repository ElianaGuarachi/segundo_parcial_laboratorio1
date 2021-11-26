

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include "utn.h"

/// @fn int MenuPrincipal()
/// @brief Funcion que muestra las opciones de Menu y pide la opcion deseada
/// @return Devuelve el numero de la opcion del menu elegido o -1 si no se ingreso una opcion valida
int MenuPrincipal();

/// @fn int ValidarCadenaDePalabras(char[], int)
/// @brief Funcion que recorre una cadena de caracteres comprobando que solo haya letras
/// @param cadena Puntero a char
/// @param limite Parametro por valor del tamanio de bytes de la cadena
/// @return Devuelve 1 si la cadena es solo de letras o 0 si algun caracter no esta permitido
int ValidarCadenaDePalabras(char* cadena, int limite);

/// @fn int ConcatenarFornatoAlArchivo(char*, char*)
/// @brief Funcion que concatena el formato del archivo
/// @param nombre Puntero a char
/// @param nombreCompleto Puntero a char
/// @return Devuelve 1 si realizo la concatenacion o -1 si los punteros eran NULL
int ConcatenarFornatoAlArchivo(char* nombre, char* nombreCompleto);

/// @fn int PedirNombreArchivo(char*, int)
/// @brief funcion que va a pedir al usuario el nombre del archivo que desea cargar
/// @param archivoCompleto Puntero a char
/// @param tamanio Sizeof del array de char
/// @return Devuelve 1 si realizo la concatenacion o -1 si los punteros eran NULL
int PedirNombreArchivo(char* archivoCompleto, int tamanio);

#endif /* VALIDACIONES_H_ */
