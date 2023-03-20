/* 6. Construa um programa que tenha uma estrutura para cadastrar alunos, contendo o nome do aluno,
a matricula e a turma. Cadastre os dados de um aluno e exiba-os em tela por acesso direto a struct.
Apos isso, exiba-os novamente, mediante uso de um ponteiro para a struct. */

#include <stdio.h>

typedef struct aluno {
    char nome[40];
    int matricula;
    char turma[40];

}taluno;

void imprimetela (taluno *paluno1){
    printf("\n nome: > %s", paluno1->nome);
    printf("\n matricula: > %d", paluno1->matricula);
    printf("\n turma: > %s", paluno1->turma);
}

void main (void){
    taluno aluno1;
    taluno *paluno1 = &aluno1;
	
    printf("\n Digite o nome do aluno: >");
    fflush (stdin);
    scanf ("%[^\n]", &aluno1.nome);
    printf("\n Digite a matricula do aluno (SOMENTE NUMEROS): >");
    scanf ("%i", &aluno1.matricula);
    fflush (stdin);
    printf("\n Digite a turma do aluno: >");
    scanf ("%[^\n]", &aluno1.turma);

    imprimetela (paluno1);

}
