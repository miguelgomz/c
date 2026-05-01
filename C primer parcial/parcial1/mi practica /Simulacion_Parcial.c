 #include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
     int guardar_i[10];
   int *puntero =mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
for(int i =0;i<10;i++){
   pid_t son=fork();
  
   if(son<0){
    exit(0);
   }

   if(son==0){
    if(i%2==0){
    printf("Soy el hijo y empezare aprte soy de indice par %d\n",getpid());
    for(int j=0;j<1000;j++){
    *puntero=*puntero+1;

   }
    }else{
    printf("Soy el hijo y empezare aprte soy de indice impar %d\n",getpid());
    for(int j=0;j<2000;j++){
    *puntero=*puntero+1;
   }
    }
   sleep(10);
   printf("Hola soy el hijo y ya acabe mi chamba %d\n y di este num de vueltas %d\n",getpid(),*puntero);
   guardar_i[i]=i;
   exit(guardar_i[i]);
   }
}

  
    int guardar[10];
//Recuerda al esperar con WEXITSTAUS no hace falta el bucel de wait NULL
for(int i =0;i<10;i++){
    wait(&guardar_i[i]);
    guardar[i]=WEXITSTATUS(guardar_i[i]);
    }
    for (int i=0;i<10;i++){
        printf("Hola soy el padre este es el indice de mi hijo %d\n",guardar[i]);
    }
    printf("Total de vueltas%d\n",*puntero);
    int total_esperado=15000-*puntero;
     printf("Total de vueltas esperadas %d\n",total_esperado);

}


