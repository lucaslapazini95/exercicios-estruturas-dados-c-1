#include <stdio.h>
#include <stdlib.h>

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