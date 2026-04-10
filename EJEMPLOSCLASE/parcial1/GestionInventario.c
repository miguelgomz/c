#include <stdio.h>

int main(){

int tipos_productos_hoy;
 
 printf("Dime cuantos tipos de productos llegaron hoy ");
 scanf("%d" , &tipos_productos_hoy);

 int array_objetos[tipos_productos_hoy];

printf("Y cauntos llegaron de cada producto  %d",tipos_productos_hoy);
 for(int i =0;i<tipos_productos_hoy;i++){
    scanf("%d", &array_objetos[i]);
 
 }
 int precio_unidad[tipos_productos_hoy];

printf("Cuanto cuesta cada producto")
 for (int i=0;i<
 tipos_productos_hoy;i++){
    scanf("%d",precio_unidad[i]);
    
 }


return 0;

}
