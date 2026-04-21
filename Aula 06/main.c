/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
# define n 33

int fila[n];
int ini = 0; // Inicia em 0 na linear
int fim = -1;
    
// Verifica se a fila está vazia
int Vazia() {
    return ini > fim;
}

// Verifica se a fila está cheia (limite do vetor)
int Cheia() {
    return fim == n - 1;
}

// Enfileirar (enqueue)
int enfileirar(int valor) {
    if (Cheia()) {
        printf("Erro: Fila está cheia.")
        return;
    }
    fim++;
    fila
}

int desenfileirar () {