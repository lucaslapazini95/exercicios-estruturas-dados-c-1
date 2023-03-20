#include <stdio.h>
#include <stdlib.h>

// estrutura autorreferenciada
typedef struct lista{
	int info;
	struct lista *prox;
} Lista;

// função de criação da lista
Lista *criar_lista(){
	return NULL;
}

// recebe a lista que receberá o novo elemento
// retorna a nova lista com inserção no início
Lista *insere_inicio(Lista *l, int i){
	Lista *novo = (Lista*)malloc(sizeof(Lista)); // cria novo nó na lista
	novo->info = i; // insere o dado a ser armazenado
	novo->prox = l; // aponta para o início da lista l (l = próximo)
	return novo; // retorna a nova lista(ponteiro para o novo elemento)
}

void imprimir_lista(Lista *l){
	Lista *p;
	// p vai varrendo cada nó da lista até NULL (tail)
	for (p = l; p != NULL; p = p->prox){
		printf("%d \n", p->info);
	}
}

// verifica se a lista está vazia
int vazia(Lista *l){
	if (l == NULL)
		return 1;
	return 0;
}

// busca elementos na lista
Lista *buscar(Lista *l, int valor){
	Lista *p;
	for (p = l; p != NULL; p = p->prox){
		if (p->info == valor){
			return p; // se o elemento for encontrado
		}
	}
	return NULL; // se o elemento não existe na lista
}

// remover um elemento da lista
Lista *remover(Lista *l, int valor){
	Lista *ant = NULL; // ponteiro para o elemento anterior
	Lista *p = l; // ponteiro para percorrer a lista
	
	while(p != NULL && p->info != valor){
		ant = p;
		p = p->prox;
	}
	
	if (p == NULL){
		printf("Valor não encontrado...\n");
		return l;
	}
	
	if (ant == NULL){
		// remove do início da lista
		l = p->prox;
	}
	else{
		// remove do meio da lista
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

// liberar a lista da memória
void liberar(Lista *l){
	Lista *p = l;
	
	while(p != NULL){
		Lista *t = p->prox; // guarda o próximo elemento da lista
		free(p); // libera o elemento atual da memória
		p = t; // atualiza a lista
	}
}

// função do menu de opções
void menu(){
	printf("\nSelecione a opção desejada: \n\t1 - Inserir no início\n\t2 - Remover\n\t3 - Imprimir\n\t4 - Buscar um valor\n\t5 - Encerrar\n\nOpção = ");
}


int main(void){
	Lista *lista;
	lista = criar_lista();
	int op = 1;
	int val;
	
	menu();
	scanf("%d", &op);
	
	while (op != 5){
		switch(op){
			case 1:
				printf("\nValor a ser inserido: ");
				scanf("%d", &val);
				lista = insere_inicio(lista, val);
				break;
			case 2:
				if (vazia(lista))
					printf("Lista VAZIA!\n");
				else{
					printf("\nValor a ser removido: ");
					scanf("%d", &val);
					lista = remover(lista, val);
				}
				break;
			case 3:
				if (vazia(lista))
					printf("Lista VAZIA!\n");
				else
					imprimir_lista(lista);
				break;
			case 4:
				if (vazia(lista))
					printf("Lista VAZIA!\n");
				else{
					printf("\nValor a ser procurado: ");
					scanf("%d", &val);
					if (buscar(lista, val) == NULL)
						printf("Valor %d NÃO encontrado na lista.\n", val);
					else
						printf("Valor %d encontrado na lista.\n", val);
				}
				break;
			default:
				printf("Opção inválida...\n\n");
		}
		menu();
		scanf("%d", &op);
	}
	
	liberar(lista);
	printf("\nPrograma encerrado. Lista liberada.\n");
}
