/* 1. Construa um programa que receba do usuario o tamanho de um vetor de inteiros a ser lido e efetue 
a alocacao dinamica de memoria. A seguir, leia as entradas do usuario para preencher o vetor e 
exiba o vetor resultante. */

#include<stdio.h>
#include<stdlib.h>

void main (void) {
    int tamanho;
    int *pvetor;
    int i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    pvetor = (int*)malloc(tamanho * sizeof(int)); //-> (int*)malloc porque voce esta indicando o tipo do PONTEIRO malloc
    
    for (i = 0; i < tamanho; i++){
        printf("Digite o valor na posicao %d: ", i);
        scanf("%d", &pvetor[i]);
    }
    
    for (i = 0; i < tamanho; i++){
        printf("Valor na posicao %d = %d \n", i, pvetor[i]);
    }
    
    free(pvetor);
    pvetor = NULL;
}
