#include <stdio.h>
#include <stdlib.h>

struct nodoCola{
	int num;
	
	struct nodoCola *siguiente;
};

struct nodoCola *inicio, *final;

void mostrarCola();

void agregarCola(int numero){
	nodoCola *NuevoNodo = new nodoCola();
	
	
	NuevoNodo->num = numero; //asigna el numero al nodo
	
	if(inicio == NULL){
		inicio = NuevoNodo;
		final = NuevoNodo;
		inicio->siguiente = NULL;
		final->siguiente = NULL;
	}else{
			
		final->siguiente = NuevoNodo;
		NuevoNodo->siguiente = NULL;
		final = NuevoNodo;
	}
	
	mostrarCola();
}

void eliminarCola(){
	struct nodoCola *aux;
	
	if(inicio != NULL){
		aux = inicio;
		
		if(inicio == final){//se eliminará el inicio
			inicio = final = NULL;
			aux->siguiente = NULL;
			aux = NULL;
			free(aux);
		}else{//si no es el inicio
			inicio = aux->siguiente;
			aux->siguiente = NULL;
			aux = NULL;
			free(aux);
		}
		
		mostrarCola();
	}else{
		printf("COLA VACIA\n");
	}
}

void mostrarCola(){
	if(inicio != NULL){
		struct nodoCola *aux;
		aux = inicio;
		while (aux != NULL){
			if(aux->siguiente != NULL){
				printf("%i -> ", aux->num);
			}else{
				printf("%i\n", aux->num);
			}
			aux = aux->siguiente;
		}
	}else{
		printf("COLA VACIA\n");
	}
}

struct nodoPila{
	int num;
	
	struct nodoPila *siguiente;
};

struct nodoPila *inicioPila, *finalPila;

void mostrarPila();

