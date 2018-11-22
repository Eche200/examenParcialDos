#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "ShowMenu.h"

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstVenta = NULL;
    }
    return this;
}

static void ll_startIterator(LinkedList* this)
{
    if(this != NULL)
    {
        this->pIteratorVenta = this->pFirstVenta;
    }
}


static void* ll_getNext(LinkedList* this)
{
    void* returnAux = NULL;
    if(this->pIteratorVenta != NULL)
    {
        returnAux = this->pIteratorVenta;
        this->pIteratorVenta = this->pIteratorVenta->pNextVenta;
    }
    return returnAux;
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

static eVenta* getVenta(LinkedList* this, int ventaIndex)
{
    eVenta* pVenta = NULL;
    int i;
    if(this != NULL && !ll_isEmpty(this) && ventaIndex >= 0 && ventaIndex < ll_len(this))
    {
        pVenta = this->pFirstVenta;
        for(i=0;i<ventaIndex;i++)
        {
            pVenta = pVenta->pNextVenta;
        }
    }
    return pVenta;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 1;
        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


static int addVenta(LinkedList* this, int ventaIndex,void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente)
{
    int returnAux = -1;
    eVenta* pNewVenta = malloc(sizeof(eVenta));
    eVenta* auxVentaAnterior = NULL;
    eVenta* auxVentaSiguiente = NULL;
    if(this != NULL && ventaIndex >= 0 && ventaIndex <= ll_len(this))
    {
        if(ventaIndex == 0)
        {
            pNewVenta->pNextVenta = this->pFirstVenta;
            this->pFirstVenta = pNewVenta;
        }
        else if(ventaIndex > 0 && ventaIndex <= ll_len(this))
        {
            auxVentaAnterior = getVenta(this, ventaIndex-1);
            auxVentaSiguiente = auxVentaAnterior->pNextVenta;
            auxVentaAnterior->pNextVenta = pNewVenta;
            pNewVenta->pNextVenta = auxVentaSiguiente;
        }
        this->size += 1;

        pNewVenta->ID_Venta = atoi(pID_Venta);
        strncpy(pNewVenta->Fecha_Venta,pFecha_Venta,23);
        strncpy(pNewVenta->Codigo_Producto,pCodigo_Producto,100);
        pNewVenta->Cantidad = atoi(pCantidad);
        pNewVenta->Precio_Unitario = atof(pPrecio_Unitario);
        strncpy(pNewVenta->CUIT_Cliente,pCUIT_Cliente,13);


        returnAux = 0;
    }
    return returnAux;
}


static int removeVenta(LinkedList* this, int ventaIndex)
{
    int returnAux = -1;
    eVenta* pDeleteVenta = NULL;
    eVenta* auxVentAnterior = NULL;
    eVenta* auxVentaSiguiente = NULL;
    if(this != NULL && !ll_isEmpty(this) && ventaIndex >= 0 && ventaIndex < ll_len(this))
    {
        pDeleteVenta = getVenta(this, ventaIndex);
        if(ventaIndex == 0)
        {
            this->pFirstVenta = pDeleteVenta->pNextVenta;
            free(pDeleteVenta);
        }
        else if(ventaIndex > 0 && ventaIndex <= ll_len(this))
        {
            auxVentAnterior = getVenta(this, ventaIndex-1);
            auxVentaSiguiente = auxVentAnterior->pNextVenta->pNextVenta;
            auxVentAnterior->pNextVenta = auxVentaSiguiente;
            free(pDeleteVenta);
        }
        this->size -= 1;
        returnAux = 0;
    }
    return returnAux;
}



int ll_add(LinkedList* this, void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente)
{
    return addVenta(this, ll_len(this), pID_Venta,pFecha_Venta,pCodigo_Producto,pCantidad,pPrecio_Unitario,pCUIT_Cliente);
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    eVenta* auxVenta = NULL;
    if(this != NULL && !ll_isEmpty(this) && index >= 0 && index < ll_len(this))
    {
        auxVenta = getVenta(this, index);
        returnAux = auxVenta;
    }
    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente)
{
    int returnAux = -1;
    eVenta* auxVenta;
    if(this != NULL && !ll_isEmpty(this) && index >= 0 && index < ll_len(this))
    {
        auxVenta = getVenta(this, index);
        auxVenta->ID_Venta = atoi(pID_Venta);
        strncpy(auxVenta->Fecha_Venta,pFecha_Venta,23);
        strncpy(auxVenta->Codigo_Producto,pCodigo_Producto,100);
        auxVenta->Cantidad = atoi(pCantidad);
        auxVenta->Precio_Unitario = atof(pPrecio_Unitario);
        strncpy(auxVenta->CUIT_Cliente,pCUIT_Cliente,13);

        returnAux = 0;
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    return removeVenta(this,index);
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL && !ll_isEmpty(this))
    {
        for(i=ll_len(this)-1; i>=0; i--)
        {
            removeVenta(this,i);
        }
        returnAux = 0;
    }
    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index,void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente)
{
    return addVenta(this, index, pID_Venta,pFecha_Venta,pCodigo_Producto,pCantidad,pPrecio_Unitario,pCUIT_Cliente);
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && !ll_isEmpty(this) && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this,index);
        removeVenta(this,index);
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* auxElement= NULL;

    void* auxID_Venta = NULL;
    void* auxFecha_Venta = NULL;
    void* auxCodigo_producto = NULL;
    void* auxCantidad = NULL;
    void* auxPrecio_Unitario = NULL;
    void* auxCUIT_Cliente = NULL;
    int i;
    if(this != NULL && from >= 0 && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        ll_startIterator(this);
        for(i=from; i<to; i++)
        {
            auxElement = ll_getNext(this);
            auxID_Venta= atoi(auxElement->ID_Venta);

            ll_add(cloneArray,auxElement->auxID_Venta,auxElement->auxFecha_Venta,auxElement->auxCodigo_producto,
            auxElement->auxCantidad , auxElement->auxPrecio_Unitario,auxElement->auxCUIT_Cliente);
        }
    }
    return cloneArray;
}
