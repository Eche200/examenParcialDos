#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"
#include "Parser.h"

void Show_Menu(LinkedList* this)
{
    printf("¿bienvenido al programa , que accion desea realizar?\n");



    parser_VentasFromText("data.csv",this);





}

