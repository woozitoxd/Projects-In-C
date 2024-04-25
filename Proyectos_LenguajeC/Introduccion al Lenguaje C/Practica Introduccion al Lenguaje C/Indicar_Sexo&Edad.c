#include <stdio.h>

int main(void) //Se le pide a la persona que ingrese su sexo y edad
{
    char sexo;
    int edad;
    printf("Ingrese el sexo de la persona donde V es varon y M mujer: ");
    scanf("%c", &sexo);
    fflush(stdin);
    printf("Ingrese la edad de la persona: ");
    scanf("d", &edad);

    if(sexo == 'V' || sexo =='v')
    {
        if( edad > 0 && edad < 18 ){
            printf("\nUsted es varon mayor");
        }else{
        printf("Usted es varon menor");
        }
    }else{
        if(sexo== 'M' || sexo == 'v')
        {
            if( edad > 0 && edad < 18)
            printf("\nUsted es mujer mayor.");
        }else{
        printf("Usted es mujer menor.");
        }
    }
return 0;
}
