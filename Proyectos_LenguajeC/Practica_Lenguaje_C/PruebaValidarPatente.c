#include <stdio.h>
#include <string.h>

int main()
{
    char patente[3];

    printf("Ingresar patente \n");
    scanf("%s", patente);
    fflush(stdin);

    strlen(patente);
         if( (patente[0]== 'a' )&& (patente[1]== 'b') &&( patente[2]==0) ){
        printf("Patente valida \n");
        }else
        printf("patente no sirve \n");


}
