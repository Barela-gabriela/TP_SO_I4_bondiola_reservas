#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "vuelo.h"
#include "destino.h"
#include "piloto.h"
int validarDia()
{
    int dia;
    printf("Ingrese dia: ");
    scanf("%d", &dia);
    while(dia<0 || dia>31)
        {
        printf("Error, dia no valido, Ingrese nuevamente: ");
        scanf("%d", &dia);
        }
    return dia;
}

int validarMes()
{
    int mes;
    printf("Ingrese mes: ");
    scanf("%d", &mes);
    while(mes<0 || mes>12)
        {
        printf("Error, mes no valido, Ingrese nuevamente: ");
        scanf("%d", &mes);
        }
    return mes;
}

int validarAnio()
{
    int anio;
    printf("Ingrese anio (entre 2015 - 2021): ");
    scanf("%d", &anio);
    while(anio<2015 || anio>2021)
        {
        printf("Error, anio no valido, Ingrese nuevamente: ");
        scanf("%d", &anio);
        }
    return anio;
}
void inicializarVuelo(eVuelo vuelo[], int tamV)
{
    int i;
    for( i=0; i < tamV; i++)
    {
        vuelo[i].isEmpty = 1;
    }
}

int altaVuelo(eVuelo vuelo[], int tamV, ePiloto piloto[], int tamP, eDestino destino[], int tamD)
{

    int todoOk = 0;
    int indice;
    int esta;
    int idVuelo;
    int idPiloto;
    int idDestino;
    int partida;
    int llegada;
    system("cls");
    printf("**** Alta Vuelo ****\n\n");

    indice = buscarLibreVuelo(vuelo, tamV);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas vuelos\n");

    }
    else
    {
        printf("\nIngrese id del vuelo (2000 - 3000): ");
        scanf("%d", &idVuelo );

        while(idVuelo<2000 || idVuelo>3000)
        {
            printf("\nError, id invalida. Ingrese nuevamente: ");
            scanf("%d", &idVuelo );
        }

        esta = buscarAuto(idVuelo, vuelo, tamV);

        if( esta != -1)
        {
            printf("Vuelo ya registrado\n");
            mostrarVuelo(vuelo[esta], piloto, tamP, destino, tamD);
            system("pause");
        }
        else
        {
            mostrarPilotos(piloto, tamP);
            idPiloto=validarPiloto(piloto, tamP);

            mostrarDestinos(destino, tamD);
            idDestino = validarDestino(destino, tamD);

            printf("Ingrese fechad de  partida:");
            scanf("%d", &partida);
            printf("Ingrese fechad de  llegada:");
            scanf("%d", &llegada);

            vuelo[indice] = newVuelo(idVuelo, idPiloto, idDestino, partida, llegada);
            todoOk = 1;
        }
    }
    return todoOk;
}

int modificarVuelo(eVuelo vuelo[], int tamV, ePiloto piloto[], int tamP, eDestino destino[], int tamD)
{
    int todoOk = 0;
    int indice;
    int idVuelo;
    int opcion;
    int idDestino;
    int partida;
    int llegada;


    system("cls");
    printf("**** Modificar vuelo ****\n\n");

    printf("Ingrese id vuelo: ");
    scanf("%d", &idVuelo);

    indice = buscarVuelo(idVuelo, vuelo, tamV);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese vuelo\n");
        system("pause");
    }
    else
    {
        mostrarVuelo(vuelo[indice], piloto, tamP, destino, tamD);

        printf("Modificar\n\n");
        printf("1 -destino\n");
        printf("2- fecha de partida\n");
        printf("3- fecha de llegada\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            mostrarDestinos(destino, tamD);
            printf("Ingrese idDestino");
            idDestino=validarDestino(destino, tamD);

            vuelo[indice].idDestino=idDestino;
            printf("Se actualizo el Destino");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Ingrese fecha");
            scanf("%d", &partida);
            vuelo[indice].partida=partida;
            printf("Se actualizo la fecha");
            todoOk = 1;

        }
        else if( opcion == 23)
        {
            printf("Ingrese fecha");
            scanf("%d", &llegada);
            vuelo[indice].llegada=llegada;
            printf("Se actualizo la fecha");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}

int bajaVeulo(eVuelo vuelo[], int tamV)
{

    int todoOk = 0;
    int indice;
    int idVuelo;
    char confirma;

    system("cls");
    printf("**** Baja Auto ****\n\n");

    printf("Ingrese id vuelo: ");
    scanf("%d", &idVuelo);

    indice = buscarVuelo(idVuelo, vuelo, tamV);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese vuelo\n");
        system("pause");
    }
    else
    {
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            vuelo[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el vuelo\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;
}

int buscarLibreVuelo(eVuelo vuelo[], int tamV)
{
    int i;
    int indice = -1;
    for( i=0; i < tamV; i++)
    {
        if( vuelo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarVuelo(int idVuelo, eVuelo vuelo[], int tamV)
{
    int i;
    int indice = -1;
    for(i=0; i < tamV; i++)
    {
        if( vuelo[i].isEmpty == 0 && vuelo[i].idVuelo == idVuelo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarVuelo(eVuelo x, ePiloto piloto[], int tamP, eDestino destino[], int tamD)
{
    char descDestino[60];
    char nombrePioloto[60];
    cargarDescDestino(x.idDestino, destino, tamD, descDestino);
    cargarDescPiloto(x.idPiloto, piloto, tamP, descPiloto);
    printf("%4d    %10s     %10s    %4d    %4d\n",x.idVuelo,nombrePiloto,descDestino,x.partida,x.llegada);
}

void mostrarVuelos(eVuelo vuelo[], int tamV,  eDestino destino[], int tamD, ePiloto piloto[], int tamP)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Vuelos ****\n\n");

    printf("id vuelo       piloto           destino    llegada       partida\n\n");
    for(int i=0; i < tamV; i++)
    {
        if( vuelo[i].isEmpty == 0)
        {
            mostrarVuelo(vuelo[i], piloto, tamP, destino, tamD);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay autos que mostrar---");
    }

    printf("\n\n");
}

void ordenarVuelo(eVuelo vec[], int tamV, eDestino destino[], int tamD, ePiloto piloto[], int tamP)
{
    eVuelo auxVuelo;

    for(int i= 0; i < tamV-1 ; i++)
    {
        for(int j= i+1; j <tamV; j++)
        {
            if(vec[i].idPiloto > vec[j].idPiloto  && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {
                auxVuelo = vec[i];
                vec[i] = vec[j];
                vec[j] = auxVuelo;
            }
            else if(vec[i].idPiloto == vec[j].idPiloto  && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {
                auxVuelo = vec[i];
                vec[i] = vec[j];
                vec[j] = auxVuelo;
            }

        }
    }

}

eVuelo newVuelo(int idVuelo, int idPiloto, int idDestino, int partida, int llegada)
{
    eVuelo nuevoVuelo;
    nuevoVuelo.idVuelo=idVuelo;
    nuevoVuelo.idPiloto=idPiloto;
    nuevoVuelo.idDestino=idDestino;
    nuevoVuelo.partida=partida;
    nuevoVuelo.llegada=llegada;
    nuevoVuelo.isEmpty=0;

    return nuevoAuto;
}
