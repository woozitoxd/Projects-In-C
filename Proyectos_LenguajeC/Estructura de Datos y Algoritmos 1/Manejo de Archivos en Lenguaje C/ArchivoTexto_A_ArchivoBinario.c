#include<stdio.h>

int main(){

    FILE * archivo, *texto;
    char string[50];

    texto = fopen("Leer_Lineas.txt","r");
    archivo = fopen("Salida_Binario_2.bin","wb");

    if(archivo!=NULL && texto!=NULL){

        while(!feof(texto))
        {
            fscanf(texto,"%s",string);
            fwrite(string,sizeof(string),1,archivo);
        }

        printf("\nLargo del archivo: %d"), ftell(archivo);
        fseek(archivo,0,SEEK_END);

        fclose(archivo);
        fclose(texto);
    }

    return 1;
}

