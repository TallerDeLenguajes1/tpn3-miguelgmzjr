#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct{
    int productoID;   //Numerado en ciclo iterativo
    int cantidad;   //entre 1 y 10
    char* TipoProducto;   //Algún valordel arreglo TiposProductos
    float PrecioUnitario;   //entre 10 -100
}Producto;

typedef struct{
    int clienteID;   // Numerado en el ciclo iterativo
    char *NombreCliente;   // Ingresado por usuario
    int CantidadProductosAPedir;   // (alteatorio entre 1 y 5)
    Producto *Productos;   //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}Cliente;



void CrearCliente(Cliente *client,int c);
void CargarProducto(Producto *P,int prod);
int CostoProducto(Producto *p);
void MostrarProductos(Producto *p,int prod);




int main(){

srand (time(NULL));

int cant_clientes,i,j;
char *nombre, n[100];
Cliente *clientes;

printf("Ingrese la cantidad de clientes a cargar: ");
scanf("%d",&cant_clientes);

while(cant_clientes>5){
    printf("Se excedió de la cantidad máxima de clientes permitida, ingrese una cantidad menor a 5: ");
    scanf("%d",&cant_clientes);
}

clientes = (Cliente*) malloc(cant_clientes * sizeof(Cliente));  //Reservo memoria para la cantidad de clientes ingresada

CrearCliente(clientes,cant_clientes);  //funcion para cargar clientes 



//////////////MUESTRO CLIENTES Y PRODUCTOS//////////////////
for (i=0;i<cant_clientes;i++){
    printf("\n\n----------------------------------------------");

    printf("\n\nID DE CLIENTE %d -> %d\n",i+1,i);
    printf("NOMBRE DEL CLIENTE: %s\n",clientes[i].NombreCliente);
    printf("CANTIDAD DE PRODUCTOS A PEDIR: %d\n\n",clientes[i].CantidadProductosAPedir);

    MostrarProductos(clientes[i].Productos,clientes[i].CantidadProductosAPedir); //Funcion para mostrar productos

    printf("----------------------------------------------");


}


    scanf(" %c");
    return 0;
}


/////////////////////////////FUNCIONES///////////////////////////////////////

void CrearCliente(Cliente *client,int c){
    
    int i;
    char n[100];

    for(i=0;i<c;i++){
        
        client[i].clienteID = i;

        printf("Ingrese nombre del cliente ID:%d -> ",i);
        scanf("%s",n);
        client[i].NombreCliente = (char*) malloc((strlen(n)+1) * sizeof(char));
        strcpy(client[i].NombreCliente,n);
        

        client[i].CantidadProductosAPedir = rand() % 5+1;

        client[i].Productos = (Producto*) malloc(client[i].CantidadProductosAPedir * sizeof(Producto));

        CargarProducto(client[i].Productos,client[i].CantidadProductosAPedir);


    }


}


void CargarProducto(Producto *p,int prod){
    
    int i,aleatorio;
    char *aux;

    for(i=0;i<prod;i++){
        
        aleatorio = rand()% 5+0;
        p[i].productoID = aleatorio;
        p[i].cantidad = rand() % 10+1;

        aux = TiposProductos[aleatorio];
        p[i].TipoProducto = (char*) malloc((strlen(aux)+1) * sizeof(char));
        strcpy(p[i].TipoProducto,aux);

        p[i].PrecioUnitario = rand() % 91+10;
    }
}


int CostoProducto(Producto *p){
    float total;

    total = (p->cantidad) * (p->PrecioUnitario);

    return total;

}


void MostrarProductos(Producto *p,int prod){
    int i,total=0;

    for(i=0;i<prod;i++){
        printf("ID DE PRODUCTO %d -> %d\n",i+1,p[i].productoID);
        printf("CANTIDAD: %d\n",p[i].cantidad);
        printf("TIPO DE PRODUCTO: %s\n",p[i].TipoProducto);
        printf("Precio Unitario: %f\n\n",p[i].PrecioUnitario);
        total = total + CostoProducto(p+i);
    }
    printf("TOTAL AL PAGAR: $%d\n\n",total);

    
}