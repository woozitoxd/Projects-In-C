/*Desarrollar el código C que permita generar un vector de 10 posiciones con los
números 1, 3, 5, 7, 9, 11, 13, 15, 17 y 19 y luego, utilizando un bucle, los muestre en
pantalla al usuario*/

#include <stdio.h>

int main() {
    int vec[10];
    int valor = 1;

    for(int i = 0; i < 10; i++) { //Primer bucle for para llenar el vector con el incremento de 2 por cada posicion, empezando con valor 1 en posicion 1
        vec[i] = valor;
        valor += 2;
    }

    for (int i =0; i< 10; i++){  //Segundo bucle for para mostrar en pantalla las posiciones
        printf("vec [%d]: %d\n", i+1, vec[i]);
    }
    return 0;
}
