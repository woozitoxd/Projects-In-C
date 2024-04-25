#include <stdio.h>

int main(void)
{
    char letra;
    printf("Ingrese una letra del abecedario: ");
    scanf("%c", &letra);



    if(letra<109){
        printf("Letra esta antes de m ");
        }else{
    if(letra>109){
        printf("Letra esta despues de m ");}
    }
}
