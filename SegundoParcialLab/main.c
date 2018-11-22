#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "Parser.h"
#include "ShowMenu.h"
int main()
{
    LinkedList* listadoDeVentas=ll_newLinkedList();
    Show_Menu(listadoDeVentas);
    return 0;
}
