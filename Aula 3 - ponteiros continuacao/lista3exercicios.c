------------------------------------------------------------------------------------------------

/* 1. Elabore um programa que contenha um vetor do tipo float com 10 elementos.
Usando um ponteiro, imprima o conteudo e o endereco de cada posicao desse vetor */

#include <stdio.h>
// biblioteca stdlib para NULL
#include <stdlib.h>
#include <time.h>

void main (void){
	float vetor [10];
	//declaracao de vetor USAR O ASTERISCO " * "
	float *pvetor[10];
	int i;
	srand (time(NULL));

	//gerar numeros para servir de conteudo aos elementos do vetor
	for (i = 0; i<10; i++) {
		vetor[i] = rand () % 100;
	}

	// impressao para verificar resultado do conteudo
	for (i = 0; i<10; i++) {
		printf ("conteudo do elemento %i: >%.0f \n", i, vetor[i]);
	}

	// impressao para verificar posicao de cada elemento
	for (i = 0; i<10; i++) {
		printf ("pos do elemento %i: >%p \n", i, &vetor[i]);
	}

	for (i = 0; i<10; i++) {
		pvetor[i] = &vetor[i];
	}

	// impressao para verificar conteudo dos elemento com PONTEIRO
	for (i = 0; i<10; i++) {
		printf ("conteudo do elemento %i com PONTEIRO: >%.0f \n", i, *pvetor[i]);
	}

	// impressao para verificar posicao de cada elemento com PONTEIRO
	for (i = 0; i<10; i++) {
		printf ("pos do elemento %i com PONTEIRO: >%p \n", i, pvetor[i]);
	}
	
}

------------------------------------------------------------------------------------------------

/* 2. Crie um programa que contenha um vetor do tipo int com 5 elementos. Utilizando apenas aritmetica
de ponteiros (acesse cada posicao diretamente pela memoria, sem uso do indice do vetor como visto em
aula) preencha o vetor com as entradas do usuario e exiba em tela o dobro de cada valor lido. */

#include <stdio.h>

void main (void){
	int vetor [5];
	int *pvetor = vetor;
    //OBSERVE COMO PODE SER ARMAZENADO A PRÓPRIA VARIAVEL VETOR POIS O PROPRIO VETOR JA INDICA O ENDERECO DO PRIMEIRO ELEMENTO
    int i;

    for (i=0; i < 5; i++){
        printf ("\n Digite o valor do elemento [%d]: >", i+1);
        scanf ("%d", pvetor + i);
    }

    for (i=0; i < 5; i++){
        printf ("\n elemento [%d]: (%d * 2) = %d", i+1, *(pvetor+i), 2*(*(pvetor+i)));
    }
}

// MATEMATICA DE PONTEIROS
// printf... *(pvet + i) -> nesse caso ele pega o endereco de pvet e avanca i posicoes
// printf... *pvet + i -> aqui ele pega o conteudo de pvet e soma o i

//AINDA DE MATEMATICA DE PONTEIROS
//scanf ("%d", pvet + i);
//veja como posso armazenar diretamente na posicao deseja sem o "&" para acessar o endereco

------------------------------------------------------------------------------------------------

/* 3. Construa uma funcao que receba como parametro um vetor de inteiros com 10 valores aleatorios
entre 0 e 6. A funcao deve determinar O MAIOR ELEMENTO e o NUMERO DE VEZES QUE ELE OCORRE no vetor.
A funcao deve ser do tipo void e o programa deve, apos a execucao da funcao, listar o vetor e
apresentar os valores manipulados pela funcao (maior valor e quantidade de vezes que aparece no
vetor) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcao (int *pvetor[], int *pmaior, int *pquant){
    int i;
    *pquant = 0;
    *pmaior = *pvetor [0];
    
    for (i = 1; i<10; i++) {
        if (*pvetor[i] > *pmaior){
            *pmaior = *pvetor[i];
        }
	}

    for (i = 0; i<10; i++) {
		if (*pvetor[i] == *pmaior){
            //o operador de incremento nao funciona no ponteiro, especificamente *pxxxx++
            *pquant = *pquant + 1;
        }
	}
}

void main (void){
	int vetor [10], maior, quant = 0;
	int *pvetor[10];
    int *pmaior = &maior;
    int *pquant = &quant;
	int i;
	srand (time(NULL));

	for (i = 0; i<10; i++) {
		vetor[i] = rand () % 7;
	}

    for (i = 0; i<10; i++) {
		pvetor[i] = &vetor[i];
	}

    printf (" Vetor: ");
    for (i=0;i<10;i++){
        printf ("%d ", vetor[i]);
    }

    funcao (pvetor, pmaior, pquant);

    printf ("\n Maior elemento: >%d", maior);

    printf ("\n Quantidade de vezes que maior elemento aparece: >%d", quant);
}

------------------------------------------------------------------------------------------------

/* 4. Crie uma struct chamada ponto2d que tenha como atributos os pontos x e y.
Crie duas estruturas do tipo ponto2d chamadas ponto_inicial e ponto_final. A seguir, o programa
deve solicitar ao usuario a entrada dos dois pontos (ponto_inicial e ponto_final) e exibir o
resultado do calculo da distancia entre os dois pontos.
Lembre: a distancia entre dois pontos eh a raiz quadrada de ((x1-x2)� + (y1-y2)�) */

