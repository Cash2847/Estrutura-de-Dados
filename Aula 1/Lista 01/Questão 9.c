/*9. Desenvolva um programa que leia um número inteiro e mostre os números de 1 até ele.*/

#include <stdio.h>

int main() {
    int limite, i;

    printf("Digite um número inteiro: ");
    scanf("%d", &limite);

    printf("Contagem de 1 até %d:\n", limite);
    
    for(i = 1; i <= limite; i++) {
        printf("%d ", i);
    }

    printf("\n");
    return 0;
}


