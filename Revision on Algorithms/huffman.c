#include <stdio.h>
#include <stdlib.h>

typedef struct key{
    int frequency;
    char character;

    struct key *left, *right;
} Key;

typedef struct heap{
    Key **keys;
    int size;
} Heap;

int parent(int childPosition){
    return (childPosition/2);
}

int left(int parentPosition){
    return (2 * parentPosition);
}

int right(int parentPosition){
    return ((2 * parentPosition) + 1);
}

Key *allocKey(int frequency, char character){
    Key *key = (Key *) calloc(1, sizeof(Key));

    if (key == NULL){
        printf("Erro! - Falta Memoria!\n");
        exit(1);
    }

    key->frequency = frequency;
    key->character = character;

    return key;
}

Heap *allocHeap(int size){
    Heap *heap = (Heap *) calloc(1, sizeof(Heap));

    if (heap == NULL){
        printf("Erro! - Falta Memoria!\n");
        exit(1);
    }

    heap->size = size;

    Key **keys = (Key **) calloc(size, sizeof(Key *));

    if (keys == NULL){
        printf("Erro! - Falta Memoria!\n");
        exit(1);
    }

    heap->keys = keys;

    return heap;
}

void minHeapify(Heap *heap, int key){
    int minKey = key;

    int leftIndex = left(key);
    int rightIndex = right(key);

    if (leftIndex <= heap->size && (*(heap->keys + leftIndex))->frequency < (*(heap->keys + key))->frequency){
        minKey = leftIndex;
    }

    if (rightIndex <= heap->size && (*(heap->keys + rightIndex))->frequency < (*(heap->keys + key))->frequency){
        minKey = rightIndex;
    }

    if (minKey != key){
        Key *aux = (*(heap->keys + key));

        (*(heap->keys + key)) = (*(heap->keys + minKey));
        (*(heap->keys + minKey)) = (*(heap->keys + key));

        minHeapify(heap, minKey);
    }
}