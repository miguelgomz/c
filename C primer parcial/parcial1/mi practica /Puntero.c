#include <stdio.h>

int main (){

int caja_fuerte=500;
int *gps;

gps=&caja_fuerte;

printf("Valor caja fuerte %d",caja_fuerte);
printf("Dirrecion d memoria de caja fuerte %p",gps);


*gps=1;

printf("Ahora la caja fuerte vale %d",caja_fuerte);
return 0;

}