/* 3. Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas 2 variaveis e troque
o seu conteudo, ou seja, esta funcao eh chamada passando duas variaveis A e B, por exemplo, e apos a execucao
da funcao, A contera o valor de B e B tera o valor de A. (USE PONTEIROS) */

#include <stdio.h>
//funcao retorna algo
//procedure retorna nada

void change (int *pValue1, int *pValue2){
    int pValue3;
    pValue3 = *pValue1;
    *pValue1 = *pValue2;
    *pValue2 = pValue3;
}

void main (void){
    int value1, value2;
    int *pValue1, *pValue2;
    printf ("type an integer number >");
    scanf ("%d", &value1);
    printf ("type another integer number :>");
    scanf ("%d", &value2);
    printf ("\noriginal");
    printf ("\n%d", value1);
    printf ("\n%d", value2);
    pValue1 = &value1;
    pValue2 = &value2;
    change (pValue1, pValue2);
    printf ("\nchange:");
    printf ("\n%d", value1);
    printf ("\n%d", value2);
}