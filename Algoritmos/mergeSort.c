#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

int *merge(int* lista1, int* lista2, int size1, int size2){
    int i = 0, j = 0, k = 0;

    int *resposta = (int *) calloc(size1 + size2, sizeof(int));

    while (i < size1 || j < size2){
        if (i < size1 && j < size2){
            if (lista1[i] < lista2[j]){
                resposta[k] = lista1[i];
                i++;
            } else {
                resposta[k] = lista2[j];
                j++;
            }
        } else if (i < size1){
            resposta[k] = lista1[i];
            i++;
        } else {
            resposta[k] = lista2[j];
            j++;
        }

        k++;
    }

    return resposta;
}

int *mergeSort(int* lista, int size){
    if (size == 1){
        return lista;
    }

    int s1, s2;

    if (!(size & 1)){
        s1 = size/2;
        s2 = s1;
    } else{
        s1 = size/2;
        s2 = size/2 + 1;
    }

    int *l1 = (int *) calloc(s1, sizeof(int));
    int *l2 = (int *) calloc(s2, sizeof(int));

    for (int i = 0; i < size; i++){
        if (i < s1){
            l1[i] = lista[i];
        } else {
            l2[i - s1] = lista[i];
        }
    }

    int *d1 = mergeSort(l1, s1);
    int *d2 = mergeSort(l2, s2);

    return merge(d1, d2, s1, s2);
}

int main(){
    int* lista = (int *) calloc(6, sizeof(int));

    lista[0] = 5;
    lista[1] = 4;
    lista[2] = 2;
    lista[3] = 3;
    lista[4] = 1;
    lista[5] = 0;

    printLista(lista, 6, 1);

    lista = mergeSort(lista, 6);

    printLista(lista, 6, 2);

    return 0;
}