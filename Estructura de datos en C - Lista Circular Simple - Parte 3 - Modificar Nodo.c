#include <stdio.h>
#include <conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;


nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void desplegarLista();


int main(){
	int opcionMenu = 0;
	do{
		printf("\n|-------------------------------------|");
		printf("\n|      ° LISTA CIRCULAR SIMPLE °      |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 4. Eliminar      |");
		printf("\n| 2. Buscar        | 5. Desplegar     |");
		printf("\n| 3. Modificar     | 6. Salir         |");
		printf("\n|------------------|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA NODO EN LA LISTA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA LISTA \n\n");
				buscarNodo();
				break;	
			case 3:
				printf("\n\n MODIFICAR UN NODO DE LA LISTA \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				break;
			case 5:
				printf("\n\n DESPLEGAR LISTA DE NODOS \n\n");
				desplegarLista();
				break;
			case 6:
				printf("\n\n Programa finalizado...");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcionMenu != 6);
	return 0;
}

// primero = 17     ultimo = 3    nuevo = 3                actual = 9       nodoBuscado = 9    encontrado = 1           

// lista circula simple ----      17 -> 6 -> 9 -> 3 -> primero                      


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

void buscarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo a Buscar: ");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual!=primero && encontrado!=1);
		
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vaci\n\n");
	}	
}

void modificarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo a Buscar para Modificar: ");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d",&actual->dato);
				printf("\n Nodo modificado con exito\n\n");
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual!=primero && encontrado!=1);
		
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vaci\n\n");
	}	
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







/*

*/






