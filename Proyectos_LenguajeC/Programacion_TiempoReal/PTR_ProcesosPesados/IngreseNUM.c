#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int potenciaCercana(int base, int numero);

int main() {
    int numero, resultado;
    pid_t pid;
    clock_t inicio, fin;
    double tiempo;

    // acá pido el numero al usuario
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    // con la funcion clock cuento el timepo transcurrido
    inicio = clock();

    // bases de 2, 3, 5, 7
    int bases[4] = {2, 3, 5, 7};
    int num_bases = 4;

    // Crear procesos hijos para calcular las potencias en paralelo
    for (int i = 0; i < num_bases; i++) {
        pid = fork();
        if (pid == 0) {
            // Proceso hijo
            resultado = potenciaCercana(bases[i], numero);
            printf("La potencia de %d mas cercana a %d es: %d\n", bases[i], numero, resultado);
            exit(0); // Salir del proceso hijo
        } else if (pid < 0) {
            // Error al crear el proceso hijo
            printf("Error");
            return 0;
        }
    }

    //  proceso padre
    for (int i = 0; i < num_bases; i++) {
        waitpid(pid, NULL, 0); 
    }

    // tiempo de fin y calcular el tiempo transcurrido
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %.4f segundos\n", tiempo);

    return 0;
}

// esta funcion me sirve para calcular la potencia más cercana a un numero para una base dada
int potenciaCercana(int base, int numero) { //primero recibo por parametro la base y el numero
    int potencia = 1; 
    while (potencia * base <= numero) { //mientras la potencia multiplicada por la base, sea menor o igual al numero ingresado
        potencia *= base;  //la potencia se incrementa multiplicando por la base.
    }
    return potencia; //retorno el valor el valor de la potencia que quedó despues del while
}