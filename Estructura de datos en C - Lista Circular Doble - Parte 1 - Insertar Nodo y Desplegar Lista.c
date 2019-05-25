#include <stdio.h>
#include <conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();

void desplegarListaPU();
void desplegarListaUP();

int main(){
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	printf("\n Primero al utlimo \n");
	desplegarListaPU();
	printf("\n Utlimo al Primero \n");
	desplegarListaUP();
	return 0;
}


// primero = 12    ultimo = 7       nuevo = 7         actual = 7                     7  6 4 12

// lista circular doble   --     7 <- 12 -> <- 4 -> <- 6 -> <- 7 -> 12               12  4  6 7

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		nuevo->atras = ultimo;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	printf("\n Nodo Ingresado\n\n");
}

void desplegarListaPU(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual != primero);
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
}

void desplegarListaUP(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = ultimo;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->atras;
		}while(actual != ultimo);
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
}






































