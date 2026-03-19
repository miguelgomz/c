#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pipe_p_h[2]; // Pipe Padre a Hijo
    int pipe_h_p[2]; // Pipe Hijo a Padre
    char buffer[100];
    pid_t pid;

    // Creamos las dos tuberías
    if (pipe(pipe_p_h) == -1 || pipe(pipe_h_p) == -1) {
        perror("Error en pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Error en fork");
        exit(1);
    }

    if (pid > 0) { 
        // --- PROCESO PADRE ---
        close(pipe_p_h[0]); // Cierra lectura del primer pipe
        close(pipe_h_p[1]); // Cierra escritura del segundo pipe

        printf("Padre: Introduce una cadena (máx 100): ");
        fgets(buffer, 100, stdin);
        
        // Enviamos la cadena al hijo
        write(pipe_p_h[1], buffer, strlen(buffer) + 1);

        // Esperamos la respuesta del hijo
        int num_vocales;
        read(pipe_h_p[0], &num_vocales, sizeof(int));

        printf("Padre: El hijo dice que hay %d vocales.\n", num_vocales);

        close(pipe_p_h[1]);
        close(pipe_h_p[0]);
    } 
    else { 
        // --- PROCESO HIJO ---
        close(pipe_p_h[1]); // Cierra escritura del primer pipe
        close(pipe_h_p[0]); // Cierra lectura del segundo pipe

        // Leemos la cadena enviada por el padre
        read(pipe_p_h[0], buffer, 100);

        int contador = 0;
        for (int i = 0; buffer[i] != '\0'; i++) {
            char c = loflower(buffer[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                contador++;
            }
        }

        // Enviamos el resultado al padre
        write(pipe_h_p[1], &contador, sizeof(int));

        close(pipe_p_h[0]);
        close(pipe_h_p[1]);
        exit(0);
    }

    return 0;
}