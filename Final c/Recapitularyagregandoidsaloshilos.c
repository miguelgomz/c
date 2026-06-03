#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
pthread_mutex_t candado;
pthread_cond_t condicion;
int contador=0;
int presion=0;
void* usar_hilos(void*arg){
    int recibir_numero=*(int*)arg;
    int *ids=malloc(sizeof(int));
    int *contador=malloc(sizeof(int));
    *ids=recibir_numero;

    pthread_mutex_lock(&candado);
while(ids=!contador ){
pthread_cond_wait(&condicion,&candado);
}

if(ids ==0){
sleep(4);
printf("Hola soy el hijo %d\n",ids);
printf("Cmbiare la presion y llamra al resto de compuertas  %d\n",ids);
presion =1;
contador++;
pthread_cond_broadcast(&condicion);
pthread_mutex_unlock(&candado);
}else{
    printf("Soy la compuerta abriendose %d\n",ids);
    contador++;
    pthread_cond_broadcast(&condicion);
    pthread_mutex_unlock(&candado);
}


}


int main(){
    int numeros_mandar[4];
 
    pthread_mutex_init(&candado,NULL);
    pthread_cond_init(&condicion,NULL);
    pthread_t hilos[4];

    for(int i = 0;i<4;i++){
        numeros_mandar[i]=i;
    
pthread_create(&hilos[i],NULL,usar_hilos,&numeros_mandar[i]);
}
for(int i = 0;i<4;i++){
pthread_join(&hilos[i],NULL);
}
    pthread_cond_destroy(&condicion);
    pthread_mutex_destroy(&candado);

    return 0;
    }