#include <stdio.h>
#include <stdlib.h>
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


int menu();
int verifySystem(eAuto autos[], int tamA);

int main()
{
    eMarca marcas[TAMM] = {{1000, "Renault"},{1001, "Fiat"},{1002, "Ford"},{1003, "Chevrolet"},{1004, "Peugeot"}};
    eColor colores[TAMC] = {{5000, "Negro"},{5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};
    eServicio servicios[TAMS] = {{20000, "Lavado", 250.00},{20001, "Pulido", 300.00},{20002, "Encerado", 400.00},{20003, "Completo", 600.00}};
    eAuto autos[TAMA] = {{1050, "aaa111", 1002, 5002, 2012, 0},{1051, "bbb222", 1003, 5001, 2002, 0},{1052, "ccc333", 1001, 5000, 2009, 0},{1053, "ddd444", 1000, 5004, 2017, 0},{1054, "eee555", 1004, 5001, 2006, 0},{1055, "fff666", 1002, 5000, 2014, 0},{1056, "ggg777", 1004, 5002, 2018, 0},{1057, "hhh888", 1000, 5001, 2007, 0},{1058, "iii999", 1001, 5000, 2006, 0},{1059, "jjj010", 1003, 5003, 2010, 0},{1050, "FNM 789", 1002, 5003, 2012, 1},{1050, "FNM 789", 1002, 5003, 2012, 1},{1050, "FNM 789", 1002, 5003, 2012, 1},{1050, "FNM 789", 1002, 5003, 2012, 1},{1050, "FNM 789", 1002, 5003, 2012, 1}};
    eTrabajo trabajos [TAMT] = {{7000, "aaa111", 20003, {10,9,2019}, 0},{7001, "aaa111", 20003, {15,9,2019}, 0},{7002, "aaa111", 20002, {22,9,2019}, 0},{7003, "bbb222", 20000, {22,9,2019}, 0},{7004, "bbb222", 20001, {30,9,2019}, 0},{7005, "aaa111", 20003, {5,10,2019}, 0},{7006, "ccc333", 20001, {5,10,2019}, 0},{7007, "ccc333", 20003, {12,10,2019}, 0},{7008, "ddd444", 20002, {19,10,2019}, 0},{7009, "eee555", 20000, {20,10,2019}, 0},{7000, "fff666", 20001, {22,9,2019}, 0},{7000, "ggg777", 20001, {22,9,2019}, 0},{7000, "aaa111", 20003, {10,10,2019}, 1},{7000, "aaa111", 20003, {10,10,2019}, 1},{7000, "aaa111", 20003, {10,10,2019}, 1}};

    int idTrabajo=7000 + 9;
    char salir ='n';
    //inicializarAutos(autos, TAMA);
    //inicializarTrabajos(trabajos, TAMT);
    do{
    switch(menu()){
        case 1:
                altaAuto(autos, TAMA, marcas, TAMM, colores, TAMC);
            break;
        case 2:
            if(verifySystem(autos, TAMA))
                {
                    modificarAuto(autos, TAMA, marcas, TAMM, colores, TAMC);
                }
            else
                {
                    printf("Error, aun no hay datos en el sistema\n");
                    system("pause");
                }
            break;
        case 3:
            if(verifySystem(autos, TAMA))
                {
                    bajaAuto(autos, TAMA);
                }
            else
                {
                    printf("Error, aun no hay datos en el sistema\n");
                }
            system("pause");
            break;
        case 4:
            ordenarAutos(autos, TAMA, colores, TAMC, marcas, TAMM);
            system("cls");
            mostrarAutos(autos, TAMA, colores, TAMC, marcas, TAMM);
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarMarcas(marcas, TAMM);
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarColores(colores, TAMC);
            system("pause");
            break;
        case 7:
            system("cls");
            printf("***** Servicios *****");
            mostrarServicios(servicios, TAMS);
            system("pause");
            break;
        case 8:
            if(altaTrabajo(idTrabajo, trabajos, TAMT, autos, TAMA, servicios, TAMS))
                {
                    idTrabajo=idTrabajo+1;
                }
            system("pause");
            break;
        case 9:
            mostrarTrabajos(trabajos, TAMT, servicios, TAMS, autos, TAMS);
            system("pause");
            break;
        case 10:
            informes(autos, TAMA, marcas, TAMM, colores, TAMC, servicios, TAMS, trabajos, TAMT);
            break;
            case 11:
                printf("confirma salida? ingrese s/n: ");
                fflush(stdin);
                scanf("%c", &salir);
                break;
            default:
                printf("opcion invalida ");
                break;
        }
    }while(salir=='n');
    return 0;
}
int menu()
{
    int opcion;
    system("cls");
    printf("MENU\n\n");
    printf("1- Alta auto\n");
    printf("2- Modificar auto\n");
    printf("3- Baja auto\n");
    printf("4- Listar autos\n");
    printf("5- Listar marcas\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar trabajos\n");
    printf("10- Informes\n");
    printf("11- SALIR\n\n");
    printf("ELIJA UNA OPCION: ");
    scanf("%d", &opcion);
    return opcion;
}
int verifySystem(eAuto autos[], int tamA){
    int rta=0;
    system("cls");
    for(int i=0; i<tamA; i++)
        {
        if(autos[i].isEmpty==0)
        {
            rta=1;
        }
    }
    return rta;
}
int menuInformes()
{
    int opcion;
    system("cls");
    printf("*** INFORMES ***\n\n");
    printf("1- Mostrar autos de color negro\n");
    printf("2- Mostrar autos de una marca seleccionada\n");
    printf("3- Mostrar trabajos efectuados a un auto\n");
    printf("4- Lstar los autos que no tuvieron trabajo\n");
    printf("5- Importe a pagar por auto elejido\n");
    printf("6- Mostrar el servicio del pedido\n");
    printf("7- Mostrar la recaudacion en la fecha\n");
    printf("8- Mostrar autos que realizaron el encerado\n");
    printf("9- Mostrar trabajos realizados a autos blancos\n");
    printf("10- Facturacion total por los pulidos\n");
    printf("11- Informar la marca de autos que mas realizaron los lavados completos\n");
    printf("12- Listar los trabajos que realizaron trabajos en una fecha determinada\n");
    printf("13- SALIR\n\n");
    printf("ELIJA UNA OPCION: ");
    scanf("%d", &opcion);
    return opcion;
}
