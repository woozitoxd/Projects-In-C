// Florencio Elias Contrera - 43.239.945

#include <stdio.h>

void menu();
void sumar_iva();
void promedio_num();
void par_o_impar();
void detectar_caract();
void calcular_pot();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    menu();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sumar_iva()
{
    int importe, descuento, IVA=21;
    float total, precio, aux;

    printf ( "Ingrese el valor de su importe: " );
    scanf  ( "%d", &importe );
    fflush ( stdin );

    printf ( "Ingrese un porcentaje de descuento: " );
    scanf  ( "%d", &descuento );
    fflush ( stdin );

    //Aca se realiza la operacion del descuento y luego sumar el precio del IVA (21 porciento).

   descuento  =   ( importe * descuento )/100;

   aux        =   ( importe * IVA )/100;

   precio     =     importe - descuento;

   total      =      precio + aux;

    printf  ( "El precio con descuento es de: %.2f  sumado al IVA el precio a pagar es de: %.2f \n", precio, total ); //Muestro por pantalla los valores finales.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void promedio_num() // - Ingresar una serie indeterminada de números enteros e indicar su promedio y ademas calcular el maximo y el minimo de los numeros ingresados
{
    int num, minimo, maximo, total_numeros=0;
    float acumular=0;

    printf ( "\n Ingrese un numero entero || Negativo para finalizar: " );
    scanf  ( "%d", &num );

    while  ( num>0 )
        {
        if(total_numeros==0) // Si el total de numeros es 0, lo que se hace es igualar el valor de minimo y maximo al numero ingresado.
            {
            minimo=num;
            maximo=num;
            }

    total_numeros++ ; // Aqui incremento el valor de todos los numeros.

    if  ( num<minimo )    { minimo=num; }
    if  ( num>maximo )    { maximo=num; }

    acumular += num;

    printf ( "Ingresar un numero entero || Negativo para finalizar: " );
    scanf  ( "%d", &num );

        }

    if(total_numeros>0)
        { //Una vez aqui, no solo voy a mostrar el promedio, sino tambien mostrare el numero maximo ingresado y el minimo.

        printf ( "============================================================= \n" );

        printf ( "El numero max: %d y el min es: %d \n", maximo, minimo );

        printf ( "El promedio de los numeros es: %.2f \n", acumular/total_numeros );

        }else
    {
    printf ( " No se ingresaron numeros. \n" );
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void par_o_impar()
    {
        int numero;

       while ( numero!=0 ) // El bucle se ejecutara infinitas veces hasta que el usuario ingrese un 0.
        {

        printf ( "\nIngrese un numero para determinar si es par o impar || 0 para terminar: " );
        scanf  ( "%d", &numero );
        fflush ( stdin );

        if ( numero % 2 == 0 ) //Si numero ingresado es divisible entre 2 y es igual a 0, entonces es par, sino impar.

            {
            printf ( "=== El numero ingresado es par === " );
            }else
            {
            printf ( "=== El numero ingresado es impar === " );
            }

        if ( numero==0 )
            {
            printf ( "\n == Programa terminado == " );
            }
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void detectar_caract()
    {
        unsigned char caract;

        printf ( "Ingrese un caracter del teclado: \n");
        fflush ( stdin);
        scanf  ( "%c", &caract);
        fflush ( stdin);


        if ( caract == 'a' || caract == 'e' || caract == 'i' || caract == 'o' || caract == 'u' || //SI se ingresa alguna de estas letras, es una vocal.
             caract == 'A' || caract == 'E' || caract == 'I' || caract == 'O' || caract == 'U' )
            {
                printf("El caracter ingresado es una VOCAL. \n");
            }

        else if
           ( caract == 'b' || caract == 'c' || caract == 'd' || caract == 'f' || caract == 'g' || caract ==  'h' || caract == 'j' || //Si se ingresa cualquiera de estas
             caract == 'k' || caract == 'l' || caract == 'm' || caract == 'n' || caract == 'p' || caract == 'q'  || caract == 'r' || // letras del abecedario, entonces
             caract == 's' || caract == 't' || caract == 'v' || caract == 'w' || caract == 'x' || caract == 'y'  || caract == 'z' || // es una consonante.
             caract == 'B' || caract == 'C' || caract == 'D' || caract == 'F' || caract == 'G' || caract ==  'H' || caract == 'J' ||
             caract == 'K' || caract == 'L' || caract == 'M' || caract == 'N' || caract == 'P' || caract == 'Q'  || caract == 'R' ||
             caract == 'S' || caract == 'T' || caract == 'V' || caract == 'W' || caract == 'X' || caract == 'Y'  || caract == 'Z' )
            {
                printf ( "El caracter ingresado es una CONSONANTE.\n");
            }
        else if ( caract >= '0' && caract <= '9' )      // Si el caracter ingresado es menor o igual a 0 y mayor o igual a 9, entonces es un numero.
            {
                printf ( "El caracter es un NUMERO. \n");
            }
        else{
                printf ( "El caracter pertenece al grupo de OTROS. \n");  // Si no es ninguna de las anteriores, simplemente es OTRO.
            }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void calcular_pot()
        {
            int   exp, base, resultado=1, i;
            fflush(stdin);
            printf ( " Ingrese la base: " );
            scanf  ( "%d", &base );
            fflush ( stdin );

            printf ( " Ingrese el exponente: " );
            scanf  ( "%d", &exp );
            fflush ( stdin);

          for( i= 1; i<= exp; i++ )       // En esta parte, si el exponente es menor o igual a i, entonces se incrementa el valor de I..
                                         // de esta forma se incrementara el valor de I por la cantidad de veces que se pida con el exponente.
          {
            resultado = resultado * base; //Aqui lo que se realiza es la multiplicacion de la base por si misma segun la cantidad de veces que se pidio con el exponente en el for.
          }

          printf   ( "Ingresando %d como base y %d como exponente, el resultado es: %d", base, exp, resultado );

        }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void menu()
{
    int aux;

     do
    {
   printf ( "\n== Seleccione una opcion que desee ejecutar: ==\n" );
    printf ( " \n1- Determinar precio sumando el IVA.\n2- Indicar promedio de los numeros. \n3- Determinar si el numero es par o impar. \n4- Detectar el caracter. \n5- Calcular potencia. \n"   );
    printf ( "6- Finalizar el programa.\n"   );
    printf ( "Seleccione una opcion: "   );
    scanf  (  "%d", &aux  ); //
    printf ( "============================================================= \n"   );



        switch(aux)  //Aqui es el menu de opciones, dependiendo que opcion elija, se llamara a la funcion para ejecutarla.
        {
    case 1:
        sumar_iva();
        break;

    case 2:
        promedio_num();
        break;

    case 3:
        par_o_impar();
        break;

    case 4:
        detectar_caract();
        break;

    case 5:
        fflush(stdin);
        calcular_pot();
        break;

    case 6:
        printf ( "\n Muchisimas gracias por utilizar mi programa. Adios! \n" );
        break;

    default:
        fflush(stdin);
        printf ( " Opcion Incorrecta! " );
        }

    }while( aux!=6 );

        printf ( "\n ========= Fin del programa. Saludos cordiales. ========= \n" );
}

// Todas las variables AUX utilizadas son varialbes auxiliares para ayudar a ejectuar el codigo.+
