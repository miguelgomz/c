#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t candado;
void* sumar_valores(void*arg){
int recibir_num=*(int*)arg;
int *varible_puntero=malloc(sizeof(int));
*varible_puntero=recibir_num;

pthread_mutex_lock(&candado);
printf("Hola este son los valores del primer array%d\n",recibir_num);
pthread_mutex_unlock(&candado);
return (void*) varible_puntero;
}

void* sumar_valores_dos(void*arg){
int recibir_num_2=*(int*)arg;
int *varible_puntero=malloc(sizeof(int));
*varible_puntero=recibir_num_2;

pthread_mutex_lock(&candado);
printf("Hola este son los valores del segundo array%d\n",recibir_num_2);
pthread_mutex_unlock(&candado);
return (void*) varible_puntero;
}


int main(){
    pthread_mutex_init(&candado,NULL);
    pthread_t hilos[2];
    int num_mandar[10];
    int * num_recibir;

    
    
    for(int i =0;i<5;i++){
        num_mandar[i]=i;
    pthread_create(&hilos[0],NULL,sumar_valores,&num_mandar[i]);
    }
    for(int i =0;i<5;i++){
        
    pthread_join(hilos[0],(void**)&num_recibir);
    free(num_recibir);

    } 
    for(int i =4;i<9;i++){
        num_mandar[i]=i;
    pthread_create(&hilos[1],NULL,sumar_valores_dos,&num_mandar[i]);
    }
    for(int i =4;i<9;i++){
        
    pthread_join(hilos[1],(void**)&num_recibir);
    free(num_recibir);
    }


    pthread_mutex_destroy(&candado);

}