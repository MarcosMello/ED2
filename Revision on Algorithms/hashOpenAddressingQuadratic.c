#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
} Node;

typedef struct hashmap{
    int elements;
    int capacity;

    Node **table;
} HashMap;

HashMap *allocHashMap(int capacity){
    HashMap *hash = (HashMap *) calloc(1, sizeof(HashMap));

    if (hash == NULL){
        printf("Erro! - Memoria insuficiente!\n");
        exit(1);
    }

    hash->capacity = capacity;

    Node **table = (Node **) calloc(capacity, sizeof(Node *));

    if (table == NULL){
        printf("Erro! - Memoria insuficiente!\n");
        exit(1);
    }

    hash->table = table;

    return hash;
}

Node *allocNode(int key){
    Node *node  = (Node *) calloc(1, sizeof(Node));

    if (node == NULL){
        printf("Erro! - Memoria insuficiente!\n");
        exit(1);
    }

    node->key = key;

    return node;
}

int linearHashFunction(int capacity, int key){
    return key % capacity;
}

int quadraticHashFunction(int capacity, int actual, int secondFactor){
    return (actual + (secondFactor * secondFactor)) % capacity;
}

void insertHashMap(HashMap *hash, int key){
    int hashIndex = linearHashFunction(hash->capacity, key), quadracticFactor = 1;

    if (hash->capacity == hash->elements){
        printf("Hash cheio!\n");
        return;
    }

    while ((*(hash->table + hashIndex)) != NULL && (*(hash->table + hashIndex))->key != key){
        hashIndex = quadraticHashFunction(hash->capacity, hashIndex, quadracticFactor++);
    }

    if ((*(hash->table + hashIndex)) != NULL){
        printf("Chave já existe!\n");
        return;
    }

    *(hash->table + hashIndex) = (allocNode(key));
}

Node **searchHashMap(HashMap *hash, int key){
    int hashIndex = linearHashFunction(hash->capacity, key), counter = 0, quadracticFactor = 1;

    while (counter < hash->capacity){
        if ((*(hash->table + hashIndex)) != NULL && (*(hash->table + hashIndex))->key == key){
            break;
        }

        hashIndex = quadraticHashFunction(hash->capacity, hashIndex, quadracticFactor++);
        counter++;
    }

    return ((*(hash->table + hashIndex)) != NULL && (*(hash->table + hashIndex))->key == key) ? (hash->table + hashIndex) : NULL;
}

void removeHashMap(HashMap *hash, int key){
    Node **nodeToBeRemoved = searchHashMap(hash, key);
    Node *aux = (*nodeToBeRemoved);

    if (nodeToBeRemoved != NULL){
        *nodeToBeRemoved = NULL;
        free(aux);
    }
}

void printHashMap(HashMap *hash){
    for (int i = 0; i < hash->capacity; i++){
        printf("Table Pos. %d: ", i);

        if ((*(hash->table + i)) == NULL){
            printf("Vazio\n");
        } else {
            printf("%d\n", (*(hash->table + i))->key);
        }
    }
    printf("\n");
}

int main(){
    HashMap *hash = allocHashMap(23);

    insertHashMap(hash, 23);
    insertHashMap(hash, 46);
    insertHashMap(hash, 69);
    insertHashMap(hash, 92);
    insertHashMap(hash, 115);
    insertHashMap(hash, 24);
    insertHashMap(hash, 25);
    insertHashMap(hash, 26);
    insertHashMap(hash, 27);
    insertHashMap(hash, 47);

    printHashMap(hash);

    removeHashMap(hash, 27);

    printHashMap(hash);

    removeHashMap(hash, 115);

    printHashMap(hash);

    removeHashMap(hash, 46);

    printHashMap(hash);

    printf("\nEncontrei: %d\n\n", (*(searchHashMap(hash, 69)))->key);

    removeHashMap(hash, 23);

    printHashMap(hash);

    insertHashMap(hash, 27);

    printHashMap(hash);
}