#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
     
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
   
   exit(i);
   }
}

int esperar_hijos_i;//esta esperara los valores de i 
int guardar_exits[10];
for(int i =0;i<10;i++){
//Recuerda el wifexit es un true false el wexitstaus es para agarra el valor del exit
pid_t verificar_hijos=wait(&esperar_hijos_i);
if(WIFEXITED(esperar_hijos_i)){
    printf("Los hijos nacieron bien %d\n",getpid());
    int pasra_bist_a_numeros=WEXITSTATUS(esperar_hijos_i);
    guardar_exits[i]=pasra_bist_a_numeros;
    

}else{
    printf("Tus hijos salieron mal %d\n",getpid());
}
}

 for(int i =0;i<10;i++){
    printf("Las i de cada uno de mis hijos %d\n",guardar_exits[i]);
 }

  for(int i =0;i<10;i++){
    printf("Las vueltas totales  %d\n",*puntero);
 }
 int vueltas_esperadaas=15000-*puntero;

 printf("Las vueltas totales  %d\n",vueltas_esperadaas);
}


  