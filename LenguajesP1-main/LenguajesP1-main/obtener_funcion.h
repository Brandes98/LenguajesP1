#ifndef OBTENER_FUNCION_H
#define OBTENER_FUNCION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estructura de una tupla de doubles
typedef struct
{
    double first_double;
    double second_double;
} Tupla_doubles;


// Estructura de las sumas de los logaritmos
typedef struct
{
    double sumLogX;
    double sumLogY;
    double sumLogXY;
    double sumLogX2;
} LogSums;



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




Tupla_doubles aplicar_cramer(double ecuaciones[2][3])
{
    
    double matriz_delta_K[2][2] = {{ecuaciones[0][1], ecuaciones[0][2]}, {ecuaciones[1][1], ecuaciones[1][2]}};

    // Se calcula el determinate de matriz_delta_K 
    double delta_K = matriz_delta_K[0][0] * matriz_delta_K[1][1] - matriz_delta_K[0][1] * matriz_delta_K[1][0];

    double matriz_delta_B[2][2] = {{ecuaciones[0][0], ecuaciones[0][2]}, {ecuaciones[1][0], ecuaciones[1][2]}};

    // Se calcula el determinate de matriz_delta_B 
    double delta_B = matriz_delta_B[0][0] * matriz_delta_B[1][1] - matriz_delta_B[0][1] * matriz_delta_B[1][0];

    double matriz_delta_S[2][2] = {{ecuaciones[0][0], ecuaciones[0][1]}, {ecuaciones[1][0], ecuaciones[1][1]}};

    // Se calcula el determinate de matriz_delta_S 
    double delta_S = matriz_delta_S[0][0] * matriz_delta_S[1][1] - matriz_delta_S[0][1] * matriz_delta_S[1][0];

    double K = delta_K / delta_S;

    double B = delta_B / delta_S;

    Tupla_doubles KB = {-K, B};
    return KB;
}

Tupla_doubles obtener_funcion(Elemento *elementos){

    // Calcular las sumas de los logaritmos
    LogSums sums = calcular_sum_logs(elementos);

    // Crear la matriz de la formula
    double formula1[2][3] = {{100, sums.sumLogX, sums.sumLogY}, {sums.sumLogX, sums.sumLogX2, sums.sumLogXY}};

    Tupla_doubles KB = aplicar_cramer(formula1);

    Tupla_doubles AB = {exp(KB.first_double), KB.second_double};

    return AB;
}



#endif // OBTENER_FUNCION_H