# include <stdio.h>
# include <stdlib.h>

// Estrutura que representa a fila circular
typedef struct{
    int *dados;        // Ponteiro para o vetor dinâmico (onde os vetores ficam)
    int frente;        // Indicie de primeiro elemento da fila
    int tras;          // indice do ultimo elemento inserido
    int tamanho;       // Quantidade atual de elementos da fila
    int capacidade;    // tamanho máximo da fila
} Fila;

Fila* criarFila(int capacidade) {

    Fila *f = (Fila*) malloc(sizeof(Fila));



    f->dados = (int*) malloc(capacidade * sizeof(Fila));

    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}


int estaVazia(Fila *f) {
    return f->tamanho == 0;
}

int estaCheia(Fila *f) {
    return f->tamanho == f->capacidade;
}

void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Erro: Está cheia!\n");
        return;
    }

    f->tras = (f->tras + 1) % f->capacidade;

    *(f->dados + f->tras) = valor;

    f->tamanho++;

    printf("Enfileiranbdo: %d", valor);
}

int desenfileirar(Fila *f) {

    if (estaVazia(f)) {
        printf("Erro: Fila está vazia!");
        return -1;
    }

    int valor = *(f->dados + f->frente);

    f->frente = (f->frente + 1) % f->capacidade;

    f->tamanho--;

    return valor;
}