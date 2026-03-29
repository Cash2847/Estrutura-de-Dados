#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *itens;
    int topo;
    int capacidade;
} Pilha;


int Vazia(Pilha *p) {
    return p->topo == -1;
}


int Cheia(Pilha *p) {
    return p->topo == p->capacidade - 1;
}


void empilhar(Pilha *p, int valor) {
    if (Cheia(p)) {
        printf("Erro: Pilha cheia!\n");
    } else {
        p->itens[++(p->topo)] = valor;
    }
}


int desempilhar(Pilha *p) {
    if (Vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[(p->topo)--];
}


void exibirPilha(Pilha *p) {
    if (Vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Conteúdo da Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    int tamanho, valor;
    Pilha p;

    printf("Defina o tamanho maximo da pilha: ");
    scanf("%d", &tamanho);


    p.capacidade = tamanho;
    p.topo = -1;
    p.itens = (int *)malloc(tamanho * sizeof(int));


    printf("Insira %d elementos:\n", tamanho - 1);
    for (int i = 0; i < tamanho - 1; i++) {
        scanf("%d", &valor);
        empilhar(&p, valor);
    }


    exibirPilha(&p);
    printf("A pilha esta vazia? %s\n", Vazia(&p) ? "Sim" : "Nao");
    printf("A pilha esta cheia? %s\n", Cheia(&p) ? "Sim" : "Nao");


    printf("\nInserindo elemento 10.\n");
    empilhar(&p, 10);
    exibirPilha(&p);
    printf("A pilha esta cheia agora? %s\n", Cheia(&p) ? "Sim" : "Nao");
    
    printf("\nRemovendo o elemento do topo (%d)...\n", desempilhar(&p));
    exibirPilha(&p);

    free(p.itens);
    return 0;
}

