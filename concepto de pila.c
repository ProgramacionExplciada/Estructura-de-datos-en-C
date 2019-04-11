#include <conio.h>
#include <stdio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
}nodo;

nodo* primero = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarPila();


int main(){
	int opcionMenu = 0;
	do{
		printf("\n|-------------------------------------|");
		printf("\n|         ° CONCEPTO DE PILA °        |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 4. Eliminar      |");
		printf("\n| 2. Buscar        | 5. Desplegar     |");
		printf("\n| 3. Modificar     | 6. Salir         |");
		printf("\n|------------------|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA NODO EN LA PILA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA PILA \n\n");
				buscarNodo();
				break;	
			case 3:
				printf("\n\n MODIFICAR UN NODO DE LA PILA \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n ELIMINAR UN NODO DE LA PILA \n\n");
				eliminarNodo();
				break;
			case 5:
				printf("\n\n DESPLEGAR PILA DE NODOS \n\n");	
				desplegarPila();
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

//primero = 13   actual = 20  anterior = 17  nodoBuscado = 17

// 13 ->  16 ->  20 -> null

// 17 -> 20


void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	nuevo->siguiente = primero;
	primero = nuevo;
}

void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del Nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		while(actual != NULL){
			
			if(actual->dato == nodoBuscado){
				printf("\n EL Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			
			actual = actual -> siguiente;			
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La pila se encuentra Vacia\n\n");
	}
}

void modificarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del Nodo a Buscar para Modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		while(actual != NULL){
			
			if(actual->dato == nodoBuscado){
				printf("\n EL Nodo con el dato ( %d ) Encontrado", nodoBuscado);
				
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d",&actual->dato);
				printf(" Nodo Modificado\n\n");
							
				encontrado = 1;
			}
			
			actual = actual -> siguiente;			
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La pila se encuentra Vacia\n\n");
	}
}

void eliminarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del Nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		while(actual != NULL && encontrado != 1){
			if(actual->dato == nodoBuscado){
				if(actual == primero){
					primero = primero -> siguiente;
				}else{
					anterior -> siguiente = actual -> siguiente;
				}
				printf("\n El Nodo ha sido eliminado con Exito");
				encontrado = 1;
			}
			anterior = actual;
			actual = actual -> siguiente;			
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La pila se encuentra Vacia\n\n");
	}
}

void desplegarPila(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL){
		while(actual != NULL){
			printf("\n %d", actual -> dato);
			actual = actual -> siguiente;			
		}
	}else{
		printf("\n La pila se encuentra Vacia\n\n");
	}
}
