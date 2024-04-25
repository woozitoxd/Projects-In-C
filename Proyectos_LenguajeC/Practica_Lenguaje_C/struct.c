#include<stdio.h>
#include<stdlib.h>
struct global
{
    int valor;
    char nombre[10];
    float precio;
};


int main(){

struct global n1;

n1.valor=5;
n1.precio=54.5;


printf("%d",n1.valor);

}
