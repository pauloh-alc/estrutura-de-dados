#include <stdio.h>
#include <stdlib.h>
#define TAM 100

// Procedimento: responsável por exibir erros.
void erros (char* mensagem)
{
    fprintf(stderr,"Erro: %s !!\n",mensagem);
    exit(1);
}

// Procedimento: reponsável por adicionar algum elemento dada uma posição, em uma lista feita com vetor.
void adicionar (int* vetor, int posicao, int elemento, int* tamanho) 
{
    if (posicao >= 0 && posicao <= *tamanho) {
        int i;
        for (i = *tamanho; i > posicao; i--) {
            vetor[i] = vetor[i-1];
        }
        vetor[posicao] = elemento;
    *tamanho += 1;
    }
    else {
      erros ("posicao informada invalida");
    }
}

// Procedimento: exibe lista de elementos [0, tamanho - 1].
void exibe (int* vetor, int tamanho)
{   
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%d ",*(vetor + i));
    }
    printf("\n");
}

// Função: responsável por remover um elemento dada uma posição.
int remover (int* vetor, int posicao, int* tamanho)
{   
    int removido = vetor[posicao];

    if (posicao >= 0 && posicao < *tamanho) {
       int i;
       for (i = posicao; i < *tamanho - 1; i++) {
          vetor[i] = vetor[i+1];
       }
    *tamanho -= 1; 
    }
    else {
      erros ("posicao informada invalida");
    }
    
    return removido;
}

// Função: responsável por buscar um elemento na lista
int buscar (int* vetor, int elemento, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++) {
        if (*(vetor + i) == elemento) {
            return i;
        }
    }
    printf("Elemento %d não encontrado\n", elemento);
    return -1;
}

// Procedimento: responsável por ordenar um vetor
void ordenar_vetor (int* vetor_o, int tamanho)
{
    int i, j, pos_menor, menor;

    for (i = 0; i < tamanho - 1; i++) {
        menor = vetor_o[i];
        pos_menor = i;  
        for (j = i; j < tamanho; j++) {
            if (vetor_o[j] < menor) {
                menor = vetor_o[j];
                pos_menor = j;
            }        
        }
        vetor_o[pos_menor] = vetor_o[i];
        vetor_o[i] = menor;
    }
    
    // Exibindo vetor ordenado
    printf("vetor ordenado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ",vetor_o[i]);
    }
    printf("\n");
}

// Função: principal
int main (void) {
    
    // Dicionário de dados:  
    int vetor[TAM];
    int tamanho = 0;
  
    // adicionando
    adicionar (vetor, 0, 100, &tamanho);
    adicionar (vetor, 1, 5, &tamanho);
    adicionar (vetor, 0, 2, &tamanho);
    adicionar (vetor, 3, 7, &tamanho);
    // exibindo
    exibe (vetor, tamanho);
    // removendo
    int elemento_removido = remover (vetor, 3, &tamanho);
    printf("Elemento removido foi: %d \n", elemento_removido);
    // exibindo depois da remoção
    exibe (vetor, tamanho);
  
    // buscando elemento com vetor desordenado
    int posicao = buscar (vetor, 7, tamanho);
    if (posicao != -1) printf("posicao = %d \n", posicao);
  
    // ordenando um vetor
    ordenar_vetor (vetor, tamanho);
  
 return 0;
}
