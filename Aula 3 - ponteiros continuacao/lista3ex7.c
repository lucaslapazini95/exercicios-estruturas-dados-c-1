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