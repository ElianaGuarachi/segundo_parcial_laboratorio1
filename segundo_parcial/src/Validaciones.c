
#include "Validaciones.h"

int MenuPrincipal()
{
	int retorno=-1;
	int option;
	printf("\nMenu:\n"
		    			"\n1. Cargar los datos de los libros desde el archivo libros.csv (modo texto)"
		    			"\n2. Cargar los datos de las editoriales desde el archivo editoriales.csv (modo texto)"
		    			"\n3. Ordenar la lista de libros por Autor de manera ascendente"
		    			"\n4. Listado de los libros"
		    			"\n5. listado de los libros de la editorial MINOTAURO. Guardar el listado en un archivo csv."
						"\n6. Nuevo listado con precios descuentos"
		    			"\n7. Salir");

	if(ObtenerEntero(&option, "\nIngrese una opcion del menu: ", "Error. Ingrese una opcion que este dentro del menu: ", 1, 7, 1)==0)
	{
		retorno = option;
	}
	return retorno;
}

int ValidarCadenaDePalabras(char* cadena, int limite)
{
	int retorno=1;
	int i;
	for(i=0; i< limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] > 64 && cadena [i] < 91) || (cadena[i] > 159 && cadena[i] < 166) || (i!=0 && cadena[i] == 32))
			{
				continue;
			}

			if(cadena[i] < 97 || cadena[i] > 122)
			{
				retorno= 0;
				break;
			}
		}

	return retorno;
}

int ConcatenarFornatoAlArchivo(char* nombre, char* nombreCompleto)
{
	int retorno=-1;
	if(nombre != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,nombre);
		strcat(nombreCompleto,".csv");
		retorno = 1;
	}
	return retorno;
}

int PedirNombreArchivo(char* archivoCompleto, int tamanio)
{
	int retorno=-1;
	char archivo[128];
	char auxArchivoCompleto[128];
	char respuesta;

	if(ObtenerNombreDeArchivo(archivo, "\nIngrese el nombre del archivo CSV (sin extension): \n",
			 "\nError en nombre del archivo, ingrese nuevamente: \n", 1)
			&& ConcatenarFornatoAlArchivo(archivo, auxArchivoCompleto))
	{
	   printf("\nEl nombre del archivo es: %s", auxArchivoCompleto);
	   if(!(ObtenerCaracterDosOpciones(&respuesta, "\nEs correcto? (s-n): ", "\nError, ingrese una opcion correcta: ",'s','n',1)) && respuesta == 's')
	   {
		   retorno=1;
		   strncpy(archivoCompleto,auxArchivoCompleto, tamanio);
	   }
	}
	return retorno;
}














