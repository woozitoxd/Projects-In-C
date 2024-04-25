#include <stdio.h>

int division(int, int);

int main()
{
    int num, numero;

    printf("Ingresar Dividendo: ");
    scanf("%d", &num);
    fflush(stdin);
    printf("Ingresar Divisor: ");
    scanf("%d", &numero);
    fflush(stdin);

    printf("Resultado: %d", division(num, numero));
}

int division(int A, int B)
{
    if( B > A){
        return 0;
    }else{
        return division(A-B, B)+1;
    }
}
