// Autor: Paulo Henrique Diniz de Lima Alencar
// Código: análise prática do melhor caso, caso médio e pior caso na análise das partes de um algorítmo.
#include <stdio.h>

int main (void) {
    int vetor [] = {4, 6, 7, 5, 2, 0, 3, 1};
    int i;

    // Melhor caso: encontrar o 4 na posição [0] - intera 1 item - O(1) constante
    
    for (i = 0; i < 8; i++) {
        if (vetor[i] == 4) {
            printf("%d\n",i);
            break;
        }
    }
    
    // No caso médio: encontrar o 5 na posição [3] - intera 4 itens - O(0,5 n)
    
    for (i = 0; i < 8; i++) {
        if (vetor[i] == 5) {
            printf("%d\n",i);
            break;
        }
    }

    // No pior caso: encontrar o 1 na última posição [7] - intera todos os 'n' itens - O(n) linear
    
    for (i = 0; i < 8; i++) {
        if (vetor[i] == 1) {
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}
