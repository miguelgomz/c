#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
int temperatura=100;
int contador=0;
sem_t semaforo;

void sistema_op(int señal){
    contador++;
if(contador<3){
    printf("El sistema operativo se esta enfriando\n");
}else if (contador>=3){
    printf("Hola me voy a apagar \n");
    exit(0);
}
}

void * modificar_temp(void*arg){
int ids_reci =*(int*)arg;
while(1){
sem_wait(&semaforo);
    temperatura +=5;
    printf("Temperatura aumenta \n");
    sem_post(&semaforo);
    sleep(2);
}

return 0;
}

int main(){
    pthread_t hijos[3];
sem_init(&semaforo,0,1);
signal(SIGINT,sistema_op);

    int ids[3];

    for(int i =0;i<3;i++){
        ids[i]=i;
        pthread_create(&hijos[i],NULL,modificar_temp,&ids[i]);
    }
    for(int i =0;i<3;i++){
        pthread_join(hijos[i],NULL);
    }

sem_destroy(&semaforo);

}