#include <stdio.h>
#include <stdlib.h>

//array semelhante a uma arvore binária completa (quando temos folhas no penúltimo e último nível)
// [0, 1, 2]
// x   ^
//     | raiz do heap
// após, segue os níveis da árvore da esquerda para a direita.
// 1-> raiz
// 2 e 3 -> nós do primeiro nível
// 4, 5, 6 e 7 -> nós do segundo nível ...
// filhos de 5 = 5x2 e (5x2) + 1
// pai de 5 = piso de 5 / 2. divisão inteira

// heap máximo -> filho menor que o pai (A[pai(i)] >= A[i]), com excessão da raiz; (Raiz >)
// heap mínimo -> filho maior que o pai (A[pai(i)] <= A[i]), com excessão da raiz; (Raiz <) Altura é dada pela raiz, com a maior altura sendo a raiz

// maxHeapify (heap maximo) (int *array, int i) -> utilizado para fazer com que, se ambos filhos forem hep máximos, o elemento em I seja maior que seus filhos, atendendo assim as regras do heapmáximo
// podemos usar as folhas para poder converter qualquer array em um heap de baixo para cima, uma vez que as folhas já são heap máximo

// podemos utilizar o maxHeapify para criar um heap e depois usar o mesmo para ordenar uma lista

//podemos por fim utilizar o heap para criar uma fila de prioridade

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

typedef struct heap{
    int *lista;
    int tamanho;
} Heap;

int pai(int i){
    return i / 2;
}

int esquerdo(int i){
    return (i * 2);
}

int direito(int i){
    return (i * 2) + 1;
}

void maxHeapify(Heap *heap, int i){
    int e = esquerdo(i);
    int d = direito(i);

    int maior = i;

    if (e <= heap->tamanho && *(heap->lista + e) > *(heap->lista + maior)){
        maior = e;
    }

    if (d <= heap->tamanho && *(heap->lista + d) > *(heap->lista + maior)){
        maior = d;
    }

    if (maior != i){
        int tmp = *(heap->lista + maior);

        *(heap->lista + maior) = *(heap->lista + i);
        *(heap->lista + i) = tmp;

        maxHeapify(heap, maior);
    }

    return;
}

Heap* construirHeapMaximo(int *vetor, int tamanho){
    Heap *heap = (Heap *) calloc(1, sizeof(Heap));

    heap->tamanho = tamanho - 1;
    heap->lista = vetor;

    for (int i = tamanho/2; i > 0; i--){
        maxHeapify(heap, i);
    }

    return heap;
}

void heapsort(int *vetor, int tamanho){
    Heap *heap = construirHeapMaximo(vetor, tamanho);

    for (int i = (tamanho - 1); i > 1; i--){
        int tmp = *(heap->lista + i);

        *(heap->lista + i) = *(heap->lista + 1);
        *(heap->lista + 1) = tmp;

        heap->tamanho--;

        maxHeapify(heap, 1);
    }
}

int main(){
    int *vetor = (int *) calloc(11, sizeof(int));

    *(vetor + 1) = 4;
    *(vetor + 2) = 1;
    *(vetor + 3) = 3;
    *(vetor + 4) = 2;
    *(vetor + 5) = 16;
    *(vetor + 6) = 9;
    *(vetor + 7) = 10;
    *(vetor + 8) = 14;
    *(vetor + 9) = 8;
    *(vetor + 10) = 7;

    printLista(vetor, 11, 1);

    heapsort(vetor, 11);

    printLista(vetor, 11, 2);

    return 0;
}
