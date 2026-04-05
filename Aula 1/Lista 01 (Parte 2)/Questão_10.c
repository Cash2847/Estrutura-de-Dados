/*10. Faça um programa que leia os dados de uma struct e mostre na tela em C.*/

#include <stdio.h>


struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno a;


    printf("Nome do aluno: ");
    scanf(" %[^\n]s", a.nome);

    printf("Idade: ");
    scanf("%d", &a.idade);

    printf("Nota: ");
    scanf("%f", &a.nota);

    printf("\nRelatório do Aluno\n");
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d anos\n", a.idade);
    printf("Nota: %.2f\n", a.nota);

    return 0;
}