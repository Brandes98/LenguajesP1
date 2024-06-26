/*
FechaDeCreacion: 27-04-2024-18:00pm
FechaDeUltimaModificacion: 28-04-2024-15:00pm
Integrantes:
Jose Barquero Diaz
Brandon Calderon Cubero
Josue Echeverria
Jose jimenez

                */

#include "Functions.h"

int main(int argc, char *argv[])
{

    Elemento elementos[100] =
        {
            {1, 0}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {6, 6}, {7, 7}, {8, 8}, {9, 10}, {10, 10}, {11, 12}, {12, 12}, {13, 14}, {14, 14}, {15, 16}, {16, 16}, {17, 17}, {18, 22}, {19, 20}, {20, 20}, {21, 24}, {22, 26}, {23, 28}, {24, 28}, {25, 30}, {26, 30}, {27, 32}, {28, 31}, {29, 35}, {30, 35}, {31, 39}, {32, 41}, {33, 42}, {34, 45}, {35, 45}, {36, 48}, {37, 48}, {38, 50}, {39, 50}, {40, 51}, {41, 52}, {42, 54}, {43, 55}, {44, 57}, {45, 58}, {46, 60}, {47, 61}, {48, 64}, {49, 66}, {50, 69}, {51, 71}, {52, 76}, {53, 74}, {54, 77}, {55, 78}, {56, 81}, {57, 82}, {58, 82}, {59, 84}, {60, 84}, {61, 84}, {62, 88}, {63, 89}, {64, 93}, {65, 94}, {66, 97}, {67, 98}, {68, 99}, {69, 100}, {70, 103}, {71, 104}, {72, 106}, {73, 108}, {74, 110}, {75, 111}, {76, 114}, {77, 115}, {78, 117}, {79, 118}, {80, 121}, {81, 123}, {82, 125}, {83, 126}, {84, 125}, {85, 125}, {86, 136}, {87, 136}, {88, 138}, {89, 138}, {90, 142}, {91, 140}, {92, 146}, {93, 144}, {94, 150}, {95, 148}, {96, 151}, {97, 150}, {98, 153}, {99, 153}, {100, 157}};
    // verTabla(elementos);
    LogSums sums = calcular_sum_logs(elementos);

    // nk + sum(ln(x)) = sum(ln(y))
    // sum(ln(x)) + sum(ln(x^2)) = sum(ln(x)ln(y))
    double formula1[2][3] = {{100, sums.sumLogX, sums.sumLogY}, {sums.sumLogX, sums.sumLogX2, sums.sumLogXY}};

    struct Tupla_doubles KB = aplicar_cramer(formula1);

    printf("El resultado final de k es: %f\n", KB.K);
    printf("El resultado final de b es: %f\n", KB.B);
    // print sums
    printf("sumLogX: %f\n", sums.sumLogX);
    printf("sumLogY: %f\n", sums.sumLogY);
    printf("sumLogXY: %f\n", sums.sumLogXY);
    printf("sumLogX2: %f\n", sums.sumLogX2);

    return 0;
}
