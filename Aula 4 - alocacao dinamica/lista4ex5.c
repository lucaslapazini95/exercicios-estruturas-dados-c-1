/* 5 Crie um programa que declare uma estrutura (registro/struct) para um cadastro de alunos segundo
os seguintes requisitos:
a) Deverão ser armazenados para cada aluno: matrícula, nome (apenas um) e ano de nascimento.
b) No início do programa o usuário deverá informar o total de alunos que serão armazenados e o
programa deverá alocar dinamicamente a quantidade necessária de memória para armazenar os
registros dos alunos.
c) O programa deve solicitar ao usuário a entrada de dados dos alunos.
d) Ao final do cadastramento, o programa deve exibir os dados armazenados e liberar a memória */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cadastro{
    int matricula;
    char nome [20];
    int data;
}tcadastro;

void main (void){
    int tam;
    int i;
    tcadastro *aluno;

    printf("Informe a quantia de alunos: >");
    scanf ("%d", &tam);

    aluno = (tcadastro*)calloc(tam, sizeof(tcadastro));

    for (i=0; i<tam; i++){
        printf ("\nDigite o nome do aluno: >");
        scanf ("%s", &aluno[i].nome);
        printf ("\nDigite a matricula: >");
        scanf ("%d", &aluno[i].matricula);
        printf("\nDigite o ano de nascimento: >");
        scanf ("%d", &aluno[i].data);
    }
    for (i=0; i<tam; i++){
        printf ("\nAluno: %s", aluno[i].nome);
        printf ("\nMatricula: %d", aluno[i].matricula);
        printf("\nAno de nascimento: %d", aluno[i].data);
    }
}