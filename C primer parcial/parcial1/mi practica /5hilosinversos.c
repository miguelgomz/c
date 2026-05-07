#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
pthread_mutex_t candado;
pthread_cond_t condicion;
int contador=0;
int contador_regreso=4;
void* imprimir_por_turnos_ida(void*arg){
 int recibir=*(int*)arg;
 int * recibiiir=malloc(sizeof(int));
 *recibiiir=recibir;

pthread_mutex_lock(&candado);
while(contador!=recibir){

    pthread_cond_wait(&condicion,&candado);
}

printf("Hola imprimire tu numero de i %d\n",recibir);
contador++;
pthread_cond_broadcast(&condicion);//despierta a los demas 
pthread_mutex_unlock(&candado);

return (void**)recibiiir;
}


void* imprimir_por_turnos_vuelta(void*arg){
 int recibir_regreso=*(int*)arg;
 int * devolver_regreso=malloc(sizeof(int));
 *devolver_regreso=recibir_regreso;

pthread_mutex_lock(&candado);
while(contador_regreso!=recibir_regreso){

    pthread_cond_wait(&condicion,&candado);
}


printf("Hola imprimire tu numero de i inversooo %d\n",recibir_regreso);
contador_regreso--;
pthread_cond_broadcast(&condicion);//despierta a los demas 
pthread_mutex_unlock(&candado);

return (void**)devolver_regreso;
}



int main(){
    pthread_mutex_init(&candado,NULL);
    pthread_cond_init(&condicion,NULL);
    pthread_t hilos[5];
    int numero_mandar[5];
    int *recibir;
    int numero_mandar_dos[5];
    


     for(int i =0;i<5;i++){
        numero_mandar[i]=i;
        pthread_create(&hilos[i],NULL,imprimir_por_turnos_ida,&numero_mandar[i]);
}
     for(int i =0;i<5;i++){
        pthread_join(hilos[i],(void**)&recibir);
        free(recibir);
     }


    for(int i =4;i>=0;i--){
        numero_mandar_dos[i]=i;
        pthread_create(&hilos[i],NULL,imprimir_por_turnos_vuelta,&numero_mandar_dos[i]);
}
     for(int i =4;i>=0;i--){
        pthread_join(hilos[i],(void**)&recibir);
        free(recibir);
     }


     pthread_cond_destroy(&condicion);
    pthread_mutex_destroy(&candado);

    return 0;


}
