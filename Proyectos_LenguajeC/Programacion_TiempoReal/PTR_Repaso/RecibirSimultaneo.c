#include <stdio.h>
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
        resultadoPotencia = pow(num1, num2);

        // calculo el factorial
        for (int i = 1; i <= num1; ++i) {
            factorial1 *= i;
        }
        for (int j = 1; j <= num2; ++j) {
            factorial2 *= j;
        }

        printf("El factorial de %d es %llu, el factorial de %d es %llu\n", num1, factorial1, num2, factorial2);
        printf("La potencia de %d elevado a %d es %.2f\n", num1, num2, resultadoPotencia);
    }

    return 0;
}
