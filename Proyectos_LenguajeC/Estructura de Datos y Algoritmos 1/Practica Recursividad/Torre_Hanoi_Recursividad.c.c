#include <stdio.h>
#include <conio.h>

void resolver(int, int, int, int);

int main()
{
    int discos;
    char flag = 'A';
    char aux  = 'B';
    char dou  = 'C';

    printf("Ingresar cantidad de discos a resolver: ");
    scanf("%d", &discos);

    printf("Los movimientos necesarios que hacer son: \n");
    resolver(discos, flag, aux, dou);
}

void resolver(int X, int A, int B, int C)
{
    if ( X == 1){
        printf("%c -> %c", A, C);
    }else{
         resolver(X-1, A, C, B);
         printf("\n%c -> %c \n", A, C);
         resolver(X-1, B, A, C);
    }
}
