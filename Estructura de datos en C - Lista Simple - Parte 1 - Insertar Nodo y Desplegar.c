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
	desplegarLista();
	return 0;
}

// primero = 7     ultimo = 9    nuevo = 9   actual = NULL

/// Lista   7 -> 5 -> 2 ->  9 -> NULL

// 7, 5, 2, 9

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con Exito\n\n");
}

void desplegarLista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

