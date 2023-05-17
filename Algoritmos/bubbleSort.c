#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

void bubbleSort(int* lista, int size){
    int tmp;

    for (int i = 0; i < size; i++){
        for (int j = 1; j < size; j++){
            if (lista[j - 1] > lista[j]){
                tmp = lista[j - 1];
                lista[j - 1] = lista[j];
                lista[j] = tmp;
            }
        }
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

    bubbleSort(lista, 5);

    printLista(lista, 5, 2);

    return 0;
}