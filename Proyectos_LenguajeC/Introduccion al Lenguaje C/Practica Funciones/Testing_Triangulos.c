#include <stdio.h>
//0 equilatero
//1 isosceles
//2 escaleno
int determinarTriangulo (int, int, int);
//1,1,1 = 0
//1,2,1 = 1
//1,2,3 = 2
int test();
int
main ()
{
if (test() == 1)
    printf ("Pruebas exitosas");
else
    printf ("Pruebas fallidas");
}
int
determinarTriangulo (int a, int b, int c)
{
  if ((a + b > c) && (a + c > b) && (b + c > a))
    {
      if ((a == b) && (b == c))
	return 1;
      else
	{
	  if ((a == b && b != c) || (b == c && c != a) || (a == c && c != b))
	    return 1;
	  else
	    return 1;
	}
    }
    return -1;
}
int test(){
//caso de prueba 1
int a=2, b=2, c=2;
if (determinarTriangulo(a,b,c) != 0) //equilitero
{
    return 0;
}
//caso de prueba 2
a=2; b=3; c=2;
if (determinarTriangulo(a,b,c) != 1) //isosceles
{
    return 0;
}
//caso de prueba 3
a=2; b=3; c=4;
if (determinarTriangulo(a,b,c) != 2) //escaleno
{
    return 0;
}
//caso de prueba 4
a=-1; b=0; c=-1;
if (determinarTriangulo(a,b,c) != -1) //error o no es un triangulo
{
    return 0;
}
return 1;
}
