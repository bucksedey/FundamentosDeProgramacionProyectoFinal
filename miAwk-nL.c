// Este programa lee un archivo de texto ("ArchivoEntrada.txt") y numera cada línea en el archivo,
// mostrando el número de línea antes de cada línea del contenido. Los números de línea comienzan en 1.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
      FILE *fp1;
      int  ult=0;
      char ch;
      size_t nL=1;
      fp1 = fopen("ArchivoEntrada.txt", "r");
      if (fp1 == NULL)
      {
            puts("El Archivo No existe..");
            exit(1);
      }
	  
    printf("%zu.- ", nL++);            /* n�mero de l�nea de salida 1 */
    while ((ch = fgetc(fp1)) != EOF) {  /* leer cada caracter */
        if (ult)                       /* probar el ultimo conjunto */
            putchar (ult);             /* salida de todos los caracteres */
        if (ult == '\n')               /* prueba si la ultima es una nueva linea */
            printf("%zu.- ", nL++);   /* salida siguiente numero de linea */
        ult = ch;                      /* ultimo conjunto a caracter */

    }
    putchar (ult);                     /* salida del caracter final */
    if (ult != '\n')                   /* comprobar el final del archivo EOF */
        putchar('\n');                 /* organizar la nueva linea */


    return 0;
}
