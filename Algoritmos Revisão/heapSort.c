#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int tamanho;
    int *heap;
}Heap;

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

int pai(int pos){
    return pos/2;
}

int filhoEsquerdo(int pos){
    return pos * 2;
}

int filhoDireita(int pos){
    return (pos * 2) + 1;
}

void maxHeapify(Heap *heap, int i){
    int esq, dir, tmp, maior = i;

    esq = filhoEsquerdo(i);
    dir = filhoDireita(i);

    if ((heap->tamanho >= esq) && (*(heap->heap + esq) > *(heap->heap + maior))){
        maior = esq;
    }

    if ((heap->tamanho >= dir) && (*(heap->heap + dir) > *(heap->heap + maior))){
        maior = dir;
    }

    if (maior != i){
        tmp = *(heap->heap + i);

        *(heap->heap + i) = *(heap->heap + maior);
        *(heap->heap + maior) = tmp;

        maxHeapify(heap, maior);
    }
}

Heap *construirMaxHeap(int *lista, int tamanho){
    Heap *heap = (Heap *) calloc(1, sizeof(Heap));

    heap->tamanho = tamanho - 1;
    heap->heap = lista;

    for (int i = ((heap->tamanho + 1) / 2); i > 0; i--){
        maxHeapify(heap, i);
    }

    return heap;
}

void heapSort(int *lista, int tamanho){
    int tmp;
    Heap *heap = construirMaxHeap(lista, tamanho);

    for (int i = heap->tamanho; i > 1; i--){
        tmp = *(heap->heap + 1);

        *(heap->heap + 1) = *(heap->heap + i);
        *(heap->heap + i) = tmp;

        heap->tamanho--;

        maxHeapify(heap, 1);
    }
}

int main(){
    int *vetor = (int *) calloc(9, sizeof(int));

    *(vetor + 1) = 50;
    *(vetor + 2) = 40;
    *(vetor + 3) = 30;
    *(vetor + 4) = 33;
    *(vetor + 5) = 15;
    *(vetor + 6) = 10;
    *(vetor + 7) = 20;
    *(vetor + 8) = 60;

    printLista(vetor, 9, 1);

    printLista(construirMaxHeap(vetor, 9)->heap, 9, 2);

    heapSort(vetor, 9);

    printLista(vetor, 9, 3);

    return 0;
}