#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int contador =0;

void capturar_error(int señal){
    contador++;
    if(contador <3){
printf("Eppaaa lo quieres cerrar eh \n");
    }else{
        printf("Lo conseguiste me cierras \n");
        exit (0);
    }

}

int main(){

    signal(SIGINT, capturar_error);
    printf ("Hola");
    while(1){
        printf("Este programa funciona eternamente \n");
        sleep(1);
    }

    return 0;
}