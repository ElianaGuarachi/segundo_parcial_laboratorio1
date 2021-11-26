
#include "Parser.h"

int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks)
{
	int retorno=-1;
	if(pFile != NULL && pArrayListBooks != NULL)
	{
		int cantidad;
		char auxId[10];
		char auxBook[150];
		char auxAuthor[150];
		char auxPrice[50];
		char auxIdEditorial[10];

		eLibro* aBook;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxBook,auxAuthor,auxPrice,auxIdEditorial);// CABECERA
		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxBook,auxAuthor,auxPrice,auxIdEditorial);
			if(cantidad==5)
			{
				retorno=0;
				aBook = eLibro_newParametros(auxId,auxBook,auxAuthor,auxPrice,auxIdEditorial);
				ll_add(pArrayListBooks, aBook);
			}
			else
			{
				break;
			}

		}while(!feof(pFile));
	}
    return retorno;
}

int parser_EditorialsFromText(FILE* pFile , LinkedList* pArrayListEditoriales)
{
	int retorno=-1;
	if(pFile != NULL && pArrayListEditoriales != NULL)
	{
		int cantidad;
		char auxId[10];
		char auxEditorial[150];

		eEditorial* aEditorial;

		fscanf(pFile,"%[^,],%[^\n]\n",auxId,auxEditorial);// CABECERA
		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^\n]\n",auxId,auxEditorial);
			if(cantidad==2)
			{
				retorno=0;
				aEditorial = eEditorial_newParametros(auxId,auxEditorial);
				ll_add(pArrayListEditoriales, aEditorial);
			}
			else
			{
				break;
			}

		}while(!feof(pFile));
	}
    return retorno;
}

int parser_BooksToTextByEditorial(FILE* pFile, LinkedList* filteredList)
{
	int retorno=-1;
	int len;
	int id;
	char title[128];
	char author[128];
	float price;
	int idEditorial;
	eLibro* aBook;
	if(pFile != NULL && filteredList != NULL && (len = ll_len(filteredList))>0)
	{
		fprintf(pFile, "id,title,author,price,idEditorial\n");
		for(int i=0; i<len;i++)
		{
			aBook = (eLibro*) ll_get(filteredList, i);
			if(aBook != NULL && eLibro_getId(aBook, &id)==0 &&
					eLibro_getTitle(aBook, title)==0 &&
					eLibro_getAuthor(aBook, author) ==0 &&
					eLibro_getPrice(aBook,&price)==0 && eLibro_getIdEditorial(aBook,&idEditorial)==0)
			{
				fprintf(pFile, "%d,%s,%s,%.2f,%d\n", id, title,author,price, idEditorial);
			}
		}
		retorno=0;
	}
	return retorno;
}
