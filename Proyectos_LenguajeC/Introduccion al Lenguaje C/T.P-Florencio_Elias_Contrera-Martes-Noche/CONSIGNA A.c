// Florencio Elias Contrera - 43.239.945

#include <stdio.h>

void main()
{
    int   edad, menores=0, mujeres=0, varones=0, entre=0, total=0, exterior=0, interior=0, sinpermiso=0, flag, aux;
    char  sexo, prov;
    float porcentaje;

    printf     (" ---- COMPANIA DE SEGUROS AUTOMOVILISTICOS QUIERE SACAR PORCENTAJES ---- \n");

    do
    {
        total++;

        printf ( "\nIngrese su sexo -- V varon M mujer -- :  " );
        scanf  ( "%c", &sexo );
        fflush ( stdin );

        if ( sexo == 'm' || sexo == 'M' )  {// Si es MUJER, sumo la variable para mujeres
        mujeres++;
         }   if ( sexo == 'v' || sexo == 'V' ) { // Si es VARON, sumo la variable para varones
            varones++;
            }


        printf ( "\nIngrese su provincia: (0 exterior, 1 interior:  ");
        scanf  ( "%c", &prov);
        fflush ( stdin);


                if ( prov == '0'  ) { // Si el ingreso es 'e' o 'E', el conductor es de otra.
                exterior++;
                 }   if ( prov == '1' ) { // Si el ingreso es 'i' o 'I', el conductor es de la provincia.
                    interior++;
                    }



        printf ( "\nIngrese su edad ||  0 si desea terminar los ingresos : " );
        scanf  ( "%d", &edad );
        fflush ( stdin );

                        if ( edad >= 18 && edad <= 25 ) {  // Si la edad es entre 18 y 25 años, sumo la variable ENTRE
                        entre++;
                         }   if ( edad < 25 && edad != 0 )    {  // Si la edad es menor a 25 años, sumo la variable MENORES
                            menores++;
                             }   if ( edad < 16 && edad > 0 )     {
                                sinpermiso++;
                                }







    }while ( edad!=0 ); // Se termina el bucle si se ingresa la edad de 0.


        printf ( " ============================================================================= \n"        );
        printf ( " -- El total de conductores es de: %d -- \n",   total                                     );
        printf ( " -- El total de conductores  con edad entre 18 y 25 anios es de: %d -- \n",      entre    );
        printf ( " -- El total de conductores menores de 25 anios de edad es de : %d -- \n",       menores  );
        printf ( " -- El total de personas de otra provincia es de: %d -- \n",                     exterior );
        printf ( " -- El total de personas de esta provincia es de: %d -- \n",                     interior );
        printf ( " -- El total de mujeres es de: %d -- \n",                                        mujeres  );
        printf ( " -- El total de varones es de: %d -- \n",                                        varones  );
        printf ( " -- El total de personas menores de 16 anios (no permitido) es de : %d -- \n", sinpermiso );
        printf ( " ============================================================================= \n"        );

    do
    {

    printf ( "\n Seleccione una opcion para saber porcentaje: " );

    printf ( " \n1- Porcentaje de menores de 25 anios. \n2- Porcentaje de Varones. \n3- Porcentaje de mujeres. \n4- Porcentaje de edad entre 18 y 25 anios.  \n" );
    printf ( "5- Finalizar programa. \n" );
    scanf  ( "%d", &aux ); // Aca se pregunta cual porcentaje de conductores quiere saber

    switch( aux )

        {
        printf( " --------------------------------------------------------- \n" ); //En los cases, se realiza la operacion dependiendo que porcentaje se pide.
    case 1:
        porcentaje = ( menores*100 )/total;
        printf  ( " -- El porcentaje de menores de 25 anios de: %.2f -- \n", porcentaje );
        break;

    case 2:
        porcentaje = ( varones*100 )/total;
        printf  ( " -- El porcentaje de varones es de: %.2f -- \n", porcentaje );
        break;

    case 3:
        porcentaje = ( mujeres*100 )/total;
        printf  ( " -- El porcentaje de mujeres es de: %.2f -- \n", porcentaje );
        break;

    case 4:
        porcentaje = (  entre*100  )/total;
        printf  ( " -- El porcentaje de conductores entre 18 y 25 anios es de: %.2f -- \n", porcentaje);
        break;

    case 5:
        printf  ( " Gracias por utilizar este programa. " );
        break;

    default:
        fflush(stdin);
        printf  ( " Opcion Incorrecta! Ingrese una de las opciones correctas. \n" );

        }
    }          while ( aux!=5 );printf   ( "\n===== Saludos!. =====" );
}

// Todas las variables AUX o FLAG utilizadas son varialbes auxiliares para ayudar a ejectuar el codigo.
