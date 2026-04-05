/*2. Faça um programa que leia 5 números em um vetor e mostre-os na tela em C.*/
#include <stdio.h>

int main() {
    int vetor[5];


    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }


    printf("\nNúmeros digitados: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}


