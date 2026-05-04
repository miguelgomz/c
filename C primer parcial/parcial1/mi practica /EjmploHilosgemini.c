#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* calcular_doble(void* arg) {
    // 1. Recibimos el número (hay que convertir el void* a int)
    int numero = *(int*)arg; 
    printf("Hilo: Me mandaste un %d, voy a calcular el doble...\n", numero);
    
    // 2. Creamos el "regalo" en memoria dinámica
    int* resultado = malloc(sizeof(int));
    *resultado = numero * 2;
    
    // 3. Devolvemos el puntero con el resultado
    return (void*)resultado; 
}

int main() {
    pthread_t hilo;
    int valor_a_enviar = 50;
    int* valor_recibido; // Aquí guardaremos lo que el hilo devuelva

    // Mandamos la dirección de 'valor_a_enviar' en el último parámetro
    pthread_create(&hilo, NULL, calcular_doble, &valor_a_enviar);

    // Recibimos el regalo en 'valor_recibido' en el segundo parámetro
    pthread_join(hilo, (void**)&valor_recibido);

    printf("Padre: El hilo terminó y me devolvió un: %d\n", *valor_recibido);
    
    free(valor_recibido); // Limpiamos la memoria
    return 0;
}