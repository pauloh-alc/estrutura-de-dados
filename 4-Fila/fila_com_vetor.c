// FILA: usando vetor.
#include <stdio.h>
#define MAX 30

int fila[MAX];
int tam = 0;

void adicionar (int valor) 
{
    if (tam == MAX) {
        printf("Fila cheia !!\n");
    }
    else {
        fila[tam] = valor;
        tam++;
    }    
}

int remover () 
{
    if (tam == 0) {
        printf("Fila está vazia !!\n");
        return -1;
    }
    else {
        int removido = fila[0];
        for (int i = 0; i < tam - 1; i++) {
            fila[i] = fila[i+1];
        }
        tam--;
        return removido;
    }
}

void visualizar ()
{
    for (int i = 0; i < tam; i++) {
        printf("%d ",fila[i]);
    }
    printf("\n");
}

int main (void) {
    adicionar (2);
    adicionar (3);
    adicionar (5);
    adicionar (7);
   
    remover ();
     
    visualizar ();

    return 0;
}
