#include <stdio.h>
#include <math.h>

int main(void)

{
    char letra;
    printf("\ningrese una letra: ");   // Ingresar un caracter para determinar un valor
    printf("Valor de letra: ", letra=getchar());
    printf("%d\n", letra);

    double potencia = 2;

    double elevado = pow(letra, potencia);

    printf("\nEl valor ASCII de letra elevado a la potencia de %1.f es %6f", potencia, elevado);  //Elevando al cuadrado el valor de un char
    return 0;
}
