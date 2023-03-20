#include <stdio.h>
#include <stdlib.h>

int soma(int value) {
    int calc;
    if(value <= 1) return 1;
    
    calc = value + soma(value - 1);
    return calc;
}

int main() {
    int x;
    printf("Número de somas: ");
    scanf("%d", &x);
    printf("Valor da soma = %d", soma(x));
    return 0;
}