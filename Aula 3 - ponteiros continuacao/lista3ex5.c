/* 5. Crie uma struct para armazenar os dados dos jogadores de um time de volei
(nome, idade, posicao, e numero_camisa). Crie duas estruturas: uma para 
armazenar os jogadores titulares e outra para os reservas. Construa um programa
no qual o usuario possa cadastrar os jogadores (6 titulares e 4 reservas) e
exibir um relatorio completo do time (use funcoes e ponteiros quando possivel, 
e um menu para as opcoes do usuario).*/

#include <stdio.h>

typedef struct reserva {
    char nome[40];
    int idade;
    char posicao[30];
    int numerocamisa;
}treserva;

typedef struct titular {
    char nome[40];
    int idade;
    char posicao[30];
    int numerocamisa;
}ttitular;

void main (void){
    
}