/* 1. Construa um programa que receba do usuario o tamanho de um vetor de inteiros a ser lido e efetue 
a alocacao dinamica de memoria. A seguir, leia as entradas do usuario para preencher o vetor e 
exiba o vetor resultante. */

#include<stdio.h>
#include<stdlib.h>

void main (void) {
    int tamanho;
    int *pvetor;
    int i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    pvetor = (int*)malloc(tamanho * sizeof(int)); //-> (int*)malloc porque voce esta indicando o tipo do PONTEIRO malloc
    
    for (i = 0; i < tamanho; i++){
        printf("Digite o valor na posicao %d: ", i);
        scanf("%d", &pvetor[i]);
    }
    
    for (i = 0; i < tamanho; i++){
        printf("Valor na posicao %d = %d \n", i, pvetor[i]);
    }
    
    free(pvetor);
    pvetor = NULL;
}
--------------------------------------------------------------------------------------------------------------------------
/* 3. Desenvolva um programa que armazene na memoria dois vetores do tipo inteiro contendo 1000 
posicoes cada um. O primeiro deve ser criado utilizando MALLOC, e o segundo utilizando CALLOC. 
Apo-s isso, percorra os vetores com uma funcao que retorne a quantidade de zeros existentes em 
cada um deles. */

#include<stdio.h>
#include<stdlib.h>

void percorre (int *pvetor1, int *pvetor2) {
	int zeros1 = 0;
	int zeros2 = 0;
	int tamanho = 1000;
	int i;
	for (i = 0; i < tamanho; i++){
		printf (" %d ", pvetor1[i]);
		if (pvetor1[i] == 0){
			zeros1++;
		}
	}
	
	printf ("\n \n \n \n");
	for (i = 0; i < tamanho; i++){
	printf (" %d ", pvetor2[i]);
		if (pvetor2[i] == 0){
			zeros2++;
		}
	}
	printf ("\n zeros1: %d", zeros1);
	printf ("\n zeros2: %d", zeros2);
}

void main (void) {
    int *pvetor1;
    int *pvetor2;
    int tamanho = 1000;
    
	pvetor1 = (int*)malloc(tamanho * sizeof(int));
	pvetor2 = (int*)calloc(tamanho, sizeof(int));
	
	percorre (pvetor1, pvetor2);
	
}
--------------------------------------------------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------------------------------------------------
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
--------------------------------------------------------------------------------------------------------------------------
/* 6 Escreva um programa que aloque dinamicamente uma matriz de inteiros de dimensões definidas
pelo usuário e a preencha de forma automática com valores aleatórios entre 0 e 100. Em seguida,
implemente uma função que receba um valor digitado pelo usuário e retorne 1 (um) caso o valor
informado esteja na matriz ou retorne 0 (zero) caso o valor não seja localizado. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main (void){
    srand(time(NULL));
    int linha, coluna;
    int i, j;
    int valor, conf = 0;
    int **matriz; //vetor de vetores (** = ponteiro para ponteiro)


    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linha);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &coluna);
    printf ("\nEm seguida, digite um valor inteiro positivo qualquer: ");
    scanf ("%d", &valor);

    // alocar memória para o vetor de ponteiros
    matriz = (int**)malloc(linha * sizeof(int*)); // "int*" porque tem ponteiros nesse int

    //alocar memória individualmento para os ponteiros dentro do vetor dos ponteiros
    for (i = 0; i < linha; i++){
        matriz [i] = (int*)malloc(coluna * sizeof(int));
    }
    
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            matriz [i][j] = rand () % 100;
            if (valor == matriz [i][j]){
                conf = 1;
            }
            printf ("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    if (conf == 1){
        printf ("\nO valor %d esta na matriz. %d", valor, conf);
    }
    else{
        printf ("\nO valor %d nao esta na matriz. %d", valor, conf);
    }

    for (i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
--------------------------------------------------------------------------------------------------------------------------
/* 7 Crie um programa que receba do usuário dois números N e M e crie uma matriz de inteiros N x M. A
seguir a matriz deve ser preenchida com valores aleatórios de forma automática. Por fim, o programa
deve localizar os três maiores números contidos na matriz e exibir os índices da linha e coluna onde
se encontra cada um deles. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main (void){
    srand(time(NULL));
    int linha, coluna;
    int i, j, i1 = 0, i2 = 0, i3 = 0, j1 = 0, j2 = 0, j3 = 0;
    int maior1 = 0, maior2 = 0, maior3 = 0;
    int **matriz;

    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linha);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &coluna);

    matriz = (int**)malloc(linha * sizeof(int*));

    for (i = 0; i < linha; i++){
        matriz [i] = (int*)malloc(coluna * sizeof(int));
    }
    
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            matriz [i][j] = rand () % 100;
            if (matriz [i][j] > maior1){
                i3 = i2;
                j3 = j2;
                maior3 = maior2;
                i2 = i1;
                j2 = j1;
                maior2 = maior1;
                i1 = i;
                j1 = j;
                maior1 = matriz [i][j];
            }
            else if (matriz [i][j] > maior2 && matriz [i][j] != maior1){
                i3 = i2;
                j3 = j2;
                maior3 = maior2;
                i2 = i;
                j2 = j;
                maior2 = matriz [i][j];
            }
            else if (matriz [i][j] > maior3 && matriz [i][j] != maior2 && matriz [i][j] != maior1){
                i3 = i;
                j3 = j;
                maior3 = matriz [i][j];
            }
            printf ("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf ("\nMaior valor: %d %da Linha %da Coluna", maior1, i1+1, j1+1);
    printf ("\nSegundo maior valor: %d %da Linha %da Coluna", maior2, i2+1, j2+1);
    printf ("\nTerceiro maior valor: %d %da Linha %a Coluna", maior3, i3+1, j3+1);

    for (i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
--------------------------------------------------------------------------------------------------------------------------
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