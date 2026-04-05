/*19. Escreva um programa que leia uma matriz 2x2 e mostre seus elementos.*/

#include <stdio.h>

int main() {
    int matriz[2][2];
    int i, j;


    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nElementos da matriz 2x2:\n");
    
  
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n"); 
    }

    return 0;
}

