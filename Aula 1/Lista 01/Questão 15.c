/*15. Faça um programa que leia um número e utilize uma função para verificar se ele é par.*/

#include <stdio.h>

int Par(int n) {
    if (n % 2 == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if (ehPar(numero)) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }

    return 0;
}


