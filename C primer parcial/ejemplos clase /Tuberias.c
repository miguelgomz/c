#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    // 1. Creamos la tubería antes del fork
    if (pipe(fd) == -1) {
        perror("Error al crear pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Error al crear el hijo");
        return 1;
    }

    if (pid == 0) {
        // --- PROCESO HIJO ---
        int num1, num2, suma;

        close(fd[1]); // El hijo solo va a leer, cerramos escritura

        // El hijo se queda bloqueado en read() esperando al padre
        read(fd[0], &num1, sizeof(int));
        read(fd[0], &num2, sizeof(int));

        suma = num1 + num2;
        printf("\n[Hijo] Recibí %d y %d. La suma es: %d\n", num1, num2, suma);

        close(fd[0]);
        exit(0); // El hijo termina aquí

    } else {
        // --- PROCESO PADRE ---
        int n1, n2;

        close(fd[0]); // El padre solo va a escribir, cerramos lectura

        printf("[Padre] Introduce el primer número: ");
        scanf("%d", &n1);
        write(fd[1], &n1, sizeof(int));

        printf("[Padre] Introduce el segundo número: ");
        scanf("%d", &n2);
        write(fd[1], &n2, sizeof(int));

        close(fd[1]);

        // Esperamos a que el hijo termine para que el padre sea el último
        wait(NULL);
        printf("[Padre] Mi hijo ha terminado. Ahora cierro yo.\n");
    }

    return 0;
}