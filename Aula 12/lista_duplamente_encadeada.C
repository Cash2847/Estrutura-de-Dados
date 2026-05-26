# include <stdio.h>
# include <stdlib.h>

// Estrutura do nó da lista duplamente encadeada
struct No {
    int valor;
    struct No* prox;
    struct No* ant;
};

// Ponteiros da lista
struct No* inicio = NULL;
struct No* fim = NULL;

// Inserir um novo nó no início da lista
void inserir(int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    
    if (novo == NULL) {
        printf("Erro de memória.\n");
        return;
    }
    
    novo->valor = valor;
    novo->prox = inicio;
    novo->ant = NULL;

    if (inicio != NULL) {
        inicio->ant = novo;
    } else {
        fim = novo; // Se a lista estava vazia, o novo nó é o fim
    }
    inicio = novo; // O novo nó se torna o início da lista
}

// Inserir no final da lista
void inserirFim(int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    
    if (novo == NULL) {
        printf("Erro de memória.\n");
        return;
    }
    
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = fim;

    if (fim != NULL) {
        fim->prox = novo;
    } else {
        inicio = novo; // Se a lista estava vazia, o novo nó é o início
    }
    fim = novo; // O novo nó se torna o fim da lista
}

// Remover um nó da lista
void remover(int valor) {
    struct No* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox;
            } else {
                inicio = atual->prox; // Se for o primeiro nó
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            } else {
                fim = atual->ant; // Se for o último nó
            }
            free(atual);
            return;
        }
        atual = atual->prox;
    }
    printf("Valor %d não encontrado na lista.\n", valor);
}

// Exibir a lista do início ao fim
void ExibirInicioFim() {
    struct No* atual = inicio;
    printf("Lista (Início -> Fim): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}  

// Exibir a lista do fim ao início
void ExibirFimInicio() {
    struct No* atual = fim;
    printf("Lista (Fim -> Início): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
    printf("\n");
}

// Programa principal para testar a lista duplamente encadeada
int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    ExibirInicioFim();

    inserirFim(40);
    inserirFim(50);
    ExibirInicioFim();

    remover(20);
    ExibirInicioFim();

    remover(10);
    ExibirInicioFim();

    remover(50);
    ExibirInicioFim();
    ExibirFimInicio();

    return 0;
}