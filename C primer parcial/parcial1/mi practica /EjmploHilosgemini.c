#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* calcular_doble(void* arg) {
    
    int numero = *(int*)arg; 
    printf("Hilo: Me mandaste un %d, voy a calcular el doble...\n", numero);
    
    int* resultado = malloc(sizeof(int));
    *resultado = numero * 2;

    return (void*)resultado; 
}

int main() {
    pthread_t hilo;
    int valor_a_enviar = 50;
    int* valor_recibido; 
  
    pthread_create(&hilo, NULL, calcular_doble, &valor_a_enviar);

    pthread_join(hilo, (void**)&valor_recibido);

    printf("Padre: El hilo terminó y me devolvió un: %d\n", *valor_recibido);
    
    free(valor_recibido);
    return 0;
}