#include <stdio.h>
#include <stdlib.h>

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