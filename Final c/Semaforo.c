#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
sem_t semaforo;
void * autolavado(void*arg){
int recibir_autos=*(int*)arg;


sem_wait(&semaforo);
printf("Entre por que hay cupo soy el coche %d\n",recibir_autos);
sleep(4);
sem_post(&semaforo);
return NULL;
}


int main(){
    pthread_t hilos[5];
    int numero_mandar[5];

    sem_init(&semaforo,0,3);

    for(int i =0;i<5;i++){
        numero_mandar[i]=i;
        pthread_create(&hilos[i],NULL,autolavado,&numero_mandar[i]);
    }
        for(int i =0;i<5;i++){

        pthread_join(hilos[i],NULL);
    }
sem_destroy(&semaforo);

}