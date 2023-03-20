/* 7 Crie um programa que receba do usuário dois números N e M e crie uma matriz de inteiros N x M. A
seguir a matriz deve ser preenchida com valores aleatórios de forma automática. Por fim, o programa
deve localizar os três maiores números contidos na matriz e exibir os índices da linha e coluna onde
se encontra cada um deles. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main (void){
    srand(time(NULL));
    int linha, coluna;
    int i, j, i1 = 0, i2 = 0, i3 = 0, j1 = 0, j2 = 0, j3 = 0;
    int maior1 = 0, maior2 = 0, maior3 = 0;
    int **matriz;

    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linha);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &coluna);

    matriz = (int**)malloc(linha * sizeof(int*));

    for (i = 0; i < linha; i++){
        matriz [i] = (int*)malloc(coluna * sizeof(int));
    }
    
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            matriz [i][j] = rand () % 100;
            if (matriz [i][j] > maior1){
                i3 = i2;
                j3 = j2;
                maior3 = maior2;
                i2 = i1;
                j2 = j1;
                maior2 = maior1;
                i1 = i;
                j1 = j;
                maior1 = matriz [i][j];
            }
            else if (matriz [i][j] > maior2 && matriz [i][j] != maior1){
                i3 = i2;
                j3 = j2;
                maior3 = maior2;
                i2 = i;
                j2 = j;
                maior2 = matriz [i][j];
            }
            else if (matriz [i][j] > maior3 && matriz [i][j] != maior2 && matriz [i][j] != maior1){
                i3 = i;
                j3 = j;
                maior3 = matriz [i][j];
            }
            printf ("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf ("\nMaior valor: %d %da Linha %da Coluna", maior1, i1+1, j1+1);
    printf ("\nSegundo maior valor: %d %da Linha %da Coluna", maior2, i2+1, j2+1);
    printf ("\nTerceiro maior valor: %d %da Linha %a Coluna", maior3, i3+1, j3+1);

    for (i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

