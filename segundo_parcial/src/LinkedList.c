
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;
	if(this != NULL && nodeIndex>=0 &&  ll_len(this)> nodeIndex)
	{
		pNode = this->pFirstNode;

		for(i=0; i< ll_len(this); i++)
		{
			if(i== nodeIndex)
			{
				break;
			}
			else
			{
				pNode = pNode->pNextNode;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this != NULL && nodeIndex >= 0 &&  nodeIndex <= ll_len(this))
    {
    	pNode = (Node*)malloc(sizeof(Node));
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
			if(nodeIndex == 0)
			{
				pNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
			}
			else
			{
				pNode->pNextNode = getNode(this, nodeIndex);
				getNode(this, nodeIndex-1)->pNextNode = pNode;
			}
			this->size++;
			returnAux=0;
    	}
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(addNode(this, ll_len(this), pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && ll_len(this) > index)
    {
    	pNode =  getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this != NULL && index >= 0 && ll_len(this) > index)
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    if(this != NULL && index >= 0 && ll_len(this) > index)
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		if(index == 0)
    		{
				this->pFirstNode = pNode->pNextNode;
    		}
    		else
    		{
				getNode(this, index-1)->pNextNode = pNode->pNextNode;
    		}
    		free(pNode);
			this->size--;
			returnAux = 0;
    	}
    }
    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
    	for(i=ll_len(this)-1; i>=0; i--)
    	{
    		free(getNode(this, i));
    	}
    	this->pFirstNode = NULL;
    	this->size = 0;
    	returnAux = 0;
    }
    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL && !ll_clear(this))
    {
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int index = -1;
    int i;
    if(this != NULL)
    {
    	for(i=0; i< ll_len(this); i++)
    	{
    		if(ll_get(this,i) == pElement)
    		{
    			index = i;
    			break;
    		}
    	}
    }
    return index;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 1;
    	if(ll_len(this))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(!addNode(this,index, pElement))
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && ll_len(this) > index)
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this,index);
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 1;
    	if(ll_indexOf(this, pElement) < 0)
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(i=0; i<ll_len(this2);i++)
    	{
    		if(!ll_contains(this, ll_get(this2, i)))
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    int i;
    len = ll_len(this);
    if(this != NULL && from >= 0 && from <= len && to >= from && to <= len)
    {
    	cloneArray = ll_newLinkedList();
		for(i = from; i< to; i++)
		{
			ll_add(cloneArray,ll_get(this,i));
		}
    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len,i,j;
    void* elementA;
    void* elementB;
    if(this != NULL && pFunc!= NULL && (order==0 || order == 1))
    {
    	len = ll_len(this);
    	for(i=0; i<len-1; i++)
    	{
    		for(j=i+1; j<len; j++)
    		{
    			elementA = ll_get(this,i);
    			elementB = ll_get(this,j);
    			if((order==1 && pFunc(elementA,elementB) > 0) || (order==0 && pFunc(elementA,elementB) < 0))
    			{
    				ll_set(this,i,elementB);
    				ll_set(this,j,elementA);
    			}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}



LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* filteredList = NULL;
	int i,len;
	if(this != NULL && fn != NULL)
	{
		filteredList = ll_newLinkedList();
		len = ll_len(this);
		for(i = 0; i< len; i++)
		{
			if(fn(ll_get(this,i)))
			{
				ll_add(filteredList,ll_get(this,i));
			}
		}
	}
	return filteredList;
}


/*
Desarrollar la funci�n ll_map en la biblioteca linkedList, la cual recibir� la lista y una funci�n.
La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem de la lista,
de este modo se realizar�n descuentos a los precios seg�n se detalla:
* PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
*/

LinkedList* ll_map(LinkedList* this, int (*fn)(void* element))
{
	int len;
	int i;
	LinkedList* mapList = NULL;
	if(this != NULL && fn != NULL)
	{
		mapList = ll_newLinkedList();
		len = ll_len(this);
		for(i=0;i<len;i++)
		{
			if(fn(ll_get(this,i))==0)
			{
				ll_add(mapList,ll_get(this,i));
			}
		}
	}
	return mapList;
}




