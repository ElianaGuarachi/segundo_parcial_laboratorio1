
#include "Editorial.h"


eEditorial* eEditorial_new()
{
	eEditorial* newEditorial;
	newEditorial = (eEditorial*)malloc(sizeof(eEditorial));
	if(newEditorial != NULL)
	{
		eEditorial_setId(newEditorial,0);
		eEditorial_setName(newEditorial, " ");
	}
	return newEditorial;
}

eEditorial* eEditorial_newParametros(char* idString, char* name)
{
	eEditorial* newEditorial;
	int id;
	if(idString != NULL && name != NULL)
	{
		newEditorial = eEditorial_new();
		id = atoi(idString);
		if(!(eEditorial_setId(newEditorial,id)==0 && eEditorial_setName(newEditorial, name)==0))
		{
			free(newEditorial);
			newEditorial = NULL;
		}
	}
	return newEditorial;
}

int eEditorial_delete(eEditorial* this)
{
	int retorno=-1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int eEditorial_setId(eEditorial* this,int id)
{
	int retorno=-1;
	if(this != NULL && id>0)
	{
		this->idEditorial = id;
		retorno=0;
	}
	return retorno;
}

int eEditorial_getId(eEditorial* this,int* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		*id=this->idEditorial;
		retorno=0;
	}
	return retorno;
}

int eEditorial_setName(eEditorial* this,char* name)
{
	int retorno=-1;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name, name);
		retorno=0;
	}
	return retorno;
}

int eEditorial_getName(eEditorial* this,char* name)
{
	int retorno=-1;
	if(this != NULL && name != NULL)
	{
		strcpy(name, this->name);
		retorno=0;
	}
	return retorno;
}

void eEditorial_showAEditorial(eEditorial* this)
{
	int id;
	char editorial[128];
	if(eEditorial_getId(this, &id)==0 &&
	   eEditorial_getName(this, editorial)==0)
	{
		printf("\n%5d\t %25s\n", id, editorial);
	}
}
















