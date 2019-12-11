#include <string.h>
#include <conio.h>
#include "auto.h"
#include "colores.h"
#include "marcas.h"
#include "servicios.h"
#include "trabajos.h"
#include "informes.h"
#define TAMA 15
#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMT 15
void informes(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT){

    char salir ='n';


    do{

        switch(menuInformes()){

    case 1:
        //AUTOS DE COLOR NEGRO
        listAutosNegros(autos, tamA, colores, tamC, marcas, tamM);
        break;
    case 2:
        //AUTOS DE MARCA SELECCIONADA
        autosMarca(autos, tamA, marcas, tamM, colores, tamC);
        break;
    case 3:
        //TRABAJOS EFECTUADOS A AUTO
        trabajosAuto(trabajos, tamT, autos, tamA, servicios, tamS, colores, tamC, marcas, tamM);
        break;
    case 4:
        //AUTOS QUE NO TUVIERON TRABAJOS
        autosSinTrabajos(trabajos, tamT, autos, tamA, colores, tamC, marcas, tamM);
        break;
    case 5:
        //IMPORTE A PAGAR POR AUTO SELECCIONADO
        deudaAuto(autos, tamA, trabajos, tamT, servicios, tamS, marcas, tamM, colores, tamC);
        break;
    case 6:
        //SERVICIO MAS PEDIDO
        servicioMasPedido(trabajos, tamT, servicios, tamS);
        break;
    case 7:
        //RECAUDACION EN FECHA PARTICULAR
        recaudadoEnFecha(trabajos, tamT, servicios, tamS);
        break;
    case 8:
        //AUTOS QUE REALIZARON ENCERADO C/ FECHA
        autosEncerados(autos, tamA, trabajos, tamT, marcas, tamM, colores, tamC);
        break;
    case 9:
        //TRABAJOS A AUTOS BLANCOS
        trabajosAutosBlancos(autos, tamA, trabajos, tamT, servicios, tamS);
        break;
    case 10:
        //FACTURACION TOTAL POR PULIDOS
        facturacionPulidos(trabajos, tamT, servicios, tamS);
        break;
    case 11:
        //INFORMAR LA MARCA DE AUTOS C/ MAS LAVADOS COMPLETOS
        MarcaMasCompletos(marcas, tamM, autos, tamA, trabajos, tamT);
        break;
    case 12:
        //AUTOS QUE RECIBIERON TRABAJOS EN FECHA DETERMINADA

        break;
    case 13:
        salir='y';
        break;
    default:
        printf("Opcion invalida");

        }

    }while (salir=='n');

}

void listAutosNegros (eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM){

    int flag=0;

    system("cls");
    printf("*** AUTOS COLOR NEGRO ***\n\n");

    for(int i=0; i<tamA; i++){

        if(autos[i].idColor == 5000 && autos[i].isEmpty ==0){

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag=1;
        }

    }
    if(flag==0){

        printf("--No hay autos color negro cargados en el sistema--\n\n");

    }

    printf("\n\n");
    system("pause");
}

void autosMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int idMarca;
    int flag=0;
    char descMarca[20];


    system("cls");
    printf("*** AUTOS EN MARCA SELECCIONADA ***\n\n");

    mostrarMarcas(marcas, tamM);
    idMarca = validarMarca(marcas, tamM);
    cargarDescMarca(idMarca, marcas, tamM, descMarca);

    system("cls");
    printf("Autos marca %s\n\n",descMarca);

    for(int i=0; i<tamA; i++){

        if(autos[i].idMarca==idMarca && autos[i].isEmpty==0){

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag=1;
        }
    }

    if(flag==0){
        printf("---No hay autos de esa marca en el sistema---");
    }
    printf("\n\n");
    system("pause");
}

void trabajosAuto(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eColor colores[], int tamC, eMarca marcas[], int tamM){

    char patente[10];
    int flag=0;

    system("cls");
    printf("*** TRABAJOS REALIZADOS A AUTO SELECCIONADO ***\n\n");
    mostrarAutos(autos, tamA, colores, tamC, marcas, tamM);
    validarPatente(patente, autos, tamA);

    system("cls");
    printf("Trabajos realizados a auto de patente %s:\n\n", patente);

    for(int i=0; i<tamT; i++){

        if(strcmp(patente, trabajos[i].patente)==0 && trabajos[i].isEmpty==0){

            mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
            flag=1;
        }

    }
    if(flag==0){
        printf("---No hay trabajos realizados---");
    }

    printf("\n\n");
    system("pause");
}

void autosSinTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eColor colores[], int tamC, eMarca marcas[], int tamM){

    int flag=0;

    system("cls");
    printf("*** AUTOS SIN TRABAJOS REALIZADOS ***\n\n");

    for(int i=0; i<tamA; i++){
        flag=0;
        for(int j=0; j<tamT; j++){

            if(strcmp(trabajos[j].patente, autos[i].patente)==0 && trabajos[j].isEmpty == 0 && autos[i].isEmpty==0){
             flag=1;
            }

        }

        if(flag==0 && autos[i].isEmpty==0){

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);

        }

    }

    printf("\n\n");
    system("pause");
}

void deudaAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC){

    char patente[10];
    float deuda=0;

    system("cls");
    printf("*** Deuda de Vehiculo ***\n\n");

    mostrarAutos(autos, tamA, colores, tamC, marcas, tamM);
    printf("\n");
    validarPatente(patente, autos, tamA);

    for(int i=0; i<tamT; i++ ){

        if(strcmp(trabajos[i].patente, patente)==0 && trabajos[i].isEmpty==0){

            for(int j=0; j<tamS; j++){

                if(trabajos[i].idServicio==servicios[j].idServicio){

                    deuda+=servicios[j].precio;

                }
            }
        }
    }

    system("cls");
    printf("\nPatente: %s\n", patente);
    printf("Deuda: $%.2f\n\n\n", deuda);

    system("pause");
}

void servicioMasPedido(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    int cantidadS[tamS];
    int flag=0;
    int mayor;

    system("cls");
    printf("*** SERVICIO MAS PEDIDO ***\n\n");
    for(int i=0; i<tamS; i++){
        cantidadS[i]=0;
    }

    for(int i=0; i<tamS; i++){

        for(int j=0; j<tamT; j++){

            if(servicios[i].idServicio == trabajos[j].idServicio && trabajos[j].isEmpty==0){

                cantidadS[i]++;

            }
        }
    }


    for(int i=0; i<tamS; i++){


        if(cantidadS[i]>mayor || flag==0){
            mayor=cantidadS[i];
            flag=1;
        }
    }

    for(int i=0; i<tamS; i++){

        if(cantidadS[i] == mayor){

            printf("Servicio: %s\n", servicios[i].descriprcion);
            printf("Cantidad: %d\n\n", cantidadS[i]);
        }
    }

        system("pause");
}

void recaudadoEnFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    eFecha aux;
    int flag=0;
    float acumulador=0;

    system("cls");
    printf("*** RECAUDADO EN FECHA DETERMINADA ***\n\n");
    aux.dia = validarDia();
    aux.mes = validarMes();
    aux.anio = validarAnio();

    system("cls");
    printf(" \nRecaudado en %02d/%02d/%4d: ", aux.dia, aux.mes, aux.anio);

    for(int i=0; i<tamT; i++){

        if(trabajos[i].fecha.dia == aux.dia && trabajos[i].fecha.mes == aux.mes && trabajos[i].fecha.anio == aux.anio && trabajos[i].isEmpty==0){

            acumulador+=cargarPrecioServicio(trabajos[i].idServicio, servicios, tamS);
            flag=1;

        }
    }
    printf("$%.2f\n\n", acumulador);
    if(flag==0){

        printf("--- No hay trabajos en la fecha indicada ---\n\n");

    }

    system("pause");
}

void autosEncerados(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eMarca marcas[], int tamM, eColor colores[], int tamC){


    system("cls");
    printf("*** AUTOS QUE RECIBIERON ENCERADO ***\n\n");

    for(int i=0; i<tamA; i++){

        for(int j=0; j<tamT; j++){

            if(strcmp(autos[i].patente, trabajos[j].patente)==0 && autos[i].isEmpty==0 && trabajos[j].isEmpty==0 && trabajos[j].idServicio == 20002){

                printf("Auto: \n");
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                printf("Fecha de encerado: %02d/%02d/%4d\n\n", trabajos[j].fecha.dia, trabajos[j].fecha.mes, trabajos[j].fecha.anio);
            }

        }

    }
        system("pause");
}

void trabajosAutosBlancos(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    system("cls");
    printf("*** TRABAJOS REALIZADOS A AUTOS BLANCOS ***\n\n");

    for(int i=0; i<tamA; i++){

        if(autos[i].idColor == 5001 && autos[i].isEmpty==0){

            for(int j=0; j<tamT; j++){

                if(strcmp(autos[i].patente, trabajos[j].patente)==0 && trabajos[j].isEmpty==0){

                    mostrarTrabajo(trabajos[j], autos, tamA, servicios, tamS);

                }
            }
        }
    }
    system("pause");
}

void facturacionPulidos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

    float acumulador=0;

    system("cls");
    printf("*** FACTURACION TOTAL PULIDOS***\n\n");
    for(int i=0; i<tamT; i++){

        if(trabajos[i].idServicio == 20001 && trabajos[i].isEmpty==0){

            acumulador+=cargarPrecioServicio(trabajos[i].idServicio, servicios, tamS);

        }
    }

    printf("Facturado: %.2f\n\n", acumulador);
    system("pause");
}

void MarcaMasCompletos(eMarca marcas[], int tamM, eAuto autos[], int tamA, eTrabajo trabajos[], int tamT){

    int contadorC[tamM];
    int mayor;
    int flag=0;

    for(int i=0; i<tamM; i++){
        contadorC[i]=0;
    }

    system("cls");
    printf("*** Marca con mas lavados completos ***\n\n");

    for(int i=0; i<tamM; i++){

        for(int j=0; j<tamA; j++){

            if(autos[j].idMarca == marcas[i].idMarca && autos[j].isEmpty==0){

                for(int k=0; k<tamT; k++){

                    if(trabajos[k].idServicio == 20003 && strcmp(autos[j].patente, trabajos[k].patente)==0 && trabajos[k].isEmpty==0){

                        contadorC[i]++;

                    }
                }
            }
        }
    }

    for(int i=0; i<tamM; i++){

        if(contadorC[i] > mayor || flag==0){

            mayor=contadorC[i];
            flag=1;

        }
    }

    for(int i=0; i<tamM; i++){

        if(contadorC[i]==mayor){

            printf("Marca con mas lavados completos: %s, con %d lavados completos\n\n\n", marcas[i].descripcion, contadorC[i]);

        }
    }
    system("pause");

}
