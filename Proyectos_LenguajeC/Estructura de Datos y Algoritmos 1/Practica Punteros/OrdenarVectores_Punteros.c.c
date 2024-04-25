/*
Estudiante: Contrera Elias
DNI: 43239945
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM1 500        /* Se definen constantes globales para ahorrar memoria y se utilicen */
#define TAM2 1000       /* globalmente dentro de su funciones segun corresponda */
#define TAM3 2000
#define TAM4 4000


struct registro{
    int indice;
    int vector[4000];
};

void CargarVector500(struct registro * vec500);       //Funciones para cargar los vectores
void CargarVector1000(struct registro * vec1000);
void CargarVector2000(struct registro * vec2000);
void CargarVector4000(struct registro * vec4000);

double OrdenarVECTOR500_B(struct registro * vec500);           /* Funciones con ordenamiento Burbuja*/
double OrdenarVECTOR1000_B(struct registro * vec1000);
double OrdenarVECTOR2000_B(struct registro * vec2000);
double OrdenarVECTOR4000_B(struct registro * vec4000);

double QuickSort500(struct registro * vec500, int, int);        /* Funciones con ordenamiento QuickSort*/
double QuickSort1000(struct registro * vec1000, int, int);
double QuickSort2000(struct registro * vec2000, int, int);
double QuickSort4000(struct registro * vec4000, int, int);


