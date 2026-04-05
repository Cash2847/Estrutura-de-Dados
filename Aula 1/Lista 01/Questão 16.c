/*16. Desenvolva um programa que utilize uma função para calcular o quadrado de um
número.*/

#include <stdio.h>

float calcularQuadrado(float n) {
    return n * n;
}

int main() {
    float numero, resultado;

    printf("Digite um número: ");
    scanf("%f", &numero);


    resultado = calcularQuadrado(numero);

    printf("O quadrado de %.2f é: %.2f\n", numero, resultado);

    return 0;
}

