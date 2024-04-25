//Solo identifica letras en minuscula
#include <stdio.h>
#include <stdlib.h>

int esVocal (char);
int prueba ();
int prueba_intermedia ();
int prueba_avanzada ();

int main (){
  char letra;
  int valida;

  if (prueba_avanzada () == 0){
      printf ("\nPrueba FALLO");
    }
    else{
      printf ("\nPrueba OK");
    }
}
int esVocal (char let)
{				//funcion que devolvera un valor entero acorde a lo que ingresemos
    if (let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u'){
        return 1;	//si el caracter ingresado es una vocal minuscula devolvera 1
    }else{
        return 0;//si el caracter ingresado es una consonante minuscula devolvera 0
    }
}
int
prueba_basica ()
{
//caso de prueba 1
  char letra = 'a';
  if (esVocal (letra) != 1){
      return 0;			//fallo
    }
//caso de prueba 2
  letra = 'B';
  if (esVocal (letra) != 0){
      return 0;
    }
  return 1;
}

int prueba_avanzada ()
{
  int vocales_contadas = 0;

  for (int i = 0; i < 255; i++){
      char letra = i;
        if (esVocal (letra) == 1){
        vocales_contadas++;
        }
    }
  if (vocales_contadas != 5){
      return 0;
    }
  return 1;
}

int prueba_intermedia ()
{
  char vocal[5] = { 'A', 'E', 'I', 'O', 'U' };
  char consonantes[21] =
    { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R',
    'S', 'T', 'V', 'X', 'Z', 'W', 'Y'
  };
  char caracteres_especiales[10] =
    { '-', '_', '*', '+', ')', '(', '/', '$', '#', '!' };
  int i;
// casos de prueba de vocales
  for (i = 0; i < 5; i++){
        if (esVocal (vocal[i]) != 1){
            return 0;
        }
    }
// casos de prueba de consonantes
  for (i = 0; i < 22; i++){
        if (esVocal (consonantes[i]) != 0){
            return 0;
        }
    }
// casos de prueba de caracteres especiales
  for (i = 0; i < 10; i++){
        if (esVocal (caracteres_especiales[i]) != 0){
            return 0;
        }
    }
}
