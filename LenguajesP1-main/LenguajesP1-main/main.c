/*
FechaDeCreacion: 27-04-2024-18:00pm
FechaDeUltimaModificacion: 28-04-2024-15:00pm
Integrantes:
Jose Barquero Diaz
Brandon Calderon Cubero
Josue Echeverria
Jose jimenez

                */

#include "obtener_funcion.h"
#include "elementos.h"

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

    printf("El valor es: %f\n", AB.second_double);
    printf("El valor es: %f\n", AB.first_double);
    ///////////////////////////////////////////
    // 3. Desplegar la tabla de estimaciones //
    ///////////////////////////////////////////

    // TODO: Hacer solo un despliegue de la tabla
    // generar_tabla_estimaciones(AB.first_double, AB.second_double, estimaciones);
    // desplegar_Tabla(tablaPeriodica, elementos, estimaciones);
    return 0;
}
