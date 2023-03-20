#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double soma(int value) {
    double calc;
    if(value <= 1) return 1;
    calc = pow(value, 3) + soma(value - 1);
    return calc;
}

int main() {
    int x;
    printf("Número de somas: ");
    scanf("%d", &x);
    printf("Valor da soma = %.0f", soma(x));
    return 0;
}