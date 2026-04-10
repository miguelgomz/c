#include<stdio.h>
#include <unistd.h>

int numero_mandar_del_padre=50;
int varaible_a_recibir_por_el_hijo=0;

int main(){

//PIPES
int array_tuberias[2];
pipe(array_tuberias);
//PUNTERO
int *gps;
gps=&varaible_a_recibir_por_el_hijo;

    pid_t hijo=fork();


    if (hijo>0){

        printf("Hola soy el padre y el valor a mandar es %d",numero_mandar_del_padre);
        write(array_tuberias[1],&numero_mandar_del_padre, sizeof(int));
        close(array_tuberias[1]);
        
        
    }else if (hijo==0){

        printf("Hola soy el hijo voy a cambiar la variable con el puntero");
        int nuevo_valor;
        read(array_tuberias[0],&nuevo_valor,sizeof(int));

        *gps=nuevo_valor;

        printf("El valor modificado qued %d", varaible_a_recibir_por_el_hijo);
        close(array_tuberias[0]);
    }
    return 0;

}