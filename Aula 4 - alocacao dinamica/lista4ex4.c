/* 4 Faça um programa que leia uma quantidade qualquer de números armazenando-os na memória e
pare a leitura quando o usuário entrar um valor negativo. Em seguida, imprima o vetor lido. Use a
função REALLOC como achar mais conveniente para realocar memória sempre que necessário. */

#include<stdio.h>
#include<stdlib.h>


void main (void){
    int *vet;
    int i, x = 0;
    int valor;
    int tam = 0;
    
    vet = (int*)calloc(tam, sizeof(int));

    printf (">");
    scanf ("%d", &valor);
    while (valor >= 0){
        tam++;
        vet = (int*)realloc(vet, tam * sizeof(int));
        //"tam-1" é o jump do cat
        vet[tam-1] = valor;
        // x++;
        printf ("\n>");
        scanf ("%d", &valor);
    }
    for (i = 0; i < tam; i++){
        printf ("%d ", vet[i]);
    }
}