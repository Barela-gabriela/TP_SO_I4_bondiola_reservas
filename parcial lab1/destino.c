#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "destino.h"
#include "piloto.h"
#include "vuelo.h"
int askMenuOption()
{
    int option;
    printf("\t ******MENU DE OPERACIONES******\n\n1 .ALTA VUELO \n2 .BAJA VUELO\n3 .MODIFICAR ESTADO\n4 .MOSTRAR TODOS LOS VUELOS CON DECRIPCION DEL DESTINO Y EL NOMBRE DEL PILOTO\n5 .INFORMES\n6 .SALIR\n\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}
int askMenuOptionInformes()
{
    int option;
    printf("\t ******MENU DE INFORMES******\n\n1 .TODOS LOS VUELOS DEL PILOTO SELECCIONADO \n2 .TODOS LOS QUE VOLARON A UN DESTINO ESPECIFICO\n3 .RECADUDACION POR CADA PILOTO\n4 .DESTINO MAS ELEJIDO\n5 .SALIR\N\n\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}
int cargarDescDestino(int idDestino, eDestino destino[], int tamD, char descDestino[])
{
    int ok=0;
    int i;
    for(i=0; i<tamD; i++)
        {
            if(idDestino == destino[i].idDestino)
            {
                strcpy(descDestino, destino[i].descDestino);
                ok=1;
            break;
            }
        }
    return ok;
}
void mostrarDestino(eDestino x)
{
    printf("%4d    %10s      %.2f\n",x.idDestino,x.descDestino,x.precio);
}

void mostrarDestinos(eDestino destino[], int tamD)
{
    int i;
    printf("**** Listado de Destinos ****\n\n");

    printf("  id      Descripcion    Precio\n\n");
    for(i=0; i < tamD; i++)
    {
         mostrarDestino(destino[i]);
    }
    printf("\n\n");
}
int validarDestino(eDestino destino[], int tamD)
{
    int idDestino;
    int flag=0;
    int i;

    printf("ingrese id Destino ");
    scanf("%d", &idDestino);

    for(i=0; i<tamD; i++)
        {

        if(destino[i].idDestino == idDestino)
        {
            flag=1;
        }
    }
    while(flag==0)
        {
            int i;

        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idDestino);
        for(i=0; i<tamD; i++)
            {
                if(destino[i].idDestino == idDestino)
                {
                    flag=1;
                }
            }
        }
    return idDestino;
}
float cargarPrecioDestino(int idDestino, eDestino destino[], int tamD)
{
    int i;
    float precio;
    for( i=0; i<tamD; i++)
        {
            if(destino[i].idDestino==idDestino)
            {
                precio=destino[i].precio;
            }
        }
    return precio;
}
