#include <stdio.h>
#include <stdlib.h>

// estrutura autorreferenciada
typedef struct lista{
	int info;
	struct lista *prox;
} Lista;

// funcao de criacao da lista
Lista *criar_lista(){
	return NULL;
}

// recebe a lista que recebera o novo elemento
// retorna a nova lista com insercao no inicio
Lista *insere_inicio(Lista *l, int i){
	Lista *novo = (Lista*)malloc(sizeof(Lista)); // cria novo no na lista
	novo->info = i; // insere o dado a ser armazenado
	novo->prox = l; // aponta para o inicio da lista l (l = proximo)
	return novo; // retorna a nova lista(ponteiro para o novo elemento)
}

void imprimir_lista(Lista *l){
	Lista *p;
	// p vai varrendo cada no da lista ato NULL (tail)
	for (p = l; p != NULL; p = p->prox){
		printf("%d \n", p->info);
	}
}

// verifica se a lista esta vazia
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
	return NULL; // se o elemento nao existe na lista
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
		printf("Valor nao encontrado...\n");
		return l;
	}
	
	if (ant == NULL){
		// remove do inicio da lista
		l = p->prox;
	}
	else{
		// remove do meio da lista
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

// liberar a lista da memoria
void liberar(Lista *l){
	Lista *p = l;
	
	while(p != NULL){
		Lista *t = p->prox; // guarda o proximo elemento da lista
		free(p); // libera o elemento atual da memoria
		p = t; // atualiza a lista
	}
}

void buscaMaior (Lista *l, int *maior, int *posicao){
	Lista *p;
	*maior = l->info;
	*posicao = 1;
	int i = 0;
	
	for(p = l; p != NULL; p = p->prox){
		i++;
		if (p->info > *maior){
			*maior = p->info;
			*posicao = i;
		}
	}
}

Lista* pares(Lista *l, Lista *lPares){
	Lista *p;
	for (p = l; p != NULL; p = p->prox){
		if (p->info % 2 == 0){
			lPares = insere_inicio (lPares, p->info);
		}
	}
	return lPares;
}

Lista* inverter(Lista *l, Lista *lInversa){
	Lista *p;
	for (p = l; p != NULL; p = p->prox){
		lInversa = insere_inicio (lInversa, p->info);
		}
	return lInversa;
}

Lista* removePosicao(Lista* l, int posicao){
	Lista *ant = NULL; // ponteiro para o elemento anterior
	Lista *p = l; // ponteiro para percorrer a lista
	int i = 1;
	
	while(p != NULL && i!= posicao){
		ant = p;
		p = p->prox;
		i++;
	}
	
	if (p == NULL){
		printf("Posicao nao encontrada...\n");
		return l;
	}
	
	if (ant == NULL){
		// remove do inicio da lista
		l = p->prox;
	}
	else{
		// remove do meio da lista
		ant->prox = p->prox;
	}
	printf ("Elemento %d removido da lista\n", posicao);
	free(p);
	return l;
}

int contar(Lista* l){
	Lista *p = l;
	int i = 0;
	while (p != NULL){
		i++;
		p = p -> prox;
	}
	return i;
}

int contarRecursiva (Lista* l){
	Lista *p = l;
	if (p != NULL) return (1 + contarRecursiva(p->prox));
	else return(0);
}

// funcao do menu de opcoes
void menu(){
	printf("\nSelecione a opcao desejada: ");
	printf("\n\t1 - Inserir no inicio");
	printf("\n\t2 - Remover");
	printf("\n\t3 - Imprimir");
	printf("\n\t4 - Buscar um valor");
	printf("\n\t5 - Busca o maior elemento");
	printf("\n\t6 - Imprime nova lista com valores pares");
	printf("\n\t7 - Imprime nova lista com a ordem invertida");
	printf("\n\t8 - Remover posicao");
	printf("\n\t9 - Contar elementos");
	printf("\n\t10 - Contar elementos com recursividade");
	printf("\n\t11 - Encerra o programa");
	printf("\nOpcao: ");
}

int main(void){
	Lista *lista;
	lista = criar_lista();
	int op = 1;
	int val;
	int maior = 0;
	int posicao = 0;
	
	menu();
	scanf("%d", &op);
	
	while (op != 11){
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
						printf("Valor %d Nao encontrado na lista.\n", val);
					else
						printf("Valor %d encontrado na lista.\n", val);
				}
				break;
			case 5:
				if (vazia(lista))
					printf ("Lista VAZIA\n");
				else{
					buscaMaior (lista, &maior, &posicao);
					printf ("%d valor, %d posicao", maior, posicao);
				}
				break;
			case 6:
				if (vazia(lista))
					printf ("Lista VAZIA\n");
				else{
					Lista *lPares;
					lPares = criar_lista();
					imprimir_lista(pares(lista, lPares));
					liberar(lPares);
				}
				break;
			case 7:
				if (vazia(lista))
					printf ("Lista VAZIA\n");
				else{
					Lista *lInversa;
					lInversa = criar_lista();
					imprimir_lista(inverter(lista, lInversa));
					liberar(lInversa);
				}
				break;
			case 8:
				if (vazia(lista))
					printf ("Lista VAZIA\n");
				else{
					printf ("\nPosicao a ser removida: ");
					scanf ("%d", &posicao);
					lista = removePosicao(lista, posicao);
				}
				break;
			case 9:
				if (vazia(lista))
					printf ("Lista VAZIA\n");
				else{
					printf ("\nNos da lista: %d", contar(lista));
				}
				break;
			case 10:
				if (vazia(lista))
					printf ("Lista VAZIA\n");
				else{
					printf ("\nNos da lista: %d", contarRecursiva(lista));
				}
				break;
			default:
				printf("Opcao invalida...\n\n");
		}
		menu();
		scanf("%d", &op);
	}
	
	liberar(lista);
	printf("\nPrograma encerrado. Lista liberada.\n");
}