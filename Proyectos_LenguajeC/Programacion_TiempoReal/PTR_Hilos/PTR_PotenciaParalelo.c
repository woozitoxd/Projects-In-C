#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>

// Función para calcular la potencia más cercana a un número para una base dada
int potenciaCercana(int base, int numero) {
    int potencia = 1;
    while (potencia * base <= numero) {
        potencia *= base;
    }
    return potencia;
}

// Función que se ejecuta en paralelo para calcular las potencias más cercanas
void *calcularPotencia(void *arg) {
    int *args = (int *)arg;
    int numero = args[0];
    int base = args[1];
    int potencia = potenciaCercana(base, numero);
    printf("La potencia de %d más cercana a %d es: %d\n", base, numero, potencia);

    return NULL;
}

int main() {
    int number;
    printf("Ingrese un número entero: ");
    scanf("%d", &number);

    pthread_t threads[4];
    int bases[4] = {2, 3, 5, 7}; // Bases para calcular las potencias

    // Crear los hilos y calcular las potencias
    for (int i = 0; i < 4; i++) {
        int args[2] = {number, bases[i]}; // Argumentos para cada hilo
        pthread_create(&threads[i], NULL, calcularPotencia, args);
        pthread_join(threads[i], NULL); // Esperar a que cada hilo termine antes de continuar
    }

    return 0;
}