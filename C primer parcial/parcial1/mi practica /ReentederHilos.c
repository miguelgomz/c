#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void*hola(void*arg){
    printf("hola quiero imprimir este mensaje");
    return NULL;
}
int main (){
pthread_t hilo1;


pthread_create(&hilo1,NULL,hola,NULL);
pthread_join(hilo1,NULL);
}

//Hola re captando lo que era hacer hilos 