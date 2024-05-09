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

// Estructura de un elemento
typedef struct
{
    double numeroAtomico;
    int neutrones;
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

// TODO: No hace falta esta funcion
void verTabla(Elemento elementos[])
{
    for (int i = 0; i < 100; i++)
    {
        printf("Element %d - Atomic Number: %f, Neutrons: %d\n",
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

// Funcion que aplica la regla de Cramer para resolver un sistema de ecuaciones de 2x2
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

void print_formula(double a, double B)
{
    printf("La formula es: y = %f * x^%f\n", a, B);
}

// TODO: Se puede unir esta funcion con otra funcion
double obtener_parametro_a(double K)
{
    double a = exp(K);
    return a;
}

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
void desplegar_Tabla(TablaPeriodica elementos[100], Elemento lista[100], int estimaciones[100])
{
    for (int i = 0; i < 100; i++)
    {
        printf("Elemento %d - Numero Atomico: %d, Nombre: %s,\n Neutrones: %d, Estimacion: %d\n",
               i + 1, elementos[i].numeroAtomico, elementos[i].nombre, lista[i].neutrones, estimaciones[i]);
    }
}

#endif // FUNCTIONS_H