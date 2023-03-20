/* 6 Escreva um programa que aloque dinamicamente uma matriz de inteiros de dimensões definidas
pelo usuário e a preencha de forma automática com valores aleatórios entre 0 e 100. Em seguida,
implemente uma função que receba um valor digitado pelo usuário e retorne 1 (um) caso o valor
informado esteja na matriz ou retorne 0 (zero) caso o valor não seja localizado. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main (void){
    srand(time(NULL));
    int linha, coluna;
    int i, j;
    int valor, conf = 0;
    int **matriz; //vetor de vetores (** = ponteiro para ponteiro)


    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linha);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &coluna);
    printf ("\nEm seguida, digite um valor inteiro positivo qualquer: ");
    scanf ("%d", &valor);

    // alocar memória para o vetor de ponteiros
    matriz = (int**)malloc(linha * sizeof(int*)); // "int*" porque tem ponteiros nesse int

    //alocar memória individualmento para os ponteiros dentro do vetor dos ponteiros
    for (i = 0; i < linha; i++){
        matriz [i] = (int*)malloc(coluna * sizeof(int));
    }
    
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            matriz [i][j] = rand () % 100;
            if (valor == matriz [i][j]){
                conf = 1;
            }
            printf ("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    if (conf == 1){
        printf ("\nO valor %d esta na matriz. %d", valor, conf);
    }
    else{
        printf ("\nO valor %d nao esta na matriz. %d", valor, conf);
    }

    for (i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);
}