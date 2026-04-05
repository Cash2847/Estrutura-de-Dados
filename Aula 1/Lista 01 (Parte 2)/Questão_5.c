/*5. Faça um programa que conte quantos números pares existem em um vetor em C.*/
#include <stdio.h>

int main() {
    int vetor[5];
    int pares = 0;


    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    printf("\nO vetor possui %d número(s) pare(s).\n", pares);

    return 0;
}


