/*11. Crie um programa que leia 5 números inteiros e mostre a soma deles.*/

#include <stdio.h>

int main() {
    int numero, i, soma = 0;

    for(i = 1; i <= 5; i++) {
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);
        
        soma += numero; 
    }

    printf("\nA soma total dos 5 números é: %d\n", soma);

    return 0;
}

