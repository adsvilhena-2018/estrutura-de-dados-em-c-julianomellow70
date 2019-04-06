#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    struct node *prox;
    int valor;

}Node;

typedef struct lista{
    Node *topo;
    int tamanho;
}Lista;

void fpv (Lista *lista){
    lista->tamanho = 0;
    lista->topo = NULL;
}

int empty(Lista lista){
    return lista.tamanho == 0;
}

void inserir (Lista *lista, int valor){
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    if (empty(*lista)){
        novo->prox = NULL;
        lista->topo = novo;
    }else{
        novo->prox = lista->topo;
        lista->topo = novo;
    }
    lista->tamanho++;
}
void remover (Lista *lista){
    if (empty(*lista)){
        printf("Sua lista está vazia");
    }else{
        Node *liberar = lista->topo;

        lista->topo = lista->topo->prox;
        free(liberar);
    }
    lista--;
}

void imprimir (Lista lista){
    Node *atual = lista.topo;

    while (atual->prox != NULL){
        printf("%d",atual->valor);
        atual = atual->prox;
    }
    printf("%d",atual->valor);

}
int main() {

    Lista lista1;
    fpv(&lista1);
    inserir(&lista1,0);
    inserir(&lista1,2);
    inserir(&lista1,3);
    inserir(&lista1,1);
    //imprimindo valores
    imprimir(lista1);
    //removendo valores
    remover(&lista1);
    remover(&lista1);
    //imprimindo valores depois de removidos 2 valores
    printf("\n");
    imprimir(lista1);
    //inserindo mais dois valores
    inserir(&lista1,8);
    inserir(&lista1,9);
    printf("\n");
    imprimir(lista1);
    //removendo valor
    remover(&lista1);
    printf("\n");
    imprimir(lista1);
    return 0;
}
