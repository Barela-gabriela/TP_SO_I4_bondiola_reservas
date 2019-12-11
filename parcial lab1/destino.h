#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
int askMenuOption();
int askMenuOptionInformes();
typedef struct
{
    int idDestino;
    char descDestino[60];
    float precio;
}eDestino;
int validarDestino(eDestino destino[], int tamD);
float cargarPrecioDestino(int idDestino, eDestino destino[], int tamD);
void mostrarDestinos(eDestino destino[], int tamD);
void mostrarDestino(eDestino x);
int cargarDescDestino(int idDestino, eDestino destino[], int tamD, char descDestino[]);

#endif // DESTINO_H_INCLUDED
