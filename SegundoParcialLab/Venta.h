#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
struct eVenta
{
    int ID_Venta;
    char Fecha_Venta[23];
    char Codigo_Producto[100];
    int Cantidad;
    float Precio_Unitario;
    char CUIT_Cliente[13];
    struct eVenta* pNextVenta;
}typedef eVenta;

struct LinkedList
{
    eVenta* pFirstVenta;
    eVenta* pIteratorVenta;
    int size;
}typedef LinkedList;
LinkedList* ll_newLinkedList(void);

int ll_isEmpty(LinkedList* this);

int ll_len(LinkedList* this);

LinkedList* ll_newLinkedList(void);

int ll_add(LinkedList* this, void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente);

void* ll_get(LinkedList* this, int index);

int ll_set(LinkedList* this, int index,void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente);

int ll_remove(LinkedList* this,int index);

int ll_clear(LinkedList* this);

int ll_deleteLinkedList(LinkedList* this);

int ll_push(LinkedList* this, int index,void* pID_Venta,
void* pFecha_Venta,void* pCodigo_Producto,void* pCantidad,void* pPrecio_Unitario,void* pCUIT_Cliente);

void* ll_pop(LinkedList* this,int index);


LinkedList* ll_subList(LinkedList* this,int from,int to);



#endif // VENTA_H_INCLUDED
