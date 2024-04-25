#include <stdio.h>

// 0 equil�tero
// 1 is�sceles
// 2 escaleno
int determinarTriangulo(int, int, int);
int test();

int main() {
    if (test() == 1)
        printf("Pruebas exitosas\n");
    else
        printf("Pruebas fallidas\n");

    return 0;
}

int determinarTriangulo(int a, int b, int c) {
    if ((a <= 0) || (b <= 0) || (c <= 0))
        return -1; // No es un tri�ngulo o tiene lados negativos

    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
        return -1; // No es un tri�ngulo

    if ((a == b) && (b == c))
        return 0; // Equil�tero
    else if ((a == b) || (b == c) || (a == c))
        return 1; // Is�sceles
    else
        return 2; // Escaleno
}

int test() {
    // Caso de prueba 1: Equil�tero
    int a = 2, b = 2, c = 2;
    if (determinarTriangulo(a, b, c) != 0)
        return 0;

    // Caso de prueba 2: Is�sceles
    a = 2; b = 3; c = 2;
    if (determinarTriangulo(a, b, c) != 1)
        return 0;

    // Caso de prueba 3: Escaleno
    a = 2; b = 3; c = 4;
    if (determinarTriangulo(a, b, c) != 2)
        return 0;

    // Caso de prueba 4: No es un tri�ngulo
    a = -1; b = 0; c = -1;
    if (determinarTriangulo(a, b, c) != -1)
        return 0;

    return 1; // Todas las pruebas fueron exitosas
}
