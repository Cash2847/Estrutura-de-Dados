# include <stdio.h>
# include <stdlib.h>

// Estrutura do nó
struct No
{
   int valor;
   struct No *prox;
   struct No *ant;
};

// Ponteiro para o início da lista
struct No *inicio = NULL;

// Inserir no início da lista
void inserirInicio(int valor)
{
   struct No *novo = (struct No *)malloc(sizeof(struct No));

    if (novo == NULL){
        printf("Erro de memória.\n");
        return;
    }

   novo->valor = valor;
   novo->prox = inicio;
   inicio = novo;
}

// Inserir no final
void inserirFim(int valor)
{
   struct No *novo = (struct No *)malloc(sizeof(struct No));
   struct No *atual; 
    if (novo == NULL){
        printf("Erro de memória.\n");
        return;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (inicio == NULL)
    {
        inicio = novo;
        return;
    }

    atual = inicio;

    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo;
}