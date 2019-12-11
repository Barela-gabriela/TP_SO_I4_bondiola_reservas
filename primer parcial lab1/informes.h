#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int menuInformes();
void informes(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT);
void listAutosNegros (eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM);
void autosMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
void trabajosAuto(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eColor colores[], int tamC, eMarca marcas[], int tamM);
void autosSinTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM);
void deudaAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
void servicioMasPedido(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void recaudadoEnFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void autosEncerados(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eMarca marcas[], int tamM, eColor colores[], int tamC);
void trabajosAutosBlancos(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void facturacionPulidos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
void MarcaMasCompletos(eMarca marcas[], int tamM, eAuto autos[], int tamA, eTrabajo trabajos[], int tamT);


#endif // INFORMES_H_INCLUDED
