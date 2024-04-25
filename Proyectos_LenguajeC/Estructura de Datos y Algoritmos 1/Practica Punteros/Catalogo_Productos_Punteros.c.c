#include <stdio.h>
#define TAM 50

struct catalogo{
    int id;
    char nombre[50];
    float costo;
    int cantidad;
};

int menu();
void limpia_string(char *);
void agregar(struct catalogo *, int *);
float consultar_total(struct catalogo *, int *);
int consultar_articulo(struct catalogo *, int *);

int main()
{

    struct catalogo inventario[TAM];
    struct catalogo * ptr_inicial=inventario;

    int cant = 0,opcion; // almacena la cantidad de articulos
    int resultado;

    do{
        opcion = menu();
        switch(opcion){

            case 1:
                agregar(inventario,&cant);
                break;

            case 2:
                resultado = consultar_articulo(inventario,&cant);
                if(resultado>=0){
                    printf("\nEl Articulo existe:");

                    printf("\nID: %d - Nombre: %s - Costo: %f - Cant: %d",
                            (ptr_inicial+resultado)->id,
                            (ptr_inicial+resultado)->nombre,
                            (ptr_inicial+resultado)->costo,
                            (ptr_inicial+resultado)->cantidad);
                }else{
                    printf("\nNo existe el articulo.");
                }
                break;

            case 3:
                printf("\nInventario total: %.2f \n\n",consultar_total(inventario,&cant));
                break;

            case 4:
                printf("\n\nFinalizando programa...");
                break;
        }
    }while(opcion!=4);

    return 0;
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

int menu()
{
    int opcion;
    do{
        printf("Seleccionar opcion:\n 1 - Agregar\n 2 - Consular Articulo\n 3 - Ver Costo Inventario\n 4 - Salir");
        printf("\nSu opcion: ");
        scanf("%d", &opcion);
    }while(opcion>4 || opcion<1);

    return opcion;
}

void agregar(struct catalogo * pinv, int * pcant){
    int articulo;

    printf("\nIngrese numero de articulo (0 para finalizar):");
    scanf("%d", &articulo);

    pinv=pinv+(*pcant);

    while(articulo!=0&& *pcant<TAM){

        pinv->id = articulo;

        fflush(stdin);
        printf("\nIngrese nombre:");
        fgets(pinv->nombre,50,stdin);
        limpia_string(pinv->nombre);

        printf("\nIngrese costo:");
        scanf("%f", &pinv->costo);
        fflush(stdin);

        printf("\nIngrese cantidad: ");
        scanf("%d", &pinv->cantidad);
        fflush(stdin);
        (*pcant)++;
        pinv++;

        printf("\nIngrese numero de articulo (0 para finalizar):");
        scanf("%d", &articulo);
        fflush(stdin);
    }
}

int consultar_articulo(struct catalogo * pinv, int * pcant)
{
    int id_buscar, contador = 0;

    printf("\nIngrese ID a buscar:");
    scanf("%d", &id_buscar);

    while((pinv->id != id_buscar) && (contador < *pcant)){
        pinv++;
        contador++;
    }

    if(pinv->id == id_buscar){
        return contador;
    }else{
        return -1;}
}

float consultar_total(struct catalogo * pinv, int *pcant){

    float acum = 0;
    int contar = 0;

    while(contar < *pcant){
        acum+=(pinv->costo) * (pinv->cantidad); // acum= acum + pinv->costo*pinv->cantidad;
        contar++;
        pinv++;
    }
    return acum;
}
