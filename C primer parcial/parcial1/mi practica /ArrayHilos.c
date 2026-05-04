#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* multiplicaion(void*arg){
    int recibir_numer=*(int*)arg;

    int* multiplicar=malloc(sizeof(int));
    *multiplicar=recibir_numer*5;

    return (void*)multiplicar;
}
int main(){

    pthread_t hilo[5];
    int num_mandar[5];
    int *num_recibir[5];


    for(int i =0;i<5;i++){
        num_mandar[i]=i;
        pthread_create(&hilo[i],NULL,multiplicaion,&num_mandar[i]);
    }

    for(int i =0;i<5;i++){
        pthread_join(hilo[i],(void**)&num_recibir[i]);
    }

     for(int i=0;i<5;i++){
        printf("Hola esto es el valor de la multiplicacion %d\n",*num_recibir[i]);
      
     }

    for(int i=0;i<5;i++){
        free(num_recibir[i]);
    }
    return 0;



}