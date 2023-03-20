/* 8. Escreva uma funcao que converta minutos em horas e minutos. A funcao recebe
um inteiro (MINUTOS) e os enderecos de duas variaveis inteiras (HORAS e MINUTOS)
e atribui valores e essas variaveis de modo que m seja menor que 60 e que 60 * H + M
seja = a MINUTOS. Escreva tambem uma funcao main que use essa funcao */

#include <stdio.h>

int horario (int minutos, int *horas, int *min){
    *horas = minutos/60;
    *min = minutos % 60;
}

void main (void){
    int minutos;
    int horas, min;
    printf(" type minutos: >");
    scanf ("%d", &minutos);
    horario (minutos, &horas, &min);
    printf ("\n convertido em horas: > %d:%d", horas, min);
}