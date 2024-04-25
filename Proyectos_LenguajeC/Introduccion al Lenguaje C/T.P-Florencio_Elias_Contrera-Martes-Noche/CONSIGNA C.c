// Florencio Elias Contrera - 43.239.945

#include<stdio.h>
#define ITER 5
#define N 3
int main()
{
    int i, j, valor1=0, valor2=0, valor3=1;
    for(j=0; j<ITER; j++)
    {
        for(i=0; i<N; i++)      //Aqui lo que se realiza son calculos y operaciones para determinar si incrementar o no
            valor1=valor1+i;    // y luego de esa forma se realiza las cuentas sumano, restando y multiplicando las variables.
        for(i=0; i<N; i++)
            valor2=valor2-i;
        for(i=1; i<N; i++)
            valor3=valor3*i;
    }
    if(i==0) //Si el valor de I es igual a 0, entonces
    {        // se dice que J vale 0.
        j=0;
    }else
    {
        i=2+3; //Si no es igual a 0, i pasa a valer 2+3 (5)
    }
    while(i>0)
    {
        j++;                //Innecesario el incremento y decremento de J ya que no se utiliza en la operacion.
        valor2=valor2+1;
        i--;
        valor1=valor2+valor3;
        valor1=valor2+valor3; //Una vez que las variables tomaron valores, se restan y suman entre ellas para llegar a 24, -10 y -44.
        valor3=valor2-valor3;
        j--;
    }


    printf(" %d %d %d %d %d %d %d ", i, j, valor1, valor2, valor3, ITER, N); //Muestro por pantalla los valores en cual quedaron todas las variables.
    return 0;
}

// La finalidad de este programa es incrementar el valor de las variables I y J
// asi de esta forma buscar su objetivo de que las variables VALOR queden en 24, -10 y -44.
//
