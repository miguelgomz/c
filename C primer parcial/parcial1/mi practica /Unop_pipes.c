#include <stdio.h>
#include <unistd.h>

int calculo(int n){

	int resultado=n*n;
	
	return resultado;
	}

int main (){

	int array_de_tuberias[2];
	int resultado_cualculo=0;
    int numero_usuario=0;

	pipe(array_de_tuberias);

    pid_t hijo=fork();


	if(hijo>0){

            printf("Ingrese un numero para el calculo \n");
			scanf("%d", &numero_usuario);

            write(array_de_tuberias[1],&numero_usuario,sizeof(int));
			close(array_de_tuberias[1]);
            printf("Ya te pase el numero hijo mio %d\n",numero_usuario);
	

			}else if(hijo==0){
				

                read(array_de_tuberias[0],&numero_usuario,sizeof(int));
				resultado_cualculo=calculo(numero_usuario);

				  printf("Soy el hijo y el resulatodo es %d",resultado_cualculo);
				  close(array_de_tuberias[0]);

                
            }
			 return 0;
	
	}

