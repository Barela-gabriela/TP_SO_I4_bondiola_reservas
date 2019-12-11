#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED
typedef struct
{
    int idPiloto;
    char nombrePiloto[60];
}ePiloto;
//funciones
int cargarDescPiloto(int idPiloto, ePiloto piloto[], int tamP, char descPiloto[]);
int validarPiloto(ePiloto piloto[], int tamP);
void mostrarPilotos(ePiloto piloto[], int tamP);
void mostrarPiloto(ePiloto x);

#endif // PILOTO_H_INCLUDED
