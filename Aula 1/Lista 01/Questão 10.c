/*10. Faça um programa que leia um número e calcule seu fatorial (usando for).*/

#include <stdio.h>

int main() {
    int n, i;
    long long fatorial = 1;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Não existe fatorial de número negativo.\n");
    } else {
        for(i = 1; i <= n; i++) {
            fatorial *= i;
        }

        printf("O fatorial de %d é: %lld\n", n, fatorial);
    }

    return 0;
}

