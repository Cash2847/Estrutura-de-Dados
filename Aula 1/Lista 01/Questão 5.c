/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*5. Faça um programa que leia um número inteiro e informe se ele é par ou ímpar.*/

#include <stdio.h>

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d é Par.\n", num);
    } else {
        printf("%d é Ímpar.\n", num);
    }

    return 0;
}

