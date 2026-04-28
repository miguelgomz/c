#include <stdio.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/wait.h> 
#include <stdbool.h> 
#include <stdlib.h> 

//Aqui los hijos estaran vivos a la vez 
int main (){
  
    for(int i=0;i<6;i++){
        pid_t hijos=fork();
        if(hijos<0){
            exit(0);
        }

        if(hijos==0){
    

            printf("Hola soy el hijo %d\n",getpid());
            sleep(6);

             printf("Soy el hijo me desperte y a morir %d\n",getpid());
            exit(0);

        }
         
    }


    for(int i=0;i<6;i++){
        wait(NULL);
    }
    printf("Ya debieron acabr todos");
  
            
        }
    

