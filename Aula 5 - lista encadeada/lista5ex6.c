/*6. Com base no codigo visto em aula, 
construa uma funcao que busque a posicao (numero do no) 
e o valor do maior elemento da lista, 
os quais devem ser retornados por referencia (ponteiros). A funcao
deve informar se a operacao foi possivel ou nao (caso a lista esteja vazia).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct listaStruct {
	int info;
	struct listaStruct *prox;
}tipoLista;

tipoLista *criaLista(){
	return NULL;
}

tipoLista* insereInicio(tipoLista *l, int i){
	tipoLista *novoNo = (tipoLista*)malloc(sizeof(tipoLista));
	novoNo->info = i; // "i" eh info
	novoNo->prox = l; // "l" eh proximo
	return novoNo;
}

void imprimeLista (tipoLista *l){
	tipoLista *pontVarre;
	for (pontVarre = l; pontVarre != NULL; pontVarre = pontVarre->prox){
		printf ("%d \n", pontVarre->info);
	}
}

int main (void){
	tipoLista *lista;
	lista = criaLista();
	lista = insereInicio(lista, 10);
	lista = insereInicio(lista, 20);
	lista = insereInicio(lista, 30);
}