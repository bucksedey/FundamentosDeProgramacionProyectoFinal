// Este programa lee un archivo de texto ("ArchivoEntrada.txt") y cuenta cuántas veces aparece un
// sufijo o prefijo (proporcionado por el usuario) en el archivo. El resultado se muestra al usuario.

#include<stdio.h>
#define BUFFER_SIZE 100

int ocurrencias(FILE *fptr, const char *suf)
{
  char str[BUFFER_SIZE];
  char *pos;

  int ind, cont;

  cont = 0;

  // Leer la l�nea del archivo hasta el fin del archivo.
  while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
      ind = 0;

      // Encntrar la siguiente ocurrencia del sufijo o prefijo en la siguiente l�nea
      while ((pos = strstr(str + ind, suf)) != NULL)
        {
      // El indice del suf en la linea es
      // Direccion de memoria de pos - memoria
      // Direcci�n de la cadena.
      ind = (pos - str) + 1;

      cont++;
        }
    }

  return cont;
}
int main()
{
  FILE * fptr;
  char  * suf;
  int i=0;

  suf = malloc(25 * sizeof(char));
  fptr = fopen("ArchivoEntrada.txt", "r");

  if (!fptr)
    printf("No se encontr� el archivo. \n");

  else
  {
    printf("\n Ingresa el Sufijo o Prefijo a encontrar: ");
    scanf("%s", suf);
    i=ocurrencias(fptr, suf);
  }
  if (i==0)
    printf("No se encuentra el sufijo o prefijo.\n");
  else
    printf(" '%s' Fue encontrado %d veces en el texto de entrada.\n",suf,i);

  fclose(fptr);
  return 0;
}
