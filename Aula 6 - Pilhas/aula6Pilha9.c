/* 9 Na programação, as ordens algébricas devem ser consideradas da mesma forma como na
matemática, e os parênteses devem ser usados para priorizar algumas expressões diante de outras.
Construa um programa que lê uma expressão com parênteses, e usando pilhas, verifica se os
parênteses foram abertos e fechados na ordem correta.

Entradas: (())), ()()(()()), ()), (()) 
Respectivas saídas esperadas: Erro, OK, Erro, OK*/

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

//função push da pilha
Pilha* push(Pilha *ponteiroPilha, int valor){
    Pilha *novo= (Pilha*)malloc(sizeof(Pilha)); //cria novo no na pilha
    novo->prox = ponteiroPilha; //aponta para o elemento da proxima pilha
    novo->info = valor; //insere o dado a ser armazenado
    return novo; //retorna a nova pilha(ponteiro para o novo elemento)
}

//função pop da pilha
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

//verifica se a pilha está vazia
int vazia(Pilha *l){
    if (l == NULL)
        return 1;
    return 0;
}

//insera sua expressao com parenteses
void inserirExpressao(Pilha *pilhaMain){
    Pilha *p = pilhaMain;
    char expressao[100];
    printf("Digite a expressao: ");
    scanf("%s", expressao);
    int i;
    for (i = 0; expressao[i] != '\0'; i++){
        if (expressao[i] == '('){
            pilhaMain = push(pilhaMain, expressao[i]);
        }
        else if (expressao[i] == ')'){
            pilhaMain = pop(pilhaMain);
        }
    }
    if (vazia(pilhaMain) == 1){
        printf("OK");
    }
    else{
        printf("Erro");
    }
}

int main(){
    Pilha *pilhaMain = criar_pilha();
    inserirExpressao(pilhaMain);
    return 0;
}