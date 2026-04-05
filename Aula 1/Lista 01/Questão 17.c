/*17. Crie um programa que leia dois números e utilize uma função para retornar o maior.*/

#include <stdio.h>

float encontrarMaior(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    float n1, n2, maior;

    printf("Digite o primeiro número: ");
    scanf("%f", &n1);

    printf("Digite o segundo número: ");
    scanf("%f", &n2);


    maior = encontrarMaior(n1, n2);

    printf("O maior número entre %.2f e %.2f é: %.2f\n", n1, n2, maior);

    return 0;
}

