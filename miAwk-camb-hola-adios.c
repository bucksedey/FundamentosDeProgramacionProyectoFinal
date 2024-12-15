// Este programa abre un archivo de entrada ("ArchivoEntrada.txt") y busca una palabra específica.
// Luego, reemplaza todas las ocurrencias de esa palabra por otra proporcionada por el usuario.
// Los resultados se guardan en un nuevo archivo ("ArchivoSalida.txt").

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BuscarReemplazar()
{
    FILE *fp1, *fp2;
    char palabra[100], ch, leer[100], reemplazar[100];
    int palabra_len, i, p = 0;

    fp1 = fopen("ArchivoEntrada.txt", "r");
    fp2 = fopen("ArchivoSalida.txt", "w+");
    if (fp1 == NULL || fp2 == NULL) {
        printf("No se puede abrir el archivo.");
        exit(0);
    }

    puts("\nIngresa la palabra a reemplazar: ");
    fgets(palabra, 100, stdin);

    // elimina el caracter de nueva l�nea de la cadena
    palabra[strlen(palabra) - 1] = palabra[strlen(palabra)];

    puts("Ingresa la palabra por la cual se va a reemplazar :");
    fgets(reemplazar, 100, stdin);

    // elimina el caracter de nueva l�nea de la cadena
    reemplazar[strlen(reemplazar) - 1] = reemplazar[strlen(reemplazar)];

    fprintf(fp2, "Reemplazar %s por %s\n", palabra, reemplazar);

    // comparando palabra en el archivo
    rewind(fp1);
    while (!feof(fp1)) {

        fscanf(fp1, "%s", leer);

        if (strcmp(leer, palabra) == 0) {

            // para borrar la palabra
            strcpy(leer, reemplazar);
        }

        // En el �ltimo bucle se ejecuta dos veces
        fprintf(fp2, "%s ", leer);
    }

	printf("El archivo se ha modificado satisfactoriamente");

    fclose(fp1);
    fclose(fp2);
}


void main()
{
    BuscarReemplazar();
}
