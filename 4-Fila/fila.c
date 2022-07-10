// Discente: Paulo Henrique Diniz de Lima Alencar.
// Matrícula: 494837

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* inicio = NULL;
No* fim    = NULL;
int tam = 0;


// Procedimento: responsável por adicionar elementos em minha fila.
void adicionar (int valor) 
{
    No* novo = (No*) malloc (sizeof(No));
    novo -> valor = valor;
    novo -> prox = NULL;
    
    if (inicio == NULL) { //. O(1) - Constante 
        inicio = novo;
    }
    else { // ............... O(1) - Constante
        fim -> prox = novo; 
    } 

    fim = novo;
    tam++;
}

int remover () 
{
    if (inicio != NULL) { // O(1) - Constante
        No* lixo;
        
        lixo = inicio;
        
        if (tam == 1) {
            inicio = NULL;
            fim = NULL;
        }
       
        inicio = inicio -> prox;
        int removido = lixo -> valor;
        free(lixo);
        tam--;
        
        return removido;  
    }
    else {
        printf("Fila vazia !!\n");
        return -1;
    }
}


// Procedimento: responsável por exibir fila
void visualizar () 
{
    No* aux = inicio;

    while (aux != NULL) {
        printf("%d ",aux -> valor);
        aux = aux -> prox;
    }    
    printf("\n");
}


// Função: principal
int main (void) {
    adicionar (1);
    adicionar (2);
    adicionar (3);
    adicionar (4);
    adicionar (5);
    
    remover ();
    remover ();
    
    adicionar (6);
    adicionar (7);
    
    remover ();
    
    adicionar (8);
    adicionar (9);
    adicionar (10);
    
    remover ();
    remover ();
   
    visualizar ();
    
    return 0;
}
