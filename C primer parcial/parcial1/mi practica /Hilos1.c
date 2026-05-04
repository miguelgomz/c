#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void* numero1(void*arg){
    int numero_acp1=*(int*)arg;
    int*raiz1=malloc(sizeof(int));
    *raiz1=numero_acp1*numero_acp1;
    return (void*)raiz1;
}
void* numero2(void*arg){
    int numero_acp2=*(int*)arg;
    int*raiz2=malloc(sizeof(int));
    *raiz2=numero_acp2*numero_acp2;
    return (void*)raiz2;
}
void* numero3(void*arg){
    int numero_acp3=*(int*)arg;
    int*raiz3=malloc(sizeof(int));
    *raiz3=numero_acp3*numero_acp3;
    return (void*)raiz3;
}


int main(){


pthread_t hilo1;

int numero_mandar1=5;
int numero_mandar2=34;
int numero_mandar3=2;


int* num_rec1=0;
int* num_rec2=0;
int* num_rec3=0;




pthread_create(&hilo1,NULL,numero1,&numero_mandar1);
pthread_join(hilo1,(void*)&num_rec1);
pthread_create(&hilo1,NULL,numero1,&numero_mandar2);
pthread_join(hilo1,(void*)&num_rec2);
pthread_create(&hilo1,NULL,numero1,&numero_mandar3);
pthread_join(hilo1,(void*)&num_rec3);


printf("Hola raiz primer numero %d\n",*num_rec1);
printf("Hola raiz primer numero %d\n",*num_rec2);
printf("Hola raiz primer numero %d\n",*num_rec3);


free(num_rec1);
free(num_rec2);
free(num_rec3);
return 0;
}