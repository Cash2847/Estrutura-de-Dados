/*12. Faça um programa que leia 5 números e informe qual é o maior.*/

#include <stdio.h>

int main() {
    int numero, i, maior;

    for(i = 1; i <= 5; i++) {
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);

        if (i == 1) {
            maior = numero;
        } else {
 
            if (numero > maior) {
                maior = numero;
            }
        }
    }

    printf("\nO maior número e: %d\n", maior);

    return 0;
}

