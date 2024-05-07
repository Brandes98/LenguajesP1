#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct {
    int numeroAtomico;
    char nombre[20];
} TablaPeriodica;

typedef struct {
    double numeroAtomico;
    int neutrones;
} Elemento;

struct Tupla_doubles {
    double K;
    double B;
};

void verTabla(Elemento elementos[]) {
    for (int i = 0; i < 100; i++) {
        printf("Element %d - Atomic Number: %f, Neutrons: %d\n",
              i + 1, elementos[i].numeroAtomico, elementos[i].neutrones);
    }
}
void calcular_sumatorias(Elemento elementos[100], double lista[4]){
    double sumLogX = 0.0;
    double sumLogY = 0.0;
    double sumLogXY = 0.0;
    double sumLogX2 = 0.0;
    elementos[0].neutrones=1;
    printf("Calculando sumatorias\n");
     for (int i = 0; i < 100; i++) {
        sumLogX += log(elementos[i].numeroAtomico);
        sumLogY +=log(elementos[i].neutrones);
        sumLogXY +=(log(elementos[i].neutrones)*log(elementos[i].numeroAtomico));
        sumLogX2 += pow(log(elementos[i].numeroAtomico),2);
    }
    lista[0] = sumLogX;
    lista[1] = sumLogY;
    lista[2] = sumLogXY;
    lista[3] = sumLogX2;
    for(int i =0; i<4;i++)
    {
        printf("resultado %f\n",lista[i]);
    };
}
void verSumatorias (double elementos[])
{
    printf("Sumatorias resultado\n");
    for (int i = 0; i < 4; i++) {
        printf("Element %d - Sumatorias: %f\n",
              i + 1, elementos[i]);
    }
}


double calcular_determinante(double matriz_2x2[2][2]){
    return matriz_2x2[0][0]*matriz_2x2[1][1] - matriz_2x2[0][1]*matriz_2x2[1][0];
}


struct Tupla_doubles aplicar_cramer(double ecuaciones[2][3]){

    double matriz_delta_K[2][2] = {{ecuaciones[0][1], ecuaciones[0][2]}
                        ,{ecuaciones[1][1], ecuaciones[1][2]}};

    double delta_K = calcular_determinante(matriz_delta_K);

    double matriz_delta_B[2][2] = {{ecuaciones[0][0], ecuaciones[0][2]}
                        ,{ecuaciones[1][0], ecuaciones[1][2]}};

    double delta_B = calcular_determinante(matriz_delta_B);

    double matriz_delta_S[2][2] = {{ecuaciones[0][0], ecuaciones[0][1]}
                        ,{ecuaciones[1][0], ecuaciones[1][1]}};

    double delta_S = calcular_determinante(matriz_delta_S);


    double K = delta_K/delta_S;

    double B = delta_B/delta_S;


    struct Tupla_doubles KB = {-K,B};
    return KB;
}
double obtener_parametro_a(double K){
   double a = exp(K);
   return a;
}

void print_formula(double a, double B){
    printf("La formula es: y = %f * x^%f\n", a, B);
}

void generar_tabla_estimaciones(double a, double B, int estimaciones[100]){
    printf("Generando tabla de estimaciones\n");
    for (int i = 1; i <= 100; i++) {
        int estimacion = round(a * pow(i, B));
        printf("Element %d - Estimacion: %d\n",
              i, estimacion);
        estimaciones[i-1] = estimacion;
    }
}

void desplegar_Tabla(TablaPeriodica elementos[100], Elemento lista[100], int estimaciones[100]){
    for (int i = 0; i < 100; i++) {
        printf("Elemento %d - Numero Atomico: %d, Nombre: %s\n, Neutrones: %d, Estimacion: %d\n",
              i + 1, elementos[i].numeroAtomico, elementos[i].nombre, lista[i].neutrones, estimaciones[i]);
    }
}

#endif // FUNCTIONS_H