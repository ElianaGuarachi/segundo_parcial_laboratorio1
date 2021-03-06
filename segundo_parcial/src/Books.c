
#include "Books.h"

eLibro* eLibro_new()
{
	eLibro* newBook;
	newBook = (eLibro*)malloc(sizeof(eLibro));
	if(newBook != NULL)
	{
		eLibro_setId(newBook, 0);
		eLibro_setTitle(newBook, " ");
		eLibro_setAuthor(newBook, " ");
		eLibro_setPrice(newBook, 0);
		eLibro_setIdEditorial(newBook, 0);
	}
	return newBook;
}
eLibro* eLibro_newParametros(char* idString, char* title, char* author, char* priceString, char* idEditorialString)
{
	eLibro* newBook;
	int id;
	float price;
	int idEditorial;
	if(idString != NULL && title != NULL && author != NULL && priceString != NULL && idEditorialString != NULL)
	{
		newBook = eLibro_new();
		id = atoi(idString);
		price = atof(priceString);
		idEditorial = atoi(idEditorialString);

		if(!(eLibro_setId(newBook, id)==0 && eLibro_setTitle(newBook, title) == 0 && eLibro_setAuthor(newBook,author) == 0 &&
				eLibro_setPrice(newBook, price)==0 && eLibro_setIdEditorial(newBook,idEditorial) == 0))
		{
			free(newBook);
			newBook = NULL;
		}
	}
	return newBook;
}

int eLibro_delete(eLibro* this)
{
	int retorno=-1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int eLibro_setId(eLibro* this,int id)
{
	int retorno=-1;
	if(this != NULL && id>0)
	{
		this->id = id;
		retorno=0;
	}
	return retorno;
}

int eLibro_getId(eLibro* this,int* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}

int eLibro_setTitle(eLibro* this,char* title)
{
	int retorno=-1;
	if(this != NULL && title != NULL)
	{
		strcpy(this->title,title);
		retorno=0;
	}
	return retorno;
}

int eLibro_getTitle(eLibro* this,char* title)
{
	int retorno=-1;
	if(this != NULL && title != NULL)
	{
		strcpy(title, this->title);
		retorno=0;
	}
	return retorno;
}

int eLibro_setAuthor(eLibro* this,char* author)
{
	int retorno=-1;
	if(this != NULL && author != NULL)
	{
		strcpy(this->author,author);
		retorno=0;
	}
	return retorno;
}

int eLibro_getAuthor(eLibro* this,char* author)
{
	int retorno=-1;
	if(this != NULL && author != NULL)
	{
		strcpy(author, this->author);
		retorno = 0;
	}
	return retorno;
}

int eLibro_setPrice(eLibro* this,float price)
{
	int retorno=-1;
	if(this != NULL && price > 0)
	{
		this->price = price;
		retorno=0;
	}
	return retorno;
}

int eLibro_getPrice(eLibro* this,float* price)
{
	int retorno=-1;
	if(this != NULL && price != NULL)
	{
		*price = this->price;
		retorno=0;
	}
	return retorno;
}

int eLibro_setIdEditorial(eLibro* this,int idEditorial)
{
	int retorno=-1;
	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}

int eLibro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno=-1;
	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

int eLibro_showABook(eLibro* this, eEditorial* this2)
{
	int retorno=-1;
	int id;
	char title[128];
	char author[128];
	float price;
	int idEditorial;
	int idListEditorial;
	char nameEditorial[128];
	if(eLibro_getIdEditorial(this,&idEditorial)==0 && eEditorial_getId(this2, &idListEditorial) == 0 && idEditorial == idListEditorial)
	{
		if(eLibro_getId(this, &id)==0 &&
			   eLibro_getTitle(this, title)==0 &&
			   eLibro_getAuthor(this, author) ==0 &&
			   eLibro_getPrice(this,&price)==0 && eEditorial_getName(this2, nameEditorial) == 0)
		{
			printf("\n%5d\t %45s \t %30s \t %5.2f \t %20s \n", id, title, author, price, nameEditorial);
			retorno = 0;
		}
	}
	return retorno;
}

int eLibro_CompareByName(void* element1, void* element2)
{
	char authorA[50];
	char authorB[50];
	int compara;
	if(element1 != NULL && element2 != NULL)
	{
		if(eLibro_getAuthor((eLibro*) element1, authorA)==0 &&
		   eLibro_getAuthor((eLibro*) element2, authorB)==0)
		{
			compara = strcmp(authorA,authorB);
		}
	}
	return compara;
}

int eLibros_filterByEditorial(void* element)
{
	int retorno=-1;
	int auxId;

	if(element != NULL)
	{
		retorno=0;
		if(!eLibro_getIdEditorial((eLibro*)element,&auxId) && auxId == 4)
		{
			retorno=1;
		}
	}
	return retorno;
}


int eLibros_mapByEditorial(void* element)
{
	int retorno=-1;
	int auxId;
	float auxPrice;
	float descuento;
	float newPrice;
	if(element != NULL && eLibro_getIdEditorial((eLibro*)element,&auxId)==0 &&
			eLibro_getPrice((eLibro*)element,&auxPrice)==0 && (auxId == 1 || auxId == 2))
	{
		if(auxId == 1  && auxPrice>=300)
		{
			descuento = 0.2;
		}
		else
		{
			if(auxId == 2  && auxPrice<=200)
			{
				descuento = 0.1;
			}
		}
		newPrice = auxPrice - auxPrice * descuento;
		if(!eLibro_setPrice((eLibro*)element,newPrice))
		{
			retorno = 0;
		}
	}
	return retorno;
}


float eLibro_CountBooks(void* element)
{
	float retorno=-1;
	float auxPrice;
	if(element != NULL)
	{
		retorno=0;
		if(eLibro_getPrice((eLibro*)element,&auxPrice)==0  && auxPrice>500)
		{
			retorno=1;
		}
	}
	return retorno;
}

float eLibro_CountPriceByEditorial(void* element)
{
	float price = 0;
	float auxPrice;
	int auxIdEditorial;
	if(element != NULL && eLibro_getIdEditorial((eLibro*)element,&auxIdEditorial)==0 &&
			eLibro_getPrice((eLibro*)element,&auxPrice)==0 && auxIdEditorial == 3)
	{
		price = auxPrice;
	}
	return price;
}



