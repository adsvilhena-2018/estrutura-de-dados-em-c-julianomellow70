#include <stdio.h>
#define TAMANHO_MAX 1000

typedef struct lista{
    int tamanho;
    int head;
    int tail;
    int valores [TAMANHO_MAX];
}Lista;

void FLV (Lista *lista){
    lista->tamanho = 0;
    lista->head = 0;
    lista->tail = 0;
}

int empty(Lista lista){
   return lista.tamanho <= 0;
}
void enfileira (Lista *lista, int valor){
    if (empty(*lista)){
        lista->head = 0;
        lista->tail = 0;
        lista->valores[lista->tail] = valor;
    }else{
          if(lista->tail == (TAMANHO_MAX - 1)){
              lista->tail = -1;
          }
        
          if (lista->tail + 1 == lista->head || lista->tamanho == 1000){
            printf("A lista já esgotou sua capacidade, remova valores para liberar espaço");
          }else{
             lista->tail = lista->tail+1;
             lista->valores[lista->tail] = valor;
          }
    }
    lista->tamanho++;
}
void remover_FIFO (Lista *lista){
   if(empty(*lista)){
    printf("Sua lista está vazia!");   
   }else{
    lista->valores[lista->head] = -999;
    lista->head ++;
    lista->tamanho --;
    }
   }

void imprimir_lista (Lista lista){
    if (empty(lista)){
        printf("Sua lista está vazia!");
    }else{
    
    int atual = lista.head;
    while (atual != lista.tail){
    printf("%d  ",lista.valores[atual]);
        if (atual == (TAMANHO_MAX-1)){
            atual = 0;
        }else{
            atual++;
        }
    }
    printf("%d  ",lista.valores[atual]);
    }
}

int main()
{
   Lista lista1;
   FLV(&lista1);
   imprimir_lista(lista1);
   //enfileirando valores
   enfileira(&lista1, 5);
   enfileira(&lista1, 8);
   enfileira(&lista1, 1);
   enfileira(&lista1, 0);
   enfileira(&lista1, 5);
   enfileira(&lista1, 5);
   enfileira(&lista1, 6);
   enfileira(&lista1, 4);
   //imprimindo valores
   printf("\nImprimindo valores:\n");
   imprimir_lista(lista1);
    //removendo e imprimindo 8 vezes
    for (int i = 0; i<=7;i++) {
            //removendo valores
            remover_FIFO(&lista1);
            //imprimindo valores
            printf("\nRemovendo, utilizando método FIFO:\n");
            imprimir_lista(lista1);
    }
   
   
   
   return 0;
}
