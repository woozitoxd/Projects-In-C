#include<stdio.h>

int main(){

    FILE * archivo;
    int dato,contador=0;
    archivo = fopen("Salida_Binario_1.bin","wb");

    if(archivo!=NULL){

        while(contador<5)
        {
            printf("\nIngrese valor: ");
            scanf("%d",&dato);
            fwrite(&dato,sizeof(dato),1,archivo);
            contador++;
        }
        fclose(archivo);
    }

    return 1;
}
