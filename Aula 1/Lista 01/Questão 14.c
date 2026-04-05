/*14. Crie um programa que leia um vetor de 5 números e calcule a média.*/

#include <stdio.h>

int main() {
    float vetor[5], soma = 0, media;
    int i;


    for(i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }


    media = soma / 5;

    printf("\nA soma total é: %.2f", soma);
    printf("\nA média dos 5 números é: %.2f\n", media);

    return 0;
}


}