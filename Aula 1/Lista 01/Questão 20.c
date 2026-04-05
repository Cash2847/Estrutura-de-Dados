/*20. Crie um programa que leia uma matriz 2x2 e calcule a soma de todos os valores.*/

#include <stdio.h>

int main() {
    int matriz[2][2];
    int i, j, soma = 0;


    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            soma += matriz[i][j];
        }
    }

    printf("\nA soma de todos os elementos da matriz é: %d\n", soma);

    return 0;