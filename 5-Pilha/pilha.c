#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

struct no typedef No;

No* topo = NULL;
int tam = 0;

void adicionar (int valor) {
    
    No* novo = (No*) malloc (sizeof(No));
    novo -> valor = valor;
    //novo -> prox = NULL;
  
    novo -> prox = topo;
    topo = novo; 
    tam++;
}

int remover () 
{   

    No* lixo;
    int removido;

    if (topo != NULL) {
        lixo = topo;
        topo = topo -> prox;
        removido = lixo -> valor;
        free(lixo);
        tam--;
        return removido;    
    }
    else {
        printf("Lista vazia !!\n"); 
        return -1;
    }
    
}

void visualizar ()
{   
    No* aux = topo;

    for (int i = 0; i < tam; i++) {
        printf("%d\n", aux -> valor);
        aux = aux -> prox;
    }
}

int main (void) {
    adicionar (1);
    adicionar (2);
    adicionar (3);
    adicionar (4);
    visualizar ();
    remover ();
    printf("\n");
    visualizar ();
    return 0;
}
