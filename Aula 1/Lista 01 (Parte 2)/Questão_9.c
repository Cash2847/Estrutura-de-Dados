/*9. Crie um programa que utilize uma struct para armazenar nome e idade de uma pessoa em C.*/
#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p;


    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin); 
    
    printf("Digite a idade: ");
    scanf("%d", &p.idade);


    printf("\nDados cadastrados:\n");
    printf("Nome: %s", p.nome);
    printf("Idade: %d anos\n", p.idade);

    return 0;
}


