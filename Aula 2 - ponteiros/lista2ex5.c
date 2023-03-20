/* 5. Crie um programa que contenha uma funcao que permita passar por parametro dois
nUmeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e armazenar 
o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera modificar o valor do 
primeiro parametro. Imprima os valores de A e B na funcao principal.(USE PONTEIROS) */

#include <stdio.h>

void soma (int *pvalor1, int *pvalor2){
    *pvalor1=(*pvalor1)+(*pvalor2);
}

int main (void){
    int valor1, valor2;
    int *pvalor1, *pvalor2;
    printf ("type >");
    scanf ("%d", &valor1);
    printf ("type again :>");
    scanf ("%d", &valor2);
    printf ("\n original:");
    printf ("\n %d", valor1);
    printf ("\n %d", valor2);
    pvalor1 = &valor1;
    pvalor2 = &valor2;
    soma (pvalor1, pvalor2);
    printf ("\n soma dos dois numeros armazenado no valor1:");
    printf ("\n %d", valor1);
    printf ("\n %d", valor2);
}