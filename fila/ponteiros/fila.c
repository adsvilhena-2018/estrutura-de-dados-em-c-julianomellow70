#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    struct Node *prox;
    int valor;

}Node;

typedef struct Lista{
    int tamanho;
    Node *head;
}Lista;
void flV (Lista *lista){
    lista->head = NULL;
    lista->tamanho = 0;
}
int vazia (Lista lista){
    return lista.head == NULL;
}
void enfileira (Lista *lista, int item){
    Node *novo = malloc(sizeof(Node));
    novo->valor = item;
    if (vazia(*lista)){
        lista->head = novo;
        novo->prox = NULL;
    }else{
        Node *atual = lista->head;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->prox = NULL;
    }
    lista->tamanho++;
}
void desinfileira (Lista *lista){
    if (vazia(*lista)){
        lista->head = NULL;
        lista->tamanho = 0;
    }else{
        Node *liberar = lista->head;
        lista->head = lista->head->prox;
        free(liberar);
        lista->tamanho--;
    }

}
void imprimir (Lista lista){
    if (vazia(lista)){
        printf("Lista está vazia");
    }else{
       Node *atual = lista.head;
        while (atual->prox != NULL){
            printf("%d  ",atual->valor);
            atual = atual->prox;
        }
        printf("%d  ",atual->valor);
    }
}
int main() {
    Lista lista1;
    flV(&lista1);

    //enfileirando valores
    enfileira(&lista1, 1);
    enfileira(&lista1, 5);
    enfileira(&lista1, 6);
    enfileira(&lista1, 2);
    enfileira(&lista1, 6);
    enfileira(&lista1, 7);
    enfileira(&lista1, 8);
    imprimir(lista1);
    printf("\nDesinfileirando ---------\n");
    //desinfileirar
    desinfileira(&lista1);
    imprimir(lista1);
    printf("\nDesinfileirando ---------\n");
    //desinfileirar
    desinfileira(&lista1);
    imprimir(lista1);
    printf("\nDesinfileirando ---------\n");
    //desinfileirar
    desinfileira(&lista1);
    imprimir(lista1);

    return 0;
}
