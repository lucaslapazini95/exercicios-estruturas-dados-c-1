/* 2. Crie um programa que contenha um vetor do tipo int com 5 elementos. Utilizando apenas aritmetica
de ponteiros (acesse cada posicao diretamente pela memoria, sem uso do indice do vetor como visto em
aula) preencha o vetor com as entradas do usuario e exiba em tela o dobro de cada valor lido. */

#include <stdio.h>

void main (void){
	int vetor [5];
	int *pvetor = vetor;
    //OBSERVE COMO PODE SER ARMAZENADO A PRÓPRIA VARIAVEL VETOR POIS O PROPRIO VETOR JA INDICA O ENDERECO DO PRIMEIRO ELEMENTO
    int i;

    for (i=0; i < 5; i++){
        printf ("\n Digite o valor do elemento [%d]: >", i+1);
        scanf ("%d", pvetor + i);
    }

    for (i=0; i < 5; i++){
        printf ("\n elemento [%d]: (%d * 2) = %d", i+1, *(pvetor+i), 2*(*(pvetor+i)));
    }
}

// MATEMATICA DE PONTEIROS
// printf... *(pvet + i) -> nesse caso ele pega o endereco de pvet e avanca i posicoes
// printf... *pvet + i -> aqui ele pega o conteudo de pvet e soma o i

//AINDA DE MATEMATICA DE PONTEIROS
//scanf ("%d", pvet + i);
//veja como posso armazenar diretamente na posicao deseja sem o "&" para acessar o endereco
