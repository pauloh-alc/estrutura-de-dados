#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox; 
    struct no *ant; 
} No;

// Var GLOBAIS:
No* inicio = NULL;
No* fim    = NULL;
int tamanho = 0;

void adicionar (int valor, int posicao)
{
    if (posicao >= 0 && posicao <= tamanho) {
        No* novo = (No*) malloc (sizeof(No));
        novo -> valor = valor;
        novo -> prox = NULL;
        novo -> ant  = NULL;

        if (inicio == NULL) {
            inicio = novo;
            fim    = novo;
        }
        else if (posicao == 0) {
            novo -> prox = inicio;
            inicio -> ant = novo;
            inicio = novo;
        }
        else if (posicao == tamanho) {
            fim -> prox = novo;
            novo -> ant = fim;
            fim = novo;
        }
        else {
            No* aux = inicio;
            int i;
            for (i = 0; i < posicao; i++) {
                aux = aux -> prox;
            }
            
            novo -> ant = aux -> ant;
            aux -> ant -> prox = novo;
            
            novo -> prox = aux;
            aux -> ant = novo;
        }
    tamanho++;
    }
}

// Função: responsável por remover um Nó em uma posição n qualquer, tal que, n > 0 e n < tamanho da lista.
int remover (int n) {   
    
    int removido = -1;
    
    if (n > 0 && n < tamanho) {
        No* lixo;

        if (n == tamanho - 1) { //.... Remover elemento na última posição.
            lixo = fim;
            fim = fim -> ant;
            fim -> prox = NULL;
        } 
        else { //..................... Remover elemento no "meio"
            No* aux = inicio;
            int i;
            for (i = 0; i < n; i++) {
                aux = aux -> prox;
            }
            lixo = aux;
            aux -> prox -> ant = aux -> ant;
            aux -> ant -> prox = aux -> prox;
        }   
        removido = lixo -> valor;
        free(lixo);
    tamanho--;
    }
    else {
        printf("Posição inválida !! \n");
    }
    return removido;
}

void imprimir ()
{   
    No* i = inicio;
    while (i != NULL) {
        printf("%d ", i -> valor);
    i = i -> prox;
    }
    printf("\n");
}

void imprimir_reverso () 
{   
    No* i;
    for (i = fim; i != NULL; i = i -> ant) {
        printf("%d ",i -> valor);
    }
    printf("\n");
}


