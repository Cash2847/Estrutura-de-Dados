#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    int *vetor;

    printf("Entre com o tamanho do vetor; ");
    scanf("%d", &n);
    
    //alocando as posições de memória n*32bits
    vetor = (int*)malloc(n*sizeof(int));
    
    //boa prática - sempre verificar
    if(vetor == NULL){
        return 1;
    }
    for(i = 0; i < n; i ++){
        vetor[i] = i * 20;
        printf("Posição %d: %d, i, vetor[i]");
    }
    free(vetor);

    return 0;
}