/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*4. Desenvolva um programa que leia um número e informe se ele é positivo ou negativo.*/

#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O número %d é positivo.\n", numero);
    } else if (numero < 0) {
        printf("O número %d é negativo.\n", numero);
    } else {
        printf("O número é zero.\n");
    }

    return 0;
}





