#include <stdio.h>
#include <conio.h>

void ingreso_frase(char *,int);     //Prototipos de funciones con punteros a char
void limpia_string(char *);
void convertir(char *,int);

int main()
{

    char frase[51];             //Declaro cadena, variable OPCION y llamo a la funcion de ingresar la palabra
    int opcion;
    ingreso_frase(frase,51);    // Le paso la cadena y el largo que tiene.

    do{
    printf("\nIndicar accion (0 -> MAYUSCULA / 1-> minuscula): ");
    scanf("%d",&opcion);
    }while( opcion!=0 && opcion!=1);        //Una vez seleccionó una opcion, llama a la funcion convertir tomando como referencia la frase ingresada

    convertir(frase,opcion);
    printf("\n%s \n",frase);            //Una vez se convirtio la frase, se imprime por pantalla la ya transformada.
    return 0;
}

void ingreso_frase(char * ptr,int largo)
{
    fflush(stdin);
    printf("\nIngrese frase a transformar: ");      //Le pido por pantalla que ingrese una palabra
    fgets(ptr,largo,stdin);                         // lo leo con fgets para que incluya los espacios hasta el \0, guardando el ingreso en el puntero PTR y tomando el largo de la cadena.
    limpia_string(ptr);                             // Se llama a la funcion limpiar cadena dandole como referencia lo que apunta ptr.
}

void convertir(char * ptr,int opcion)   // la funcion tiene como referencia un puntero a char y la opcion que se ingresó
{                                       // PTR esta apuntando a donde se guardo el ingreso por pantalla
    if(opcion == 1)
    {
        while(*ptr!='\0')
        {
            if(*ptr>='A'&& *ptr<='Z')
                *ptr+=32;
            ptr++;
        }
    }else{
        while(*ptr!='\0')
        {
            if(*ptr>='a'&& *ptr<='z'){
                *ptr-=32;}
            ptr++;
        }
    }
}

void limpia_string(char * ptr)
{
    while(*ptr!='\0'&&*ptr!='\n'){
        ptr++;
    }

    if(*ptr=='\n'){
       *ptr='\0';
    }
}
