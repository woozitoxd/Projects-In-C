#include <stdio.h>

int esPrimo(int n);
void encontrarGemelos(int m, int pareja[]);

int main() {
    int m;
    printf("Ingrese un número entero para encontrar la pareja de números primos gemelos: ");
    scanf("%d", &m);

    int pareja[2] = {0};  // vector para almacenar la pareja de numeros primos gemelos
    encontrarGemelos(m, pareja); //funcion para encontrar los numeros primos gemelos, le paso el numero ingresado y el vector

    if (pareja[0] != 0 && pareja[1] != 0) { //Si los numeros almacenados dentro del vector son distintos de 0, muestro por pantalla:
        printf("La pareja de numeros primos gemelos mas pequeña tal que %d <= p < q es (%d, %d)\n", m, pareja[0], pareja[1]);
    }

    return 0;
}
////////////////////////////////////////////////////////////////////


int esPrimo(int n) { //Funcion para validar de que el numero ingresado sea primo
    if (n <= 1) {
        return 0;  // Retorno 0 (false = no es primo)
    }
    for (int i = 2; i * i <= n; i++) { // bucle for para iterar desde 2 hasta la raíz cuadrada de n. Esto se hace porque si un numero tiene un divisor, este divisor estará en el rango de
                            //[2,raiz.n], por lo que no es necesario verificar más allá de la raíz cuadrada.
        if (n % i == 0) { //Verifico si n es divisible por i, si lo es; no es primo
            return 0;  // Si sus divisores son distintos de 1 y de si mismo, tampoco es primo
        }
    }
    return 1;  // Si unicamente es divisible por 1 y por si mismo, retorno 1 (true)
}

////////////////////////////////////////////////////////////////////


void encontrarGemelos(int m, int pareja[]) {//Funcion para encontrar la pareja, recibe entero m y vector pareja

    int encontrado = 0;
    for (int i = m; ; i++) { //bucle for, se detiene cuando se encuentre la pareja
        if (esPrimo(i) && esPrimo(i + 2)) { //dentro de la condicion, usando la funcion esPrimo, verifico si son primos gemelos
            pareja[0] = i; //La primera posicion la almaceno con el primer numero primo
            pareja[1] = i + 2;  //Segunda posicion la almaceno con el numero primo gemelo del primero
            encontrado = 1;  //encontrado toma valor de 1 (true)
            break; //punto break para salir del bucle for.
        }
    }
    if (!encontrado) {  //Si encontrado se mantiene en 0, significa que no encontre numeros primos, muestro por pantalla:
        printf("No se encontraron números primos gemelos para %d o superiores.\n", m);
    }
}
