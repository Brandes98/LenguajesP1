#ifndef MOSTRAR_TABLA_H
#define MOSTRAR_TABLA_H



void desplegar_Tabla(Elemento lista[100], double a, double b) {
    for (int i = 0; i < 100; i++) {
        int estimacion = round(a * pow(lista[i].numeroAtomico, b));
        
        printf("Elemento %d - Numero Atomico: %d, Nombre: %s, Neutrones: %d, Estimacion: %d\n",
              i + 1, lista[i].numeroAtomico, lista[i].nombre, lista[i].neutrones, estimacion);
    }
}

#endif // MOSTRAR_TABLA_H