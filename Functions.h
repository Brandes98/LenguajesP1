#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double numeroAtomico;
    double neutrones;
} Elemento;

void verTabla(Elemento elementos[]) {
    for (int i = 0; i < 100; i++) {
        printf("Element %d - Atomic Number: %f, Neutrons: %f\n",
              i + 1, elementos[i].numeroAtomico, elementos[i].neutrones);
    }
}

double calcular_sum_logX(Elemento elementos[]) {
    double sumLogX = 0.0;
    for (int i = 0; i < 100; i++) {
        sumLogX += log(elementos[i].numeroAtomico);
    }
    return sumLogX;
}

double calcular_sum_logY(Elemento elementos[]) {
    double sumLogY = 0.0;
    for (int i = 1; i < 100; i++) {
        sumLogY +=log(elementos[i].neutrones);
    }
    return sumLogY;
}

double calcular_sum_logXY(Elemento elementos[]) {
    double sumLogXY = 0.0;
    for (int i = 0; i < 100; i++) {
        if (i==0){
            continue;
        } 
        else
        sumLogXY +=(log(elementos[i].neutrones)*log(elementos[i].numeroAtomico));
    }
    return sumLogXY;
}
double calcular_sum_logX2(Elemento elementos[]) {
    double sumLogX2 = 0.0;
    for (int i = 0; i < 100; i++) {
        sumLogX2 += pow(log(elementos[i].numeroAtomico),2);
    }
    return sumLogX2;
}
#endif // FUNCTIONS_H