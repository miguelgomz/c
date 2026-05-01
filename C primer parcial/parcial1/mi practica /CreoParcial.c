#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    //int status;
    int *puntero =mmap(NULL,sizeof(int)*8,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    for(int i=0;i<8;i++){
    pid_t son=fork();
    if(son<0){
        exit(0);
    }
    

    if (son==0){
        printf("HOLA soy hijo %d\n",getpid());
        for(int j=0;j<100000;j++){ 

            puntero[i]=puntero[i] +1;
        }
            sleep(5);
        printf("He terminado de dar vueltas a mi id %d\n",getpid());
        exit(0);   
            }
        }


        for(int i =0;i<100000;i++){
            wait(NULL);
        }

    for(int i =0;i<8;i++){
    printf("Hola soy el padre y estos son las vueltas que dio cada hijo mi id %d\n y mis vueltas %d\n",getpid(),puntero[i]);
    }

    int total_vueltas_hijo=0;
    for(int i =0;i<8;i++){
        total_vueltas_hijo=total_vueltas_hijo+puntero[i];
    }
     printf("Hola soy el padre este es el total de vueltas  %d\n",total_vueltas_hijo);
    
    exit(0);
    
}

