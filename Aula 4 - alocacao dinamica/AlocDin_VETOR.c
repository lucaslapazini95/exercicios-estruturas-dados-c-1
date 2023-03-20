// ---------------------------------------------
// vetor com ponteiros
// ---------------------------------------------

#include<stdio.h>
#include<stdlib.h>

int main (void) {
    int tam, *pVet;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    
    pVet = (int*)malloc(tam * sizeof(int));
    
    for (int i = 0; i < tam; i++){
        printf("Informe o valor da posição %d: ", i);
        scanf("%d", &pVet[i]);
    }
    
    for (int i = 0; i < tam; i++){
        printf("Valor na posição %d = %d\n", i, pVet[i]);
    }
    
    free(pVet);
    pVet = NULL;
}