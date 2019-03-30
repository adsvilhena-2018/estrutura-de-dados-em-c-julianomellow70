#include <stdio.h>
#include <stdlib.h>
//Lista duplamente encadeada.

typedef struct node {
    struct node *prox;
    struct node *anterior;
    int valor;
}Node;

typedef struct lista {
    Node *head;
    int tamanho;
}Lista;

void flvazia(Lista *lista){
    lista->head = NULL;
    lista->tamanho = 0;
}
int vazia (Lista lista){
    return lista.head == NULL;
}
void inserir_fim (Lista *lista , int valor){
    Node *novo_elemento = malloc(sizeof(Node));
    if (vazia(*lista)){
        lista->head = novo_elemento;
        lista->head->valor = valor;
        lista->head->prox = NULL;
        lista->head->anterior = NULL;
    }else{
        Node *atual = lista->head;
        while (atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novo_elemento;
        novo_elemento->valor = valor;
        novo_elemento->prox = NULL;
        novo_elemento->anterior = atual;
    }
    lista->tamanho++;
}

void insere (Lista *lista, int valor, int pos){
   Node *novo = malloc(sizeof(Node));
   novo->valor = valor;

    if (pos == 1){
       novo->prox = lista->head;
       lista->head->anterior = novo;
       lista->head = novo;
       novo->anterior = NULL;
   }else{
        int auxiliar = 2;
        Node *atual = lista->head;
        while (auxiliar < pos){
            atual = atual->prox;
            auxiliar++;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
        atual->prox->prox->anterior = novo;
        novo->anterior = atual;
    }
    lista->tamanho++;
}

void remover (Lista *lista, int pos) {
    if (pos == 1) {
    Node *remover = lista->head;

    lista->head = lista->head->prox;
    lista->head->anterior = NULL;
    free(remover);

    }else{
        Node *atual = lista->head;
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        Node *remover = atual->prox;
        atual->prox = atual->prox->prox;
        free (remover);
    }
    lista->tamanho--;
}
void imprimir (Lista lista){
    printf("\nImprimindo valores:\n");
    Node *atual = lista.head;
    if (lista.tamanho == 1){
        printf("%d  ",lista.head->valor);
    }else{
        while (atual->prox != NULL ){
            printf("%d  ",atual->valor);
            atual = atual->prox;
        }
        printf("%d  ",atual->valor);

    }
printf("\n");
}
int main() {
 //criando lista
 Lista  lista1;
 //inicializando lista vazia
 flvazia(&lista1);
 //inserindo valores no final
    inserir_fim(&lista1,2);
    inserir_fim(&lista1,9);
    inserir_fim(&lista1,4);
    inserir_fim(&lista1,7);
    inserir_fim(&lista1,8);
    inserir_fim(&lista1,0);
    inserir_fim(&lista1,1);
    //imprimindo valores
    imprimir(lista1);
    //inserindo valores no meio
    printf("Inserindo valor na posição 1\n");
    insere(&lista1,0,1);
    imprimir(lista1);
    printf("Inserindo valor na posição 4\n");
    insere(&lista1,0,4);
    imprimir(lista1);
    printf("Inserindo valor na posição 6\n");
    insere(&lista1,-1,6);
    imprimir(lista1);

}
