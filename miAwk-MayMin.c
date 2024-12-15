// Este programa lee un archivo de entrada ("ArchivoEntrada.txt") y convierte todos los caracteres
// a minúsculas. Luego, guarda el contenido modificado en un nuevo archivo ("ArchivoSalida.txt").

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
      FILE *fp1, *fp2;
      char ch;
      fp1 = fopen("ArchivoEntrada.txt", "r");
      if (fp1 == NULL)
      {
            puts("El Archivo No existe.");
            exit(1);
      }
      fp2 = fopen("ArchivoSalida.txt", "w+");

      while((ch=fgetc(fp1))!=EOF)
      {
            ch = tolower(ch);
            fputc(ch,fp2);
      }
      printf("\nEl archivo se ha copiado satisfactoriamente.");
      return 0;
}

