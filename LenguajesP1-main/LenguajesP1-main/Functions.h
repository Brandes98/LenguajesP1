#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    int numeroAtomico;
    char nombre[20];
} TablaPeriodica;

// Estructura de una tupla de doubles
typedef struct
{
    double K;
    double B;
} Tupla_doubles;

// TODO: No hace falta esta funcion
void verTabla(Elemento elementos[])
{
    for (int i = 0; i < 100; i++)
    {
        printf("Element %d - Atomic Number: %f, Neutrons: %d\n",
               i + 1, elementos[i].numeroAtomico, elementos[i].neutrones);
    }
}

// // TODO: Se puede unir esta funcion con otra funcion
// double obtener_parametro_a(double K)
// {
//     double a = exp(K);
//     return a;
// }

// TODO: No es necesario hacer dos ciclos, se puede hacer en uno solo
void generar_tabla_estimaciones(double a, double B, int estimaciones[100])
{
    printf("Generando tabla de estimaciones\n");
    for (int i = 1; i <= 100; i++)
    {
        int estimacion = round(a * pow(i, B));
        printf("Element %d - Estimacion: %d\n",
               i, estimacion);
        estimaciones[i - 1] = estimacion;
    }
}
void desplegar_Tabla(Elemento lista[100], int estimaciones[100])
{
    for (int i = 0; i < 100; i++)
    {
        printf("Elemento %d - Numero Atomico: %d, Nombre: %s,\n Neutrones: %d, Estimacion: %d\n",
               i + 1, lista[i].numeroAtomico, lista[i].nombre, lista[i].neutrones, estimaciones[i]);
    }
}

#endif // FUNCTIONS_H