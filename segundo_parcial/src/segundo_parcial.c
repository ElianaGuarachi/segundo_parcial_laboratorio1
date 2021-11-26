/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"
#include "Validaciones.h"
#include "LinkedList.h"
#include "Books.h"
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int option;
	int flagCargaLibros=0;
	int flagCargaEditoriales=0;
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();

	printf("\nLIBROS Y EDITORIALES\n");
	    do{

	    	if((option=MenuPrincipal()) != -1)
	    	{
				switch(option)
				{
					case 1:
						if(controller_loadBooksFromText(listaLibros)==-1)
						{
							printf("\nNo hay un archivo con el nombre ingresado o fallo la carga\n");
						}
						else
						{
							flagCargaLibros=1;
							printf("\nSe realizo la carga de la lista de libros correctamente\n");
						}
						break;

					case 2:
						if(controller_loadFromText(listaEditoriales)==0)
						{
							flagCargaEditoriales=1;
							printf("\nSe realizo la carga de la lista de editoriales correctamente\n");
						}
						else
						{
							printf("\nNo hay un archivo con el nombre ingresado o fallo la carga\n");
						}
						break;

					case 3:
						if(controller_sortBooks(listaLibros)==-1 || flagCargaLibros == 0 || flagCargaEditoriales == 0)
						{
							printf("\nHubo un error al ordenar la lista o no cargo la informacion de alguna lista\n");
						}
						else
						{
							printf("\nLos libros fueron ordenados alfabeticamente por autor\n");
						}
						break;

					case 4:
						if(controller_ListBooks(listaLibros, listaEditoriales)==-1 || flagCargaLibros == 0 || flagCargaEditoriales == 0)
						{
							printf("\nHubo un error para mostrar la lista de libros o no cargo la informacion de alguna lista\n");
						}
						break;

					case 5:
						if(controller_FilteredListByEditorials(listaLibros, listaEditoriales) == -1 || flagCargaLibros == 0 || flagCargaEditoriales == 0)
						{
							printf("\nHubo un error para mostrar la lista de libros o no cargo la informacion de alguna lista\n");
						}
						break;

					case 6:
						if(controller_mapListByEditorials(listaLibros) == 0)
						{
							printf("\nSe creo la lista mapeada\n");
						}
						break;

					case 7:
						printf("\nUsted salio del programa\n");
						break;
				}
	    	}
		}while(option != 7);

	return EXIT_SUCCESS;
}