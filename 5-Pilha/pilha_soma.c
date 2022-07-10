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

void visualizar_reverso (No* aux)
{   
    if (aux != NULL) {
        visualizar_reverso (aux -> prox);
        printf("%d\n",aux -> valor);
    }
}


int soma (No* aux)
{  
    /* 
    if (aux != NULL) {
        return soma (aux -> prox) + aux -> valor;
    }
    else {
        return 0;
    }
    */

    if (aux == NULL) return 0;
    return soma (aux -> prox) + aux -> valor;

}

int main (void) {
    adicionar (1);
    adicionar (2);
    adicionar (3);
    adicionar (4);
    visualizar_reverso (topo);
    printf("%d\n",soma (topo));


    remover ();
    printf("\n");
    visualizar_reverso (topo);
    
    printf("%d\n",soma (topo));
    return 0;
}
