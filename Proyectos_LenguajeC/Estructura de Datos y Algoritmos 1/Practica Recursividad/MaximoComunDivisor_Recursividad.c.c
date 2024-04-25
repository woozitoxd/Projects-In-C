#include <stdio.h>

int MCD_numeros(int, int);

int main()
{
    int numero, num;

    printf(" Ingresar Primer Numero: ");
    scanf("%d", &numero);

    printf("\n Ingresar segundo numero: ");
    scanf("%d", &num);
    fflush(stdin);

    printf(" El maximo comun divisor es: %d", MCD_numeros(numero, num));
}

int MCD_numeros(int A, int B)
{
    if (  B == 0){
        return A;
    }else{
        return MCD_numeros(B, A%B);
     }
}
