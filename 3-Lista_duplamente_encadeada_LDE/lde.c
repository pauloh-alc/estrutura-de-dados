#include <stdio.h>
#include "lde_funcoes.h"

int main (void) {
    adicionar (20, 0);
    adicionar (10, 0);
    adicionar (30, 2);
    adicionar (5,  1);
    
    imprimir ();
    int removido = remover (3);
    imprimir ();
    printf("removido--> %d \n", removido);
    imprimir ();
    
    //imprimir_reverso ();
    return 0;
}
