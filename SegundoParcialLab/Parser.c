#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"
#include "ShowMenu.h"


int parser_VentasFromText(char* fileName, LinkedList* this)
{
    const char delimitante[2] = ",";
    FILE* pFile;
    char auxFile[40000];
    char* bufferID_venta;
    char* bufferFecha_Venta;
    char* bufferCodigo_Producto;
    char* bufferCantidad;
    char* bufferPrecio_Unitario;
    char* bufferCUIT_Cliente;
    int retorno = -1;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL && fileName != NULL && this != NULL)
    {
        retorno=0;
        fgets(auxFile,40000,pFile);
        while(!feof(pFile))
        {
            fgets(auxFile,40000,pFile);
            bufferID_venta = strtok(auxFile,delimitante);
            bufferFecha_Venta = strtok(NULL, delimitante);
            bufferCodigo_Producto = strtok(NULL , delimitante);
            bufferCantidad = strtok(NULL,delimitante);
            bufferPrecio_Unitario = strtok(NULL, delimitante);
            bufferCUIT_Cliente = strtok(NULL , "\n");
           /* this = (eVenta *)malloc(sizeof(eVenta));
            this->ID_Venta = atof(bufferID_venta);*/
            //aca si no cambio me pisa todo
        }
    }
    return retorno;
}


/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* pEmpleado;
    int bufferId;
    int lastId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile!=NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            pEmpleado = employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                lastId = bufferId;
            }
        }
        for(i=0;i<=lastId;i++)
        {
            employee_getNextId();
        }
    }
    return retorno;
}



int parser_saveAsText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile != NULL)
    {
        retorno = 0;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fprintf(pFile,"\n%d,%s,%d,%d",  bufferId,bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            }
        }
    }
    return retorno;
}


int parser_saveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile != NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fwrite(pEmpleado,sizeof(Employee),1,pFile);
            }
        }
    }
    return retorno;
}*/
