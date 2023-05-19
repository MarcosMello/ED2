#include <stdio.h>

void insectionSort(int *vetor, int size){
    int chave, i;

    for (int j = 1; j < size; j++){
        chave = vetor[j];
        i = j - 1;

        while (i >= 0 && vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i -= 1;
        }

        vetor[i + 1] = chave;
    }
}

int main(int argc, char const *argv[])
{
    int vetor[6] = {8, 2, 3, 8, 1, 8};

    insectionSort(vetor, 6);

    for (int i = 0; i < 6; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}