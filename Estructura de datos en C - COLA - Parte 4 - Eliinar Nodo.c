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
void eliminarNodo();
void desplegarCola();

int main(){
	int opcionMenu = 0;
	do{
		printf("\n|-------------------------------------|");
		printf("\n|              ° COLA °               |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 4. Eliminar      |");
		printf("\n| 2. Buscar        | 5. Desplegar     |");
		printf("\n| 3. Modificar     | 6. Salir         |");
		printf("\n|------------------|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTAR NODO EN LA COLA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA COLA \n\n");
				buscarNodo();
				break;	
			case 3:
				printf("\n\n MODIFICAR UN NODO DE LA COLA \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n ELIMINAR UN NODO DE LA COLA \n\n");
				eliminarNodo();
				break;
			case 5:
				printf("\n\n DESPLEGAR COLA DE NODOS \n\n");
				desplegarCola();	
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

// primero = 13    ultimo = 8    nuevo  20     actual = 8  anterior = 12   nodobuscado = 12     encontrado = 1

// cola -     13 ->  8 -> 20 -> null    

// 13, 3, 20                                    -.....   13   12   3   20

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con exito\n\n");
}

void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor del Nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
						
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}

void modificarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor del Nodo a Buscar para Modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d" , &actual->dato);
				printf("\n Nodo Modificado con exito\n\n");
				encontrado = 1;
			}
						
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}

void eliminarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor del Nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){		
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				printf("\n El Nodo eliminado con exito\n\n");
				encontrado = 1;
			}
			anterior = actual;	
			actual = actual->siguiente;
		}
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}

void desplegarCola(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La cola no existe\n\n");
	}
}











/**/






