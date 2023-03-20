/* 1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real e char. 
Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando ponteiros. 
Imprima os valores das variavaeis antes e depois. */

#include <stdio.h>

void main (void){
    int inteiro = 1;
    float real = 2.5;
    char caractere = 'a';
    // char eh um vetor disfarcado;
    // cada letra ocupa uma posicao;
    int *pInteiro = &inteiro;
    float *pReal = &real;
    char *pCaractere = &caractere;
    printf ("%d \n", inteiro);
    printf ("%.2f \n", real);
    //nao esquecer de colocar s para string
    printf ("%c \n", caractere);
    *pInteiro = 2;
    *pReal = 3.75;
    *pCaractere = 'b';
    printf ("%d \n", inteiro);
    printf ("%.2f \n", real);
    printf ("%c \n", caractere);
}