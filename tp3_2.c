#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define filas 5
#define columnas 12
void cargarMatriz(int matriz[][columnas]);
void mostrarMatriz(int matriz[][columnas]);
void calcularPromedioPorAnio(int matriz[][columnas]);
void minimoMaximo(int matriz[][columnas]);


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int matriz[filas][columnas];

cargarMatriz(matriz);
mostrarMatriz(matriz);
calcularPromedioPorAnio(matriz);
minimoMaximo(matriz);
    
    return 0;
}

void cargarMatriz(int matriz[][columnas]){
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j]=rand()%40000+10000;
        }
        
    }
}

void mostrarMatriz(int matriz[][columnas]){

 for (int i = 0; i < filas; i++)
 {
    for (int j = 0; j < columnas; j++)
    {
        printf("\t %d", matriz[i][j]);
    }
    printf("\n");
 }

}

void calcularPromedioPorAnio(int matriz[][columnas]){
    float promedio, suma=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma=suma+matriz[i][j];
        }
        promedio=suma/columnas;
        suma=0;
        printf("\n EL promedio de ganancias correspondiente al anio %d  es %.2f$", i+2025, promedio);
    }
    

}

void minimoMaximo(int matriz[][columnas]){
int minimo=10000, maximo=50000, mayor, menor, anio, mes;
for (int i = 0; i < filas; i++)
{
    for (int j = 0; j < columnas; j++)
    {
        if (matriz[i][j]>minimo)
        {
            minimo=matriz[i][j];
            mayor=matriz[i][j];
            anio=i;
            mes=j;
        }
        
    }
}
printf("\n EL valor maximo obtenido fue %d, correspondiente al anio %d, mes numero %d", mayor, anio+2024, mes+1);

for (int i = 0; i < filas; i++)
{
    for (int j = 0; j < columnas; j++)
    {
        if (matriz[i][j]<maximo)
        {
            maximo=matriz[i][j];
            menor=matriz[i][j];
            anio=i;
            mes=j;
        }
        
    }
}
printf("\n EL valor minimo obtenido fue %d, correspondiente al anio %d, mes numero %d", menor, anio+2024, mes+1);
}