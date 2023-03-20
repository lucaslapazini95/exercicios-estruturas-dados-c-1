#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retorno(int **mat, int l, int c, int valor){
	int i, j, r;
	
	printf("Informe um valor: \n");
	scanf("%d", &valor);
	
	for(i = 0; i < l; i++){ 
    	for(j = 0; j < c; j++){
	        if(mat[i][c] == valor){
	            r = 1;
	        }else{
	            r = 0;
	        }
        }
    }
    return r;
}

int main(){
	
	srand (time(0));
	
	int l, c, i, j, valor, r;
	int **mat;
	
	printf("Informe a dimencao da matriz: \n");
	scanf("%d", &l);
	scanf("%d", &c);
	
	mat = (int*)malloc(l * sizeof(int));
	
	for(i = 0; i < l; i++) {
        mat[i] = (int*)malloc(c * sizeof(int));
    }
    
    for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			mat[i][j] = rand()%100;
		}
	}
	
	for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf ("\n");
    }
    printf("Informe um valor: \n");
	scanf("%d", &valor);
	
    for(i = 0; i < l; i++){  
    	for(j = 0; j < c; j++){
	        if(valor == mat[i][j]){
	            r = 1;
                break;
			}
            else{
                r = 0;
            }
        }
    }
   printf("%d", r);
}