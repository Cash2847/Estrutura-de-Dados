#include <stdlib.h>
#include <stdio.h>

#define MAX 10

// Estrutura da fila de prioridade.
typedef struct {
    int valor;
    int prioridade;
} Elemento;

Elemento fila[MAX];
int tamanho = 0;

// Verifica se a fila está vazia.
int filaVazia() {
    return tamanho == 0;
}

// Verifica se a fila está cheia.

int filaCheia() {
    return tamanho == MAX;
}

// Inserir elemento na fila.
//valor 10 | Prioridade 1
//Valor 20 | Perioridade 10

void enqueue(int valor, int prioridade) {
    if (filaCheia()) {
        printf("Fila chaia.\n");
        return;
    }

    fila[tamanho].valor = valor;
    fila[tamanho].prioridade = prioridade;
    tamanho++;

    printf("Elemento %d inserido com prioridade %d\n", valor, prioridade);
}

// Remover elemento de maior prioridade

void dequeue() {
    if (filaVazia()) {
        printf("Fila vazia.\n");
        return;
    }

    int maiorPrioridade = 0;

    // Procura o indice do elemento com maior prioridade.

    for (int i = 1; i < tamanho, i++) {
        if (fila[i].prioridade > fila[maiorPrioridade].prioridade) {
            maiorPrioridade = i;
        }
    }

    printf("Removido: %d (Prioridade: %d)\n",
        fila[maiorPrioridade].valor,
        fila[maiorPrioridade].prioridade);

    // Move os elementos para preencher o espaço removido.
    for (int i = maiorPrioridade; i < tamanho - 1; i++) {
        fila[i] = fila[i + 1];
    }

    tamanho--;
}

// Exibir Fila.

void exibirFila() {
    if (filaVazia()) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila de Prioridade:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Valor: %d | Prioridade: %d\n",
                fila[i].valor,
                fila[i].prioridade);
    }
}

int main() {

    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 1);
    enqueue(40, 4);

    exibirFila();

    printf("\n");

    dequeue();

    printf("\n");

    return 0;
}