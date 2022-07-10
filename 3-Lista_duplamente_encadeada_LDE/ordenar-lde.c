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

void ordenar ()
{
    No *i, *j, *menor;
    
    int cont = 0;
    int menor_valor;

    i = inicio;
    while (i != NULL) {
        
        menor_valor = i -> valor;
        
        for (j = i; j != NULL; j = j -> prox) {
            if (j -> valor <= menor_valor) {
                menor = j;                 
                menor_valor = j -> valor; 
            }
        }
        
        if (menor == i) {  
            i = i -> prox;
        }
        else if (cont == 0) {    
            if (menor == fim) {  
                fim = fim -> ant;
                fim -> prox = NULL;
            } else {             
                menor -> ant -> prox = menor -> prox;
                menor -> prox -> ant = menor -> ant;
            }
            menor -> prox = inicio;
            inicio -> ant = menor;
            inicio = menor;
            inicio -> ant = NULL;
        }
        else {                       
            if (menor == fim) {  
                fim = fim -> ant;
                fim -> prox = NULL;
            }
            else { 
                menor -> ant -> prox = menor -> prox;
                menor -> prox -> ant = menor -> ant;
            }     
            menor -> prox = i;
            menor -> ant = i -> ant;
            i -> ant -> prox = menor;
            i -> ant = menor;
        }
        cont++;  
     }
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

int main (void) {
    
    adicionar (2, 0);
    adicionar (5, 1); 
    adicionar (-3, 2);
    adicionar (4, 3);
    adicionar (5, 4);
    adicionar (1, 5);
    imprimir ();
    ordenar ();
    imprimir ();
    
    /*
    adicionar (4, 0);
    adicionar (3, 1); 
    adicionar (2, 2);
    adicionar (2, 3);
    adicionar (1, 4);
    imprimir ();

    ordenar ();
    imprimir ();
    */
    return 0;
}



