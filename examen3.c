#include <stdio.h>
void imprimir(int arr[], int tam){
	for (int i=0; i<tam; i++) {
		printf("%d ",arr[i]);
	}
	
}
void quickS(int arr[],int init,int tam){
	int cero = init, ultim = tam; 
	int ref, aux, dd;
	dd =(cero+ultim)/2;
	ref = arr[dd];
	cero = init;
	ultim = tam;
	do{
		while(cero<tam && arr[cero]<ref){
			cero++;
		}
		while(ultim > init && ref<arr[ultim]){
			ultim--;
		}
		if(cero <=ultim){
			aux = arr[ultim];
			arr[ultim]=arr[cero];
			arr[cero]=aux;
			ultim--;
			cero++;
		}
	}while(cero<=ultim);
	if(init<ultim)
		quickS(arr,init,ultim);
	if(tam>cero)
		quickS(arr,cero,tam);
}
int main(){
	int tam;
	printf("Dame el tamaño de tu arreglo:\n");
	scanf("%d", &tam);
	int arr[tam];
	printf("Introduce los valores: \n");
	for(int i = 0; i<tam;i++){
		int valor;
		scanf("%d", &valor);
		arr[i]=valor;
	}
	quickS(arr,0,tam-1);
	printf("Tus valores ordenados: \n");
	imprimir(arr, tam);
	printf("\n");
	return 0;
}