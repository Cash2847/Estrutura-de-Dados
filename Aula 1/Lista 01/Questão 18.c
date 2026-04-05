/*18. Faça um programa que leia um número inteiro e calcule a soma dos números pares até
ele.*/

#include <stdio.h>

int main() {
    int limite, i, soma = 0;

    printf("Digite um número inteiro: ");
    scanf("%d", &limite);

    for(i = 1; i <= limite; i++) {
        
        if (i % 2 == 0) {
            soma += i;
        }
    }

    printf("A soma dos números pares de 1 até %d é: %d\n", limite, soma);

    return 0;
}


