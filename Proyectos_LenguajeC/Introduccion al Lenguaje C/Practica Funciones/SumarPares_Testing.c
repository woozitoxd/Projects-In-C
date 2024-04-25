#include <stdio.h>

int test();
int sumar_par();


void main()
{
    test();
  /*  int num1, num2, total;

    printf("\nIngrese primer numero: ");
    scanf("%d", &num1);
    fflush(stdin);
    printf("\nIngrese segundo numero: ");
    scanf("%d", &num2);
    fflush(stdin);

    sumar_par(num1, num2);*/
}


int sumar_par(int a, int b)
{
    int total;
    int flag=a, suma=0;

    if(a>b){
        a=b;
        b=flag;
    }
    while( a<=b ){
        if( a%2 == 0){
            suma=suma+a;
        }
        a++;
    }

    return suma;
}

int test()
{
    int A=4, B=11;

    if (sumar_par(A, B) == 28){
            printf("Test 1 Funciona: ");
    }else{
        printf("\nTest fallo en prueba 1");
        }

///////////////////////////////////////////////////////////////////

    A= 11, B= 5;
    if (sumar_par(A, B) == 24){
        printf("\nTest 2 Funciona: ");

    }else{
        printf("\nTest fallo en 2.");}

/////////////////////////////////////////////////////////////

    A= 5, B=5;
    if (sumar_par(A, B) == 0){
        printf("\nTest 3 Funciona: ");

    }else{
        printf("\nTest fallo en 3.");}

  ///////////////////////////////////////////////////////////////////////////

    A=2, B=2;
    if (sumar_par(A, B) == 2){
            printf("\nTest 4 Funciona: ");

    }else{
        printf("\nTest fallo en 4.");}

///////////////////////////////////////////////////////////

    A=-11, B=-4;
    if (sumar_par(A, B) == -28){
        printf("\nTest 5 Funciona: ");

    }else{
        printf("\nTest fallo en 5.");}

//////////////////////////////////////////////////////////////////////////////////////////

    A=-11, B=-5;
    if (sumar_par(A, B)== -24){
        printf("\nTest 6 Funciona: ");
    }else{
        printf("\nTest fallo en 6.");
        }


////////////////////////////////////////////////////////////////////////////////////
    return 0;
}


