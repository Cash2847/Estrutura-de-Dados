/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
# define n 5



typedef struct {
    int *valores;
    int ini;
    int fim;
} Fila;
// Verifica se a fila está vazia
int Vazia(Fila *f) {
    return f->ini > f->fim;
}

// Verifica se a fila está cheia (limite do vetor)
int Cheia(Fila *f) {
    return f->fim == n - 1;
}

// Enfileirar (enqueue)
void enfileirar(Fila *f, int posicao) {
    if (Cheia(f)) {
        printf("Erro: Fila está cheia.\n");
        return;
    }
    f->valores[++(f->fim)];
    return;
}

int desenfileirar (Fila *f) {
    if (Vazia(f)) {
        printf("Erro: Fila está vazia.\n");
        return -1;
    }
    return f->valores[(f->ini)--];

}
    
// Exibindo os valores da fila

void Exibir(Fila *f) {
    if (Vazia(f)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->ini; i <= f->fim; i ++) {
    printf("%d", f->valores[i]);
    }
    printf("\n");
}


int main() {
    Fila f;
    f.ini = 0;
    f.fim = 0;
    enfileirar(&f, 10); // Chamando a funcão
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    
    Exibir(&f);

    printf("Desenfileirado: %d\n", desenfileirar(&f));
    
    Exibir(&f); // Note que o espaço '10' agora está "perdido"

    return 0;
}