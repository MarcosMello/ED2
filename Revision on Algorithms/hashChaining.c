#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;

    struct node *next;
} Node;

typedef struct hashmap{
    int elements;
    int capacity;

    Node **table;
} HashMap;

HashMap *allocHashMap(int capacity){
    HashMap *hash = (HashMap *) calloc(1, sizeof(HashMap));

    if (hash == NULL){
        printf("Erro! - Memoria insuficiente!");
        exit(1);
    }

    hash->capacity = capacity;

    Node **table = (Node **) calloc(capacity, sizeof(Node *));

    if (table == NULL){
        printf("Erro! - Memoria insuficiente!");
        exit(1);
    }

    hash->table = table;

    return hash;
}

Node *allocNode(int key){
    Node *node  = (Node *) calloc(1, sizeof(Node));

    if (node == NULL){
        printf("Erro! - Memoria insuficiente!");
        exit(1);
    }

    node->key = key;

    return node;
}

int hashFunction(int capacity, int key){
    return key % capacity;
}

void insertHashMap(HashMap *hash, int key){
    int hashIndex = hashFunction(hash->capacity, key);

    Node *node = allocNode(key);

    if (*(hash->table + hashIndex) == NULL){
        *(hash->table + hashIndex) = node;
    } else{
        node->next = *(hash->table + hashIndex);
        *(hash->table + hashIndex) = node;
    }

    hash->elements++;
}

Node *searchNode(HashMap *hash, int key){
    int hashIndex = hashFunction(hash->capacity, key);

    Node *aux = *(hash->table + hashIndex);

    while (aux != NULL && aux->key != key){
        aux = aux->next;
    }

    return aux;
}

void removeHashMap(HashMap *hash, int key){
    int hashIndex = hashFunction(hash->capacity, key);

    Node *aux = *(hash->table + hashIndex), *aux2;

    if (aux == NULL){
        return;
    } else if (aux->key == key){
        *(hash->table + hashIndex) = aux->next;
        return;
    }

    while (aux->next != NULL && aux->next->key != key){
        aux = aux->next;
    }

    if (aux != NULL){
        aux2 = aux->next;
        aux->next = aux->next->next;

        hash->elements--;
        free(aux2);
    }
}

void printHashMap(HashMap *hash){
    Node *aux;

    if (hash == NULL){
        return;
    }

    for (int i = 0; i < hash->capacity; i++){
        aux = *(hash->table + i);

        printf("Table Pos. %d: %s", i, (aux == NULL ? "Vazio" : "["));

        while (aux != NULL){
            printf("%d%s", aux->key, (aux->next == NULL ? "]" : ", "));

            aux = aux->next;
        }

        printf("\n");
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

    printHashMap(hash);

    removeHashMap(hash, 27);

    printHashMap(hash);

    removeHashMap(hash, 115);

    printHashMap(hash);

    removeHashMap(hash, 46);

    printHashMap(hash);

    removeHashMap(hash, 23);

    printHashMap(hash);

    insertHashMap(hash, 27);

    printHashMap(hash);
}