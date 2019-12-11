#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "piloto.h"

int cargarDescPiloto(int idPiloto, ePiloto piloto[], int tamP, char descPiloto[])
{
    int ok=0;
    int i;
    for(i=0; i<tamP; i++)
        {
            if(idPiloto == piloto[i].idPiloto)
            {
                strcpy(descPiloto, piloto[i].nombrePiloto);
                ok=1;
            break;
            }
        }
    return ok;
}
void mostrarPiloto(ePiloto x)
{
    printf("%4d     %10s \n",x.idPiloto,x.nombrePiloto);
}

void mostrarPilotos(ePiloto piloto[], int tamP)
{
    int i;
    printf("**** Listado de pilotos ****\n\n");
    printf("id Piloto   Descripcion\n\n");
    for(i=0; i < tamP; i++)
    {
         mostrarPiloto(piloto[i]);
    }
    printf("\n\n");
}

int validarPiloto(ePiloto piloto[], int tamP)
{
    int idPiloto;
    int flag=0;
    int i;
    printf("ingrese id del destino ");
    scanf("%d", &idPiloto);
    for(i=0; i<tamP; i++)
        {
            if(piloto[i].idPiloto == idPiloto)
            {
                flag=1;
            }
    }
    while(flag==0)
    {
        printf("id no registrado, ingrese nuevamente: ");
        scanf("%d", &idPiloto);
        for(i=0; i<tamP; i++)
        {
            if(piloto[i].idPiloto == idPiloto)
            {
                flag=1;
            }
        }
    }
    return idPiloto;
}
