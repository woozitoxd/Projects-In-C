#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    char Campo1[250];
    char Campo2[250];
    char Campo3[250];
    int  Campo4_Num;
};

void LeerArchivo(FILE *);

void main()
{
    FILE * archivo;
    archivo = fopen("Sin_Separador.txt", "r+");

    if ( archivo != NULL){
        printf("Abriendo archivo...\n\n");
        LeerArchivo(archivo);
        fclose(archivo);
    }else{
    printf("ERROR!, El archivo 'separador.txt' no existe... \n\n");
    }
}

void LeerArchivo(FILE * archivo)
{
    char buffer[500], *ptr, *ptr_campo1, *ptr_campo2, *ptr_campo3;
    struct registro DATO;
    int contar_largo;

    while(!feof(archivo)){
        ptr = buffer;
        fgets(buffer, 500, archivo);
        contar_largo = 0 ;

        ptr_campo1 = DATO.Campo1;
        ptr_campo2 = DATO.Campo2;
        ptr_campo3 = DATO.Campo3;

        while(contar_largo < 17){
            if(contar_largo >=0 && contar_largo < 3){
                *ptr_campo1=*ptr;
                *ptr_campo1++;
            }
            if(contar_largo >=3 && contar_largo < 10){
                *ptr_campo2=*ptr;
                *ptr_campo2++;
            }
            if(contar_largo >=10 && contar_largo < 16){
                *ptr_campo3=*ptr;
                *ptr_campo3++;
            }
            if(contar_largo == 16){
                DATO.Campo4_Num = atoi(ptr);
            }
            contar_largo++;
            ptr++;
        }

        *ptr_campo1 = '\0';
        *ptr_campo2 = '\0';
        *ptr_campo3 = '\0';


        printf("Campo 1: %s\n", DATO.Campo1);
        printf("Campo 2: %s\n", DATO.Campo2);
        printf("Campo 3: %s\n", DATO.Campo3);
        printf("Campo Numerico: %d\n\n", DATO.Campo4_Num);
    }

}

