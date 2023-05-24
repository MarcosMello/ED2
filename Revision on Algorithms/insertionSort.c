#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

void insertionSort(int *vetor, int size){
    int chave, i;

    for (int j = 1; j < size; j++){
        chave = vetor[j];
        i = j - 1;

        while (i >= 0 && vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i -= 1;
        }

        vetor[i + 1] = chave;
    }
}

int main(){
    int* lista = (int *) calloc(5, sizeof(int));

    lista[0] = 5;
    lista[1] = 4;
    lista[2] = 2;
    lista[3] = 3;
    lista[4] = 1;

    printLista(lista, 5, 1);

    insertionSort(lista, 5);

    printLista(lista, 5, 2);

    return 0;
}