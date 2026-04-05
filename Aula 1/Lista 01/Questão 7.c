/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*7. Crie um programa que leia o nome e a idade de uma pessoa e mostre esses dados.*/

#include <stdio.h>

int main() {
    char nome[50];
    int idade;

    printf("Digite o seu nome: ");
    
    fgets(nome, sizeof(nome), stdin);

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    printf("\nNome: %s", nome);
    printf("Idade: %d anos\n", idade);

    return 0;
}
