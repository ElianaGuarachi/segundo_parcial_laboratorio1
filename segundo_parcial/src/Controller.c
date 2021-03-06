
#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Validaciones.h"

int controller_loadBooksFromText(LinkedList* pArrayListBooks)
{
	int retorno=-1;
	char archivoCompleto[128];
	if(pArrayListBooks != NULL && PedirNombreArchivo(archivoCompleto, sizeof(archivoCompleto)))
	{
	   FILE* pFile;
	   pFile = fopen(archivoCompleto, "r");
	   if(pFile != NULL && parser_BooksFromText(pFile, pArrayListBooks)==0)
	   {
		   retorno=0;
		   fclose(pFile);
	   }
	}
	return retorno;
}

int controller_loadFromText(LinkedList* pArrayListEditorials)
{
	int retorno=-1;
	char archivoCompleto[128];
	if(pArrayListEditorials != NULL && PedirNombreArchivo(archivoCompleto,sizeof(archivoCompleto)))
	{
	   FILE* pFile;
	   pFile = fopen(archivoCompleto, "r");
	   if(pFile != NULL && parser_EditorialsFromText(pFile, pArrayListEditorials)==0)
	   {
			   retorno=0;
			   fclose(pFile);
	   }
	}
	return retorno;
}

int controller_sortBooks(LinkedList* pArrayListBooks)
{
	int retorno=-1;
	if(pArrayListBooks != NULL && ll_sort(pArrayListBooks,eLibro_CompareByName, 1) == 0)
	{
		retorno=0;
	}
	return retorno;
}

int controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials)
{
	int retorno=-1;
	int len;
	int lenE;
	int i,j;
	eLibro* aBook;
	eEditorial* aEditorial;
	if(pArrayListBooks != NULL && (len = ll_len(pArrayListBooks)) > 0 && (lenE = ll_len(pArrayListEditorials)) > 0)
	{
		for(i=0; i<len; i++)
		{
			for(j=0; j<lenE;j++)
			{
				aBook = (eLibro*) ll_get(pArrayListBooks, i);
				aEditorial = (eEditorial*) ll_get(pArrayListEditorials,j);
				if(aBook != NULL && aEditorial != NULL)
				{
					if(eLibro_showABook(aBook, aEditorial)==0)
					{
						break;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_FilteredListByEditorials(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials)
{
	int retorno=-1;
	LinkedList* filteredList = NULL;
	FILE* pFile;
	if(pArrayListBooks != NULL)
	{
		filteredList = ll_filter(pArrayListBooks, eLibros_filterByEditorial);
		controller_ListBooks( filteredList,pArrayListEditorials);
		pFile = fopen("archivoFiltrado.csv", "w");
		if(pFile != NULL && parser_BooksToTextByEditorial(pFile, filteredList)==0)
		{
			retorno=0;
			fclose(pFile);
		}
	}
	return retorno;
}


int controller_mapListByEditorials(LinkedList* pArrayListBooks)
{
	int retorno=-1;
	FILE* pFile;
	if(pArrayListBooks != NULL)
	{
		ll_map(pArrayListBooks, eLibros_mapByEditorial);
		pFile = fopen("mapeado.csv", "w");
		if(pFile != NULL && parser_BooksToTextByEditorial(pFile, pArrayListBooks)==0)
		{
			retorno=0;
			fclose(pFile);
		}
	}
	return retorno;
}

int controller_countBooks(LinkedList* pArrayListBooks)
{
	int retorno=-1;
	int cantidad;
	if(pArrayListBooks != NULL)
	{
		cantidad = ll_count(pArrayListBooks, eLibro_CountBooks);
		retorno = cantidad;
	}
	return retorno;
}


float controller_countPriceByEditorial(LinkedList* pArrayListBooks)
{
	float retorno=-1;
	float priceTotal;
	if(pArrayListBooks != NULL)
	{
		priceTotal = ll_count(pArrayListBooks,eLibro_CountPriceByEditorial);
		retorno = priceTotal;
	}
	return retorno;
}






