#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f

typedef struct node {
    struct node *parent;
    struct node *child;
    struct node *sibling;
    int key;
    int degree;
} Heap;

void printBinomialHeap(Heap *heap){
    Heap *TMP = heap;

    while (TMP != NULL){
        printf("(%d - %d) ", TMP->key, TMP->degree);

        if (TMP->degree){
            printBinomialHeap(TMP->child);
        }

        TMP = TMP->sibling;
    }

    return;
}

Heap *alocaHeap(){
    Heap *newHeap = (Heap *) calloc(1, sizeof(Heap));

    if (newHeap == NULL){
        exit(1);
    }

    return newHeap;
}

Heap *BinomialHeapMinimo(Heap *heap){
    Heap *minHeap = NULL, *aux = heap;
    int min = INF;

    while (aux != NULL){
        if (aux->key < min){
            min = aux->key;

            minHeap = aux;
        }

        aux = aux->sibling;
    }

    return minHeap;
}

Heap *conectaHeapsBinomiais(Heap *pai, Heap *filho){
    filho->parent = pai;
    filho->sibling = pai->child;
    pai->child = filho;
    pai->degree++;

    return pai;
}

Heap *unirHeapsBinomiais(Heap *h1, Heap *h2){
    Heap *heapR = NULL, *auxRNext = NULL, *auxR, *heapAux = alocaHeap();

    while (h1 != NULL || h2 != NULL){
        if (h1 != NULL && h2 != NULL){
            if (h1->degree == h2->degree){
                if (h1->key == h2->key || h1->key < h2->key){
                    auxR = h2;
                    h2 = h2->sibling;

                    auxR = conectaHeapsBinomiais(h1, auxR);

                    h1 = h1->sibling;
                } else {
                    auxR = h1;
                    h1 = h1->sibling;

                    auxR = conectaHeapsBinomiais(h2, auxR);

                    h2 = h2->sibling;
                }
            } else if (h1->degree < h2->degree){
                auxR = h1;

                h1 = h1->sibling;
            } else {
                auxR = h2;

                h2 = h2->sibling;
            }
        } else if (h1 != NULL){
            auxR = h1;

            h1 = h1->sibling;
        } else {
            auxR = h2;

            h2 = h2->sibling;
        }

        auxR->sibling = NULL;

        if (auxRNext != NULL){
            if (auxRNext->degree == auxR->degree){
                if (auxRNext->key > auxR->key){
                    *(heapAux) = *(auxRNext);
                    *(auxRNext) = *(auxR);
                    *(auxR) = *(heapAux);
                }

                conectaHeapsBinomiais(auxRNext, auxR);
            } else {
                auxRNext->sibling = auxR;
                auxRNext = auxRNext->sibling;
            }
        } else{
            heapR = auxR;
            auxRNext = heapR;
        }
    }

    return heapR;
}

Heap *inserirHeapBinomial(int chave, Heap *heap){
    Heap *newHeap = alocaHeap();

    newHeap->degree = 0;
    newHeap->key = chave;

    return unirHeapsBinomiais(heap, newHeap);
}

Heap *removeHeapBinomial(Heap *heap){
    Heap *heapToBeRemoved = BinomialHeapMinimo(heap), *aux = heap, *newHeap = NULL;

    if (aux != heapToBeRemoved){
        while (aux->sibling != NULL && aux->sibling != heapToBeRemoved){
            aux = aux->sibling;
        }

        aux->sibling = heapToBeRemoved->sibling;
    } else {
        heap = heapToBeRemoved->sibling;
    }

    aux = heapToBeRemoved->child;
    free(heapToBeRemoved);

    heapToBeRemoved = aux;

    while (heapToBeRemoved != NULL){
        if (newHeap == NULL){
            newHeap = heapToBeRemoved;

            heapToBeRemoved = heapToBeRemoved->sibling;

            newHeap->sibling = NULL;
        } else{
            aux = heapToBeRemoved;

            heapToBeRemoved = heapToBeRemoved->sibling;

            aux->sibling = newHeap;
            newHeap = aux;
        }
    }

    return unirHeapsBinomiais(heap, newHeap);
}

int main(){
    Heap *p1_1 = (Heap *) calloc(1, sizeof(Heap));

    Heap *p1_2 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p1_2_1 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p1_2_2 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p1_2_1_1 = (Heap *) calloc(1, sizeof(Heap));

    p1_1->degree = 0;
    p1_1->key = 12;
    p1_1->sibling = p1_2;

    p1_2->degree = 2;
    p1_2->key = 8;
    p1_2->child = p1_2_1;

    p1_2_1->degree = 1;
    p1_2_1->key = 11;
    p1_2_1->child = p1_2_1_1;
    p1_2_1->sibling = p1_2_2;
    p1_2_1->parent = p1_2;

    p1_2_1_1->parent = p1_2_1;
    p1_2_1_1->degree = 0;
    p1_2_1_1->key = 27;

    p1_2_2->parent = p1_2;
    p1_2_2->degree = 0;
    p1_2_2->key = 17;

    Heap *h1 = p1_1;



    Heap *p2_1 = (Heap *) calloc(1, sizeof(Heap));

    Heap *p2_2 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p2_2_1 = (Heap *) calloc(1, sizeof(Heap));

    Heap *p2_3 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p2_3_1 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p2_3_2 = (Heap *) calloc(1, sizeof(Heap));
    Heap *p2_3_1_1 = (Heap *) calloc(1, sizeof(Heap));

    p2_1->degree = 0;
    p2_1->key = 18;
    p2_1->sibling = p2_2;

    p2_2->degree = 1;
    p2_2->key = 1;
    p2_2->child = p2_2_1;
    p2_2->sibling = p2_3;

    p2_2_1->degree = 0;
    p2_2_1->key = 25;
    p2_2_1->parent = p2_2;

    p2_3->degree = 2;
    p2_3->key = 6;
    p2_3->child = p2_3_1;

    p2_3_1->child = p2_3_1_1;
    p2_3_1->degree = 1;
    p2_3_1->key = 14;
    p2_3_1->parent = p2_3;
    p2_3_1->sibling = p2_3_2;

    p2_3_1_1->degree = 0;
    p2_3_1_1->key = 38;
    p2_3_1_1->parent = p2_3_1;

    p2_3_2->degree = 0;
    p2_3_2->key = 29;
    p2_3_2->parent = p2_3;

    Heap *h2 = p2_1;

    printBinomialHeap(h1);
    printf("\n\n");

    printBinomialHeap(h2);
    printf("\n\n");

    Heap *h3 = unirHeapsBinomiais(h1, h2);

    printBinomialHeap(h3);
    printf("\n\n");

    h3 = inserirHeapBinomial(5, h3);

    printBinomialHeap(h3);
    printf("\n\n");

    h3 = inserirHeapBinomial(15, h3);

    printBinomialHeap(h3);
    printf("\n\n");

    h3 = removeHeapBinomial(h3);

    printBinomialHeap(h3);
    printf("\n");

    return 0;
}