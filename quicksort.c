// 9 2 3 7 4
//         ^
// [2, 3] 4 [7, 9]
//     ^     ^
// [2, 3] [4, 7, 9]
// [2, 3, 4, 7, 9]

//trocar elementos de lugar baseado no i que sempre vai guardar o último elemento da lista de menores elementos

// [2, 1, 3, 8,   7, 5, 6, 4]
//  p     i (i+1)          r

// [2, 1, 3, 4,   7, 5, 6, 8]
//  p     i (i+1)          r

//não criar uma cópia da lista

//q = particao(A, p, r) -> resposta da função é o indice do pivo em sua posição correta;
//quicksort(A, p, q-1);
//quicksort(A, q+1, r);

//em partição precisamos usar uma função para iterar sobre a lista
//caso os numeros sejam repetidos, podemos utilizar <= para resolver

//melhor caso é onde o pivo é o elemento central da lista => O(nlog(n))
//pior caso é onde a lista já se encontra a lista ordenada, seja essa decrescente ou crescente => O(n^2)
//como evitar o pior caso? sortear três elementos e escolher o elemento do meio -> implementar esse (sempre passar o pivo para o final da lista)

//caso tenhamos elementos repetidos, estaremos no pior caso do particiona =>
//Usa uma nova variavel para podermos saber onde começa os números repetidos (que estarão sempre sendo jogados para o final) para podermos ordenar depois os mesmos após o i

#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

int particionaAleatorio(int* lista, int inicio, int fim){
    int cPivot1 = (rand() % (fim - inicio + 1)) + inicio;
    int cPivot2 = (rand() % (fim - inicio + 1)) + inicio;
    int cPivot3 = (rand() % (fim - inicio + 1)) + inicio;

    int pivotIndex;

    if (cPivot1 > cPivot2 && cPivot1 > cPivot3){
        pivotIndex = cPivot1;
    } else if (cPivot2 > cPivot3 && cPivot2 > cPivot1){
        pivotIndex = cPivot2;
    } else {
        pivotIndex = cPivot3;
    }

    int pivot = *(lista + pivotIndex);

    int i = -1;

    for (int j = 0; j < fim + 1; j++){
        if (j != pivotIndex && (*(lista + j) < pivot)){
            int tmp = *(lista + j);

            *(lista + j) = *(lista + (i + 1));
            *(lista + (i + 1)) = tmp;
            i++;
        }
    }

    *(lista + pivotIndex) = *(lista + (i + 1));
    *(lista + (i + 1)) = pivot;

    return (i + 1);
}

void quicksortAleatorio(int* lista, int inicio, int fim){
    if (inicio < fim){
        int q = particionaAleatorio(lista, inicio, fim);
        quicksortAleatorio(lista, inicio, q-1);
        quicksortAleatorio(lista, q+1, fim);
    }
}

int particiona(int* lista, int inicio, int fim){
    int pivot = *(lista + fim);

    int i = -1;

    for (int j = 0; j < fim; j++){
        if (*(lista + j) < pivot){
            int tmp = *(lista + j);

            *(lista + j) = *(lista + (i + 1));
            *(lista + (i + 1)) = tmp;
            i++;
        }
    }

    *(lista + fim) = *(lista + (i + 1));
    *(lista + (i + 1)) = pivot;

    return (i + 1);
}

void quicksort(int* lista, int inicio, int fim){
    if (inicio < fim){
        int q = particiona(lista, inicio, fim);
        quicksort(lista, inicio, q-1);
        quicksort(lista, q+1, fim);
    }
}

int main(){
    int *lista = calloc(6, sizeof(int));

    *(lista + 0) = 6;
    *(lista + 1) = 2;
    *(lista + 2) = 5;
    *(lista + 3) = 3;
    *(lista + 4) = 4;
    *(lista + 5) = 1;

    printLista(lista, 6, 1);

    quicksort(lista, 0, 5);

    printLista(lista, 6, 2);

    *(lista + 0) = 6;
    *(lista + 1) = 2;
    *(lista + 2) = 5;
    *(lista + 3) = 3;
    *(lista + 4) = 4;
    *(lista + 5) = 1;

    printLista(lista, 6, 3);

    quicksortAleatorio(lista, 0, 5);

    printLista(lista, 6, 4);

    return 1;
}