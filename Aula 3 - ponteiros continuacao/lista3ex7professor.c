#include <stdio.h>

typedef struct tCarro
{
   char  placa[7];
   char  modelo[10];
   int hEntrada, mEntrada, hSaida, mSaida;
} tCarro;

int main(void){
   tCarro carro;
   int tHoras = 0;
   int tMinutos = 0;
   int minutos = 0;
   int total = 0;
   
   printf("Insira a placa: ");
   scanf("%s", carro.placa);
   
   printf("Insira o modelo: ");
   scanf("%s", carro.modelo);
   
   printf("Insira a hora de entrada: ");
   scanf("%d", &carro.hEntrada);
   
   printf("Insira os minutos da entrada: ");
   scanf("%d", &carro.mEntrada);
   
   printf("Insira a hora de sa�da: ");
   scanf("%d", &carro.hSaida);
   
   printf("Insira os minutos da sa�da: ");
   scanf("%d", &carro.mSaida);
   
   minutos = ((carro.hSaida - carro.hEntrada) * 60)+(carro.mSaida-carro.mEntrada);
   
   if (minutos >= 60){
      tHoras = minutos/60;
      tMinutos = minutos - (tHoras * 60);
   }
   else{
      tHoras = 0;
      tMinutos = minutos;
   }

   printf("\nTempo = %d horas e %d minutos ", tHoras, tMinutos);
   for (int i = 1; i <= tHoras; i++){
      if (i == 1){
         total = 5;
      }
      else{
         total += 2;
      }
   }
   
   if ((tHoras == 0) && (tMinutos > 0)){
      total = 5;
   }
   else if (tMinutos > 0){
      total += 1;
   }
   
   printf("\nTotal a pagar %d", total);
}