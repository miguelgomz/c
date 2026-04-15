#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>


int main(){

    int *pizarra= mmap(NULL,sizeof(int), PROT_READ | PROT_WRITE , MAP_SHARED| MAP_ANONYMOUS ,-1, 0);
    
    pid_t hijo=fork();

    int numero_por_consola;

    if (hijo>0){

    printf("Escribe un numero por consola de favor ");
    scanf("%d",&numero_por_consola);

     *pizarra=numero_por_consola;

    wait(NULL);
    
    printf("El numero lo veo y vale %d",*pizarra);

    }else if(hijo==0){

        sleep(5);
        printf("Yo soy el hijo y el valor es %d",*pizarra);
        
        *pizarra= *pizarra + 1;

        printf("Soy El hijo y modifique el valor ");
    }
    munmap(pizarra,sizeof(int));
    return 0;

}