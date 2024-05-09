/*
FechaDeCreacion: 27-04-2024-18:00pm
FechaDeUltimaModificacion: 28-04-2024-15:00pm
Integrantes:
Jose Barquero Diaz
Brandon Calderon Cubero
Josue Echeverria
Jose jimenez

                */

#include "elementos.h"
#include "obtener_funcion.h"
#include "mostrar_tabla.h"

int main(int argc, char *argv[])
{

    ////////////////////////////////////////
    // 1. Leer los datos de los elementos //
    ////////////////////////////////////////

    Elemento *elementos = obtener_elementos();

    ////////////////////////////////////////////////
    // 2. Obtener la formula de la funcion lineal //
    ////////////////////////////////////////////////

    Tupla_doubles AB = obtener_funcion(elementos);
    
    ///////////////////////////////////////////
    // 3. Desplegar la tabla de estimaciones //
    ///////////////////////////////////////////

    desplegar_Tabla(elementos,AB.first_double, AB.second_double);

    return 0;
}
