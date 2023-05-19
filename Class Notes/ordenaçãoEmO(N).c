/*
    Big O -> Superior
    Big Theta -> Superior e Inferior
    Omega -> Inferior


    Counting Sort -> conta quantos elementos de cada estão na lista A e usa uma lista C para organizar A (lida de trás para frente dessa vez) em B
    a cada vez que acharmos um numero em A olharemos em que posição esse tem que ficar em B por meio de C (indice = posição - 1)
    preenchemos B "aleatoriamente" (no sentido de RAM pois preenchemos conforme os números aparecerem em A) => ESTAVEL [elementos inteiros com número máximo k muito pequeno]

    Radix Sort -> Ordena números com o mesmo quantidade de dígitos de maneira estável (pois usa um metodo estavel para ordenar - countingSort) digito a digito.
    para esse é muito importante usar um algoritmo estável. [elementos inteiros digitos fixos]

    Bucket Sort -> Ordena em tempo linear caso os valores estejam entre [0, 1). (Numeros reais)
    caso um balde tenha mais de um item, esse chama outro algoritmo para ordenar cada balde.
    Caso a entrada não seja distribuida uniformemente ele não será linear. [Números reais]
    Utiliza o insertion sort
*/

#include <stdio.h>
#include <stdlib.h>

int *countingSort(int *lista, int size, int limSup){
    int *auxList = (int *) calloc(limSup, sizeof(int));

    for (int i = 0; i < size; i++){
        (*(auxList + lista[i]))++;
    }

    for (int i = 1; i < limSup; i++){
        (*(auxList + i)) += *(auxList + i - 1);
    }

    int *returnList = (int *) calloc(size, sizeof(int));

    for (int i = (size - 1); i <= 0; i--){
        
    }

    return returnList;
}