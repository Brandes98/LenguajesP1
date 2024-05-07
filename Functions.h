#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    double numeroAtomico;
    double neutrones;
} Elemento;

typedef struct
{
    double sumLogX;
    double sumLogY;
    double sumLogXY;
    double sumLogX2;
} LogSums;

struct Tupla_doubles
{
    double K;
    double B;
};

void verTabla(Elemento elementos[])
{
    for (int i = 0; i < 100; i++)
    {
        printf("Element %d - Atomic Number: %f, Neutrons: %f\n",
               i + 1, elementos[i].numeroAtomico, elementos[i].neutrones);
    }
}

LogSums calcular_sum_logs(Elemento elementos[])
{
    LogSums sums = {0.0, 0.0, 0.0, 0.0};
    double logNumeroAtomico, logNeutrones;
    for (int i = 0; i < 100; i++)
    {
        logNumeroAtomico = log(elementos[i].numeroAtomico);
        sums.sumLogX += logNumeroAtomico;
        sums.sumLogX2 += pow(logNumeroAtomico, 2);
        if (elementos[i].neutrones != 0)
        {
            logNeutrones = log(elementos[i].neutrones);
            sums.sumLogY += logNeutrones;
            sums.sumLogXY += (logNeutrones * logNumeroAtomico);
        }
    }
    return sums;
}

double calcular_determinante(double matriz_2x2[2][2])
{
    return matriz_2x2[0][0] * matriz_2x2[1][1] - matriz_2x2[0][1] * matriz_2x2[1][0];
}

struct Tupla_doubles aplicar_cramer(double ecuaciones[2][3])
{

    double matriz_delta_K[2][2] = {{ecuaciones[0][1], ecuaciones[0][2]}, {ecuaciones[1][1], ecuaciones[1][2]}};

    double delta_K = calcular_determinante(matriz_delta_K);

    double matriz_delta_B[2][2] = {{ecuaciones[0][0], ecuaciones[0][2]}, {ecuaciones[1][0], ecuaciones[1][2]}};

    double delta_B = calcular_determinante(matriz_delta_B);

    double matriz_delta_S[2][2] = {{ecuaciones[0][0], ecuaciones[0][1]}, {ecuaciones[1][0], ecuaciones[1][1]}};

    double delta_S = calcular_determinante(matriz_delta_S);

    double K = delta_K / delta_S;

    double B = delta_B / delta_S;

    struct Tupla_doubles KB = {-K, B};
    return KB;
}

#endif // FUNCTIONS_H