#include <stdio.h>
#include <math.h>

typedef struct ponto2d
{
    int x, y;

}tponto;


void main()
{
    tponto ponto_inicial;
    tponto ponto_final;
    float raiz;
    printf ("\n digite o ponto inicial x > ");
    scanf ("%d", &ponto_inicial.x);
    printf ("\n digite o ponto inicial y > ");
    scanf ("%d", &ponto_inicial.y);
    printf ("\n digite o ponto final x > ");
    scanf ("%d", &ponto_final.x);
    printf ("\n digite o ponto final y > ");
    scanf ("%d", &ponto_final.y);
    raiz = sqrt((ponto_final.x-ponto_inicial.x)*(ponto_final.x-ponto_inicial.x) + (ponto_final.y-ponto_inicial.y)*(ponto_final.y-ponto_inicial.y));
    printf ("\n raiz: >%.2f", raiz);
}

------------------------------------------------------------------------------------------------

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

------------------------------------------------------------------------------------------------

/* 7. Escreva um programa para controlar um estacionamento, que use uma struct
para armazenar a placa e o modelo de um carro, bem como o horario de entrada
e saida do estacionamento (horas e minutos). Defina e preencha uma variavel
do tipo da struct para 1 carro e mostre os dados do carro junto com o valor
devido ao estacionamento (precos: R$5,00 a primeira hora, R$2,00 para cada
hora extra e R$1,00 para tempo excedente inferior a uma hora). */

#include <stdio.h>

typedef struct estacionamento{
    char placa[7];
    char modelo[40];
    int entradahora, entradaminuto;
    int saidahora, saidaminuto;
} testacio;

void main (void){
    testacio veiculo1;
    int totalhoras = 0; 
	int totalminutos = 0;
	int minutos = 0; 
	int dinheiro = 0;
    int i;


    //PROFESSOR! encontrei um na problema na leitura das minhas strings!
    //ele acaba colocando o modelo do veiculo dentro do campo da placa (consigo ver quando printo na tela)
    //nao encontrei um jeito de resolver o problema usando a minha forma de incluir strings

    printf ("\n Insira a placa do veiculo: >");
    fflush (stdin);
    scanf ("%7[^\n]", &veiculo1.placa);
    printf ("\n Insira o modelo do veiculo: >");
    fflush (stdin);
    scanf ("%40[^\n]", &veiculo1.modelo);
    
	printf ("\n Insira a hora de entrada: >");
    scanf ("%d", &veiculo1.entradahora);
    printf ("\n Insira o minuto de entrada: >");
    scanf ("%d", &veiculo1.entradaminuto);

    printf ("\n Insira a hora de saida: >");
    scanf ("%d", &veiculo1.saidahora);
    printf ("\n Insira o minuto de saida: >");
    scanf ("%d", &veiculo1.saidaminuto);
    
    //INICIO CONVERSAO PARA MINUTOS
    minutos = ((veiculo1.saidahora - veiculo1.entradahora) *60) + (veiculo1.saidaminuto - veiculo1.entradaminuto);
    if (minutos >= 60) {
      totalhoras = minutos/60;
      totalminutos = minutos - (totalhoras * 60);
   	}
   	else {
      totalhoras = 0;
      totalminutos = minutos;
  	}
  	//FIM CONVERSAO PARA MINUTOS

    //CONVERSAO PARA HORAS || MINUTOS
    if (minutos >= 60) {
        totalhoras = minutos/60;
        totalminutos = minutos - (totalhoras * 60);
    }
    else {
        totalhoras = 0;
        totalminutos = minutos;
    }
	//FIM CONVERSAO PARA HORAS || MINUTOS

    printf("\n tempo = %d horas e %d minutos ", totalhoras, totalminutos);

    for (i = 1; i <= totalhoras; i++){
      if (i == 1) {
         dinheiro = 5;
      }
      else {
         dinheiro += 2;
      }
    }

    if (totalhoras == 0 && totalminutos <= 5) {
        printf ("\n dentro da tolerancia para abatimento do valor. \n ABATIMENTO DO VALOR");
    }
    else if (totalhoras == 0 && totalminutos > 5){
      dinheiro = 5;
    }
    else if (totalminutos > 0){
      dinheiro += 1;
    }

    printf("\n placa: > %s", veiculo1.placa);
    printf("\n modelo: > %s", veiculo1.modelo);
    printf("\n valor a pagar: > R$%d,00", dinheiro);
}

------------------------------------------------------------------------------------------------