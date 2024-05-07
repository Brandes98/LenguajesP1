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

    int estimaciones[100];

    ////////////////////////////////////////
    // 1. Leer los datos de los elementos //
    ////////////////////////////////////////

    // TODO: Usar solo un arreglo de elementos, tal vez pasarlos a otro archivo
    Elemento elementos[100] =
        {
            {1, 0}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {6, 6}, {7, 7}, {8, 8}, {9, 10}, {10, 10}, {11, 12}, {12, 12}, {13, 14}, {14, 14}, {15, 16}, {16, 16}, {17, 17}, {18, 22}, {19, 20}, {20, 20}, {21, 24}, {22, 26}, {23, 28}, {24, 28}, {25, 30}, {26, 30}, {27, 32}, {28, 31}, {29, 35}, {30, 35}, {31, 39}, {32, 41}, {33, 42}, {34, 45}, {35, 45}, {36, 48}, {37, 48}, {38, 50}, {39, 50}, {40, 51}, {41, 52}, {42, 54}, {43, 55}, {44, 57}, {45, 58}, {46, 60}, {47, 61}, {48, 64}, {49, 66}, {50, 69}, {51, 71}, {52, 76}, {53, 74}, {54, 77}, {55, 78}, {56, 81}, {57, 82}, {58, 82}, {59, 84}, {60, 84}, {61, 84}, {62, 88}, {63, 89}, {64, 93}, {65, 94}, {66, 97}, {67, 98}, {68, 99}, {69, 100}, {70, 103}, {71, 104}, {72, 106}, {73, 108}, {74, 110}, {75, 111}, {76, 114}, {77, 115}, {78, 117}, {79, 118}, {80, 121}, {81, 123}, {82, 125}, {83, 126}, {84, 125}, {85, 125}, {86, 136}, {87, 136}, {88, 138}, {89, 138}, {90, 142}, {91, 140}, {92, 146}, {93, 144}, {94, 150}, {95, 148}, {96, 151}, {97, 150}, {98, 153}, {99, 153}, {100, 157}};
    TablaPeriodica tablaPeriodica[100] = {
        {1, "Hidrógeno"},
        {2, "Helio"},
        {3, "Litio"},
        {4, "Berilio"},
        {5, "Boro"},
        {6, "Carbono"},
        {7, "Nitrógeno"},
        {8, "Oxígeno"},
        {9, "Flúor"},
        {10, "Neón"},
        {11, "Sodio"},
        {12, "Magnesio"},
        {13, "Aluminio"},
        {14, "Silicio"},
        {15, "Fósforo"},
        {16, "Azufre"},
        {17, "Cloro"},
        {18, "Argón"},
        {19, "Potasio"},
        {20, "Calcio"},
        {21, "Escandio"},
        {22, "Titanio"},
        {23, "Vanadio"},
        {24, "Cromo"},
        {25, "Manganeso"},
        {26, "Hierro"},
        {27, "Cobalto"},
        {28, "Níquel"},
        {29, "Cobre"},
        {30, "Zinc"},
        {31, "Galio"},
        {32, "Germanio"},
        {33, "Arsénico"},
        {34, "Selenio"},
        {35, "Bromo"},
        {36, "Kriptón"},
        {37, "Rubidio"},
        {38, "Estroncio"},
        {39, "Itrio"},
        {40, "Circonio"},
        {41, "Niobio"},
        {42, "Molibdeno"},
        {43, "Tecnecio"},
        {44, "Rutenio"},
        {45, "Rodio"},
        {46, "Paladio"},
        {47, "Plata"},
        {48, "Cadmio"},
        {49, "Indio"},
        {50, "Estaño"},
        {51, "Antimonio"},
        {52, "Teluro"},
        {53, "Yodo"},
        {54, "Xenón"},
        {55, "Cesio"},
        {56, "Bario"},
        {57, "Lantano"},
        {58, "Cerio"},
        {59, "Praseodimio"},
        {60, "Neodimio"},
        {61, "Prometio"},
        {62, "Samario"},
        {63, "Europio"},
        {64, "Gadolinio"},
        {65, "Terbio"},
        {66, "Disprosio"},
        {67, "Holmio"},
        {68, "Erbio"},
        {69, "Tulio"},
        {70, "Iterbio"},
        {71, "Lutecio"},
        {72, "Hafnio"},
        {73, "Tantalio"},
        {74, "Wolframio"},
        {75, "Renio"},
        {76, "Osmio"},
        {77, "Iridio"},
        {78, "Platino"},
        {79, "Oro"},
        {80, "Mercurio"},
        {81, "Talio"},
        {82, "Plomo"},
        {83, "Bismuto"},
        {84, "Polonio"},
        {85, "Astato"},
        {86, "Radón"},
        {87, "Francio"},
        {88, "Radio"},
        {89, "Actinio"},
        {90, "Torio"},
        {91, "Protactinio"},
        {92, "Uranio"},
        {93, "Neptunio"},
        {94, "Plutonio"},
        {95, "Americio"},
        {96, "Curio"},
        {97, "Berkelio"},
        {98, "Californio"},
        {99, "Einstenio"},
        {100, "Fermio"}};

    // TODO: Eliminar la funcion verTabla
    verTabla(elementos);

    ////////////////////////////////////////////////
    // 2. Obtener la formula de la funcion lineal //
    ////////////////////////////////////////////////

    // Calcular las sumas de los logaritmos
    LogSums sums = calcular_sum_logs(elementos);

    // Crear la matriz de la formula
    double formula1[2][3] = {{100, sums.sumLogX, sums.sumLogY}, {sums.sumLogX, sums.sumLogX2, sums.sumLogXY}};

    Tupla_doubles KB = aplicar_cramer(formula1);

    // TODO: Eliminar prints
    printf("El resultado final de k es: %f\n", KB.K);
    printf("El resultado final de b es: %f\n", KB.B);

    double a = obtener_parametro_a(KB.K);

    // TODO: Eliminar prints
    print_formula(a, KB.B);

    ///////////////////////////////////////////
    // 3. Desplegar la tabla de estimaciones //
    ///////////////////////////////////////////

    // TODO: Hacer solo un despliegue de la tabla
    generar_tabla_estimaciones(a, KB.B, estimaciones);
    desplegar_Tabla(tablaPeriodica, elementos, estimaciones);
    return 0;
}
