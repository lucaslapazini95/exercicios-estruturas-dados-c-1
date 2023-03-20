// ---------------------------Questão 1-----------------------------------------------
#include <stdio.h>

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

// ---------------------------Questão 2-----------------------------------------------
#include <stdio.h>
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
// ---------------------------Questão 3-----------------------------------------------
#include <stdio.h>

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
// ---------------------------Questão 4-----------------------------------------------
#include <stdio.h>

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
// ---------------------------Questão 5-----------------------------------------------
#include <stdio.h>

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
// ---------------------------Questão 6-----------------------------------------------
#include <stdio.h>

int y=1;

int seq(int x) {
   if(x<=0) return 0;
   
   printf("%d ", x);
   seq(x - 1);
}

int main() {
    int x;
    printf("Número da sequência: ");
    scanf("%d", &x);
    seq(x);
    return 0;
}
// ---------------------------Questão 7-----------------------------------------------
#include <stdio.h>

int arr[] = { 10, 20, 30, 70 }, length;

int countArray(int x) {
    length = sizeof(arr)/4;
    if(x>=length) return 0;
    printf("Array[%d] = %d\n", x, arr[x]);
    countArray(++x);
}

int main() {
    countArray(0);
}
// ---------------------------Questão 8-----------------------------------------------
#include <stdio.h>

int arr[] = { 20, 30, 10, 3, 2, 1, 1, 30, 2 }, length, menor=1;

int countArray(int x, int y) {
    length = sizeof(arr)/4;
    if(x>length || y>length) return menor;
    if(arr[x] <= arr[y]) {
        menor = arr[x];
        countArray(x, ++y);
    } else {
        x = y;
        menor = arr[y];
        countArray(x, ++y);
    }
}

int main() {
    printf("Menor valor = %d", countArray(0, 0));
}
// ---------------------------Questão 9-----------------------------------------------
#include <stdio.h>

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
// ---------------------------Questão 10-----------------------------------------------
#include <stdio.h>

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