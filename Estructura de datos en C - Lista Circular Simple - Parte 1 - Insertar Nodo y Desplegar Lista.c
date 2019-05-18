#include <stdio.h>
#include <conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;


nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();

void desplegarLista();


int main(){
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	printf("\n la lista ingresada es: \n\n");
	desplegarLista();
	return 0;
}

// primero = 17     ultimo = 3    nuevo = 3                actual = 17               

// lista circula simple ----      17 -> 8 -> 9 -> 3 -> primero                        17 , 8 , 9 , 3
 
// 17,8,9,3

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d",&nuevo->dato);
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con exito\n\n");
}

void desplegarLista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("\n La lista se encuentra vaci\n\n");
	}
}









