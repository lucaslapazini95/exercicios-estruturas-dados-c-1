#include <stdio.h>
#include <stdlib.h>

int pot(int base, int expo) {
    int calc;
    if(expo <= 0) return 1;
    calc = base * pot(base, expo - 1);
    return calc;
}

int main() {
    int x, y;
    printf("Base: ");
    scanf("%d", &x);
    printf("Expo: ");
    scanf("%d", &y);
    printf("Valor da potẽncia: %d", pot(x, y));
    return 0;
}