#include <stdio.h>
#include <stdlib.h>

void printLista(int* lista, int size, int n){
    printf("Lista %d: [", n);

    for (int i = 0; i < size; i++){
        printf("%d, ", *(lista + i));
    }

    printf("]\n");
}

int *countingSort(int *entrada, int tamanho, int limSup){
    limSup++;

    int *saida = (int *) calloc(tamanho, sizeof(int));
    int *countingArray = (int *) calloc(limSup, sizeof(int));

    for (int i = 0; i < tamanho; i++){
        (*(countingArray + *(entrada + i)))++;
    }

    for (int i = 1; i < limSup; i++){
        (*(countingArray + i)) += *(countingArray + (i - 1));
    }

    for (int i = (tamanho - 1); i >= 0; i--){
        *(saida + *(countingArray + *(entrada + i)) - 1) = *(entrada + i); //saida[countingArray[entrada[i]] - 1] = entrada[i];
        (*(countingArray + *(entrada + i)))--; //countingArray[entrada[i]]--;
    }

    return saida;
}

int main(){
    int *entrada = (int *) calloc(8, sizeof(int));

    *(entrada + 0) = 2;
    *(entrada + 1) = 5;
    *(entrada + 2) = 3;
    *(entrada + 3) = 0;
    *(entrada + 4) = 2;
    *(entrada + 5) = 3;
    *(entrada + 6) = 0;
    *(entrada + 7) = 3;

    printLista(entrada, 8, 1);

    int *saida = countingSort(entrada, 8, 5);

    printLista(saida, 8, 2);

    return 0;
}