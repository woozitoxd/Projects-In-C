/*Un abuelo animado, pero inexperto con la tecnolog�a, estaba usando una
computadora para pasar a formato digital un libro de matem�ticas. Pero, donde
deb�a escribir 5 elevado a la 4 por 2 elevado al cubo (5^4 * 2^3), escribi� el n�mero
5423 (cinco mil cuatrocientos veintitr�s; no escribi� el 4 ni el 3 como potencia).
Utilice su poder de abstracci�n para realizar un programa que encuentre y devuelva
los cuatro d�gitos (como n�mero entero) que hubieran hecho pasar por
desapercibido el error del abuelo, es decir cuatro d�gitos que produzcan que ambos
modos de escribir el n�mero resulten el mismo n�mero:
Nota: La funci�n no recibe ning�n par�metro.
*/
#include <stdio.h>
#include <math.h>

int main() {
    int numero;
    printf("Ingrese un numero de 4 digitos: ");
    scanf("%d", &numero);

    // obtengo cada digito individualmente
    int X = numero / 1000; 
    int Y = (numero % 1000) / 100; 
    int Z = (numero % 100) / 10;
    int W = numero % 10; 

    // Calcular el resultado de la operaci�n
    int resultado = pow(X, Y) * pow(Z, W);

    printf("El resultado de %d elevado a la %d por %d elevado a la %d es: %d\n", X, Y, Z, W, resultado);

    return 0;
}
