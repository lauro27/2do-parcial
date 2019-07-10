#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Incrementa en 1 el size de la lista
 *
 * \param this LinkedList* Lista
 * \return int -1 si el puntero es NULL, 0 si pudo hacerlo.
 *
 */
int ll_increase_size(LinkedList* list)
{
    int retVal = -1;
    if (list!=NULL)
    {
        list->size +=1;
        retVal = 0;
    }
    return retVal;
}
/** \brief Decrementa el size de la lista
 *
 * \param this LinkedList* Lista
 * \return int -1 si el puntero es NULL, 0 si pudo hacerlo.
 *
 */
int ll_decrease_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size--;
        retVal = 0;
    }
    return retVal;
}
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if (this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}
/** \brief Crea un nuevo nodo y le asigna el elemento pasado por parametro.
 *         NO verifica nulidad de elemento.
 *         Inicializa el puntero al proximo nodo en NULL.
 *
 * \param ptrElement void* elemento.
 * \return Node* nodo con elemento cargado.
 *
 */
Node* ll_newNode(void* ptrElement)
{
    Node* retNode = (Node*)malloc(sizeof(Node));
    if (retNode!=NULL)
    {
        retNode->pElement = ptrElement;
        retNode->pNextNode = NULL;
    }
    return retNode;
}
/** \brief Devuelve el elemento señalado por un nodo
 *
 * \param this Node* Nodo
 * \return void* Si el nodo es NULL retorna NULL, sino retorna el elemento
 *
 */
void* ll_get_NodeElement(Node* this)
{
    void* retPtr = NULL;
    if (this!=NULL)
    {
        retPtr = this->pElement;
    }
    return retPtr;
}
/** \brief Retorna el primer nodo de una LinkedList.
 *
 * \param this LinkedList* Puntero a la lista.
 * \return Node* Retorna NULL si la lista es NULL, sino retorna el primer nodo.
 *
 */
Node* ll_get_fNode(LinkedList* this)
{
    Node* retNode = NULL;
    if (this!=NULL)
    {
        retNode = this->pFirstNode;
    }
    return retNode;
}
/** \brief Retorna el puntero a nodo siguiente al pasado por parametro
 *
 * \param this Node* Puntero a nodo
 * \return Node* Retorna NULL si el nodo es NULL, sino retorna el siguiente nodo
 *
 */
Node* ll_get_nNode(Node* this)
{
    Node* retNode = NULL;
    if (this!=NULL)
    {
        retNode = this->pNextNode;
    }
    return retNode;
}
/** \brief Devuelve el ultimo nodo de una lista
 *
 * \param this LinkedList* List
 * \return Node* Si la lista es NULL o esta vacia retorna NULL, sino retorna el ultimo nodo
 *
 */
Node* ll_get_lNode(LinkedList* this)
{
    Node* retNode = NULL;
    if (this!=NULL)
    {
        if (ll_isEmpty(this)==0)
        {
            Node* lastNode = ll_get_fNode(this);
            while (lastNode!=NULL)
            {
                retNode = lastNode;
                lastNode = ll_get_nNode(retNode);
            }
        }
    }
    return retNode;
}
/** \brief Setea el puntero al proximo nodo
 *
 * \param this Node* nodo a setear
 * \param nextNode Node* proximo nodo
 * \return int 0 si this / nextNode son NULL, 1 si lo seteo
 *
 */
int ll_set_NextNode(Node* this, Node* nextNode)
{
    int retVal = 0;
    if (this!=NULL&&nextNode!=NULL)
    {
        this->pNextNode = nextNode;
        retVal = 1;
    }
    return retVal;
}
/** \brief Setea el primer nodo de la lista, NO verifica si hay datos previos.
 *
 * \param this LinkedList* lista
 * \param fNode Node* nodo
 * \return int Retorna (-1) si el puntero a lista es NULL, sino retorna 1;
 *
 */
