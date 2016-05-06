#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>

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
Cell *Search(Cell *root, int find){
	Cell *Buscador;
	bool nodo= true;
	Buscador =root;
	while((Buscador->payload) != find && nodo== true){
		if(Buscador->next != NULL){
			Buscador= (Cell*) Buscador->next;
		}else{
			nodo=false;
		}
	}
	if(nodo== false){
		printf("Ese nodo no existe =(");
	}else{
		printf("Si existe ese nodo =)");
	}
	return root;
}
Cell *Insertar(Cell *root, int insertar, int nuevonodo){
	Cell *agregar;
	bool nodo= true;
	agregar = root;
	while((agregar->payload) != insertar && nodo == true){
		if(agregar->next != NULL){	
			agregar = (Cell*)agregar->next;
		}else{
			nodo = false;
		}
	}
	if(nodo == false){
		printf("No se encontro nodo\n");
	}else{
		agregar->payload = nuevonodo;
	}
	return root;
}
Cell *Delete (Cell *root, int eliminar) {
	Cell *X;
	Cell *A;
	bool nodo= true;
	X = root;
	while((X->payload) != eliminar && nodo == true){
		if(X->next != NULL){
			A = X;	
			X = (Cell*)X->next;
		}else{
			nodo = false;
		}
	}
	if(nodo == false){
		printf("No se encontro nodo");
	}else{
		if(root == X)
			root = (Cell*)X->next;
		else
			A->next = X->next;
		free((void*)X);
	}
   return root;
}   
void imprimelaLista (Cell *root){
	printf ("Empieza la serie");
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
Cell *Pop( Cell *root){
	while(root->next != NULL)
		pop(root);
	return root;
}
int menu(){
		int opcion;
		printf ("Menu- \n 0- Agrega nodo \n 1- Borrar ultimo numero \n 2- Imprime la lista \n 3- Borrar nodo \n 4- Editar nodo \n 5- Buscar nodo \n 6- Salir \n introduce opción del menu;");
		scanf ("%d", &opcion);
	return opcion;
}

int main(int argc, char* argv[]){
	Cell root;
	int nuevo_numero, eliminar, nuevonodo, find, insertar;
	root.payload = -1;
	root.next= NULL;
	int opcion = menu();
	while( opcion != 6){
		if(opcion ==0){
			printf ("Escribe un numero:");
			scanf ("%d", &nuevo_numero);
			agregar(&root, nuevo_numero);
			printf("\n");
		}else if (opcion ==1){
			pop (&root);
		}else if (opcion ==2){
			imprimelaLista(&root);
		}else if (opcion ==3){
			printf("Que nodo deseas borrar:\n");
			scanf("%d", &eliminar);
			Delete(&root, eliminar);
			
		}else if (opcion ==4){
			
			printf("Que nodo deseas cambiar:\n");
			scanf("%d", &insertar);
			printf("Que nodo deseas poner\n");
			
			scanf("%d", &nuevonodo);
			Insertar(&root, insertar, nuevonodo);
		}else if (opcion ==5){
			
			printf("Que nodo quieres buscar:\n");
			scanf("%d", &find);
			Search(&root, find);
		}
		printf("\n");
		opcion= menu();
	} 
	Pop(&root);
	return 0;
}