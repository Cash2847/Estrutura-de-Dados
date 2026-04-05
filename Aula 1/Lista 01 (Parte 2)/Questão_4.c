/*4. Crie um programa que encontre o maior valor em um vetor de 5 posições em C.*/
#include <stdio.h>

int main() {
    int vetor[5];
    int maior;


    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }


    maior = vetor[0];


    for (int i = 1; i < 5; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    printf("\nO maior valor encontrado foi: %d\n", maior);

    return 0;
}