int ll_set_fNode(LinkedList* this, Node* fNode)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->pFirstNode = fNode;
        retVal = 1;
    }
    return retVal;
}
/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL)
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
    Node* retNode = NULL;
    if (this!=NULL&&nodeIndex>=0)
    {
        if (nodeIndex<(ll_len(this)))
        {
            int actualIndex = 0;
            Node* auxNode = NULL;
            auxNode = ll_get_fNode(this);
            while (auxNode!=NULL&&actualIndex<nodeIndex)
            {
                auxNode = ll_get_nNode(auxNode);
                actualIndex++;
            }
            if (actualIndex==nodeIndex&&auxNode!=NULL)
            {
                retNode = auxNode;
            }
        }
    }
    return retNode;
}
/** \brief Setea el elemnto de un nodo
 *
 * \param this Node* Nodo
 * \param ptrElement void* Elemento
 * \return int -1 si el nodo es NULL, si lo seteo retorna 0
 *
 */
int ll_set_NodeElement(Node* this, void* ptrElement)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->pElement = ptrElement;
        retVal = 0;
    }
    return retVal;
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
    if (this!=NULL&&nodeIndex>(-1))
    {
        if (nodeIndex<=ll_len(this))
        {
            Node* auxNode = ll_get_fNode(this);
            Node* prevNode = auxNode;
            int actualIndex = 0;
            while (auxNode!=NULL&&actualIndex<nodeIndex)
            {
                prevNode = auxNode;
                auxNode = ll_get_nNode(auxNode);
                actualIndex++;
            }
            if (nodeIndex==0)
            {
                if (auxNode!=NULL)
                {
                    Node* newNode = ll_newNode(pElement);
                    ll_set_fNode(this,newNode);
                    ll_set_NextNode(newNode,auxNode);
                    ll_increase_size(this);
                    returnAux = 0;
                }
                else
                {
                    Node* newNode = ll_newNode(pElement);
                    ll_set_fNode(this,newNode);
                    ll_increase_size(this);
                    returnAux = 0;
                }
            }
            else if (actualIndex==nodeIndex)
            {
                Node* newNode = ll_newNode(pElement);
                ll_set_NextNode(prevNode,newNode);
                ll_set_NextNode(newNode,auxNode);
                ll_increase_size(this);
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        Node* newNode = ll_newNode(pElement);
        Node* lastNode = NULL;
        switch (ll_isEmpty(this))
        {
        case 0:
            lastNode = ll_get_lNode(this);
            if (newNode!=NULL)
            {
                ll_set_NextNode(lastNode,newNode);
                ll_increase_size(this);
                returnAux = 0;
            }
            break;
        case 1:
            if (newNode!=NULL)
            {
                ll_set_fNode(this,newNode);
                ll_increase_size(this);
                returnAux = 0;
            }
            break;
        default:
            free(newNode);
            break;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if (this!=NULL&&index>(-1))
    {
        Node* auxNode = ll_get_fNode(this);
        int currentIndex = 0;
        while (auxNode!=NULL&&currentIndex<index)
        {
            auxNode = ll_get_nNode(auxNode);
            currentIndex++;
        }
        if (currentIndex==index&&auxNode!=NULL)
        {
            returnAux = ll_get_NodeElement(auxNode);
        }
    }
    return returnAux;
}
int ll_delete_fNode(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        Node* fNode = NULL;
        Node* nNode = NULL;
        fNode = ll_get_fNode(this);
        nNode = ll_get_nNode(fNode);
        ll_set_fNode(this,nNode);
        free(fNode);
    }
    return retVal;
}
/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if (this!=NULL&&index>(-1))
    {
        Node* auxNode = ll_get_fNode(this);
        int currentIndex = 0;
        while (auxNode!=NULL&&currentIndex<index)
        {
            auxNode = ll_get_nNode(auxNode);
            currentIndex++;
        }
        if (currentIndex==index&&auxNode!=NULL)
        {
            ll_set_NodeElement(auxNode,pElement);
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if (this!=NULL&&index>=0)
    {
        Node* auxNode = ll_get_fNode(this);
        Node* prevNode = NULL;
        Node* nextNode = NULL;
        int currentIndex = 0;
        while (auxNode!=NULL&&currentIndex<index)
        {
            prevNode = auxNode;
            auxNode = ll_get_nNode(auxNode);
            currentIndex++;
        }
        if (currentIndex==index&&auxNode!=NULL)
        {
            if (index>0)
            {
                nextNode = ll_get_nNode(auxNode);
                ll_set_NextNode(prevNode,nextNode);
                free(auxNode);
                ll_decrease_size(this);
                returnAux = 0;
            }
            else if (index==0)
            {
                nextNode = ll_get_nNode(auxNode);
                ll_set_fNode(this,nextNode);
                ll_decrease_size(this);
                ll_set_NodeElement(auxNode,NULL);
                free(auxNode);
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        int i = 0;
        for (;i<ll_len(this);i++)
        {
            ll_delete_fNode(this);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        void* auxPtr;
        int i;
        for (i=0;i<ll_len(this);i++)
        {
            auxPtr = ll_get(this,i);
            if (auxPtr==pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        Node* fNode = ll_get_fNode(this);
        if (fNode!=NULL)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL&&index>=0)
    {
        returnAux = addNode(this,index,pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if (this!=NULL&&index>=0)
    {
        if (index<ll_len(this))
        {
            returnAux = ll_get(this,index);
            ll_remove(this,index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        int index = ll_indexOf(this,pElement);
        if (index>=0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    if (this!=NULL&&this2!=NULL)
    {
        int indexL2 , indexL1 , coincides = 0;
        void* auxElem1;
        void* auxElem2;
        for (indexL2=0;indexL2<ll_len(this2);indexL2++)
        {
            auxElem2 = ll_get(this2,indexL2);
            for (indexL1=0;indexL1<ll_len(this);indexL1++)
            {
                auxElem1 = ll_get(this,indexL1);
                if (auxElem1==auxElem2)
                {
                    coincides++;
                    break;
                }
            }
        }
        if (coincides==ll_len(this2))
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if (this!=NULL&&from>=0&&to<=ll_len(this))
    {
        LinkedList* newList = ll_newLinkedList();
        if (newList!=NULL)
        {
            int i;
            void* auxElement = NULL;
            for (i=from;i<=to;i++)
            {

                auxElement = ll_get(this,i);
                ll_add(newList,auxElement);
            }
        }
        cloneArray = newList;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if (this!=NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    if (this!=NULL&&pFunc!=NULL)
    {
        if (order==1||order==0)
        {
            int i , j , lenght , result;
            lenght = ll_len(this);
            void* auxPtr;
            for (i=0;i<(lenght-1);i++)
            {
                for (j=(i+1);j<lenght;j++)
                {
                    result = pFunc(ll_get(this,i),ll_get(this,j));
                    if (result>0&&order==1)
                    {
                        auxPtr = ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,auxPtr);
                    }
                    else if (result<0&&order==0)
                    {
                        auxPtr = ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,auxPtr);
                    }
                }
            }
            if (i==(lenght-1))
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retVal = -1;
    if (this!=NULL&&pFunc!=NULL)
    {
        int i;
        for (i=0;i<ll_len(this);i++)
        {
            void* temp;
            temp = ll_get(this,i);
            pFunc(temp);
        }
        retVal = 0;
    }
    return retVal;
}
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newList = NULL;
    if (this!=NULL&&pFunc!=NULL)
    {
        newList = ll_newLinkedList();
        void* temp = NULL;
        int i;
        for (i=0;i<ll_len(this);i++)
        {
            temp = ll_get(this,i);
            if (pFunc(temp)==1)
            {
                ll_add(newList,temp);
            }
            temp = NULL;
        }
    }
    return newList;
}
