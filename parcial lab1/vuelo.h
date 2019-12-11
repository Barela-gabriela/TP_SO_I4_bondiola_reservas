#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include"piloto.h"
#include"destino.h"
typedef struct
{
    int idVuelo;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;
    int isEmpty;
    char estadoVuelo[60];
}eVuelo;
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
int validarAnio();
int validarMes();
int validarDia();
//marca-piloto
//color destino

void inicializarVuelo(eVuelo vuelo[], int tamV);
int buscarLibreVuelo(eVuelo vuelo[], int tamV);
void mostrarVuelo(eVuelo x, ePiloto piloto[], int tamP, eDestino destino[], int tamD);
void mostrarVuelos(eVuelo vuelo[], int tamV,  eDestino destino[], int tamD, ePiloto piloto[], int tamP);
int buscarVuelo(int idVuelo, eVuelo vuelo[], int tamV);
void ordenarVuelo(eVuelo vec[], int tamV, eDestino destino[], int tamD, ePiloto piloto[], int tamP );
eVuelo newVuelo(int idVuelo, int idPiloto, int idDestino, int partida,int llegada);//ojo aca con el orden porque saque patente que estaba al lado de vuelo
int altaVuelo(eVuelo vuelo[], int tamV, ePiloto piloto[], int tamP, eDestino destino[], int tamD);
int bajaVuelo(eVuelo vuelo[], int tamV);
int modificarVuelo(eVuelo vuelo[], int tamV, ePiloto piloto[], int tamP, eDestino destino[], int tamD);
#endif // VUELO_H_INCLUDED
