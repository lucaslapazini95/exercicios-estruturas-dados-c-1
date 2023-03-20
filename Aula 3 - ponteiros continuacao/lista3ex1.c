/* 1. Elabore um programa que contenha um vetor do tipo float com 10 elementos.
Usando um ponteiro, imprima o conteudo e o endereco de cada posicao desse vetor */

#include <stdio.h>
// biblioteca stdlib para NULL
#include <stdlib.h>
#include <time.h>

void main (void){
	float vetor [10];
	//declaracao de vetor USAR O ASTERISCO " * "
	float *pvetor[10];
	int i;
	srand (time(NULL));

	//gerar numeros para servir de conteudo aos elementos do vetor
	for (i = 0; i<10; i++) {
		vetor[i] = rand () % 100;
	}

	// impressao para verificar resultado do conteudo
	for (i = 0; i<10; i++) {
		printf ("conteudo do elemento %i: >%.0f \n", i, vetor[i]);
	}

	// impressao para verificar posicao de cada elemento
	for (i = 0; i<10; i++) {
		printf ("pos do elemento %i: >%p \n", i, &vetor[i]);
	}

	for (i = 0; i<10; i++) {
		pvetor[i] = &vetor[i];
	}

	// impressao para verificar conteudo dos elemento com PONTEIRO
	for (i = 0; i<10; i++) {
		printf ("conteudo do elemento %i com PONTEIRO: >%.0f \n", i, *pvetor[i]);
	}

	// impressao para verificar posicao de cada elemento com PONTEIRO
	for (i = 0; i<10; i++) {
		printf ("pos do elemento %i com PONTEIRO: >%p \n", i, pvetor[i]);
	}
	
}