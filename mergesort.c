#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

int* mergesort(int *list, int initial, int size){
    int s1, s2;
    int *rList;

    if (size == 1){
        rList = (int *) calloc(1, sizeof(int));

        *rList = *(list + initial);

        return rList;
    }

    if (size & 1) {
        s1 = (size - 1) / 2;
        s2 = s1 + 1;
    } else {
        s1 = size / 2;
        s2 = s1;
    }

    int *rList1 = mergesort(list, initial, s1);
    int *rList2 = mergesort(list, initial + s1, s2);

    rList = (int *) calloc(size, sizeof(int));

    int x = 0, y = 0, insert;

    for (int i = 0; i < size; i++){
        if (x < s1 && y < s2){
            if (*(rList1 + x) < *(rList2 + y)){
                insert = *(rList1 + x);
                x++;
            } else {
                insert = *(rList2 + y);
                y++;
            }
        } else if (x < s1) {
            insert = *(rList1 + x);
            x++;
        } else if (y < s2){
            insert = *(rList2 + y);
            y++;
        }

        *(rList + i) = insert;
    }

    return rList;
}

int main(){
    int *lista = calloc(6, sizeof(int));

    *(lista + 0) = 6;
    *(lista + 1) = 2;
    *(lista + 2) = 5;
    *(lista + 3) = 3;
    *(lista + 4) = 4;
    *(lista + 5) = 1;


    lista = mergesort(lista, 0, 6);

    printLista(lista, 6, 1);

    free(lista);

    lista = calloc(7, sizeof(int));

    *(lista + 0) = 6;
    *(lista + 1) = 2;
    *(lista + 2) = 7;
    *(lista + 3) = 3;
    *(lista + 4) = 4;
    *(lista + 5) = 1;
    *(lista + 6) = 5;

    lista = mergesort(lista, 0, 7);

    printLista(lista, 7, 2);

    free(lista);
}