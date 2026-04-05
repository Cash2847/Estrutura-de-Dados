/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*3. Crie um programa que leia dois números inteiros e mostre a soma deles.*/

#include <stdio.h>

int main() {
    int num1, num2, soma;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    soma = num1 + num2;

    printf("A soma é: %d\n", num1, num2, soma);

    return 0;
}




