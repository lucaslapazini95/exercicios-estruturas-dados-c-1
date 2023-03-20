#include <stdio.h>
#include <stdlib.h>

//criar a struct da pilha
typedef struct pilha{
	int info;
	struct pilha *prox;
} Pilha;

//CRIAR PILHA!!
Pilha* criar_pilha(){
	return NULL;
}

//VAZIA!! verifica se a pilha esta vazia
int vazia(Pilha *l){
	if (l == NULL)
		return 1;
	return 0;
}

//EMPILHAR!! inserir no inicio
Pilha* push(Pilha *ponteiroPilha, int valor){
	Pilha *novo= (Pilha*)malloc(sizeof(Pilha)); //cria novo no na pilha
	novo->prox = ponteiroPilha; //aponta para o elemento da proxima pilha
	novo->info = valor; //insere o dado a ser armazenado
	return novo; //retorna a nova pilha(ponteiro para o novo elemento)
}

//DESEMPILHAR!! remover um elemento da pilha
Pilha* pop(Pilha *pilhaMain){
	Pilha *p = pilhaMain; //ponteiro para percorrer a pilha
	if (p == NULL){
		//pilha vazia
	}
	else{
		//remove do topo
		p = p->prox;
	}
	return p;
}

//IMPRIMIR!! pilha
void imprimir_pilha(Pilha *pilhaMain){
	Pilha *p;
	// p vai varrendo cada no da pilha ate NULL (tail)
	for (p = pilhaMain; p != NULL; p = p->prox){
		printf("%d \n", p->info);
	}
}

//TOPO!! mostra o valor no topo
int mostraTopo(Pilha *pilhaMain){
	Pilha *p = pilhaMain;
	return p->info;
}

//LIBERAR!! libera a pilha
void liberar(Pilha *pilhaMain){
	Pilha *p = pilhaMain;
	while(p != NULL){
		Pilha *t = p->prox; // guarda o proximo elemento da pilha
		free(p); // libera o elemento atual da memoria
		p = t; // atualiza a pilha
	}
}

//INVERTER!! inverte a posicao dos elementos da pilha
Pilha* inverter(Pilha *pilhaMain, Pilha *pInversa){
	Pilha *p;
	for (p = pilhaMain; p != NULL; p = p->prox){
		pInversa = push(pInversa, p->info);
	}
	return pInversa;
}

//funcao que coloca os elementos da pilha em ordem crescente
Pilha* crescente(Pilha *pilhaMain, Pilha *pilhaOrdenada){
	Pilha *p;
	int aux;
	for (p = pilhaMain; p != NULL; p = p->prox){
		if (p->prox != NULL){
			if (p->info > p->prox->info){
				aux = p->info;
				p->info = p->prox->info;
				p->prox->info = aux;
			}
		}
	}
	return pilhaMain;
}

//funcao do menu de opcoes
void menu(){
	printf("\nSelecione a opcao desejada: ");
	printf("\n\t1 - Empilha");
	printf("\n\t2 - Desempilha");
	printf("\n\t3 - Imprimir");
	printf("\n\t4 - Elemento no topo");
	printf("\n\t5 - Inverter");
	printf("\n\t6 - Ordenar pilha em ordem crescente");
	printf("\n\t7 - Encerra o programa\n");
}

int main(void){
	Pilha *pilha;
	pilha = criar_pilha();
	int op = 1;
	int val;
	menu();
	scanf("%d", &op);
	
	while (op != 7){
		switch(op){
			case 1:
				printf("\nValor a ser inserido: ");
				scanf("%d", &val);
				pilha = push(pilha, val);
				break;
			case 2:
				if (vazia(pilha))
					printf("Pilha VAZIA!\n");
				else{
					pilha = pop(pilha);
				}
				break;
			case 3:
				if (vazia(pilha))
					printf("Pilha VAZIA!\n");
				else
					imprimir_pilha(pilha);
				break;
			case 4:
				if (vazia(pilha))
					printf("Pilha VAZIA!\n");
				else{
					printf ("%d", mostraTopo(pilha));
				}
				break;
			case 5:
				if (vazia(pilha))
					printf ("Pilha VAZIA\n");
				else{
					Pilha *pInversa;
					pInversa = criar_pilha();
					pilha = inverter(pilha, pInversa);
					liberar(pInversa);
				}
				break;
			case 6:
				if (vazia(pilha))
					printf ("Pilha VAZIA\n");
				else{
					Pilha *pilhaOrdenada;
					pilhaOrdenada = criar_pilha();
					pilha = crescente(pilha, pilhaOrdenada);
					liberar(pilhaOrdenada);
				}
				break;
			default:
				printf("Opcao invalida...\n\n");
		}
		menu();
		scanf("%d", &op);
	}	
	liberar(pilha);
	printf("\nPrograma encerrado. Pilha liberada.\n");
}