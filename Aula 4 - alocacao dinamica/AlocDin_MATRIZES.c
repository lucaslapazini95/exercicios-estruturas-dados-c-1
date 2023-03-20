//ALOCAÇÃO DINÂMICA - MATRIZES
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int i, j, lin, col, cont=0;
    int **mat; //vetor de vetores (** = ponteiro para ponteiro) 
    
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &lin);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &col);
    
    //aloca memória para o vetor de ponteiros (linhas)
    mat = (int**)malloc(lin * sizeof(int*)); //-> tem ponteiros nesse int*
    
    //aloca memória para cada vetor dentro do vetor principal (colunas)
    for(i = 0; i < lin; i++) {
        mat[i] = (int*)malloc(col * sizeof(int));
    }
    
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            mat[i][j] = cont++;
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < lin; i++) {
        free(mat[i]);
    }
    free(mat);
}
