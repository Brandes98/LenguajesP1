#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estructura de un elemento
typedef struct
{
    double numeroAtomico;
    double neutrones;
} Elemento;

// Estructura de las sumas de los logaritmos
typedef struct
{
    double sumLogX;
    double sumLogY;
    double sumLogXY;
    double sumLogX2;
} LogSums;

// Estructura de una tupla de doubles
typedef struct
{
    double K;
    double B;
} Tupla_doubles;

// Funcion que imprime la tabla de elementos
void verTabla(Elemento elementos[])
{
    for (int i = 0; i < 100; i++)
    {
        printf("Element %d - Atomic Number: %f, Neutrons: %f\n",
               i + 1, elementos[i].numeroAtomico, elementos[i].neutrones);
    }
}

// Funcion que calcula las sumas de los logaritmos de los elementos
LogSums calcular_sum_logs(Elemento elementos[])
{
    // Inicializar las sumas
    LogSums sums = {0.0, 0.0, 0.0, 0.0};

    // Calcular los logaritmos y las sumas
    double logNumeroAtomico, logNeutrones;
    for (int i = 0; i < 100; i++)
    {
        // Calcular los logaritmos
        logNumeroAtomico = log(elementos[i].numeroAtomico);

        // Sumar los logaritmos
        sums.sumLogX += logNumeroAtomico;
        sums.sumLogX2 += pow(logNumeroAtomico, 2);

        // Si el elemento tiene neutrones, sumar el logaritmo de los neutrones y el producto de los logaritmos
        if (elementos[i].neutrones != 0)
        {
            logNeutrones = log(elementos[i].neutrones);
            sums.sumLogY += logNeutrones;
            sums.sumLogXY += (logNeutrones * logNumeroAtomico);
        }
    }
    return sums;
}

// Funcion que calcula el determinante de una matriz de 2x2
// TODO: Eliminar esta funcion, hacerla inline
double calcular_determinante(double matriz_2x2[2][2])
{
    return matriz_2x2[0][0] * matriz_2x2[1][1] - matriz_2x2[0][1] * matriz_2x2[1][0];
}

// Funcion que aplica la regla de Cramer para resolver un sistema de ecuaciones de 2x2
Tupla_doubles aplicar_cramer(double ecuaciones[2][3])
{
    // Calcular los determinantes
    double matriz_delta_K[2][2] = {{ecuaciones[0][1], ecuaciones[0][2]}, {ecuaciones[1][1], ecuaciones[1][2]}};

    double delta_K = calcular_determinante(matriz_delta_K);

    double matriz_delta_B[2][2] = {{ecuaciones[0][0], ecuaciones[0][2]}, {ecuaciones[1][0], ecuaciones[1][2]}};

    double delta_B = calcular_determinante(matriz_delta_B);

    double matriz_delta_S[2][2] = {{ecuaciones[0][0], ecuaciones[0][1]}, {ecuaciones[1][0], ecuaciones[1][1]}};

    double delta_S = calcular_determinante(matriz_delta_S);

    double K = delta_K / delta_S;

    double B = delta_B / delta_S;

    Tupla_doubles KB = {-K, B};
    return KB;
}

#endif // FUNCTIONS_H