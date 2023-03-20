#include <stdio.h>
#include <stdlib.h>

// struct do nó (é uma lista encadeada)
typedef struct no{
	int info;
	struct no *proximo;
} No;

// struct da fila
// necessitamos saber qual o inicio e o fim da fila para controlar a insercao e remocao
typedef struct fila{
	No *ini;
	No *fim;
} Fila;

// aloca dinamicamente a estrutura da fila e retorna um ponteiro
Fila* criarFila(){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

// informa se a fila esta vazia ou nao
int vazia(Fila *f){
	return (f->ini == NULL);
}

// adiciona um novo elemento ao final da fila
void inserir(Fila *f, int val){
	No *NoAuxiliar = (No*)malloc(sizeof(No)); // cria nó auxiliar 
	NoAuxiliar->info = val; // armazena a informacao passada pelo usuario (variavel "val")
	NoAuxiliar->proximo = NULL; // novo no passa a ser o ultimo, logo, aponta para NULL
	if(vazia(f)) // verifica se a fila esta vazia
		f->ini = NoAuxiliar; // se vazia, novo no passa a ser o primeiro
	else
		f->fim->proximo = NoAuxiliar; // se nao vazia, enlaça os nós (o ultimo aponta para o novo)
	f->fim = NoAuxiliar; // finalmente, fim da fila aponta para o novo nó
}

// remove o elemento do inicio da fila
int remover(Fila *f){
	No *temp;
	int val; 
	if(vazia(f)){
		printf("Fila vazia. Encerrando...\n");
		exit(1);
	}
	temp = f->ini; // guarda o primeiro no
	val = temp->info; // guarda o valor
	f->ini = temp->proximo; // o inicio da fila passa a ser o proximo no
	free(temp); // libera temp da memoria
	return val; // retorna o valor do nó removido
}

// imprime os elementos da fila
void imprimir(Fila* f){
	No *temp = f->ini;
	if(vazia(f))
		printf("Fila vazia.");
	else{
		while(temp != NULL){
			printf("%d ", temp->info);
			temp = temp->proximo;
		}
	}
	printf("\n");
}

// libera a memoria utilizada pela fila
void liberar(Fila* f){
	No *temp = f->ini;

	while(temp != NULL){
		No* t = temp->proximo;
		free(temp);
		temp = t;
	}
	free(f);
	printf("Memoria liberada. Encerrando...\n");
	exit(1); // encerra a execucao
}

//função que retorna o número de elementos da fila que possuem valor ímpar
void numImpar(Fila* f){
	No *auxiliar;
	auxiliar = f->ini;
	int cont = 0;
	while(auxiliar != NULL){
		if(auxiliar->info % 2 != 0)
			cont++;
		auxiliar = auxiliar->proximo;
	}
	printf("A fila possui %d elementos com valor impar.\n", cont);
}

//função que inverte a ordem dos elementos na fila
void inverter(Fila* f){
	No *auxiliar;
	auxiliar = f->ini;
	int cont = 0;
	while(auxiliar != NULL){
		cont++;
		auxiliar = auxiliar->proximo;
	}
	int vetor[cont];
	auxiliar = f->ini;
	for(int i = 0; i < cont; i++){
		vetor[i] = auxiliar->info;
		auxiliar = auxiliar->proximo;
	}
	auxiliar = f->ini;
	for(int i = cont-1; i >= 0; i--){
		auxiliar->info = vetor[i];
		auxiliar = auxiliar->proximo;
	}
}

//função que retorna fila nova sem os valores negativos
Fila* DevolveFilaSemNegativos(Fila* f){
	Fila* novaFila = criarFila();
	No* auxiliar = f->ini;
	while(auxiliar != NULL){
		if(auxiliar->info >= 0)
			inserir(novaFila, auxiliar->info);
		auxiliar = auxiliar->proximo;
	}
	return novaFila;
}

//menu de opções
void menu(){
	printf("1 - Inserir elemento na fila\n");
	printf("2 - Remover elemento da fila\n");
	printf("3 - Imprimir fila\n");
	printf("4 - Liberar memoria\n");
	printf("5 - Numero de elementos com valor impar\n");
	printf("6 - Inverter a ordem dos elementos na fila\n");
	printf("7 - Retorna a fila sem os valores negativos\n");
	printf("8 - Sair\n");
}

//função principal
int main(void){
	Fila *f = criarFila();
	int opcao, valor;
	opcao=0;
	menu();
	scanf("%d", &opcao);
	while(opcao != 8){
		switch(opcao){
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);
				inserir(f, valor);
				break;
			case 2:
				valor = remover(f);
				printf("Valor removido: %d\n", valor);
				break;
			case 3:
				imprimir(f);
				break;
			case 4:
				liberar(f);
				break;
			case 5:
				numImpar(f);
				break;
			case 6:
				inverter(f);
				break;
			case 7:
				f = DevolveFilaSemNegativos(f);
				break;
			default:
				printf("Opcao invalida.\n");
				break;
		}
		menu();
		scanf("%d", &opcao);
	}
}