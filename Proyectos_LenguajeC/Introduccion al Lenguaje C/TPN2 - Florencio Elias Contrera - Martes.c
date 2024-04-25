// Florencio Elias Contrera
// DNI : 43239945

#include <stdio.h>
#include <string.h>

struct datos
{
    int codigo;
    char descripcion[25];
    int cantidad;
    float precio;
};

//Prototipo de funciones.
void ver_stock();
void programa();

void programa() // Funcion de la operaciones completa.
{
    struct datos tienda[50];
    int contar = 0;
    int aux, i, j;
    int opcion;
    int verificar, stock, retirar_stock;
    int consultar, verificar_cod;
    float total, total_detalle;



    do
    {

        printf ( "\n\n ----- Seleccione una de las siguientes opciones ----- \n\n" );
        printf ( "  1) Ingresar un articulo\n  2) Ingresar mas cantidad de stock\n  3) Retirar cantidad de stock\n  4) Consulta de un articulo\n  5) Ver articulos faltantes de stock\n  6) Resumen del stock valorizado\n  7) Valor detallado de cada producto\n  8) Salir del programa.\n " );
        printf ( "\n OPCION A EJECUTAR: " );
        scanf  ( "%d", &opcion );
        fflush ( stdin );

        switch (opcion) // Aqui es el menu de opciones.
        {
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 1:

                printf ( "\nIngrese la cantidad de articulos que desea registrar ( MAXIMO 50 UNIDADES ): " );
                scanf  ( "%d", &aux );
                fflush ( stdin );



                for ( i = 0; i < aux && aux <= 50 && aux != 0 ; i++ )  // PEDIDO DE DATOS
                {
                    printf ( "\nProducto Nro %d | Ingrese codigo del producto: ", i + 1 );
                    fflush ( stdin );
                    scanf  ( "%d", &verificar_cod );
                    fflush ( stdin );

                    ////////////////////////// VALIDACION DEL CODIGO INGRESADO.

                        while ( verificar_cod < 1000 || verificar_cod > 9999 )
                        {
                            printf ( "\nERROR! Ingrese codigo valido de 4 digitos: ");
                            fflush ( stdin );
                            scanf  ( "%d", &verificar_cod );
                            fflush ( stdin );
                        }

                    for ( j=0; j<50; j++ ) // El for recorre los 50 espacios del vector donde se guardan los codigos.
                    {
                    //VALIDACION DE EXISTENCIA DEL CODIGO

                        while ( verificar_cod == tienda[j].codigo || verificar_cod <1000 || verificar_cod > 9999 )
                        {
                            fflush ( stdin );
                            printf ( "\nERROR! El codigo ya existe/Error de digitos. Ingrese codigo valido: " );
                            scanf  ( "%d", &verificar_cod );
                            fflush ( stdin );

                            j = -1; // J vale 1 negativo para de esta forma el vector comience de 0 y pueda validar bien los ingresos.
                        }
                    }
                    tienda[i].codigo = verificar_cod;

                    /////////////////////// Pedido de datos.

                    printf ( "\nDescripcion (nombre) del articulo: " );
                    fflush ( stdin );
                    fgets  ( tienda[contar].descripcion,sizeof(tienda[contar].descripcion),stdin );
                    fflush ( stdin );

                    printf ( "\nIngrese la cantidad de stock del articulo: " );
                    fflush ( stdin );
                    scanf  ( "%d", &tienda[contar].cantidad );
                    fflush ( stdin );

                    printf ( "\nIngrese el precio por unidad del articulo: " );
                    fflush ( stdin );
                    scanf  ( "%f", &tienda[contar].precio );
                    fflush ( stdin );

                    while ( tienda[contar].precio < 0 )
                    {
                        printf ( "\n Error de precio. Ingrese uno valido NO MENOR QUE 0 :" );
                        scanf  ( "%f", &tienda[contar].precio );
                        fflush ( stdin );
                    }

                    contar++;

                }

                for ( i=0; i<contar; i++) //Muestro de datos por pantalla. Se utiliza for para que no arroje basura.
                {
                    printf ( "\n============================================================="                   );
                    printf ( "\n [ ARTICULO NRO %d ] = CANTIDAD DISPONIBLE: %d",   i+ 1 ,  tienda[i].cantidad    );
                    printf ( "\n [ ARTICULO NRO %d ] = PRECIO DEL ARTICULO: %.2f", i+ 1 ,  tienda[i].precio      );
                    printf ( "\n [ ARTICULO NRO %d ] = CODIGO DEL ARTICULO: %d",   i+ 1 ,  tienda[i].codigo      );
                    printf ( "\n [ ARTICULO NRO %d ] = NOMBRE DEL ARTICULO: %s ",  i+ 1 ,  tienda[i].descripcion );
                    printf ( "=============================================================\n"                   );
                }

                break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            case 2:

                    printf  ( "\nIngrese el codigo de un articulo: " );
                    fflush  ( stdin );
                    scanf   ( "%d", &verificar );
                    fflush  ( stdin );


            for ( i=0; i<contar; i++ )
            {

                if ( verificar != tienda[i].codigo){ // Validacion del codigo inexistente.
                printf ( "\n CODIGO INEXISTENTE. Volviendo al menu.. \n");
                }

                    if ( tienda[i].codigo == verificar ) // Validacion de existencia del codigo.
                    {
                        printf ( "\n Articulo disponible! Cuanto stock desea ingresar? [ACTUAL: %d]: ", tienda[i].cantidad );
                        fflush ( stdin );
                        scanf  ( "%d", &stock );
                        fflush ( stdin );

                            while (  stock <= 0 ) // Si stock es negativo o 0, saldra error.
                            {
                                printf ( "\nINGRESO ERRONEO! Ingrese cantidad mayor a 0: " );
                                fflush ( stdin );
                                scanf  ( "%d", &stock );
                                fflush ( stdin );
                            }

                        tienda[i].cantidad = stock + tienda[i].cantidad; // Al stock del articulo seleccionado le sumo la cantidad que se ingreso.

                        printf ( "\n TOTAL DE STOCK ACTUAL ES DE: %d \n", tienda[i].cantidad );
                    }
            }


                 break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

             case 3:

                    printf ( "\nIngrese el codigo de un articulo: " );
                    fflush ( stdin );
                    scanf  ( "%d", &verificar );
                    fflush ( stdin );

            for ( i = 0; i < contar; i++ )
            {
                if ( verificar != tienda[i].codigo)
                {
                printf("\n CODIGO INEXISTENTE. Volviendo al menu.. \n");
                }
                    if ( verificar == tienda[i].codigo ) //Validacion de existencia
                    {
                        printf ( "\n Articulo disponible! Cuanto stock desea retirar? [ACTUAL %d]: ", tienda[i].cantidad );
                        fflush ( stdin );
                        scanf  ( "%d", &retirar_stock );
                        fflush ( stdin );

                        while ( (retirar_stock <= 0) || (retirar_stock > tienda[i].cantidad) ) //Validacion rango.
                        {
                            printf ( "\n LA CANTIDAD INGRESADA NO ESTA DISPONIBLE. Ingrese una cantidad valida: " );
                            fflush ( stdin );
                            scanf  ( "%d", &retirar_stock );
                            fflush ( stdin );
                        }
                                tienda[i].cantidad = tienda[i].cantidad -  retirar_stock ; // Se le restara a la cantidad disponible del articulo lo que se haya ingresado.
                                printf ( "\n TOTAL DE STOCK ACTUAL ES %d \n", tienda[i].cantidad );

                    }
            }

            break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             case 4:
            printf ( "Ingrese el codigo del articulo: " );
            fflush ( stdin );
            scanf  ( "%d", &consultar );
            fflush ( stdin );

       for (i=0 ; i<contar ; i++)
        {
            if ( consultar != tienda[i].codigo){ // Validacion del codigo.
            printf("\n CODIGO INEXISTENTE! Volviendo al menu.. \n");
            }

                if (consultar == tienda[i].codigo) // Muestro por pantalla los datos del articulo consultado.
                {
                    printf ( "\n CODIGO DISPONIBLE! Mostrando datos... \n" );
                    printf ( "\n///////////////////////////////////////////////////////");
                    printf ( "\n STOCK DISPONIBLE DEL ARTICULO CONSULTADO: %d", tienda[i].cantidad);
                    printf ( "\n NOMBRE DEL ARTICULO CONSULTADO: %s " ,         tienda[i].descripcion);
                    printf ( "   PRECIO DEL ARTICULO CONSULTADO: %.2f ",        tienda[i].precio);
                    printf ( "\n CODIGO DEL ARTICULO CONSULTADO: %d ",          tienda[i].codigo);
                    printf ( "\n///////////////////////////////////////////////////////\n");
                }
        }

                 break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case 5:

                    for (  i = 0; i<1 ; i++) // For utilizado para el correcto muestreo por pantalla.
                    {
                        if ( tienda[i].cantidad == 0 )
                        {
                            printf ( "\n ------ LOS ARTICULOS SIN STOCK SON LOS SIGUIENTES.. ------ \n" );
                            printf ( "\n ================================================= \n" );
                            printf ( " NOMBRE: %s ",     tienda[i].descripcion );
                            printf ( "CODIGO: %d ",      tienda[i].codigo );
                            printf ( "\n PRECIO: %.2f ", tienda[i].precio );
                            printf ( "\n ================================================= \n" );
                        } else
                          {
                            ver_stock();
                          }
                    }
                 break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

             case 6:

                 printf ( "\n ==== RESUMEN DEL IMPORTE TOTAL DE TODOS LOS ARTICULOS CON STOCK ==== \n" );

                 for (  i = 0; i<contar ; i++)
                 {
                     if ( tienda[i].cantidad > 0 )
                     {
                         total = total + tienda[i].cantidad * tienda[i].precio; //Se realiza la suma del total con la multiplicacion de la cantidad de stock por su valor (precio).
                     }
                 }
                    printf ( "\n La suma de todo el stock de la empresa es: [%.2f] \n", total);

                 break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

             case 7:

                 for (  i = 0; i<contar ; i++ )
                 {
                     if ( tienda[i].cantidad > 0 )
                     {
                         total_detalle = tienda[i].cantidad * tienda[i].precio; // Se multiplica el valor de cada producto por su cantidad de stock.
                     }

                     printf ( "\n ------- DATOS DEL ARTICULO NUMERO [%d] ------- \n", i+1               );
                     printf ( "\n===========================================\n"                         );
                     printf ( "\n NOMBRE DEL ARTICULO: [%s] ",                   tienda[i].descripcion  );
                     printf ( " CODIGO DEL ARTICULO: [%d] \n",                   tienda[i].codigo       );
                     printf ( "\n EL TOTAL DEL VALOR DETALLADO ES: [%.2f] \n",   total_detalle          );
                     printf ( "=============================================\n"                         );
                 }

                 break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 8:

                fflush(stdin);
                printf("\n Saliendo del programa! \n");
                break;

            default:
                fflush ( stdin );
                printf ( "\n=============================================================\n");
                printf ( "\n Opcion Incorrecta! \n"                                         );
                printf ( "\n=============================================================\n");
                fflush ( stdin );
        }
    }while ( opcion != 8 ); // Si ingresa la opcion 8 se saldra de la operacion entera y volvera a preguntar si quiere iniciarlo nuevamente o terminarlo.

    printf ("\n ------ EL TOTAL DE LOS PRODUCTOS QUE INGRESARON ES: %d ------ \n", contar);
}

void ver_stock()
{
    printf ("\n NO HAY ARTICULOS FALTANTES DE STOCK! Volviendo al menu.. \n");
}

int main() // El main llama a la funcion que ejecuta las operaciones.
{
    int opcion;

    do{

    printf ( "\n\n EMPRESA AUTOMOVILISTICA REQUIERE CONTROLAR STOCK! \n");          //
    printf ( "\n == DESEA INICIAR EL PROGRAMA? === [ Ingrese 1 para iniciar | Ingrese 0 para terminar ]: ");
    scanf  ( "%d", &opcion );
    fflush ( stdin);

            if ( opcion==1 )
            {
            programa();
            }

    }while( opcion != 0 );
}

// Todas las variables auxiliares se utilizan para el correcto funcionamiento del programa.
// Todos los for utilizados fueron utilizados para el correcto muestreo por pantalla del programa.
