// Discente: Paulo Henrique Diniz de Lima Alencar.
// Matrícula 494837


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
       
        novo -> prox = inicio;
        novo -> ant = inicio -> ant;
        inicio -> ant -> prox = novo; 
        inicio -> ant = novo;
            
    }
    tam++;
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
    
    int retorno = soma ();
    printf("Soma dos filhotes gerados por canguru fêmea é: %d \n", retorno);
}
