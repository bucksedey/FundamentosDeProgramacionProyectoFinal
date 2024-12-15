// Este programa abre un archivo de entrada ("ArchivoEntrada.txt") y reemplaza todas las ocurrencias
// de una letra específica por otra letra proporcionada por el usuario. El contenido modificado se guarda
// en un nuevo archivo ("ArchivoSalida.txt").

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Declaraci�n de la funci�n */
void reemplazar(char *str, const char *Letra1, const char *Letra2);


int main()
{
    /* Puntero de archivo para contener la referencia del archivo de entrada */
    FILE * fPtr;
    FILE * fTemp;
    char path[100];

    char buffer[BUFFER_SIZE];
    char Letra1[100], Letra2[100];



    printf("\nDame la letra que quieres reemplazar: ");
    scanf("%s", Letra1);

    printf("\nLa letra por la cual quieres reemplazar: ");
    scanf("%s", Letra2);


    /*  Abrir los archivos */
    fPtr  = fopen("ArchivoEntrada.txt", "r");
    fTemp = fopen("ArchivoSalida.txt", "w+");


    /*
     * Leer una linea del archivo fuente y escribir al destino
     * el archivo despues de la letra reemplazada.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Reemplazar todas las ocurrencias de una letra
        reemplazar(buffer, Letra1, Letra2);
        fputs(buffer, fTemp);
    }


    /* Cerrar los archivos usados */
    fclose(fPtr);
    fclose(fTemp);

    printf("\nSe han reemplazado de manera correcta las '%s' por las '%s'.", Letra1, Letra2);

    return 0;
}



/**
 * Reemplazar todas las ocurrencias de una letra en las cadenas.
 */
void reemplazar(char *str, const char *Letra1, const char *Letra2)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(Letra1);

    // Si Letra1 y Letra2 son lo mismo va a un loop infinito
    if (!strcmp(Letra1, Letra2)) {
        return;
    }


    /*
     * Repetir hasta que todas las ocurrencias se reemplacen.
     */

    while ((pos = strstr(str, Letra1)) != NULL)
    {
        // L�nea actual de respaldo
        strcpy(temp, str);

        // Indice de la palabra encontrada actual
        index = pos - str;

        // Terminar cadena tras �ndice de palabra encontrada
        str[index] = '\0';

        // Concatenar cadena con nueva palabra
        strcat(str, Letra2);

        // Concatenar str con las palabras restantes despu�s
        strcat(str, temp + index + owlen);
    }
}
