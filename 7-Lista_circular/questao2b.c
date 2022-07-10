// Discente: Paulo Henrique Diniz de Lima Alencar.
// Matrícula 494837
// OBS: as justificativas encontram-se no PDF.


// Resolução da questão 2 item (b)

// Incluindo bibliotecas em meu header (cabeçalho)
#include <stdlib.h>
#include <stdio.h>
#include "No.h"


// Variáveis GLOBAIS
NO *inicio;
int tam = 0;


// Procedimento: resposável por adicionar cangurus em uma lista duplamente encadeada circular.
void add (int id, int sexo, int num_filhotes) {
    NO *novo = malloc (sizeof(NO));
    novo -> id = id;
    novo -> sexo = sexo;
    novo -> num_filhotes = num_filhotes;

    if (tam == 0) {
        novo -> prox = novo;
        novo -> ant =  novo;
        inicio = novo;
    }
    else {
        NO* aux;
        if (tam == 1) { 
            inicio -> prox = novo;
            aux = novo;
            novo -> ant = inicio;
            novo -> prox = inicio;
            inicio -> ant = novo;
        }
        else {
            aux -> prox = novo;
            novo -> ant = aux;
            novo -> prox =  inicio;
            inicio -> ant = novo;
            aux = novo;
        }
    }
    tam++;
}


// Procedimento: responsável por remover um canguro, dado um Id.
void remover (int id) {
    NO* lixo;
    if (tam == 1 && inicio -> id == id ) { // ...... Remover Nó, em lista que só possui um único nó. O(1) - constante
        lixo = inicio;
        inicio = NULL;
        free(lixo);
        tam -= 1;
    }
    else if (tam > 1 && inicio -> id == id) { // ... Remover primeiro Nó, isto é, nó que representa início
                                              // ... do ciclo da LDE circular. O(1) - constante
        lixo = inicio;
        inicio = inicio -> prox;
        inicio -> ant = lixo -> ant;
        lixo -> ant -> prox = inicio;
        free(lixo);
        tam -= 1; 
    }
    else if (tam > 1 && inicio -> ant -> id == id) { // ...... Remover último Nó, representa o fim de forma abstrata - O(1) - constante
        lixo = inicio -> ant;
        lixo -> ant -> prox = inicio;
        inicio -> ant = lixo -> ant;
        free(lixo);
        tam -= 1;
    }
    else { // ...................................... Remover Nó que está no "meio". O(n) - Linear.
        NO* aux = inicio;
        do {
            if (aux -> id == id) {
                lixo = aux;
                aux -> ant -> prox =  aux -> prox;
                aux -> prox -> ant = aux -> ant;
                free(lixo);
                tam -= 1;
                break;
            }
            aux = aux -> prox;
        } while (aux != inicio);
    } 
} 



// Função: implementação da função soma, reponsável por realizar a soma dos filhores dos cangurus fêmeas. 
int soma () {
     NO* i = inicio;
     
     int soma = 0;
     do {
        if (i -> sexo == 1) { 
            soma = soma + i -> num_filhotes;
        }
        i = i -> prox;
     } while (i != inicio); 
     
     return soma;
}


// Procedimento: criado somente para verificar se minha LDE circular estava correta.
void visualizar () {
    NO* i = inicio;

    printf("Testando ciclos: \n");

    for (int j = 0; j < 20; j++) {
        printf("%d ", i -> id);// ...... Estou printando somente o 'id'.
        i = i -> prox;
    }
    printf("\n");
}


// Função: principal
void main () {

    add (1,1,2);
    add (2,1,1);
    add (3,0,0);
    add (4,1,2);
    add (5,0,0);
    
    visualizar (); 
    
    remover (5);
    
    visualizar ();

    int retorno = soma ();
    printf("Soma dos filhotes gerados por canguru fêmea é: %d \n", retorno);
}