void agregarPila(){
	nodoPila *NuevoNodo = new nodoPila();
	
	int numero;
	printf("Ingrese el número:\n");
	scanf("%i", &numero);
	
	NuevoNodo->num = numero; //asigna el numero al nodo
	
	if(inicioPila == NULL){
		inicioPila =finalPila = NuevoNodo;
		inicioPila->siguiente = finalPila->siguiente = NULL;
	}else{
		struct nodoPila *aux;
		aux = inicioPila;
		/*
			El ultimo valor de la lista apunta a NULL
		*/
		while (aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		
		aux->siguiente = NuevoNodo;
		NuevoNodo->siguiente = NULL;
		finalPila = NuevoNodo;
	}
	
	mostrarPila();
}

void eliminarPila(){
	struct nodoPila *aux;
	struct nodoPila *anterior = NULL;
	
	if(inicioPila != NULL){
		aux = inicioPila;
		
		while(aux != finalPila){
			anterior = aux;
			aux = aux->siguiente;
		}
			
		if(anterior == NULL){//se eliminará el inicio
			inicioPila = finalPila = NULL;
			aux->siguiente = NULL;
			aux = NULL;
			free(aux);
		}else{//si no es el inicio
			anterior->siguiente = NULL;
			finalPila = anterior;
			aux->siguiente = NULL;
			aux = NULL;
			free(aux);
		}
		
		mostrarPila();
	}else{
		printf("PILA VACIA\n");
	}
}

void mostrarPila(){
	if(inicioPila != NULL){
		struct nodoPila *aux;
		aux = inicioPila;
		while (aux != NULL){
			if(aux->siguiente != NULL){
				printf("%i -> ", aux->num);
			}else{
				printf("%i\n", aux->num);
			}
			aux = aux->siguiente;
		}
	}else{
		printf("PILA VACIA\n");
	}
}

struct nodoLS{
	int num;
	
	struct nodoLS *siguiente;
};

struct nodoLS *inicioLS, *finalLS;

void mostrarLS();

void agregarLS(){
	nodoLS *NuevoNodo = new nodoLS();
	
	int numero;
	printf("Ingrese el número:\n");
	scanf("%i", &numero);
	
	NuevoNodo->num = numero; //asigna el numero al nodo
	
	if(inicioLS == NULL){
		inicioLS = NuevoNodo;
		finalLS = NuevoNodo;
		inicioLS->siguiente = NULL;
		finalLS->siguiente = NULL;
	}else{
		struct nodoLS *aux;
		aux = inicioLS;
		/*
			El ultimo valor de la lista apunta a NULL
		*/
		while (aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		
		aux->siguiente = NuevoNodo;
		NuevoNodo->siguiente = NULL;
		finalLS = NuevoNodo;
	}
	
	mostrarLS();
}

void eliminarLS(){
	struct nodoLS *aux;
	struct nodoLS *anterior = NULL;
	int num;
	printf("Ingrese Nodo a Eliminar\n");
	scanf("%i", &num);
	
	if(inicioLS != NULL){
		aux = inicioLS;
		while(aux != NULL){
			if(aux->num == num){
				if(anterior == NULL){//se eliminará el inicio
					inicioLS = inicioLS->siguiente;
					aux->siguiente = NULL;
					aux = NULL;
					free(aux);
				}else{//si no es el inicio
					anterior->siguiente = aux->siguiente;
					aux->siguiente = NULL;
					aux = NULL;
					free(aux);
				}
				break;
			}
			
			anterior = aux;
			aux = aux->siguiente;
		}
		
		mostrarLS();
	}else{
		printf("LISTA VACIA\n");
	}
}

void mostrarLS(){
	if(inicioLS != NULL){
		struct nodoLS *aux;
		aux = inicioLS;
		while (aux != NULL){
			if(aux->siguiente != NULL){
				printf("%i -> ", aux->num);
			}else{
				printf("%i\n", aux->num);
			}
			aux = aux->siguiente;
		}
	}else{
		printf("LISTA VACIA\n");
	}
}

struct nodoLSC{
	char nombre[30];
	int precio;
	int codigo;
	
	struct nodoLSC *siguiente;
};

struct nodoLSC *inicioLSC, *finalLSC;

void mostrarLSC();

void agregarLSC(){
	nodoLSC *NuevoNodo = new nodoLSC();
	
	int numero;
	printf("Ingrese el Nombre:\n");
	scanf("%s", &NuevoNodo->nombre);
	printf("Ingrese el Precio:\n");
	scanf("%i", &NuevoNodo->precio);
	printf("Ingrese el Codigo:\n");
	scanf("%i", &numero);
	
	NuevoNodo->codigo = numero; //asigna el numero al nodo
	
	if(inicioLSC == NULL){
		inicioLSC = NuevoNodo;
		finalLSC = NuevoNodo;
		inicioLSC->siguiente = inicioLSC;
		finalLSC->siguiente = inicioLSC;
	}else{
		struct nodoLSC *aux;
		aux = inicioLSC;
		/*
			El ultimo valor de la lista apunta a Inicio
		*/
		while (aux != finalLSC){
			aux = aux->siguiente;
		}
		
		aux->siguiente = NuevoNodo;
		NuevoNodo->siguiente = inicioLSC;
		finalLSC = NuevoNodo;
	}
	
	mostrarLSC();
}

void eliminarLSC(){
	struct nodoLSC *aux;
	struct nodoLSC *anterior = NULL;
	int num;
	
	
	if(inicioLSC != NULL){
		printf("Ingrese Codigo a Eliminar\n");
		scanf("%i", &num);
		aux = inicioLSC;
		char bandera = '0';
		
		while(aux != finalLSC){
			if(aux->codigo == num){
				if(anterior == NULL){//se eliminará el inicio
					inicioLSC = inicioLSC->siguiente;
					aux->siguiente = NULL;
					aux = NULL;
					free(aux);
				}else{//si no es el inicio
					anterior->siguiente = aux->siguiente;
					aux->siguiente = NULL;
					aux = NULL;
					free(aux);
				}
				bandera = '1';
				break;
			}
			
			anterior = aux;
			aux = aux->siguiente;
		}
		
		if((bandera == '0') && (aux->codigo == num)){
			if(anterior == NULL){//se eliminará el inicio
				inicioLSC = finalLSC = NULL;
				aux->siguiente = NULL;
				aux = NULL;
				free(aux);
			}else{//si no es el inicio
				anterior->siguiente = inicioLSC;
				finalLSC = anterior;
				aux->siguiente = NULL;
				aux = NULL;
				free(aux);
				
			}
		}
		
		mostrarLSC();
	}else{
		printf("LISTA VACIA\n");
	}
}

void mostrarLSC(){
	if(inicioLSC != NULL){
		struct nodoLSC *aux;
		aux = inicioLSC;
		while (aux != finalLSC){
			printf("------------------------------\n");
			printf("%s\n", aux->nombre);
			printf("%i\n", aux->precio);
			printf("%i\n", aux->codigo);
			printf("------------------------------\n");
			printf("   |   \n");
			printf("   V   \n");
			aux = aux->siguiente;
		}
		printf("------------------------------\n");
		printf("%s\n", aux->nombre);
		printf("%i\n", aux->precio);
		printf("%i\n", aux->codigo);
		printf("----------------------------------\n");
		
	}else{
		printf("LISTA VACIA\n");
	}
}

struct nodoLD{
	int num;
	
	struct nodoLD *siguiente;
	struct nodoLD *atras;
};

struct nodoLD *inicioLD, *finalLD;

void mostrarLD();

void agregarLD(){
	nodoLD *NuevoNodo = new nodoLD();
	
	int numero;
	printf("Ingrese el número:\n");
	scanf("%i", &numero);
	
	NuevoNodo->num = numero; //asigna el numero al nodo
	
	if(inicioLD == NULL){
		inicioLD = NuevoNodo;
		finalLD = NuevoNodo;
		inicioLD->siguiente = NULL;
		finalLD->siguiente = NULL;
		inicioLD->atras = NULL;
		finalLD->atras = NULL;
	}else{
		struct nodoLD *aux;
		aux = inicioLD;
		/*
			El ultimo valor de la lista apunta a NULL
		*/
		while (aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		
		aux->siguiente = NuevoNodo;
		NuevoNodo->atras = aux;
		NuevoNodo->siguiente = NULL;
		finalLD = NuevoNodo;
	}
	
	mostrarLD();
}

void eliminarLD(){
	struct nodoLD *aux;
	struct nodoLD *anterior = NULL;
	int num;
	printf("Ingrese Nodo a Eliminar\n");
	scanf("%i", &num);
	
	if(inicioLD != NULL){
		aux = inicioLD;
		while(aux != NULL){
			if(aux->num == num){
				if(anterior == NULL){//se eliminará el inicio
					if(inicioLD->siguiente != NULL){
						inicioLD = inicioLD->siguiente;
						inicioLD->atras = NULL;
					}else{
						inicioLD = finalLD = NULL;
					}
					aux->siguiente = NULL;
					aux->atras = NULL;
					aux = NULL;
					free(aux);
				}else{//si no es el inicio
					if(aux->siguiente != NULL){
					 	anterior->siguiente = aux->siguiente;
						aux->siguiente->atras = aux->atras;
					}else{
						anterior->siguiente = NULL;
						finalLD = anterior;
					}
					aux->siguiente = NULL;
					aux->atras = NULL;
					aux = NULL;
					free(aux);
				}
				break;
			}
			
			anterior = aux;
			aux = aux->siguiente;
		}
		
		mostrarLD();
	}else{
		printf("LISTA VACIA\n");
	}
}

void mostrarLD(){
	if(inicioLD != NULL){
		struct nodoLD *aux;
		aux = finalLD;
		while (aux != NULL){
			if(aux->atras != NULL){
				printf("%i -> ", aux->num);
			}else{
				printf("%i\n", aux->num);
			}
			aux = aux->atras;
		}
	}else{
		printf("LISTA VACIA\n");
	}
}

struct nodoLDC{
	char nombre[30];
	int precio;
	int codigo;
	
	struct nodoLDC *siguiente;
	struct nodoLDC *atras;
};

struct nodoLDC *inicioLDC, *finalLDC;

void mostrarLDC();

void agregarLDC(){
	nodoLDC *NuevoNodo = new nodoLDC();
	
	int numero;
	printf("Ingrese el Nombre:\n");
	scanf("%s", &NuevoNodo->nombre);
	printf("Ingrese el Precio:\n");
	scanf("%i", &NuevoNodo->precio);
	printf("Ingrese el Codigo:\n");
	scanf("%i", &numero);
	
	NuevoNodo->codigo = numero; //asigna el numero al nodo
	
	if(inicioLDC == NULL){
		inicioLDC = NuevoNodo;
		finalLDC = NuevoNodo;
		inicioLDC->siguiente = inicioLDC;
		finalLDC->siguiente = inicioLDC;
		inicioLDC->atras = inicioLDC;
		finalLDC->atras = inicioLDC;
	}else{
		struct nodoLDC *aux;
		aux = inicioLDC;
		/*
			El ultimo valor de la lista apunta a Inicio
		*/
		while (aux != finalLDC){
			aux = aux->siguiente;
		}
		
		aux->siguiente = NuevoNodo;
		NuevoNodo->atras = aux;
		NuevoNodo->siguiente = inicioLDC;
		inicioLDC->atras = NuevoNodo;
		finalLDC = NuevoNodo;
	}
	
	mostrarLDC();
}

void eliminarLDC(){
	struct nodoLDC *aux;
	struct nodoLDC *anterior = NULL;
	int num;
	
	
	if(inicioLDC != NULL){
		printf("Ingrese Codigo a Eliminar\n");
		scanf("%i", &num);
		aux = inicioLDC;
		char bandera = '0';
		
		while(aux != finalLDC){
			if(aux->codigo == num){
				if(anterior == NULL){//se eliminará el inicio
					inicioLDC = inicioLDC->siguiente;
					aux->siguiente = NULL;
					aux = NULL;
					free(aux);
				}else{//si no es el inicio
					anterior->siguiente = aux->siguiente;
					aux->siguiente = NULL;
					aux = NULL;
					free(aux);
				}
				bandera = '1';
				break;
			}
			
			anterior = aux;
			aux = aux->siguiente;
		}
		
		if((bandera == '0') && (aux->codigo == num)){
			if(anterior == NULL){//se eliminará el inicio
				inicioLDC = finalLDC = NULL;
				aux->siguiente = NULL;
				aux = NULL;
				free(aux);
			}else{//si no es el inicio
				anterior->siguiente = inicioLDC;
				finalLDC = anterior;
				aux->siguiente = NULL;
				aux = NULL;
				free(aux);
				
			}
		}
		
		mostrarLDC();
	}else{
		printf("LISTA VACIA\n");
	}
}

void mostrarLDC(){
	if(inicioLDC != NULL){
		struct nodoLDC *aux;
		aux = finalLDC;
		while (aux != inicioLDC){
			printf("------------------------------\n");
			printf("%s\n", aux->nombre);
			printf("%i\n", aux->precio);
			printf("%i\n", aux->codigo);
			printf("------------------------------\n");
			printf("   |   \n");
			printf("   V   \n");
			aux = aux->atras;
		}
		
		printf("------------------------------\n");
		printf("%s\n", aux->nombre);
		printf("%i\n", aux->precio);
		printf("%i\n", aux->codigo);
		printf("------------------------------\n");
		
	}else{
		printf("LISTA VACIA\n");
	}
}

void menu(){
	int op, op2, x, c, l, m, j;
	
	do{
		printf("1- Cola\n");
		printf("2- Pila\n");
		printf("3- Lista Simple\n");
		printf("4- Lista Simple Circular\n");
		printf("5- Lista Doble\n");
		printf("6- Lista Doble Circular\n");
		printf("0- Salir\n");
		scanf("%i", &op2);
		system("cls");
		
		switch(op2){
			case 1:
				do{
					printf("1- Ingresar Valor a Cola\n");
					printf("2- Eliminar\n");
					printf("3- Salir\n");
					scanf("%i", &op);
					
					if(op == 1){
				
						int numero;
						printf("Ingrese el número:\n");
						scanf("%i", &numero);
						agregarCola(numero);
					}else if(op == 2){
						eliminarCola();
					}
				}while(op!=3);
				system("cls");
				break;
			case 2:
				inicioPila = finalPila = NULL;
	
				int x;
				do{
					printf("1- Ingresar Valor a Pila\n");
					printf("2- Eliminar\n");
					printf("3- Salir\n");
					scanf("%i", &x);
				
					if(x == 1){
						agregarPila();
					}else if(x == 2){
						eliminarPila();
					}
				}while(x!=3);
				system("cls");
				break;
			case 3:
				do{
					printf("1- Ingresar Valor a Lista\n");
					printf("2- Eliminar\n");
					printf("3- Salir\n");
					scanf("%i", &c);
			
					if(c == 1){
						agregarLS();
					}else if(c == 2){
						eliminarLS();
					}
				}while(c!=3);
				system("cls");
				break;
			case 4:
				do{
					printf("1- Ingresar Valor a Lista\n");
					printf("2- Eliminar\n");
					printf("3- Salir\n");
					scanf("%i", &l);
					
					if(l == 1){
						agregarLSC();
					}else if(l == 2){
					eliminarLSC();
					}
				}while(l != 3);
				system("cls");
				break;
			case 5:
				do{
					printf("1- Ingresar Valor a Lista\n");
					printf("2- Eliminar\n");
					printf("3- Salir\n");
					scanf("%i", &m);
		
					if(m == 1){
						agregarLD();
					}else if(m == 2){
						eliminarLD();
					}
				}while(m != 3);
				system("cls");
				break;
			case 6:
				do{
					printf("1- Ingresar Valor a Lista\n");
					printf("2- Eliminar\n");
					printf("3- Salir\n");
					scanf("%i", &j);
		
					if(j == 1){
						agregarLDC();
					}else if(j == 2){
						eliminarLDC();
					}
				}while(j != 3);
				system("cls");
				break;
			default:
				exit(-1);
				break;
		}
		
	}while(op != 0);

}

int main(){
	inicio = final = NULL;
	inicioPila = finalPila = NULL;
	inicioLS = finalLS = NULL;
	inicioLSC = finalLSC = NULL;
	inicioLD = finalLD = NULL;
	inicioLDC = finalLDC = NULL;
	
	
	menu();
	
	return 0;
}
