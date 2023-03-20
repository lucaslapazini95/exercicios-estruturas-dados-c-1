#include <stdio.h>
#include <stdlib.h>

int fat(int x, int y) {
    int calc;
    if(y <= 1) return 1;
    if(x <= 1) {
        y--;
        x = y;
    };
    
    calc = x * fat(x-1, y);
    return calc;
}

int main() {
    int x, y;
    printf("Valor:");
    scanf("%d", &x);
    y = x;
    printf("Superfatorial de %d é = %d", x, fat(x, y));
    return 0;
}