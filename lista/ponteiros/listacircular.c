
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node *proximo;
  int valor;
} Node;

typedef struct Lista
{
  Node *head;
  int tamanho;
} Lista;

void
flv (Lista * lista)
{
  lista->head = NULL;
  lista->tamanho = 0;
}

int
vazia (Lista lista)
{
  return lista.head == NULL;
}

void
insereFim (Lista * lista, int valor)
{
  Node *novo = malloc (sizeof (Node));
  novo->valor = valor;

  if (vazia (*lista))
    {
      lista->head = novo;
      novo->proximo = lista->head;
    }
  else
    {
      Node *atual = lista->head;

      while (atual->proximo != lista->head)
	{
	  atual = atual->proximo;
	}
      atual->proximo = novo;
      novo->proximo = lista->head;

    }
  lista->tamanho++;
}

void
remover (Lista * lista, int pos)
{
  if (pos == 1)
    {
      Node *liberar = lista->head;
      lista->head = lista->head->proximo;
      free (liberar);
    }
  else
    {
      int aux = 2;
      Node *atual = lista->head;
      Node *liberar = malloc (sizeof (Node));

      while (aux < pos)
	{
	  atual = atual->proximo;
	  aux++;
	}
      liberar = atual->proximo;
      atual->proximo = atual->proximo->proximo;

      free (liberar);
    }

}

void
inserir (Lista * lista, int pos, int valor)
{
  Node *novo = malloc (sizeof (Node));
  novo->valor = valor;
  if (pos == 1)
    {
      novo->proximo = lista->head;
      lista->head = novo;
    }
  else
    {
      Node *atual = lista->head;
      int aux = 2;
      while (aux < pos)
	{
	  atual = atual->proximo;
	  aux++;
	}
      novo->proximo = atual->proximo;
      atual->proximo = novo;
    }
  lista->tamanho++;

}
 void imprimir (Lista lista)
  {
    if (vazia (lista))
      {
	printf ("Sua lista estC! vazia");
      }
    else
      {
	Node *atual = lista.head;
	printf ("\nImprimindo lista:\n");
	while (atual->proximo != lista.head)
	  {
	    printf ("%d ", atual->valor);
	    atual = atual->proximo;
	  }
	printf ("\n");
      }
  }
int main (){
  //criando lista vazia
  Lista lista1;
  flv (&lista1);
  //inserindo no fim
  insereFim (&lista1, 2);
  insereFim (&lista1, 0);
  insereFim (&lista1, 1);
  insereFim (&lista1, 2);
  insereFim (&lista1, 3);
  insereFim (&lista1, 3);
  insereFim (&lista1, 7);
  //imprimindo resultado
   imprimir(lista1);
  //inserindo no meio
  inserir(&lista1, 2, -1);
  //imprimindo resultado
   imprimir(lista1);
   inserir(&lista1, 4, -1);
  //imprimindo resultado
   imprimir(lista1);
   //remover
   remover(&lista1,2);
   //imprimindo resultado
   imprimir(lista1);
   


 printf ("Hello World");

  return 0;
}
