#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

int particiona(int* lista, int inicio, int fim){
    int chave = lista[fim];
    int i = inicio - 1, tmp;

    for (int j = inicio; j < fim; j++){
        if (lista[j] <= chave){
            i++;

            tmp = lista[j];
            lista[j] = lista[i];
            lista[i] = tmp;
        }
    }

    tmp = lista[fim];
    lista[fim] = lista[i + 1];
    lista[i + 1] = tmp;

    return i + 1;
}

int particionaAleatorizado(int *lista, int inicio, int fim){
    int cPivot1 = (rand() % (fim - inicio + 1)) + inicio;
    int cPivot2 = (rand() % (fim - inicio + 1)) + inicio;
    int cPivot3 = (rand() % (fim - inicio + 1)) + inicio;

    int pivot;

    if ((lista[cPivot1] > lista[cPivot2] && lista[cPivot1] < lista[cPivot3]) || (lista[cPivot1] < lista[cPivot2] && lista[cPivot1] > lista[cPivot3])){
        pivot = cPivot1;
    } else if ((lista[cPivot2] > lista[cPivot1] && lista[cPivot2] < lista[cPivot3]) || (lista[cPivot2] < lista[cPivot1] && lista[cPivot2] > lista[cPivot3])){
        pivot = cPivot2;
    } else {
        pivot = cPivot3;
    }

    int tmp = lista[pivot];
    lista[pivot] = lista[fim];
    lista[fim] = tmp;

    return particiona(lista, inicio, fim);
}

int particionaCRepticao(int* lista, int inicio, int fim){
    int chave = lista[fim];
    int i = inicio - 1, rep = fim, tmp;

    for (int j = inicio; j < fim; j++){
        if (lista[j] < chave){
            i++;

            tmp = lista[j];
            lista[j] = lista[i];
            lista[i] = tmp;
        } else if (lista[j] == chave && j < rep){
            rep--;

            tmp = lista[j];
            lista[j] = lista[rep];
            lista[rep] = tmp;

            j--;
        }
    }

    int nI = i + 1;

    for (int j = rep; rep <= fim; rep++){
        tmp = lista[j];
        lista[j] = lista[nI];
        lista[nI] = tmp;

        nI++;
    }

    return i + 1;
}

void quickSort(int* lista, int inicio, int fim, int (*Fparticiona)(int*, int, int)){
    int pivot;

    if (fim > inicio){
        pivot = Fparticiona(lista, inicio, fim);
        quickSort(lista, inicio, pivot - 1, Fparticiona);
        quickSort(lista, pivot + 1, fim, Fparticiona);
    }
}

int main(){
    int* lista = (int *) calloc(6, sizeof(int));

    lista[0] = 5;
    lista[1] = 5;
    lista[2] = 2;
    lista[3] = 5;
    lista[4] = 1;
    lista[5] = 5;

    printLista(lista, 6, 1);

    quickSort(lista, 0, 5, &particionaCRepticao);

    printLista(lista, 6, 2);

    return 0;
}