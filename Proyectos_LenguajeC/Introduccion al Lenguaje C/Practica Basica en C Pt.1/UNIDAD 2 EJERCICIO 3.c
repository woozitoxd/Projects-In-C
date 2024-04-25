#include <stdio.h>

int main()

{
    char letra;
    printf("\ningrese una letra: ");   // Ingresar un caracter para determinar un valor
    printf("Valor de letra: ", letra=getchar());
    printf("%d\n", letra);
    printf("Division de valor ASCII de letra por 3 = %d\n", letra/3);  //Dividiendo el valor de un caracter por 3
    return 0;

}


