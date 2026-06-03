#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t candado;
pthread_cond_t condicion;
int contador=2;

void* imprimir_por_turnos_ida(void*arg){
 int recibir_num=*(int*)arg;
 int * num_puntero=malloc(sizeof(int));
 *num_puntero=recibir_num;

 pthread_mutex_lock(&candado);
while(recibir_num!=contador){
pthread_cond_wait(&condicion,&candado);
}

if(contador==2){
printf("Soy el 2 ");
contador -2;
pthread_cond_broadcast(&condicion);
}

 
 if(contador==0){
printf("Soy el 0 ");
contador ++;
pthread_cond_broadcast(&condicion);
}

if(contador==1){
printf("Soy el 1 ");
pthread_cond_broadcast(&condicion);
}

 pthread_mutex_unlock(&candado);

 return (void*) num_puntero;

}
int main(){
    pthread_mutex_init(&candado,NULL);
    pthread_cond_init(&condicion,NULL);
    pthread_t hilos[3];
    int numeros_mandar[3];
    int *num_recibir;

    for(int i=0;i<3;i++){
        numeros_mandar[i]=i;
    pthread_create(&hilos[i],NULL,imprimir_por_turnos_ida,&numeros_mandar[i]);
    }
     for(int i=0;i<3;i++){
    pthread_join(hilos[i],(void**)&num_recibir);
    free(num_recibir);
    }


    pthread_cond_destroy(&condicion);
    pthread_mutex_destroy(&candado);

    return 0;

}
