/* 3. Desenvolva um programa que armazene na memoria dois vetores do tipo inteiro contendo 1000 
posicoes cada um. O primeiro deve ser criado utilizando MALLOC, e o segundo utilizando CALLOC. 
Apo-s isso, percorra os vetores com uma funcao que retorne a quantidade de zeros existentes em 
cada um deles. */

#include<stdio.h>
#include<stdlib.h>

void percorre (int *pvetor1, int *pvetor2) {
	int zeros1 = 0;
	int zeros2 = 0;
	int tamanho = 1000;
	int i;
	for (i = 0; i < tamanho; i++){
		printf (" %d ", pvetor1[i]);
		if (pvetor1[i] == 0){
			zeros1++;
		}
	}
	
	printf ("\n \n \n \n");
	for (i = 0; i < tamanho; i++){
	printf (" %d ", pvetor2[i]);
		if (pvetor2[i] == 0){
			zeros2++;
		}
	}
	printf ("\n zeros1: %d", zeros1);
	printf ("\n zeros2: %d", zeros2);
}

void main (void) {
    int *pvetor1;
    int *pvetor2;
    int tamanho = 1000;
    
	pvetor1 = (int*)malloc(tamanho * sizeof(int));
	pvetor2 = (int*)calloc(tamanho, sizeof(int));
	
	percorre (pvetor1, pvetor2);
	
}

