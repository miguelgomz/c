#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
   int *puntero =mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
for(int i =0;i<8;i++){
   pid_t son=fork();
   if(son<0){
    exit(0);
   }

   if(son==0){
    printf("Soy el hijo y empezare %d\n",getpid());
    
   for(int j=0;j<100000;j++){
    *puntero=*puntero+1;
   }
   sleep(8);
   printf("Hola soy el hijo y ya acabe mi chamba %d\n y di este num de vueltas %d",getpid(),*puntero);

   exit(0);
   }
}


    for (int i=0;i<8;i++){
        wait(NULL);
}

int total=0;
total=*puntero;

printf("Hola soy el padre y esto es el total de vueltas%d\n",total);
int total_esperadndo=0;
total_esperadndo=800000-total;
printf("Vultas restantes por solo haber dado un espacio en el mmap%d",total_esperadndo);


}