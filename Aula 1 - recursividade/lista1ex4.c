#include <stdio.h>
#include <stdlib.h>

int calc=1;

int fibo(int x) {
    if (x==1 || x==2) return 1;
    

    calc = fibo(x-1) + fibo(x-2);
    return calc;
}

int main() {
    int x;
    printf("Número da sequência: ");
    scanf("%d", &x);
    printf("Valor = %d", fibo(x));
    return 0;
}