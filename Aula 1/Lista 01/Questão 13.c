/*13. Escreva um programa que leia um vetor de 10 posições e mostre seus valores.*/

#include <stdio.h>

int main() {
    int vetor[10]; 
    int i;


    for(i = 0; i < 10; i++) {
        printf("Digite o valor para a posição [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nOs valores armazenados no vetor são:\n");

    for(i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    return 0;
}

