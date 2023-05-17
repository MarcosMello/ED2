#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f

/*
    Heap de Fibonacci é usado para implementar priority_queue do c++
    logo, o que interessa para esse é sempre dar o menor valor dessa estrutura com O(1)
*/

typedef struct no{
    int chave;
    int grau;
    int marca;
    struct no *pai;
    struct no *filho;
    struct no *esq;
    struct no *dir;
} NO;

typedef struct head{
    int nos;
    struct no *min;
} FHEAP;

FHEAP *criaHeap(){
    return (FHEAP *) calloc(1, sizeof(FHEAP));
}

FHEAP *insereHeapFibonacci(FHEAP *heap, int n){
    NO *no = (NO *) calloc(1, sizeof(NO));
    no->chave = n;

    no->dir = (heap == NULL) ? no : heap->min->dir;
    no->esq = (heap == NULL) ? no : heap->min;
    heap->min->dir = no;

    if (heap->min == NULL || heap->min->chave > no->chave){
        heap->min = no;
    }

    heap->nos++;
}

FHEAP *uniaoHeapFibonacci(FHEAP *heap1, FHEAP *heap2);

void consolidar(FHEAP *heap); //junta as arvores para que tenham graus distintos
//lg n -> 0 até lg n (todos os nos)
//une baseado no que está na lista e não linearmente
//o vetor não precisa estar completamente preenchido

void extrairMin(FHEAP *heap);

void corte(FHEAP *heap, NO *node, NO *pai);

void corteCascata(FHEAP *heap, NO *pai);

void decrementarChave(FHEAP *heap, NO *node, int dec);

void deletar(FHEAP *heap, NO *node){
    decrementarChave(heap, node, -INF);
    extrairMin(heap);
}