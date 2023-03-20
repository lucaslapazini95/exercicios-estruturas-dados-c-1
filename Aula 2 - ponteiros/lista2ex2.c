/* 2. Escreva um programa que contenha duas variaveis inteiras. 
Compare seus enderecos e exiba o maior endereco. */

#include <stdio.h>

int main (void){
    int inteiro1, inteiro2;
    // int *ponteiro1, *ponteiro2;
    // ponteiro1 = &inteiro1;
    // ponteiro2 = &inteiro2;
    if (&inteiro1 > &inteiro2){
        printf ("%i", &inteiro1);
    }
    else{
        printf ("\n %i", &inteiro2);
    }
}