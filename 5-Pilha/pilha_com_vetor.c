// Pilha: utilizando vetor.
#include <stdio.h>
#define MAX 30 

int pilha[MAX];
int tam = 0;

void adicionar (int valor)
{    
    if (tam == MAX) {
        printf("A Pilha está cheia !!\n");
    } 
    else {
        pilha[tam] = valor;
        tam++; 
    }
}

int remover () 
{
    if (tam == 0) { 
        printf("A lista está vazia !!\n");
        return -1;
    }
    else {
        int removido = pilha[tam - 1];
        tam--;
        return removido;
    } 
}

void visualizar () 
{
    for (int i = tam - 1; i >= 0; i--) {
        printf("%d\n",pilha[i]);
    }
}

int main (void) {
    
    adicionar (2);
    adicionar (3);
    adicionar (5);
    adicionar (7);
    adicionar (11);
    int retorno = remover (); 
    printf("elemento removido = %d\n",retorno);   
    visualizar ();

    return 0;
}
