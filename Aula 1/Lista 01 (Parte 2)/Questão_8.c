/*8. Desenvolva um programa que calcule a soma dos elementos de uma matriz em C.*/
#include <stdio.h>

int main() {
    int matriz[2][2];
    int soma = 0;


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            soma += matriz[i][j];
        }
    }

    printf("\nA soma de todos os elementos da matriz é: %d\n", soma);

    return 0;
}


