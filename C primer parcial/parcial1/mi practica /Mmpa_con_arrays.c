#include <stdio.h>// libreria inicial 
#include <unistd.h>// libreria pipes 
#include <sys/mman.h>// libreria mmap
#include <sys/wait.h>// libreria wait
#include <stdbool.h>// libreria booleano
#include <stdlib.h>//libreria exit

int main(){

     int *pizarron=mmap(NULL,2*sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
     //Duda al pizarron ya tener 2 espacios guardados no tengo que hacer de pizzaron un array dado que ya este le especifique que me almacene 2 posiciones no ?

     int longitud_array=0;
     //par
     int uno_array=0;
     int suma_total_primer_parte_array_par=0;
     int suma_total_segnda_parte_array_par=0;
     int resultado_final_par=0;
     //impar
     int dos_array=0;
     int uno_impar=0;
     int suma_primera_parte_impar=0;
     int suma_segunda_parte_impar=0;
     int resultado_final_impar=0;
    

    //Array
    printf("Dime la longitud de tu array");
    scanf("%d",&longitud_array);

    int array[longitud_array];

    printf("Ingrese los valor del array de %d",longitud_array);
    for(int i =0;i<longitud_array;i++){
        scanf("%d",&array[i]);
         
    }

     bool par_impar=true; 

    if(longitud_array%2==0){
         uno_array=longitud_array/2;
         par_impar=true;

    }else if(longitud_array%2!=0){
        dos_array=longitud_array/3;
        uno_impar=dos_array*2;
        par_impar=false;

    }
   

   pid_t hijo=fork();

    if(hijo>0){

        pizarron[0]=0;
        printf("Soy el padre y sumare la primer parte del array");
        for(int i=0;i<uno_array;i++){
            suma_total_primer_parte_array_par=suma_total_primer_parte_array_par+array[i];
        
        }
        pizarron[0]=suma_total_primer_parte_array_par;
    
            wait(NULL);
             resultado_final_par=pizarron[0]+pizarron[1];
            printf("Resultado suma de todo el array %d",resultado_final_par);

        }else if(hijo==0){
            printf("Yo soy el hijo y sumare los otros 2 valores");
            for(int i =uno_array;i<longitud_array;i++){
                suma_total_segnda_parte_array_par=suma_total_primer_parte_array_par+array[i];
    
            }

         pizarron[1]=suma_total_segnda_parte_array_par;

            printf("Termine la suma soy el hijo");
            exit(0);

        }
        else{

        pizarron[0]=0;
        printf("Soy el padre y sumare los 2 primeros datos del array");
        for(int i=0;i<uno_impar;i++){
            suma_primera_parte_impar=suma_primera_parte_impar+array[i];
        
        }

        pizarron[0]=suma_primera_parte_impar;
    
            wait(NULL);
            resultado_final_impar=pizarron[0]+pizarron[1];
            printf("Resultado suma de todo el array %d",resultado_final_impar);

        }else if(){
            printf("Yo soy el hijo y sumare los otros 2 valores");
            for(int i =uno_impar;i<longitud_array;i++){
                suma_segunda_parte_impar=suma_segunda_parte_impar+array[i];
        
        }
        pizarron[1]=suma_segunda_parte_impar;

            printf("Termine la suma soy el hijo");
            exit(0);

        }

     munmap(pizarron,2*sizeof(int));
     return 0;


}