#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dato{
    int codigo;
    char nombre[51];
    int stock;
    float precio;
};

void IniciarVector(struct dato []);
void ImprimirVector(struct dato []);
void Ordenamiento(struct dato[]);
int BusquedaPrecio(struct dato[], int);
int BusquedaCodigo(struct dato[], int);
int BusquedaNombre(struct dato vec[], int);

int main(int cantidad)
{
    struct dato vec[500];
    int menu, auxPrecio, pos, auxCodigo;
    char auxNombre[10];
    char opcion;

    printf("Desea usted entrar al supermercado?(S para Si, n para No): ");
    scanf("%c",&opcion);

    while(opcion=='S'){

    printf("\nElija una de las siguientes opciones: \n1.Listado de productos por precio \n2.Busqueda de productos por codigo \n3.Busqueda de productos por descripcion \n4.Ingresar nuevo producto \n5.Salir del programa\n");
    scanf("%d", &menu);

    switch(menu){

case 1:

    Ordenamiento(vec);
    printf("Ingresar el precio a buscar: ");
    scanf("%d",&auxPrecio);
    pos=BusquedaPrecio(vec, auxPrecio);
    if(pos>=0){
        printf("El precio buscado esta en la posicion: %d",pos);
        ImprimirVector(vec);
    }else{
        printf("El valor buscado no existe");
    }

    break;

case 2:

    printf("Indicar el codigo a buscar: ");
    scanf("%d",&auxCodigo);
    pos=BusquedaCodigo(vec, auxCodigo);
    if(pos>=0){
        printf("El codigo buscado esta en la posicion: %d\n",pos+1);
        ImprimirVector(vec);
    }else{
        printf("El codigo buscado no existe");
    }

    break;

case 3:

    pos=BusquedaNombre(vec, cantidad);

    if(pos>=0){
        printf("El nombre buscado esta en la posicion: %d",pos+1);
        printf("\nCodigo: %d - Precio: %.2f - Stock: %d - Nombre: %s",vec[pos].codigo,vec[pos].precio,vec[pos].stock,vec[pos].nombre);
        //ImprimirVector(vec);
    }else{
        printf("El nombre buscado no existe");
    }

case 4:

    IniciarVector(vec);
    printf("Vector antes de ordenar\n");
    ImprimirVector(vec, cantidad);

    break;

    }
    fflush(stdin);
    if(opcion=='N'){

        printf("Gracias por venir");
        }

    }

}

void Ordenamiento(struct dato vec[]){

   struct dato aux;

    for(int i=0;i<5-1;i++){
        for(int j=0;j<5-i-1;j++){
            if(vec[j].precio>vec[j+1].precio){
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
    }

};

int BusquedaPrecio(struct dato vec[],int auxPrecio){
    int i=0;
    while(i<5 && vec[i].precio!=auxPrecio){
        i++;
    }
    if(i<5 && vec[i].precio==auxPrecio){
        return i+1;
    }else{
        return -1;
    }
}

int BusquedaCodigo(struct dato vec[],int auxCodigo){
    int i=0;
    while(i<5 && vec[i].codigo!=auxCodigo){
        i++;
    }
    if(i<5 && vec[i].codigo==auxCodigo){
        return i+1;
    }else{
        return -1;
    }
}

int BusquedaNombre(struct dato vec[], int cantidad){

    char auxNombre[10];

    printf("Indicar el nombre a buscar: ");
    scanf("%s",&auxNombre);
    fflush(stdin);

    for( int i = 0; i<cantidad; i++){
       if(strcmp(vec[i].nombre, auxNombre)==0){
        return i;
       }
    }


}

void IniciarVector(struct dato vec[]){
    int menu2=1, i=0;
    int cantidad=0;
    while(menu2==1 && i<3){

        fflush(stdin);
        printf("Ingrese codigo:");
        scanf("%d",&vec[i].codigo);

        fflush(stdin);
        printf("Ingrese stock:");
        scanf("%d",&vec[i].stock);

        fflush(stdin);
        printf("Ingrese nombre:");
        scanf("%s",&vec[i].nombre);

        fflush(stdin);

        printf("Ingrese el precio:");
        scanf("%f",&vec[i].precio);

        printf("\nDatos ingresados: ");
        printf("\nCodigo: %d \nPrecio: %.2f \nStock: %d \nNombre: %s", vec[i].codigo,vec[i].precio, vec[i].stock, vec[i].nombre);
        printf("\nCantidad total de productos ingresados: %d\n",i+1);

        printf("Desea agregar otro producto?:");
        scanf("%d",&menu2);

        i++;
        cantidad++;

        if(cantidad==500){
    printf("Ya no se pueden ingresar mas productos");
        }
    }
    main(cantidad);
}


void ImprimirVector(struct dato vec[], int cantidad){
    for(int i=0;i<cantidad;i++){
        printf("\nCodigo: %d - Precio: %.2f - Stock: %d - Nombre: %s",vec[i].codigo,vec[i].precio,vec[i].stock,vec[i].nombre);
    }
}
