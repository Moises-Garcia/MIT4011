#include <stdio.h>
#include <stdlib.h> 

struct node
{
	int data;
	struct node* next;	
};

void insertar(struct node** head, int value)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp -> data = value;
	tmp -> next = NULL;
	if(!(*head))
	{
		(*head) = tmp;
		return;
	}

	struct node* cur = *head;
	while((cur -> next) != NULL)
		cur = cur -> next;
	cur -> next = tmp;
}

void eliminar_ul(struct node** head)
{
	if(*head == NULL)
	{
		printf("La lista esta vacia.\n");
		return;
	}
	struct node* tmp = *head;
	struct node* del;
	if(tmp -> next == NULL)
	{
		*head = NULL;
		return;
	}
	while(tmp -> next -> next != NULL)
	{
		tmp = tmp -> next;
	}
	del = tmp -> next -> next;
	tmp -> next = NULL;
  	free(del);
}

void eliminal_x(struct node** head, int key)
{
	if(*head == NULL)
	{
		printf("La lista esta vacia.\n");
		return;
	}
	struct node* tmp = *head;
	struct node* del;
	if(tmp -> next == NULL){
		if(tmp -> data != key)
		{
			printf("El valor no existe.\n");
			return;
		}
		else
		{
			*head = NULL;
			return;
		}
	}
	while(tmp -> next -> next != NULL && tmp -> next -> data != key)
	{
		tmp = tmp -> next;
	}
	if(tmp -> next -> data != key)
	{
		printf("El valor no existe.\n");
		return;
	}
	else
	{
		del = tmp -> next;
		tmp -> next = tmp -> next -> next;
		free(del);
		return;
	}
}

void buscar_x(struct node** head, int key)
{
	if(*head == NULL)
	{
		printf("La lista esta vacia.\n");
		return;
	}
	int con = 1;
	struct node* tmp = *head;
	while(tmp -> next != NULL && tmp -> data != key)
	{
		tmp = tmp -> next;
		con++;
	}
	if(tmp -> data != key)
	{
		printf("El valor no existe.\n");
		return;
	}
	else
	{
		printf("El valor existe en la posicion '%d'.\n", con);
		return;
	}
}

void cambiar_x(struct node** head, int key, int new)
{
	if(*head == NULL)
	{
		printf("La lista esta vacia.\n");
		return;
	}
	struct node* tmp = *head;
	while(tmp -> next != NULL && tmp -> data != key)
	{
		tmp = tmp -> next;
	}
	if(tmp -> data != key)
	{
		printf("El valor no existe.\n");
		return;
	}
	else
	{
		tmp -> data = new;
		return;
	}
}

void imprime(struct node* head)
{
	struct node* tmp = head;
	if(tmp == NULL)
	{
		printf("La lista esta vacia.\n");
		return;
	}
	while(tmp != NULL)
	{
		printf("%d", tmp -> data);
		if(tmp -> next != NULL)
			printf(" -> ");
		tmp = tmp -> next;
	}
	printf("\n");
}

int main()
{
	struct node* head = NULL;
	int m = 1;
	int i, j;
	while (m != 6)
	{
		printf("Elige la opcion\n [0] Inserta un valor.\n [1] Borra el ultimo valor.\n [2] Borra un numero especifico.\n [3] Busca un nodo.\n [4] Cambia un valor.\n [5] Imprime la lista.\n [6] Salir.\n");
		scanf("%d", &m);
		switch(m)
		{
			case 0:
				printf("Dame el valor que quieres agregar:\n");
				scanf("%d", &i);
				insertar(&head, i);
				break;
			case 1:
				eliminar_ul(&head);
				break;
			case 2:
				printf("Dame el valor que quieres eliminar:\n");
				scanf("%d", &i);
				eliminal_x(&head, i);
				break;
			case 3:
				printf("Dame el valor que quieres buscar: \n");
				scanf("%d", &i);
				buscar_x(&head, i);
				break;
			case 4:
				printf("Dame el valor que quieres cambiar: \n");
				scanf("%d", &i);
				printf("Dame el nuevo valor: \n");
				scanf("%d", &j);
				cambiar_x(&head, i, j);
				break;
			case 5:
				imprime(head);
				printf("\n");
				break;
			default:
				break;
		}
	}
	return 0;
}
