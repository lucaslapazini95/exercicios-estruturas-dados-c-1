// ---------------------------------------------
// Alocação dinâmica - STRUCTS
// ---------------------------------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario {
    int cod;
    float salario;
}tFuncionario;

void alteraSalario(tFuncionario *pFunc, int tam) {
    for (int i = 0; i < tam; i++)
        pFunc[i].salario *= 1.3;
}

int main (void) {
    int tam;
    tFuncionario *pVet;
    
    printf("Digite o tamanho do cadastro: ");
    scanf("%d", &tam);
    
    pVet = (tFuncionario*)malloc(tam * sizeof(tFuncionario));
    
    if (pVet == NULL) {
        printf("Memória insuficente\n");
        exit(1);
    }
    
    for (int i = 0; i < tam; i++){
        printf("\nDigite o código: ");
        scanf("%d", &pVet[i].cod);
        printf("Digite o salário: ");
        scanf("%f", &pVet[i].salario);
    }
    
    alteraSalario(pVet, tam);
    
    printf("\n# Salários reajustados em 30%% #\n");
    for (int i = 0; i < tam; i++){
        printf("Código: %d  -  Salário: %.2f\n", pVet[i].cod, pVet[i].salario);
    }
    free(pVet);
}