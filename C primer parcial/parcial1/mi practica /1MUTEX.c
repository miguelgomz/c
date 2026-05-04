#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t candado;
int contador=0;
void* contadoor(void*arg){

    for(int i =0;i<1000;i++){
        pthread_mutex_lock(&candado);
    contador++;
    pthread_mutex_unlock(&candado);
    }
    return NULL;
}

int main (){
    pthread_t hilos[10];
     pthread_mutex_init(&candado,NULL);

for(int i =0;i<10;i++){
    pthread_create(&hilos[i],NULL,contadoor,NULL);
}

for(int i =0;i<10;i++){
pthread_join(hilos[i],NULL);
}

for(int i =0;i<10;i++){
    printf("Las vueltas que dio cada hilo%d\n",contador);
}

pthread_mutex_destroy(&candado);


}