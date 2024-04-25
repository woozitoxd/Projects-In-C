#include <stdio.h>
#include <math.h>

// Definicion de la funcion de la funcion matematica a evaluar
double funcion(float x)
{
	return x*x*x*x*x+x-2;
}

int main()
{
	/* ---------------------------------- */
	int n, i;
	float a, b;
	double fa, fx, fb, dx, area;
	/* ---------------------------------- */
	
	printf("Ingresa el valor del limite inferior\n");
	scanf("%f", &a);

	printf("Ingresa el valor del limite superior\n");
	scanf("%f", &b);
	
	printf("Ingresa el numero de particiones\n");
	scanf("%d", &n);
/*
	fx = 0.0;
	fa = funcion(a);
	fb = funcion(b);
	dx = (b - a)/(float)n;

	for (i = a; i < b; i += dx)
	{
		fx += funcion(i);
	}
			
	area = (fx + (fa + fb) / 2) * dx;2
*/
////////////
    double ancho_intervalos, suma=0;
    double puntos_en_x[n+1],puntos_en_y[n+1];
    ancho_intervalos =(a - b)/n;
    for (i=0; i<=n; i++)
    {
        //se evalúa x0,...xn e y0,...yn
        puntos_en_x[i]=a+i*ancho_intervalos;
        puntos_en_y[i]=f(puntos_en_x[i]);
    }
    for (i=1; i<n; i++)          //se evalúa sin los extremos ancho*(y1+...+yn-1)
    {
        suma=suma+ancho_intervalos *puntos_en_y[i];
    }
    printf("%f", area);
}