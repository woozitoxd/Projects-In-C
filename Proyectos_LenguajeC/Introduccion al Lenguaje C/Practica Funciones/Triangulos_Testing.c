#include <stdio.h>

     int triangulos(int a,int b,int c);
     void test();



void main()
 {
     //test(); //Sacar lineas para usar el test.

    int uno;
    int dos;
    int tres;

    printf ("ingrese el primer lado:  ");
    scanf("%d",&uno);
    fflush(stdin);

    printf ("ingrese segundo lado:  ");
    scanf ("%d",&dos);
    fflush(stdin);

    printf ("ingrese el tercer lado:  ");
    scanf("%d",&tres);
    fflush(stdin);

         triangulos(uno,dos,tres);

}

 int triangulos (int A, int B, int C)
  {
            if ( A==B&&A==C )
            {
            printf ("\n El triangulo es EQUILATERO \n");
            return 1;
            }
            if (A!=B&&B!=C&&C!=A)
            {
            printf("\n El triangulo es ESCALENO \n");
            return 2;
            }
            if (A!=B&&B==C||B!=C&&C==A||C!=A&&A==B)
            {
            printf ("\n El triangulo es ISOSCELES \n");
            return 3;
            }

  }

void test()
{
    int a=2,b=2,c=2;
    int aux;

    // Sacar Lineas para probar funcion

        if (triangulos(a,b,c)==1){
        printf("\nPrueba numero 1 funciona\n");
        }else{
            printf("La prueba fallo en equilatero\n");
         }

     a=3;
    if (triangulos(a,b,c)==3)
    {
        printf("\nPrueba Numero 2 Funciona\n");

    }else{ printf("La prueba fallo en isosceles");
         }

    c=4;
    if (triangulos(a,b,c)==2)
    {
        printf("\nPrueba numero 3 Funciona\n\n");

    }else{ printf("La prueba fallo en escaleno\n");
         }
}

