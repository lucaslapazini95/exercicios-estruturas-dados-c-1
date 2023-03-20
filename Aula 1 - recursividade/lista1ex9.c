#include <stdio.h>
#include <stdlib.h>

int calc=1;

int count(int x) {
    if (x==1) return 0;
    
    calc = 1 + (x*x)/x + count(x-1);
    return calc;    
}

int main() {
    int x;
    printf("Número de contas: ");
    scanf("%d", &x);
    printf("Valor = %d", count(x));
    return 0;
}