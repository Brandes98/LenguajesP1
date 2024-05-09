#ifndef ELEMENTOS_H
#define ELEMENTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estructura de un elemento

typedef struct {
    double numeroAtomico;
    int neutrones;
    char nombre[20];
    
} Elemento;

Elemento elementos[] = {
        {1, 0, "Hidrógeno"},
        {2, 2, "Helio"},
        {3, 4, "Litio"},
        {4, 5, "Berilio"},
        {5, 6, "Boro"},
        {6, 6, "Carbono"},
        {7, 7, "Nitrógeno"},
        {8, 8, "Oxígeno"},
        {9, 10, "Flúor"},
        {10, 10, "Neón"},
        {11, 12, "Sodio"},
        {12, 12, "Magnesio"},
        {13, 14, "Aluminio"},
        {14, 14, "Silicio"},
        {15, 16, "Fósforo"},
        {16, 16, "Azufre"},
        {17, 17, "Cloro"},
        {18, 22, "Argón"},
        {19, 20, "Potasio"},
        {20, 20, "Calcio"},
        {21, 24, "Escandio"},
        {22, 26, "Titanio"},
        {23, 28, "Vanadio"},
        {24, 28, "Cromo"},
        {25, 30, "Manganeso"},
        {26, 30, "Hierro"},
        {27, 32, "Cobalto"},
        {28, 31, "Níquel"},
        {29, 35, "Cobre"},
        {30, 35, "Zinc"},
        {31, 39, "Galio"},
        {32, 41, "Germanio"},
        {33, 42, "Arsénico"},
        {34, 45, "Selenio"},
        {35, 45, "Bromo"},
        {36, 48, "Kriptón"},
        {37, 48, "Rubidio"},
        {38, 50, "Estroncio"},
        {39, 50, "Itrio"},
        {40, 51, "Circonio"},
        {41, 52, "Niobio"},
        {42, 54, "Molibdeno"},
        {43, 55, "Tecnecio"},
        {44, 57, "Rutenio"},
        {45, 58, "Rodio"},
        {46, 60, "Paladio"},
        {47, 61, "Plata"},
        {48, 64, "Cadmio"},
        {49, 66, "Indio"},
        {50, 69, "Estaño"},
        {51, 71, "Antimonio"},
        {52, 76, "Teluro"},
        {53, 74, "Yodo"},
        {54, 77, "Xenón"},
        {55, 78, "Cesio"},
        {56, 81, "Bario"},
        {57, 82, "Lantano"},
        {58, 82, "Cerio"},
        {59, 84, "Praseodimio"},
        {60, 84, "Neodimio"},
        {61, 84, "Prometio"},
        {62, 88, "Samario"},
        {63, 89, "Europio"},
        {64, 93, "Gadolinio"},
        {65, 94, "Terbio"},
        {66, 97, "Disprosio"},
        {67, 98, "Holmio"},
        {68, 99, "Erbio"},
        {69, 100, "Tulio"},
        {70, 103, "Iterbio"},
        {71, 104, "Lutecio"},
        {72, 106, "Hafnio"},
        {73, 108, "Tantalio"},
        {74, 110, "Wolframio"},
        {75, 111, "Renio"},
        {76, 114, "Osmio"},
        {77, 115, "Iridio"},
        {78, 117, "Platino"},
        {79, 118, "Oro"},
        {80, 121, "Mercurio"},
        {81, 123, "Talio"},
        {82, 125, "Plomo"},
        {83, 126, "Bismuto"},
        {84, 125, "Polonio"},
        {85, 125, "Astato"},
        {86, 136, "Radón"},
        {87, 136, "Francio"},
        {88, 138, "Radio"},
        {89, 138, "Actinio"},
        {90, 142, "Torio"},
        {91, 140, "Protactinio"},
        {92, 146, "Uranio"},
        {93, 144, "Neptunio"},
        {94, 150, "Plutonio"},
        {95, 148, "Americio"},
        {96, 151, "Curio"},
        {97, 150, "Berkelio"},
        {98, 153, "Californio"},
        {99, 153, "Einstenio"},
        {100, 157, "Fermio"}};

Elemento* obtener_elementos(){
    return elementos;
}


#endif // ELEMENTOS_H