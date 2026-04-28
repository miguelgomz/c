#include <stdio.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/wait.h> 
#include <stdbool.h> 
#include <stdlib.h> 


int main (){
    int contador=0;
    for(int i=0;i<6;i++){

        pid_t hijos=fork();

        if (hijos==0){

            printf("Soy hijo %d",getpid());
            exit(0);
        }
        
        if (hijos>0){
          
            contador++;
            if (contador==6){
                wait(NULL);
                 printf("Soy el padre y mis hijos terminaron  %d",contador);
            }else{

                wait(NULL);
            }
        
           
            
        }

    }
}

    