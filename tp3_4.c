#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;


struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

void cargaClientes(Cliente *clientes, int nroclientes);
float calcularTotalProducto(Producto producto);
void mostrarDatos(Cliente *clientes, int nroclientes);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Cliente  *clientes;
    int nroclientes;
    do
    {
    printf("/n Ingrese la cantidad de clientes: ");
    scanf("%d", &nroclientes);
    } while (nroclientes > 5);

    clientes= (Cliente*)malloc(nroclientes * sizeof(Cliente));
    
cargaClientes(clientes, nroclientes);

mostrarDatos(clientes, nroclientes);

for (int i = 0; i < nroclientes; i++)
{
free(clientes[i].NombreCliente);
free(clientes[i].Productos);
    
}

free (clientes);

    return 0;
}

void cargaClientes(Cliente *clientes, int nroclientes){
char *nombre= (char*)malloc(100 * sizeof(char));
for (int i = 0; i < nroclientes; i++)
{    fflush(stdin);
    printf("\n Ingrese nombre de cliente: ");
    gets(nombre);
fflush(stdin);

    clientes[i].ClienteID=i;
    clientes[i].NombreCliente=(char*)malloc((strlen(nombre)+1)* sizeof(char));
    strcpy(clientes[i].NombreCliente,nombre);
    clientes[i].CantidadProductosAPedir= rand()%3+1;
    clientes[i].Productos=(Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

    for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
    {
        clientes[i].Productos[j].TipoProducto= (char*)malloc(30 * sizeof(char));
        clientes[i].Productos[j].ProductoID=j;
        clientes[i].Productos[j].Cantidad=rand()%10+1;
        strcpy(clientes[i].Productos[j].TipoProducto,TiposProductos[rand()%5]);//
        clientes[i].Productos[j].PrecioUnitario=rand()%90+10;
    }

}
   free(nombre); 
}

float calcularTotalProducto(Producto productos){

float total;
total= productos.Cantidad*productos.PrecioUnitario;
return total;
}


void mostrarDatos(Cliente *clientes, int nroclientes){

    for (int i = 0; i < nroclientes; i++)
    {
        float totalPagarCliente=0;
        printf("\n*********** CLIENTE NUMERO %d ***********\n", i+1);
        printf("\nCliente nombre: %s", clientes[i].NombreCliente);
        printf("\nCliente ID: %d", clientes[i].ClienteID);
        printf("\nCantidad de productos: %d", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n ******** producto nro %d ************", j+1);
            printf("\n \ttipo de producto: %s", clientes[i].Productos[j].TipoProducto);
            printf("\n \tProducto ID: %d", clientes[i].Productos[j].ProductoID);            
            printf("\n \tproducto precio: $ %.2f", clientes[i].Productos[j].PrecioUnitario);
            printf("\n \tProducto cantidad: %d", clientes[i].Productos[j].Cantidad);

            printf("\n");
            totalPagarCliente=totalPagarCliente + calcularTotalProducto(clientes[i].Productos[j]);

        }
        printf("\n EL total a pagar por todos los productos es $%.2f \n\n", totalPagarCliente);
    }
    
}