#include <stdio.h>
#define MAX_SIZE 5 // Tamanho máximo da fila

// -1 Indicar que a fila está vazia
int fila[MAX_SIZE]; // Vetor que armazena os elementos
int frente = -1; // Índice do primeiro elemento
int tras = -1; // Índice do último elemento

// Verifica se a fila está vazia
int estaVazia() {
    return frente == -1;
}

// Verifica se a fila está cheia (versão circular)
int estaCheia() {
    return (frente == (tras + 1) % MAX_SIZE);
}

// Enfileirar (enqueue)
void enfileirar(int valor) {

    if (estaCheia()) {
        printf("Erro: Fila cheia!");
        return;
    }

    if (estaVazia()) {
        frente = 0; // Primeira inserção
    }
    tras = (tras + 1) % MAX_SIZE;
    fila[tras] = valor;
    printf("Enfileirado: %d\n", valor);
}

// Desenfileirar (dequeue)
int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!")
    }

    int valor = fila[frente];

    if (frente = tras) {

        frente = -1;
        tras = -1;
    } else {
        frente = (frente + 1) % MAX_SIZE;
    }

    return valor;
}
