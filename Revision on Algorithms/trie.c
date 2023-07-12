#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define charIndex(c) ((int)c - (int)'a')

int ALPHABETSIZE = 26;

typedef struct trieNode{
    struct trieNode **nodeChilds;
    int isTerminal;
} TrieNode;

TrieNode *allocNode(){
    TrieNode *node = (TrieNode *) calloc(1, sizeof(TrieNode));

    if (node == NULL){
        printf("Erro! Memória insuficiente!\n");
        exit(1);
    }

    TrieNode **nodeList = (TrieNode **) calloc(ALPHABETSIZE, sizeof(TrieNode *));

    if (nodeList == NULL){
        printf("Erro! Memória insuficiente!\n");
        exit(1);
    }

    node->nodeChilds = nodeList;

    return node;
}

int searchTrieNode(TrieNode *trie, char *str){
    TrieNode *aux = trie;

    if (trie == NULL){
        return 0;
    }

    for (int i = 0; i < strlen(str); i++){
        if ((*(aux->nodeChilds + charIndex(str[i]))) == NULL){
            return 0;
        }

        aux = (*(aux->nodeChilds + charIndex(str[i])));
    }

    return aux->isTerminal;
}

void insertTrieNode(TrieNode *trie, char *str){
    TrieNode *aux = trie;

    for (int i = 0; i < strlen(str); i++){
        if ((*(aux->nodeChilds + charIndex(str[i]))) == NULL){
            (*(aux->nodeChilds + charIndex(str[i]))) = allocNode();
        }

        aux = (*(aux->nodeChilds + charIndex(str[i])));
    }

    aux->isTerminal = 1;
}

int main(){
    TrieNode *trie = allocNode();

    insertTrieNode(trie, "aaa");
    insertTrieNode(trie, "teste");
    insertTrieNode(trie, "aab");

    printf("aaa %s", searchTrieNode(trie, "aaa") ? "está presente!\n" : "não está presente!\n");
    printf("aaaa %s", searchTrieNode(trie, "aaaa") ? "está presente!\n" : "não está presente!\n");
    printf("teste %s", searchTrieNode(trie, "teste") ? "está presente!\n" : "não está presente!\n");
    printf("aab %s", searchTrieNode(trie, "aab") ? "está presente!\n" : "não está presente!\n");
    printf("xyz %s", searchTrieNode(trie, "xyz") ? "está presente!\n" : "não está presente!\n");
}
