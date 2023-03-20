#include <stdio.h>
#include <stdlib.h>

int y=1;

int seq(int x) {
   if(x<=0) return 0;
   
   printf("%d - ", y++);
   seq(x - 1);
}

int main() {
    int x;
    printf("Número da sequência: ");
    scanf("%d", &x);
    seq(x);
    return 0;
}