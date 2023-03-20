/* 8 Construa um programa que leia números do teclado e os armazene em um vetor alocado
dinamicamente. O usuário irá digitar uma sequência de números sem limite de quantidade. Os
números serão digitados um a um até que o usuário entre o número 0 (zero) para encerrar a entrada
de dados. Para o armazenamento, o programa deve atender os seguintes requisitos:
a) Inicia com um vetor de tamanho 10 alocado dinamicamente (n = 10).
b) Ao encher o vetor com as entradas do usuário, deve ser alocado um novo vetor com o tamanho
do vetor anterior mais 10 posições (n += 10).
c) Copie os valores já digitados da área de memória inicial para esta área maior e libere a memória
da área inicial.
d) Repita esse procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada
vez que o mesmo estiver cheio - dessa forma o vetor irá se expandindo de 10 em 10 valores.
Ao final, exiba o vetor lido. ATENÇÃO: não use REALLOC. */

#include<stdio.h>
#include<stdlib.h>

void main (void){
    int *pvetor;
    int tam = 10;
    int i = 0;
    int valor = -1;
    pvetor = (int*)malloc(tam*sizeof(int));
    while (valor != 0){
        printf("\ninforme valor: >");
        scanf ("%d", &valor);
        if (((i+1) % tam) == 0){
            tam+=10;
            pvetor=aumenta(pvetor, tam);
        }
        pvetor[i]=valor;
        i++;
    }
    for (i=0;i<tam;i++){
        printf (" %d ", pvetor[i]);
    }
}

/* essa sintaxe "int*" é usada nessa função porque estou retornando um vetor. Se não fosse um vetor ou matriz, 
poderia ser usado somente a sintaxe "int" mas como se trata de um vetor, uso "int*" */
int* aumenta (int *pvetor, int tam){
    int i;
    int *vetornovo;

    vetornovo = (int*)malloc(tam*sizeof(int));

    for (i=0;i<(tam-10);i++){
        vetornovo[i]=pvetor[i];
    }
    return vetornovo;
}