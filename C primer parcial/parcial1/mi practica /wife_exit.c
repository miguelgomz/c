#include <stdio.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/wait.h> 
#include <stdbool.h> 
#include <stdlib.h> 

int main  (){
    int array[5];

    for(int i=0;i<5;i++){

        pid_t pid=fork();
        if(pid<0){
            exit(0);
        }

        if(pid==0){

            

            printf("Soy el hijo %d\n",getpid());

            array[i]=(i+1)*10;

            exit(array[i]);

        }
    }

  int final[5];
  int suma_valores=0;
    for(int i =0;i<5;i++){
    wait(&array[i]);
   final[i] =WEXITSTATUS(array[i]);
    }
    for(int i =0;i<5;i++){
        printf("Los valores %d\n",final[i]);
           suma_valores=suma_valores+final[i];
    }

    printf("Suma de los svalores %d",suma_valores);

}