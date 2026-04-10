#include <stdio.h>

int main(){
    
    int longitud_array;
    int contador_pares=0;
    int contadores=0;
    
    printf("De cuanto va a ser tu array ");
    scanf("%d", &longitud_array);
    
    int numeros_usuario[longitud_array];
    
    printf("Dame los numeros para ver si es par o impar %d\n",longitud_array);
    for(int i=0;i<longitud_array;i++){
    scanf("%d", &numeros_usuario[i]);
}
    //Recorrer el array
    
    for(int i=0;i<longitud_array;i++){
        
        if(numeros_usuario[i]% 2 ==0){
            contador_pares ++;
        }else{
            contadores++;
            }
    }
    
    printf("NUmero dados por el usuario");
    for(int i =0;i<longitud_array;i++){
        
        printf("%d", numeros_usuario[i]);
                
        }
        printf("numeros pares  %d", contador_pares);
            printf("numeros impares  %d", contadores);
        return 0;
    }

        
