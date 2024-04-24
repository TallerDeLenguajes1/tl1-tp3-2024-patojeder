#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{ char *nombre= (char*) malloc(100 * sizeof(char));
int cantidad;
printf("\n Ingrese la cantidad de nombres que desea cargar: ");
scanf("%d", &cantidad);
    char **V;
    V=(char**) malloc(sizeof(char*)*cantidad);//crea n vectores a puntaeros de tamaño simple
    for (int i = 0; i < cantidad; i++)
    {
        fflush(stdin);
        printf("\n Ingrese un nombre: ");
        gets(nombre);
        fflush(stdin);
        V[i]= (char*) malloc((strlen(nombre)+1)* sizeof(char));//a cada puntero de tamaño simple le doy el tamaño que necesito
        strcpy(V[i], nombre);

    }

printf("\nLos nombres ingresados son");
    for (int i = 0; i < cantidad; i++)
    {

        printf("\n %s", V[i]);
    }


 for (int i = 0; i < cantidad; i++)
 {
    free(V[i]);
 }
 free (nombre);
    return 0;
}
