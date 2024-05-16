#ifndef MOSTRAR_TABLA_H
#define MOSTRAR_TABLA_H

void desplegar_Tabla(Elemento lista[100], double a, double b)
{
    char fin[107];
    memset(fin, '-', sizeof(char) * 107);
    fin[106] = '\0';
    printf("\n\r|--------------|----------------|---------------|---------------------|-----------------------|------------|\n");
    printf("|   Elemento   |     Nombre     |   Neutrones   | Neutrones(Truncado) | Neutrones(Redondeado) | Diferencia |\n");
    printf("|--------------|----------------|---------------|---------------------|-----------------------|------------|\n");

    for (int i = 0; i < 100; i++)
    {
        double estimacion = a * pow(lista[i].numeroAtomico, b);
        // redondeo hacia cero
        int truncado = (int)estimacion;
        // redondeo a al mas cercano
        int redondeado = round(estimacion);
        // Se castea a entero la estimacion para el valor truncado, se redondea y se saca la diferencia
        printf("| %-12.0f | %-14s | %-13d | %-19d | %-21d | %-10d |\n", lista[i].numeroAtomico, lista[i].nombre, lista[i].neutrones,
               (int)truncado, (int)redondeado, (int)redondeado - (int)truncado);
    }
    printf("|%s|", fin);
}
#endif // MOSTRAR_TABLA_H