int main()
{
    struct registro * vector;           /* Un unico puntero al struct registro para usar en las funciones*/

    CargarVector500(vector);        /* Llamado a las funciones que cargan los 4 "vectores" de 500, 1000, 2000 y 4000 espacios.*/
    CargarVector1000(vector);
    CargarVector2000(vector);
    CargarVector4000(vector);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CargarVector500(struct registro * vec500)
{
    double segundos_B, segundos_Q; /* variables double para mostrar el valor que se retorna con las funciones de ordenamiento*/

    vec500 = (struct registro*)malloc(TAM1*sizeof(struct registro));        /* Reservo memoria para el vector*/

    if (vec500==NULL)
    {                                                     /*Paso primordial comprobar/verificar si hay memoria disponible en la PC */
        printf("\n\nProblemas reservando memoria...");
        exit (1);
    }else{

        srand(time(NULL));
        for ( int a = 0; a < TAM1; a++){                             /* Cargo 500 elementos con la funcion rand para poder ordenarlo con Burbuja */
            (vec500+a)->indice = rand();
        // printf("Vector 1 para Burbuja - Elemento: [%d] - [%d]\n",a+1, (vec500+a)->indice);
        }

        segundos_B = OrdenarVECTOR500_B(vec500);                      /* Segundos_B toma el valor que devuelve la funcion y ordena los 500 elementos cargados*/




        srand(time(NULL));                                            /* Se vuelven a cargar 500 elementos para ordenar con QuickSort */
        for ( int w = 0; w < TAM1; w++){
            (vec500+w)->indice = rand();
     //    printf("Vector 1 para QuickSort - Elemento: [%d] - [%d]\n",w+1, (vec500+w)->indice);
        }

        segundos_Q = QuickSort500(vec500, 0, 499);                    /*Se le pasa el largo de elementos y el valor que devuelve se guarda en Segundos_Q*/

        for ( int x = 0; x < TAM1; x++){
     //  printf("VECTOR 1 - Ordenado con QuickSort: [%d]\n", (vec500+x)->indice);
        }

        printf("Segundos que tardo en ordenar 500 espacios con Burbuja: %f\n", segundos_B);         /* Se muestra por pantalla el tiempo de medicion de los ordenamientos */
        printf("Segundos que tardo en ordenar 500 espacios con QuickSort: %f\n", segundos_Q);
    }
    free(vec500);                       /* Libero la memoria que reserve con malloc*/
}





double OrdenarVECTOR500_B(struct registro * vec500)
{
    clock_t tiempo_inicio, tiempo_final;                        /* funcion clock para medir el tiempo de ejecucion de esta funcion  */
    double segundos, contador = 0;
    tiempo_inicio = clock();

    int i=1;
    int ordenado=0;
    int aux;
                                                                /*Mientras i sea menor que TAM1 y Ordenado sea igual a 0, se ejecuta*/
        while(i<TAM1 && ordenado==0){
        ordenado=1;

        for(int j=0; j<TAM1-1; j++){
            if((vec500+j)->indice > (vec500+j+1)->indice){      /*Si el elemento en la posicion de J es mayor que la siguiente posicion*/
                ordenado=0;                                     /* ordenado pasa a valer 0*/
                aux = (vec500+j+1)->indice;                     /* "aux" pasa a ser la siguiente posicion (j+1)*/
                (vec500+j+1)->indice = (vec500+j)->indice;      /* se intercambia la posicion con la anterior [j+1] = [j]*/
                (vec500+j)->indice   = aux;                     /* la posicion [j] pasa a ser aux*/
            }
        }
        i++;      /* Se incrementa el valor de i cada vez que se intercambien posiciones, esto para que siga comparando hasta que quede ordenado*/
    }

    for ( int a = 0; a < TAM1; a++){
      // printf("VECTOR 1 - Ordenado con Burbuja: [%d]\n", (vec500+a)->indice);
    } /* Quitar comentario para mostrar el vector ordenado con burbuja */

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC; /* Guarda el tiempo de medicion en segundos dentro de la variable segundos */

    return segundos; /*Retorna la variable segundos */
}




double QuickSort500(struct registro * vec500, int primero, int ultimo)
{
    clock_t tiempo_inicio, tiempo_final;
    double seconds, contador = 0;
    tiempo_inicio = clock();


    int i, j;                                 /* Variables pivote y central para tomar el elemento que se encuentra a la mitad*/
    int pivote, tmp;
    int central;

    central = (primero + ultimo)/ 2;
    pivote = ((vec500+central)->indice) ;    /* el PIVOT es el elemento que esta a la mitad del "vector" */
    i = primero;
    j = ultimo;

    do {
        while ((vec500+i)->indice < pivote) i++;
        while ((vec500+j)->indice > pivote) j--;
        if (i<=j){
             tmp = (vec500+i)->indice;
            (vec500+i)->indice = (vec500+j)->indice;     /*Intercambio la posicion de vec500[i] con vec500[j]*/
            (vec500+j)->indice  = tmp;
            i++;
            j--;
        }
    }while (i <= j);                  /* mientras i sea menorigual a j, el while se ejecuta*/

    if (primero < j)
        QuickSort500(vec500, primero, j); /* Se repite el mismo proceso con la mitad izquierda*/
    if (i < ultimo)
        QuickSort500(vec500, i, ultimo);   /* Se repite el mismo proceso con la mitad derecha*/

    tiempo_final = clock();
    seconds = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;    /* seconds toma el valor del calculo de los segundos */


    return seconds;     /* Se devuelve el valor la variable seconds */
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CargarVector1000(struct registro * vec1000)
{

    double segundos_Q, segundos_B;

    vec1000 = (struct registro*)malloc(TAM2*sizeof(struct registro));

    if (vec1000==NULL)
    {
        printf("\n\nProblemas reservando memoria...");  /*Paso primordial comprobar/verificar si hay memoria disponible en la PC */
        exit (1);
    }else{

        srand(time(NULL));

        for ( int a = 0; a < TAM2; a++){
            (vec1000+a)->indice = rand();
         //   printf("VECTOR 2 para Burbuja - Elemento: [%d] - [%d]\n",a+1, (vec1000+a)->indice);
        }
       segundos_B = OrdenarVECTOR1000_B(vec1000);

        srand(time(NULL));

        for ( int a = 0; a < TAM2; a++){
            (vec1000+a)->indice = rand();
           // printf("VECTOR 2 para QuickSort- Elemento: [%d] - [%d]\n",a+1, (vec1000+a)->indice);
        }

       segundos_Q = QuickSort500(vec1000, 0, 999);     /*Se le pasa el largo de elementos y el valor que devuelve se guarda en Segundos_Q*/
        for ( int q = 0; q < TAM2; q++){
          //  printf("VECTOR 2 - Ordenado con Quicksort: [%d]\n", (vec1000+q)->indice);
        }

        printf("Segundos que tardo en ordenar 1000 espacios con Burbuja: %f\n", segundos_B);
        printf("Segundos que tardo en ordenar 1000 espacios con QuickSort: %f\n", segundos_Q);


    }
    free(vec1000); /* Libero la memoria que se utilizó ppara vec1000 */
}







double OrdenarVECTOR1000_B(struct registro * vec1000)
{
    clock_t tiempo_inicio, tiempo_final;
    double segundos, contador = 0;

    tiempo_inicio = clock();

    int i=1;
    int ordenado=0;
    int aux;

        while(i<TAM2 && ordenado==0){
        ordenado=1;

        for(int j=0; j<TAM2-1; j++){
            if((vec1000+j)->indice > (vec1000+j+1)->indice){     /*Si el elemento en la posicion de J es mayor que la siguiente posicion*/
                ordenado=0;                                     /* ordenado pasa a valer 0*/
                aux = (vec1000+j+1)->indice;                     /* "aux" pasa a ser la siguiente posicion (j+1)*/
                (vec1000+j+1)->indice = (vec1000+j)->indice;      /* se intercambia la posicion con la anterior [j+1] = [j]*/
                (vec1000+j)->indice   = aux;                    /* la posicion [j] pasa a ser aux*/
            }
        }
        i++;
    }

    for ( int a = 0; a < TAM2; a++){
       // printf("VECTOR 2 - Ordenado con Burbuja: [%d]\n", (vec1000+a)->indice);
    }

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;    /* segundos toma el valor del calculo de los segundos */

    return segundos; /* Se devuelve el valor la variable segundos */
}




double QuickSort1000(struct registro * vec1000, int primero, int ultimo)
{

    clock_t tiempo_inicio, tiempo_final;
    double segundos, contador = 0;
    tiempo_inicio = clock();


    int i, j;
    int pivote, tmp;
    int central;

    central = (primero + ultimo)/ 2;
    pivote = ((vec1000+central)->indice) ;
    i = primero;
    j = ultimo;

    do {
        while ((vec1000+i)->indice < pivote) i++;
        while ((vec1000+j)->indice > pivote) j--;
        if (i<=j){
             tmp = (vec1000+i)->indice;
            (vec1000+i)->indice = (vec1000+j)->indice;    /*Intercambio la posicion de vec500[i] con vec500[j]*/
            (vec1000+j)->indice  = tmp;

            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        QuickSort1000(vec1000, primero, j); /* Se repite el mismo proceso con la mitad izquierda*/
    if (i < ultimo)
        QuickSort1000(vec1000, i, ultimo);  /* Se repite el mismo proceso con la mitad derecha*/

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;    /* segundos toma el valor del calculo de los segundos */


    return segundos;     /* Se devuelve el valor la variable segundos */
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CargarVector2000(struct registro * vec2000)
{
    double segundos_B, segundos_Q;


    vec2000 = (struct registro*)malloc(TAM3*sizeof(struct registro));

    if (vec2000==NULL)
    {
        printf("\n\nProblemas reservando memoria...");  /*Paso primordial comprobar/verificar si hay memoria disponible en la PC */
        exit (1);
    }else{

    srand(time(NULL));

        for ( int a = 0; a < TAM3; a++){
            (vec2000+a)->indice = rand();
           // printf("VECTOR 3 para Burbuja - Elemento: [%d] - [%d]\n",a+1, (vec2000+a)->indice);
        }
       segundos_B = OrdenarVECTOR2000_B(vec2000);

        srand(time(NULL));

        for ( int q = 0; q < TAM3; q++){
            (vec2000+q)->indice = rand();
            //printf("VECTOR 3 para QuickSort - Elemento: [%d] - [%d]\n",q+1, (vec2000+q)->indice);
        }

       segundos_Q = QuickSort2000(vec2000, 0, 1999);

        for ( int a = 0; a < TAM2; a++){
            //printf("VECTOR 3 - Ordenado con QuickSort: [%d]\n", (vec2000+a)->indice);
        }

        printf("Segundos que tardo en ordenar 2000 espacios con Burbuja: %f\n", segundos_B);
        printf("Segundos que tardo en ordenar 2000 espacios con QuickSort: %f\n", segundos_Q);

    }
    free(vec2000); /* Libero la memoria que se utilizo para vec2000 */
}





double OrdenarVECTOR2000_B(struct registro * vec2000)
{
    clock_t tiempo_inicio, tiempo_final;
    double segundos, contador = 0;
    tiempo_inicio = clock();

    int i=1;
    int ordenado=0;
    int aux;

        while(i<TAM3 && ordenado==0){
        ordenado=1;

        for(int j=0; j<TAM3-1; j++){
            if((vec2000+j)->indice > (vec2000+j+1)->indice){     /*Si el elemento en la posicion de J es mayor que la siguiente posicion*/
                ordenado=0;                                     /* ordenado pasa a valer 0*/
                aux = (vec2000+j+1)->indice;                     /* "aux" pasa a ser la siguiente posicion (j+1)*/
                (vec2000+j+1)->indice = (vec2000+j)->indice;      /* se intercambia la posicion con la anterior [j+1] = [j]*/
                (vec2000+j)->indice   = aux;                    /* la posicion [j] pasa a ser aux*/
            }
        }
        i++;
    }

    for ( int a = 0; a < TAM3; a++){
      //  printf("VECTOR 3 - Ordenado con Burbuja: [%d]\n", (vec2000+a)->indice);
    }   /*Descomentar para ver el vector" ordenado con burbuja */

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;    /* segundos toma el valor del calculo de los segundos */

    return segundos;  /* Se devuelve el valor la variable segundos */

}





double QuickSort2000(struct registro * vec2000, int primero, int ultimo)
{
    clock_t tiempo_inicio, tiempo_final;
    double segundos, contador = 0;
    tiempo_inicio = clock();

    int i, j;
    int pivote, tmp;
    int central;

    central = (primero + ultimo)/ 2;
    pivote = ((vec2000+central)->indice) ;
    i = primero;
    j = ultimo;

    do {
        while ((vec2000+i)->indice < pivote) i++;
        while ((vec2000+j)->indice > pivote) j--;
        if (i<=j){
             tmp = (vec2000+i)->indice;
            (vec2000+i)->indice = (vec2000+j)->indice;    /*Intercambio la posicion de vec500[i] con vec500[j]*/
            (vec2000+j)->indice  = tmp;

            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        QuickSort2000(vec2000, primero, j); /* Se repite el mismo proceso con la mitad izquierda*/
    if (i < ultimo)
        QuickSort2000(vec2000, i, ultimo);  /* Se repite el mismo proceso con la mitad derecha*/



    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;

    return segundos;  /* Se devuelve el valor la variable segundos */
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CargarVector4000(struct registro * vec4000)
{

    double segundos_B, segundos_Q;

    vec4000 = (struct registro*)malloc(TAM4*sizeof(struct registro));

    if (vec4000==NULL)      /*Paso primordial comprobar/verificar si hay memoria disponible en la PC */
    {
        printf("\n\nProblemas reservando memoria...");
        exit (1);
    }else{

        srand(time(NULL));

        for ( int a = 0; a < TAM4; a++){
            (vec4000+a)->indice = rand();
           // printf("VECTOR 4 para Burbuja - Elemento: [%d] - [%d]\n",a+1, (vec4000+a)->indice);
        }   /*descomentar en caso de desear ver los elementos desordeandos */

       segundos_B = OrdenarVECTOR4000_B(vec4000); /* segundos_B toma el valor retornado de la funcion de ordenamiento con burbuja */


        srand(time(NULL));

        for ( int q = 0; q < TAM4; q++){
            (vec4000+q)->indice = rand();
       //     printf("VECTOR 4 para QuickSort - Elemento: [%d] - [%d]\n",q+1, (vec4000+q)->indice);
        }

       segundos_Q = QuickSort4000(vec4000, 0, 3999); /* segundos_Q toma el valor que devuelve la funcion, a la funcion se le pasa el largo de elementos */

        for ( int a = 0; a < TAM4; a++){
      //  printf("VECTOR 4 - Ordenado con QuickSort: [%d]\n", (vec4000+a)->indice);
        }   /* descomentar en caso de que se desee ver el "vector" ordenado */

        printf("Segundos que tardo en ordenar 4000 espacios con Burbuja: %f\n", segundos_B);  /*Se muestra por pantalla la medicion de tiempo que devolvieron las funciones */
        printf("Segundos que tardo en ordenar 4000 espacios con QuickSort: %f\n", segundos_Q);

    }
    free(vec4000); /* Se libera la memoria que se uso en vec4000*/
}

double OrdenarVECTOR4000_B(struct registro * vec4000)
{
    clock_t tiempo_inicio, tiempo_final;
    double segundos, contador = 0;
    tiempo_inicio = clock();

    int i=1;
    int ordenado=0;
    int aux;

        while(i<TAM4 && ordenado==0){       /* while para ordenar las posiciones*/
        ordenado=1;

        for(int j=0; j<TAM4-1; j++){
            if((vec4000+j)->indice > (vec4000+j+1)->indice){     /*Si el elemento en la posicion de J es mayor que la siguiente posicion*/
                ordenado=0;                                     /* ordenado pasa a valer 0*/
                aux = (vec4000+j+1)->indice;                     /* "aux" pasa a ser la siguiente posicion (j+1)*/
                (vec4000+j+1)->indice = (vec4000+j)->indice;      /* se intercambia la posicion con la anterior [j+1] = [j]*/
                (vec4000+j)->indice   = aux;                    /* la posicion [j] pasa a ser aux*/
            }
        }
        i++;
    }

    for ( int a = 0; a < TAM4; a++){
     //   printf("VECTOR 4 - Ordenado con Burbuja: [%d]\n", (vec4000+a)->indice);
    } /*descomentar si se desea ver el printf*/

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC ;

    return segundos;  /* Se devuelve el valor la variable segundos */

}



double QuickSort4000(struct registro * vec4000, int primero, int ultimo)
{
    clock_t tiempo_inicio, tiempo_final;
    double segundos, contador = 0;
    tiempo_inicio = clock();

    int i, j;
    int pivote, tmp;
    int central;

    central = (primero + ultimo)/ 2;            /*calculo el valor que esta a la mitad */
    pivote = ((vec4000+central)->indice) ;  /* el PIVOT es el elemento que esta a la mitad del "vector" */
    i = primero;
    j = ultimo;

    do {                                            /* Do while para ordenar las posiciones */
        while ((vec4000+i)->indice < pivote) i++;
        while ((vec4000+j)->indice > pivote) j--;
        if (i<=j){
             tmp = (vec4000+i)->indice;
            (vec4000+i)->indice = (vec4000+j)->indice;    /*Intercambio la posicion de vec500[i] con vec500[j]*/
            (vec4000+j)->indice  = tmp;

            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        QuickSort4000(vec4000, primero, j); /* Se repite el mismo proceso con la mitad izquierda*/
    if (i < ultimo)
        QuickSort4000(vec4000, i, ultimo);  /* Se repite el mismo proceso con la mitad derecha*/

    tiempo_final = clock();
    segundos = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;

    return segundos;  /* Se devuelve el valor la variable segundos */
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
