/* 3. Construa uma funcao que receba como parametro um vetor de inteiros com 10 valores aleatorios
entre 0 e 6. A funcao deve determinar O MAIOR ELEMENTO e o NUMERO DE VEZES QUE ELE OCORRE no vetor.
A funcao deve ser do tipo void e o programa deve, apos a execucao da funcao, listar o vetor e
apresentar os valores manipulados pela funcao (maior valor e quantidade de vezes que aparece no
vetor) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcao (int *pvetor[], int *pmaior, int *pquant){
    int i;
    *pquant = 0;
    *pmaior = *pvetor [0];
    
    for (i = 1; i<10; i++) {
        if (*pvetor[i] > *pmaior){
            *pmaior = *pvetor[i];
        }
	}

    for (i = 0; i<10; i++) {
		if (*pvetor[i] == *pmaior){
            //o operador de incremento nao funciona no ponteiro, especificamente *pxxxx++
            *pquant = *pquant + 1;
        }
	}
}

void main (void){
	int vetor [10], maior, quant = 0;
	int *pvetor[10];
    int *pmaior = &maior;
    int *pquant = &quant;
	int i;
	srand (time(NULL));

	for (i = 0; i<10; i++) {
		vetor[i] = rand () % 7;
	}

    for (i = 0; i<10; i++) {
		pvetor[i] = &vetor[i];
	}

    printf (" Vetor: ");
    for (i=0;i<10;i++){
        printf ("%d ", vetor[i]);
    }

    funcao (pvetor, pmaior, pquant);

    printf ("\n Maior elemento: >%d", maior);

    printf ("\n Quantidade de vezes que maior elemento aparece: >%d", quant);
}