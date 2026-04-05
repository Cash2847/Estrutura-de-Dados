/*6. Declare uma matriz 3x3 e inicialize todos os valores com zero em C.*/
#include <stdio.h>

int main() {
    int matriz[3][3] = {0};

    printf("Matriz 3x3 inicializada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}


