#include <stdio.h>
#include <stdlib.h>
typedef struct node{
struct node *proximo;
int valor;
}Node;

typedef struct lista{
int quantidade;
Node *inicio;
}Lista;

void CriarListaVazia(Lista *lista){
lista->inicio = NULL;
lista->quantidade = 0;
}

int vazia (Lista lista){
return lista.inicio == NULL;
}

void inserir_no_fim (int valor, Lista *lista){
if (vazia(*lista)){
lista->inicio = malloc(sizeof(Node));
lista->inicio->proximo = NULL;
lista->inicio->valor = valor;
}else{
    Node *atual = lista->inicio;
    
    while (atual->proximo != NULL){
        atual = atual->proximo;
    }
    
    Node *novo = malloc(sizeof(Node));
   atual->proximo = novo;
   novo->valor = valor;
   novo->proximo = NULL;
}
lista->quantidade ++;
}

void iserir (int pos, int valor, Lista *lista){
     Node *novo = malloc(sizeof(Node));
    if (pos == 1){
       
        novo->proximo = lista->inicio;
        novo->valor = valor;
        lista->inicio = novo;
        
    }else{
        int auxiliar = 2;
        Node *atual;
        while (pos < auxiliar){
            atual = atual->proximo;
            pos++;
        }
        
    novo->valor = valor;
    atual->proximo = novo;
    
    lista->quantidade++;
    
        
    }
    
}
void remover (int pos, Lista *lista){
    if (pos == 1){
        Node *remover = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(remover);
    }else{
        int auxiliar = 2;
        Node *atual = lista->inicio; 
        while(pos < auxiliar){
            atual = atual->proximo;
            auxiliar++;
        }
        Node *remover = atual->proximo;
        atual->proximo = atual->proximo->proximo;
        free(remover);
    }
    lista->quantidade--;
}
void imprimir_lista (Lista lista){
    Node *atual = lista.inicio;
    
    while(atual->proximo != NULL){
        printf("%d",atual->valor);
        atual = atual->proximo;
    printf("\n");    
    }
    
}


int main(int argc, char** argv) {
	Lista lista;
	CriarListaVazia(&lista);
	inserir_no_fim(1,&lista);
	inserir_no_fim(2,&lista);
	inserir_no_fim(3,&lista);
	inserir_no_fim(4,&lista);
	inserir_no_fim(5,&lista);
	inserir_no_fim(6,&lista);
	inserir_no_fim(7,&lista);
	inserir_no_fim(8,&lista);
	inserir_no_fim(9,&lista);
	
	imprimir_lista(lista);
	printf("removendo");
	remover(3,&lista);
	imprimir_lista(lista);
	return 0;
}
