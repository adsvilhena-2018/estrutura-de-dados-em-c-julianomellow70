#include <stdio.h>
#define TAMANHO_MAX 1000
typedef struct Lista{
    int head,tail;
    int valores [TAMANHO_MAX];
    int tamanho;
}Pilha;

void fpv (Pilha *lista){
    lista->tamanho = 0;
    lista->head = 0;
    lista->tail = 0;
};

int empty(Pilha lista){
    return lista.tamanho == 0;
}

void inserir (Pilha *lista, int valor){
    if (empty(*lista)){
        lista->head = 0;
        lista->tail = 0;
        lista->valores[lista->head] = valor;
    }else{
        if(lista->head == (TAMANHO_MAX - 1)){
            lista->head = -1;
        }

        if (lista->head + 1 == lista->tail || lista->tail == 1000){
            printf("A lista já esgotou sua capacidade, remova valores para liberar espaço");
        }else{
            lista->head = lista->head+1;
            lista->valores[lista->head] = valor;
        }
    }
    lista->tamanho++;
}
void remover (Pilha *lista){
    if(empty(*lista)){
        printf("Sua lista está vazia!");
    }else{
        lista->valores[lista->tail] = -999;
        lista->head --;
        lista->tamanho --;
    }
}
void imprimir (Pilha lista){
    if (empty(lista)){
        printf("Sua lista está vazia!");
    }else{

        int atual = lista.head;
        while (atual != lista.tail){
            printf("%d  ",lista.valores[atual]);
            if (atual == (TAMANHO_MAX-1)){
                atual = 0;
            }else{
                atual--;
            }
        }

    }
}
int main() {
    Pilha lista1;
    inserir(&lista1,0);
    inserir(&lista1,1);
    inserir(&lista1,2);
    inserir(&lista1,3);
    imprimir(lista1);
    remover(&lista1);
    printf("\n");
    imprimir(lista1);
    remover(&lista1);
    printf("\n");
    imprimir(lista1);
    remover(&lista1);
    printf("\n");
    imprimir(lista1);
    return 0;
}
