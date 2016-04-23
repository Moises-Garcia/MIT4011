#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>

typedef struct tCell {
	int payload;
	void* next;
}Cell;

Cell* agregar (Cell *root, int numero){
	Cell *nuevo_nodo;
	nuevo_nodo = (Cell*)malloc(sizeof(Cell));
	nuevo_nodo->payload= numero;
	nuevo_nodo->next= NULL;
	Cell *cursor = root;
	while (cursor->next != NULL){
		cursor = (Cell*)cursor->next;
	}
	cursor->next = (void*)nuevo_nodo;
 	return root;
}
void imprimeLista (Cell *root){
	printf ("x");
	while ((root = ((Cell*)root->next )) !=NULL){
		printf ("-->%d ",  root->payload);
	printf("\n");
	}
}
Cell *pop(Cell *root){
	Cell *cursor = root;
	if(root->next == NULL) return root;
	while(((Cell*)cursor->next)->next != NULL){
		cursor = (Cell*)cursor->next;
	}
	free(cursor->next);
	cursor->next = NULL;
	return root;
}
Cell *erase( Cell *root){
	while(root->next != NULL)
		pop(root);
	return root;
}
int menu(){
		int opcion;
		printf ("Menu: \n 0: Agrega nodo \n 1: Borrar ultimo numero \n 2: Imprime lista \n 3: Salir \n Selecciona opción:");
		scanf ("%d", &opcion);
	return opcion;
}

int main(int argc, char* argv[]){
	Cell root;
	int nuevo_numero;
	root.payload = -1;
	root.next= NULL;
	int opcion = menu();
	while( opcion != 3){
		if(opcion ==0){
			printf ("Dame un numero:");
			scanf ("%d", &nuevo_numero);
			agregar(&root, nuevo_numero);
			printf("\n");
		}else if (opcion ==1){
			pop (&root);
		}else if (opcion ==2){
			imprimeLista(&root);
		}
		printf("\n");
		opcion= menu();
	} 
	erase(&root);
	return 0;
}	

	
