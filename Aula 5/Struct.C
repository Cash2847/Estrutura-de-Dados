#include <stdio.h>

struct Pessoa{
    char nome[20];
    int idade;
    float altura;

};


int main(){
    struct Pessoa pessoa1;
    strcpy(pessoa1.nome = "Jack");
    pessoa1.idade = 36;
    pessoa1.altura = 1.76;

    //Acesso normal a uma Struct
    printf("Idade do Jack: %d",pessoa1.idade);

    //Ponteiro para Struct
    struct Pessoa *ptr = &pessoa1;

    //Maneira fácil de acessar Struct com ponteiro
    printf("Altura do Jack é: %f", ptr->altura);

    //Maneira difícil de acessar Struct com ponteiro
    printf("A idade do Jack é: %d", (*ptr).idade);

    return 0;
}