#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

void merge (int *V, int inicio, int meio, int fim){ //conquista: recebe inicio, meio, fim, vet
	//cria as variaveis iniciais, com os vetores P1 E P2
	int i, j, k, p1, p2, *temp, tamanho;
	int fim1=0, fim2=0;
	tamanho = fim-inicio+1;
	p1=inicio; //defino o inicio dos vetores
	p2=meio+1;
	temp = (int *)malloc(tamanho*sizeof(int));//cria um novo vet: temp, com alloc
	if(temp!=NULL){//if(temp!null):
		for(i=0;i<tamanho;i++){ //percorrer os vetor
			if(!fim1 && !fim2){ //combina ordenado
				if(V[p1]<V[p2]){ // comparar os elementos do vetor de P1 E P2;
					temp[i]=V[p1++]; // caso p1>p2: add elemento de p2(e vice versa)  em temp;
				}else{
					temp[i]=V[p2++];
				}
				//vetor acabou??
				if(p1>meio) fim1=1; //verificar se acabou os vetores (p1 e p2)
				if(p2>fim) fim2=1;
			}else{ //copiar todos os elmentos restantes para o vet temp
				if(!fim1){
					temp[i] = V[p1++];
				}else{
					temp[i] = V[p2++];
				}
			}
		}
		for (j=0, k=inicio; j<tamanho; j++,k++){ //fazer copia do vet auxiliar, para o original
			V[k] = temp[j];
		}
	}
	free(temp); //no final da free(temp);
}

//duas funções uma divide e a outra conquista
void mergeSort(int *V, int inicio, int fim){ //divide: recebe vet, inicio, fim
	int meio;
	if(inicio<fim){ //verifica se inicio < fim
		meio = floor ((inicio+fim)/2); //calcula o meio floor ((inicio+fim/2))
		mergeSort(V, inicio, meio); //chama a função mergesort (com os novos valores)
		mergeSort(V, meio+1, fim);
		merge(V,inicio,meio,fim); //chama a função de conquistar
	}
}

int main(){
    int* lista = (int *) calloc(6, sizeof(int));

    lista[0] = 5;
    lista[1] = 4;
    lista[2] = 2;
    lista[3] = 3;
    lista[4] = 1;
    lista[5] = 0;

    printLista(lista, 6, 1);

    mergeSort(lista, 0, 6);

    printLista(lista, 6, 2);

    return 0;
}