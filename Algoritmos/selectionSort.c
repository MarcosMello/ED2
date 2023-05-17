#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

void selectionSort(int* lista, int size){
    int menor, aux = 0;

    for (int i = 0; i < size; i++){
        menor = i;

        for (int j = (i + 1); j < size; j++){
            if (lista[menor] > lista[j]){
                menor = j;
            }
        }

        aux = lista[i];
        lista[i] = lista[menor];
        lista[menor] = aux;

        aux = 0;
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

    selectionSort(lista, 5);

    printLista(lista, 5, 2);

    return 0;
}