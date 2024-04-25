#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main() {
    int num1 = 0, num2 = 0;
    unsigned long long factorial1 = 1, factorial2 = 1;
    double resultadoPotencia = 0;
    
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &num1);
    printf("Ingrese un segundo numero para calcular su factorial: ");
    scanf("%d", &num2);

    // primero valido que no sea negativo ningun numero
    if ((num1 < 0) || (num2 < 0)) {
        printf("Error: El factorial de un numero negativo no esta definido.\n");
    } else {
        printf("Soy proceso main %d \n",getpid());

        pid_t pid = fork(); // crear un proceso hijo1

        if (pid < 0) { // error
                 printf("Error al crear proceso hijo\n");
                 return 1;
        } else if (pid == 0) { // Proceso hijo
            // calcular factorial del primer número
            for (int i = 1; i <= num1; ++i) {
                factorial1 *= i;
            }
            printf("Soy el proceso hijo %d - El factorial de %d es %llu\n",getpid(), num1, factorial1);
        } else { // Proceso padre
            
            pid_t pid2 = fork(); // crear proceso hijo2
            //waitpid(pid, NULL, 0); 

            if (pid2 < 0) { //error
                printf("Error al crear el segundo proceso hijo 2\n");
                return 1;
            } else if (pid2 == 0) { // proceso hijo 2
                // Calcular factorial del segundo número
                for (int j = 1; j <= num2; ++j) {
                    factorial2 *= j; //en cada iteración, incremento el factorial multiplicando por j
                }
                printf("El factorial de %d es %llu\n", num2, factorial2);
            } else { // proceso padre (otra vez)
                printf("Soy proceso hijo-2 %d, el otro proceso hijo-1 es %d y el proceso main es %d \n", pid2, pid, getpid());
                // espero a que los procesos terminen
                //waitpid(pid, NULL, 0);
                //waitpid(pid2, NULL, 0);
                
                // potencia del primer num elevado al segundo
                resultadoPotencia = pow(num1, num2);
                printf("La potencia de %d elevado a %d es %.2f\n", num1, num2, resultadoPotencia);
                waitpid(pid, NULL, 0);
                waitpid(pid2, NULL, 0);
            }
        }
    }

    return 0;
}