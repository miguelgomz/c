#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* saludar(void* arg) {
    int id = *(int*)arg; // Sacamos el número del "maletín"
    printf("Hola, soy el hilo número %d\n", id);
    return NULL;
}

int main() {
    pthread_t hilos[5];
    int datos[5]; // Un "maletín" para cada hilo

    // 1. CREACIÓN: Todos nacen y empiezan a trabajar
    for (int i = 0; i < 5; i++) {
        datos[i] = i; // Guardamos el valor de 'i' en un lugar seguro
        pthread_create(&hilos[i], NULL, saludar, &datos[i]);
    }

    // 2. ESPERA: El padre se asegura de que todos terminen
    for (int i = 0; i < 5; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Padre: Todos los hilos terminaron.\n");
    return 0;
}