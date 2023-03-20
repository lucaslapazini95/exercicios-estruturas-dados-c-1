/* 4. Elaborar um programa que leia dois valores inteiros (A e B). Em seguida, faca uma funcao que retorne 
a soma do dobro dos dois numeros lidos. A funcao devera armazenar o dobro de A na propria variavel A e o dobro
de B na propria variavel B. (USE PONTEIROS) */

#include <stdio.h>
void dobro (int *pvalor1, int *pvalor2){
    *pvalor1 = *pvalor1 + (*pvalor1 * 2);
    *pvalor2 = *pvalor2 + (*pvalor2 * 2);
}

void main (void){
    int valor1, valor2;
    int *pvalor1, *pvalor2;
    printf ("type >");
    scanf ("%d", &valor1);
    printf ("type 2x :>");
    scanf ("%d", &valor2);
    printf ("\n original");
    printf ("\n %d", valor1);
    printf ("\n %d", valor2);
    pvalor1 = &valor1;
    pvalor2 = &valor2;
    dobro (pvalor1, pvalor2);
    printf ("\n dobro da soma:");
    printf ("\n %d", valor1);
    printf ("\n %d", valor2);
}