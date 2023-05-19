#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f

typedef struct node {
    struct node *parent;
    int key;
    int degree;
    struct node *child;
    struct node *sibling;
} HEAP;

void printBinomialHeap(HEAP *heap){
    HEAP *TMP = heap;

    while (TMP != NULL){
        printf("(%d - %d) ", TMP->key, TMP->degree);

        if (TMP->degree){
            printBinomialHeap(TMP->child);
        }

        TMP = TMP->sibling;
    }

    return;
}

HEAP* minBinomialHeapKey(HEAP *heap){
    HEAP *heapPointer = heap, *minHeap = NULL;
    int minValue = INF;

    while (heapPointer != NULL) {
        if (heapPointer->key < minValue){
            minValue = heapPointer->key;
            minHeap = heapPointer;
            heapPointer = heapPointer->sibling;
        }
    }

    return minHeap;
}

void connectBinomialHeaps(HEAP *heapChild, HEAP *heapParent){
    heapChild->parent = heapParent;
    heapChild->sibling = heapParent->child;
    heapParent->child = heapChild;
    heapParent->degree++;
}

HEAP* uniteBinomialHeap(HEAP *heap1, HEAP *heap2){ //mudar para receber o conteudo ao invés de ponteiro para não deixar h1 e h2 com conteúdo
    HEAP *exitHeap = NULL, *tmpHeap = NULL, *exitTmp = NULL;

    while (heap1 != NULL || heap2 != NULL){
        if (heap1 != NULL && heap2 != NULL){
            if (heap1->degree == heap2->degree){
                if (heap1->key < heap2->key){
                    tmpHeap = heap2;
                    heap2 = heap2->sibling;

                    connectBinomialHeaps(tmpHeap, heap1);

                    tmpHeap = heap1;
                    heap1 = heap1->sibling;
                } else{
                    tmpHeap = heap1;
                    heap1 = heap1->sibling;

                    connectBinomialHeaps(tmpHeap, heap2);

                    tmpHeap = heap2;
                    heap2 = heap2->sibling;
                }
            } else if (heap1->degree < heap2->degree){
                tmpHeap = heap1;
                heap1 = heap1->sibling;
            } else{
                tmpHeap = heap2;
                heap2 = heap2->sibling;
            }
        } else if (heap1 != NULL){
            tmpHeap = heap1;
            heap1 = heap1->sibling;
        } else{
            tmpHeap = heap2;
            heap2 = heap2->sibling;
        }

        if(exitTmp != NULL){
            if (tmpHeap->degree == exitTmp->degree){
                if (exitTmp->key < tmpHeap->key){
                    connectBinomialHeaps(tmpHeap, exitTmp);
                } else{
                    HEAP *mergeTmp = (HEAP *) calloc(1, sizeof(HEAP));

                    tmpHeap->sibling = NULL;

                    *(mergeTmp) = *(exitTmp);
                    *(exitTmp) = *(tmpHeap);
                    *(tmpHeap) = *(mergeTmp);

                    connectBinomialHeaps(tmpHeap, exitHeap);
                }
            } else{
                exitTmp->sibling = tmpHeap;
                exitTmp = exitTmp->sibling;
                exitTmp->sibling = NULL;
            }
        } else{
            exitHeap = tmpHeap;
            exitHeap->sibling = NULL;

            exitTmp = exitHeap;
        }
    }

    return exitHeap;
}

HEAP* insertNewNodeBinomialHeap(HEAP *h1, int key){
    HEAP *h2 = (HEAP *) calloc(1, sizeof(HEAP));

    h2->degree = 0;
    h2->key = key;

    return uniteBinomialHeap(h1, h2);
}

HEAP* removeMinNodeBinomialHeap(HEAP *h1);

int main(){
    HEAP *p1_1 = (HEAP *) calloc(1, sizeof(HEAP));

    HEAP *p1_2 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p1_2_1 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p1_2_2 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p1_2_1_1 = (HEAP *) calloc(1, sizeof(HEAP));

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

    HEAP *h1 = p1_1;



    HEAP *p2_1 = (HEAP *) calloc(1, sizeof(HEAP));

    HEAP *p2_2 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p2_2_1 = (HEAP *) calloc(1, sizeof(HEAP));

    HEAP *p2_3 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p2_3_1 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p2_3_2 = (HEAP *) calloc(1, sizeof(HEAP));
    HEAP *p2_3_1_1 = (HEAP *) calloc(1, sizeof(HEAP));

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

    HEAP *h2 = p2_1;

    printBinomialHeap(h1);
    printf("\n\n");

    printBinomialHeap(h2);
    printf("\n\n");

    HEAP *h3 = uniteBinomialHeap(h1, h2);

    printBinomialHeap(h3);
    printf("\n\n");

    h3 = insertNewNodeBinomialHeap(h3, 5);

    printBinomialHeap(h3);
    printf("\n\n");

    h3 = insertNewNodeBinomialHeap(h3, 15);

    printBinomialHeap(h3);
    printf("\n");

    return 0;
}