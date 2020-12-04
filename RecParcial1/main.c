#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "alquiler.h"
#include "informes.h"
#define CLIENTES 20
#define ALQUILERES 5
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3
#define ALQUILADO 0
#define FINALIZADO 1
//cliente cliente - alquiler almuerzo - operador comida

//estructura operador - harcodear operadores. relacionar alquiler con operador (id)
int main()
{

    int menu;
    int indice;
    int auxiliarId;
    int flag = 0;
    int flagAlta;

    /*eTipo arrayTipos[TIPOS];
    tipo_inicializarArrayTipos(arrayTipos,TIPOS);
    tipo_altaForzada(arrayTipos,TIPOS,"Ave");
    tipo_altaForzada(arrayTipos,TIPOS,"Perro");
    tipo_altaForzada(arrayTipos,TIPOS,"Gato");
    tipo_altaForzada(arrayTipos,TIPOS,"Roedor");
    tipo_altaForzada(arrayTipos,TIPOS,"Pez");

    eColor arrayColores[COLORES];
    color_inicializarArrayColores(arrayColores,COLORES);
    color_altaForzada(arrayColores,COLORES,"Negro");
    color_altaForzada(arrayColores,COLORES,"Blanco");
    color_altaForzada(arrayColores,COLORES,"Gris");
    color_altaForzada(arrayColores,COLORES,"Rojo");
    color_altaForzada(arrayColores,COLORES,"Azul");

    eServicio arrayServicios[SERVICIOS];
    servicio_inicializarArrayServicios(arrayServicios,SERVICIOS);
    servicio_altaForzada(arrayServicios,SERVICIOS,"Corte",250);
    servicio_altaForzada(arrayServicios,SERVICIOS,"Desparasitado",300);
    servicio_altaForzada(arrayServicios,SERVICIOS,"Castrado",400);
*/

    //--------------------
    /*tipo_imprimirTipos(arrayTipos,TIPOS);
    printf("\n\n");
    color_imprimirColores(arrayColores,COLORES);
    printf("\n\n");
    servicio_imprimirServicios(arrayServicios,SERVICIOS);
    printf("\n\n");
    mascota_imprimirMascotas(arrayMascotas,MASCOTAS,arrayTipos,TIPOS,arrayColores,COLORES,arrayClientes,CLIENTES);
    printf("\n\n");
    trabajo_imprimirTrabajos(arrayTrabajos,TRABAJOS,arrayMascotas,MASCOTAS,arrayServicios,SERVICIOS);
    printf("\n\n");*/
    //--------------------

    eCliente arrayClientes[CLIENTES];
    cliente_inicializarArrayClientes(arrayClientes,CLIENTES);
    cliente_altaForzada(arrayClientes,CLIENTES,"Alberto","Gimenez",11112222);
    cliente_altaForzada(arrayClientes,CLIENTES,"Pepe","A",22222222);
    cliente_altaForzada(arrayClientes,CLIENTES,"Jorgelina","B",66665555);

    cliente_imprimirClientes(arrayClientes,CLIENTES);

    eAlquiler arrayAlquileres[ALQUILERES];
    alquiler_inicializarArrayAlquileres(arrayAlquileres,ALQUILERES);
    alquiler_altaForzada(arrayAlquileres,ALQUILERES,0,AMOLADORA,ALQUILADO,24,-1);

    alquiler_imprimirAlquileres(arrayAlquileres,ALQUILERES);
/*
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Pepe",5000,1000,2,0);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Fatiga",5002,1002,11,1);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Pedro",5004,1000,12,2);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Roco",5001,1001,2,0);

    eTrabajo arrayTrabajos[TRABAJOS];
    trabajo_inicializarArrayTrabajos(arrayTrabajos,TRABAJOS);
    trabajo_altaForzada(arrayTrabajos,TRABAJOS,0,20000,1,1,2020);
    trabajo_altaForzada(arrayTrabajos,TRABAJOS,1,20002,3,2,2020);
    trabajo_altaForzada(arrayTrabajos,TRABAJOS,1,20000,3,2,2020);

*/
    printf("\n\n\n");
    printf("\t***** Alquiler de Maquinaria *****");
    printf("\n");
    do{

        getValidInt("\n\n1.Alta Cliente\n2.Modificar Datos del Cliente\n3.Baja Cliente\n4.Nuevo Alquiler\n5.Fin del Alquiler\n6.Informes\n7.Salir\n","\nNo valida\n",&menu,1,7,1);
        switch(menu)
        {
            case 1:
                system("cls");
                indice = cliente_buscarLugarLibre(arrayClientes,CLIENTES);
                if(indice >= 0){
                    flagAlta = cliente_agregarCliente(arrayClientes,CLIENTES,indice);
                    if(flagAlta == 0)
                        flag = 1;
                }
                cliente_imprimirClientes(arrayClientes,CLIENTES);
                break;
             case 2:
                if(flag!=0){
                    system("cls");
                    cliente_mostrarClienteID(arrayClientes,CLIENTES);
                    getValidInt("\tID de Cliente a modificar: ","\nID No valido\n",&auxiliarId,0,CLIENTES,2);
                    cliente_modificarCliente(arrayClientes,CLIENTES,auxiliarId);
               }
                else{

                    printf("\nDebe ingresar almenos un cliente\n");
                }
                break;
             case 3:

                 if(flag!=0){
                    system("cls");
                    cliente_mostrarClienteID(arrayClientes,CLIENTES);
                    getValidInt("\nID de Cliente a eliminar: ","\nID No valido\n",&auxiliarId,0,CLIENTES,2);
                    cliente_eliminarCliente(arrayClientes,CLIENTES,auxiliarId);
                }
                else{

                    printf("\nDebe ingresar almenos un cliente\n");
                }
                break;
            case 4:

                if(flag!=0){
                    system("cls");
                    indice = alquiler_buscarLugarLibre(arrayAlquileres,ALQUILERES);
                    if(indice >= 0)
                        alquiler_nuevoAlquiler(arrayAlquileres,ALQUILERES,arrayClientes,CLIENTES,indice);
                    alquiler_imprimirAlquileres(arrayAlquileres,ALQUILERES);
                }
                else{

                    printf("\nDebe ingresar almenos un cliente\n");
                }
                break;
            case 5:

                if(flag!=0){
                    system("cls");
                    alquiler_finAlquiler(arrayAlquileres,ALQUILERES,arrayClientes,CLIENTES);
                    alquiler_imprimirAlquileres(arrayAlquileres,ALQUILERES);
               }
                else{

                    printf("\nDebe ingresar almenos un cliente\n");
                }
                break;
            case 6:

                //if(flag!=0){
                    system("cls");
                    //informes_clienteConMasAlquileres(arrayClientes, CLIENTES, arrayAlquileres, ALQUILERES);
                    informes_clientesConSusAlquileres(arrayClientes, CLIENTES, arrayAlquileres, ALQUILERES);
                /*}
                else{

                    printf("\nDebe ingresar almenos un cliente\n");
                }*/
                break;
        }
    }while(menu != 7);


    return 0;
}

