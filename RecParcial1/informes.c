#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"
#include "alquiler.h"
#include "informes.h"
#define OCUPADO 0
#define LIBRE 1
#define EQUIPOS 3
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3
#define ALQUILADO 0
#define FINALIZADO 1

//1. El nombre y apellido del asociado con más alquileres
void resultadoClientesConMasAlquileres(eCliente* arrayClientes, int limiteClientes, eAlquiler* arrayAlquileres,int limiteAlquileres, int contadorAlquileresMAX){

    int i,j;
    int contador=0;

    printf("\nCliente(s) con mas cantidad de alquileres: ");

    for(i=0;i<limiteAlquileres;i++){

        for(j=0;j<limiteClientes;j++){

            if(arrayAlquileres[i].idCliente == arrayClientes[j].id){

                contador++;
            }
        }
        if(contador == contadorAlquileresMAX){

            printf("%s %s",arrayClientes[i].nombre,arrayClientes[i].apellido);
        }

        contador = 0;
    }

    printf("- %d alquileres(s)",contadorAlquileresMAX);

}

int informes_clienteConMasAlquileres(eCliente* arrayClientes, int limiteClientes, eAlquiler* arrayAlquileres,int limiteAlquileres){

    int retorno = -1;
    int i,j;
    int contadorAlquileres=0;
    int contadorAlquileresMAX=-1;

    if(arrayClientes != NULL && limiteClientes > 0){

        retorno = 0;

        for(i=0;i<limiteClientes;i++){

            for(j=0;j<limiteAlquileres;j++){


                if(arrayClientes[i].id == arrayAlquileres[j].idCliente){

                    contadorAlquileres++;
                }
            }
            if(contadorAlquileres > contadorAlquileresMAX){

                contadorAlquileresMAX = contadorAlquileres;
            }
            contadorAlquileres = 0;
        }


        resultadoClientesConMasAlquileres(arrayClientes,limiteClientes,arrayAlquileres,limiteAlquileres,contadorAlquileresMAX);
    }


    return retorno;
}


//6.Todos los clientes con sus alquileres
int informes_clientesConSusAlquileres(eCliente* arrayClientes, int limiteClientes, eAlquiler* arrayAlquileres,int limiteAlquileres){

    int retorno = -1;
    int i,j;
    int flag;

    if(arrayClientes != NULL && limiteClientes > 0){

        retorno = 0;

        for(i=0;i<limiteClientes;i++){

            if(arrayClientes[i].isEmpty == OCUPADO){

               flag = 0;
                printf("\n\n\tCliente: %s %s",arrayClientes[i].nombre,arrayClientes[i].apellido);
                printf("\n\t------------------------------");
                for(j=0;j<limiteAlquileres;j++){

                    if(arrayAlquileres[j].isEmpty == OCUPADO){

                        if(arrayAlquileres[i].idCliente == arrayClientes[j].id){

                            printf("\n");

                            if(arrayAlquileres[i].equipo == AMOLADORA){
                               printf("\t\tAmoladora");
                            }
                            else if(arrayAlquileres[i].equipo == MEZCLADORA){
                                printf("\t\tMezcladora");
                            }
                            else{
                                printf("\t\tTaladro");
                            }

                            if(arrayAlquileres[i].estado == ALQUILADO){
                                printf("\t\tAlquilado");
                            }
                            else{
                                printf("\t\tFinalizado");
                            }

                            printf("\t\t%d hs",arrayAlquileres[i].tiempoEstimado);

                            if(arrayAlquileres[i].tiempoReal == -1){
                                printf("\t\tNo definido");
                            }
                            else{
                                 printf("\t\t%d hs",arrayAlquileres[i].tiempoReal);
                            }

                            flag = 1;
                        }
                    }
                }
                if(flag == 0){

                    printf("\n\tSin alquileres");
                }
            }

        }
        printf("\n");
    }

    return retorno;
}

/*int informes_tiempoPromedioRealDeLosEquipos(eCliente* arrayClientes, int limiteClientes, eAlquiler* arrayAlquileres,int limiteAlquileres){
    //sin terminar

    int retorno = -1;
    int i;
    float promedioAmoladora;
    int tiempoTotalAmoladora = 0;
    int cantAmoladora=0;
    float promedioMezcladora;
    int tiempoTotalMezcladora = 0;
    int cantMezcladora=0;
    float promedioTaladro;
    int tiempoTotalTaladro = 0;
    int cantTaladro =0;

    if(arrayAlquileres != NULL && limiteAlquileres > 0){

        retorno = 0;
        for(i=0;i<limiteAlquileres;i++){

            if(arrayAlquileres[i].equipo == AMOLADORA){

                tiempoTotalAmoladora = tiempoTotalAmoladora + arrayAlquileres[i].tiempoReal;
                cantAmoladora++;
            }
            if(arrayAlquileres[i].equipo == MEZCLADORA){

                tiempoTotalAmoladora = tiempoTotalAmoladora + arrayAlquileres[i].tiempoReal;
                cantMezcladora++;
            }

            if(arrayAlquileres[i].equipo == TALADRO){

                tiempoTotalAmoladora = tiempoTotalAmoladora + arrayAlquileres[i].tiempoReal;
                cantTaladro++;
            }
        }
    }



    return retorno;
}
*/
