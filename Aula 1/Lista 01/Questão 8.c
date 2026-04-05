
/*8. Faça um programa que leia um número inteiro e mostre sua tabuada de 1 a 10.*/

#include <stdio.h>

int main() {
    int numero, i;

    printf("Digite um numero inteiro para ver a tabuada: ");
    scanf("%d", &numero);

    printf("\nTabuada de %d:\n", numero);
    for(i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}

