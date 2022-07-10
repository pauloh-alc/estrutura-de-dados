// Versão Recursiva:
// Discente: Paulo Henrique Diniz de Lima Alencar
// Matrícula: 494837
#include <stdio.h>
#include <stdlib.h>

// Definição da Estrutura do tipo No:
typedef struct no {
    int chave;
    struct no* esq;
    struct no* dir;
    struct no* pai;
} No;

No* raiz = NULL;

// Exibe erros:
void Error(char *msg) {
    printf("Erro: %s\n",msg);
}

// Função: realiza uma busca na ABB  
No* buscar_em_arvore (int valor, No* ptr) {
    if (ptr == NULL) {
        return NULL;
    } 
    else if (valor == ptr -> chave) {
        return ptr;
    } 
    else if (valor < ptr -> chave) { 
        if (ptr -> esq != NULL)
            return buscar_em_arvore (valor, ptr -> esq);
        else
            return ptr;
    }
    else {
        if (ptr -> dir != NULL) 
            return buscar_em_arvore (valor, ptr -> dir);
        else
            return ptr;
    }
}


// Procedimento: reponsável por add um elemento, caso ele não exista na ABB.
void adicionar (int valor) {
    No* no_recebido = buscar_em_arvore (valor, raiz);
    
    if (no_recebido == NULL || no_recebido -> chave != valor) {
        No* novo = (No*) malloc (sizeof(No));
        novo -> chave = valor;
        novo -> esq = NULL;
        novo -> dir = NULL;
        novo -> pai = no_recebido;

        if (no_recebido == NULL) raiz = novo;
        else {
            if (valor < no_recebido -> chave) no_recebido -> esq = novo;
            else                              no_recebido -> dir = novo;
        }
    }
    else {
        Error("elemento já existe na Árvore binária de busca");
    }
}

// Função: responsável por remover determinado elemento da ABB:
No* remover_em_arvore (No* aux, int valor) {
    No* no = buscar_em_arvore(valor, aux);
    
    // Caso o elemento buscado NÃO exista ou ABB vazia.
    if (no == NULL || no -> chave != valor) return NULL;
    
    No* lixo = (No*) malloc (sizeof(No));

    // 1° CASO: O elemento que quero Remover é uma FOLHA. 
    if (no -> esq == NULL && no -> dir == NULL) { 
        if (no -> chave < no -> pai -> chave) no -> pai -> esq = NULL;
        else                                  no -> pai -> dir = NULL;
    }
    // 2° CASO: o elemento que quero remover não é folha e possui somente um FILHO [na esquerda].
    else if (no -> esq != NULL && no -> dir == NULL) {
        if (no -> chave < no -> pai -> chave) {
            no -> pai -> esq = no -> esq;
        }
        else {
            no -> pai -> dir = no -> esq;
        }    
        no -> esq -> pai = no -> pai;
    }
    // 2° CASO AINDA: o elemento que quero remover não é folha e possui somente um FILHO [na direita].
    else if (no -> esq == NULL && no -> dir != NULL) {
        if (no -> chave < no -> pai -> chave) {
            no -> pai -> esq = no -> dir;
        }
        else {
            no -> pai -> dir = no -> dir;
        }
        no -> dir -> pai = no -> pai;
    }
    // 3° CASO: o elemento que quero remover tem 2 FILHOS.
    else {
        // Utilizando algorítimo --> Menor dos maiores, mas poderia ter utilizado o Menor dos maiores
        No* m = no -> dir;
        while (m -> esq != NULL) {
            m = m -> esq;
        }
         
        // Realizar cópia dos dados 
        lixo -> chave = no -> chave;
        // Substituição dos valores:  
        no -> chave = m -> chave;
        
        return remover_em_arvore(m, m -> chave); // Chamada recursiva !!
    }

    lixo -> chave = no -> chave;
    free(no);
    return lixo;     
}

No* remover (int valor) {    
    No* removido = remover_em_arvore(raiz, valor);
 
    if (removido == NULL) {
       Error("Chave que você deseja remover não existe na Árvore !!");
       return NULL;
    }
    else {
        return removido;
    }
}

// Busca determinado elemento:
No* buscar (int valor) {
    No* no_recebido = buscar_em_arvore (valor, raiz);

    if (no_recebido == NULL) return NULL;
    else if (no_recebido -> chave != valor) return NULL;
    else return no_recebido;
}


// Procedimento: responsável por imprimir os elementos da minha Árvore Binária de busca.
void in_ordem (No* aux) {
    if (aux -> esq != NULL)
        in_ordem (aux -> esq);

    printf("%d ",aux -> chave);
    
    if (aux -> dir != NULL)
        in_ordem (aux -> dir);    
}


// Função: principal
int main (void) {
    // ÁRVORES BINÁRIAS DE BUSCA PARA TESTE:

    /* 
    adicionar (12);
    adicionar (9);
    adicionar (8);
    adicionar (15);
    adicionar (20);
    adicionar (10);
    adicionar (2);
    adicionar(11);
    */

    /*
    adicionar (21);
    adicionar (14);
    adicionar (13);
    adicionar (19);
    adicionar (22);
    adicionar (23);
    adicionar (18);
    adicionar (20);
    adicionar (12);
    */
    
    
    adicionar (15);
    adicionar (10);
    adicionar (12);
    adicionar (6);
    adicionar (5);
    adicionar (9);
    adicionar (8);
    adicionar (20);
    adicionar (25);
    adicionar (18);
    adicionar (16);
    adicionar (19);
    adicionar (17);
    adicionar (30);
    adicionar (27);
    
    
    // Árvore completa:..................
    printf("Árvore binária de busca completa:\n");
    in_ordem(raiz);
    printf("\n");
    //...................................
    
    // Buscar:...................................................................
    No* no_recebido = buscar (9);
    
    if (no_recebido != NULL) {
        printf("\nElemento buscado foi encontrado: %d\n", no_recebido -> chave);
    }
    else {                     
        Error("Elemento buscado NÃO foi encontrado !!");
    }
    //...........................................................................
    
    // Remover:..................................................................
    remover(15); // Elemento que quero remover é raiz e possui 2 FILHOS.
    remover(22); // Elemento que quero remover NÃO EXISTE.
    remover(18); // Elemento que quero remover possui 2 filhos.
    remover(5) ; // Elemento que quero remover é uma folha.
    remover(25); // Elemento que quero remover possui somente um filho [na esquerda]
    remover(9);  // Elemento que quero remover possui somente um filho [na direita ]

    printf("\nÁrvore após a remoção dos elementos:\n");
    in_ordem(raiz);
    printf("\n");
    //...........................................................................
        return 0;
}
