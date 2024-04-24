#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{ char *nombre= (char*) malloc(100 * sizeof(char));
    //char *V[5];
    char **V;
    V=(char**) malloc(sizeof(char*)*5);//crea n vectores a puntaeros de tamaño simple
    for (int i = 0; i < 5; i++)
    {
        printf("\n Ingrese un nombre: ");
        gets(nombre);
        V[i]= (char*) malloc((strlen(nombre)+1)* sizeof(char));//a cada puntero de tamaño simple le doy el tamaño que necesito
        strcpy(V[i], nombre);

    }


    for (int i = 0; i < 5; i++)
    {

        printf("\n %s", V[i]);
    }


 for (int i = 0; i < 5; i++)
 {
    free(V[i]);
 }
 
    return 0;
}
