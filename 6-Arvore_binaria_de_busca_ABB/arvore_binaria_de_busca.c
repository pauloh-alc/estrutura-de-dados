// Versão Iterativa da Árvore Binária de Busca:
// Discente: Paulo Henrique Diniz de Lima Alencar.
// Matrícula: 494837.
#include <stdio.h>
#include <stdlib.h>

// Definição da Estrutura do Tipo No:
typedef struct no {
    int chave;
    struct no* esq;
    struct no* dir;
    struct no* pai;
} No;

No* raiz = NULL;

// Procedimento: responsável por exibir os erros.
void Error(char *msg) {
    printf("Erro: %s\n",msg);
}


// Função: recebe um valor e realiza uma busca na ABB. Se árvore estiver vazia, retorna NULL. Se elemento for encontrado, retorna o endereço do Nó que o elemento se encontra.
// Se elemento não for encontrado, retorna o endereço de uma folha, que facilitará em adições futuras.   
No* buscar_em_arvore (int valor, No* ptr) {
    if (ptr == NULL) {
        return NULL; //................. Árvore Vazia.
    }
    else if (valor == ptr -> chave) {
        return ptr; //.................. Encontrei elemento que eu estava buscando.
    }
    else if (valor < ptr -> chave) { //.............. Ainda não encontrei meu elemento, mas se (valor < ptr -> chave) [True], ele pode estar do lado esquerdo.
        if (ptr -> esq != NULL)
            return buscar_em_arvore (valor, ptr -> esq);
        else
            return ptr;
    }
    else { //........................................ Ainda não encontrei meu elemento, mas se (valor > ptr -> chave) [True], ele pode estar do lado direito.
        if (ptr -> dir != NULL) 
            return buscar_em_arvore (valor, ptr -> dir);
        else
            return ptr;
    }
}


// Procedimento: recebe um determinado valor, verifica se ele existe. Se o elemento não existir na Árvore binária de busca, ele será add.
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

// Função: recebe uma valor e realiza a remoção nos seguintes casos:
// 1) CASO -> Se elemento que quero remover é uma FOLHA.
// 2) CASO -> Se elemento que quero remover não é uma folha e possui 1 FILHO [Poderá se um filho na DIREITA ou ESQUERDA]
//            # Elemento possui filho [na esquerda]
//            # Elemento possui filho [na direita ]
// 3) CASO -> Se elemento que quero remover possui 2 FILHOS [na esquerda e na direita]

No* remover (int valor) {
    No* no = buscar_em_arvore(valor, raiz);
    
    if (no == NULL || no -> chave != valor) {
        Error("Chave que você deseja remover não existe na Árvore !!");
        return NULL;
    }
    
    // Nó que vai armazenar os atributos do Nó removido (Criei isso, caso o programador precise acessar algum atributo do nó removido):
    No* lixo = (No*) malloc (sizeof(No));

    // 1° CASO:
    if (no -> esq == NULL && no -> dir == NULL) { // O elemento que quero remover é uma FOLHA. 
        if (no -> chave < no -> pai -> chave) no -> pai -> esq = NULL;
        else                                  no -> pai -> dir = NULL;    
        
        lixo -> chave = no -> chave; // realizando a cópia dos atributos do Nó removido para o Nó lixo.
        free(no);
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
        
        lixo -> chave = no -> chave;
        free(no);
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
        
        lixo -> chave = no -> chave;
        free(no);
    }
    // 3° CASO: o elemento que quero remover tem 2 FILHOS [na esquerda e na direita].
    else {
        // Utilizando algorítimo: Menor dos maiores (1 vez para a direita, depois vou para a esquerda até chegar em NULL)
        No* m = no -> dir;
        while (m -> esq != NULL) {
            m = m -> esq;
        }
        // Realizar cópia dos dados [Passando os elementos do no que vou remover, para um Nó chamado lixo] 
        lixo -> chave = no -> chave;
        
        // Substituição dos valores:  
        no -> chave = m -> chave;
        
        // TRATANDO OS CASOS: 1) se for uma FOLHA, ou 2) se nó (que m está apontando) possui somente UM filho [na direita].
        
        // Obs: no caso 2) só precisamos do caso que o Nó possui o filho [na direita], isso porque estou usando o algoritmo
        // Menor dos maiores [1 vez para direita, depois vou para esquerda até chegar em NULL], logo não tem como esse nó ter um
        // filho na esquerda, pois eu vou no máxima para a esquerda até chegar em NULL.      
        
        // 1)
        if (m -> esq == NULL && m -> dir == NULL) {  
            if (m -> chave < m -> pai -> chave) m -> pai -> esq = NULL;
            else                                m -> pai -> dir = NULL;    
        }
        // 2)
        else if (m -> esq == NULL && m -> dir != NULL) {
            if (m -> chave < m -> pai -> chave) {
                m -> pai -> esq = m -> dir;
            }
            else {
                m -> pai -> dir = m -> dir;
            }
            m -> dir -> pai = m -> pai;
        }
        free(m);
    }
    return lixo;     
}


// Função: realiza a busca de um elemento.
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
    // ÁRVORES BINÁRIAS DE BUSCA PARA TESTAR:

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
    No* no_recebido = buscar (20);
    
    if (no_recebido != NULL) {
        printf("\nElemento buscado foi encontrado: %d\n", no_recebido -> chave);
    }
    else {                     
        Error("Elemento buscado NÃO foi encontrado !!");
    }
    //...........................................................................
    
    // Remover:..................................................................
    
    No* r1 = remover(15); // Elemento que quero remover é raiz e possui 2 FILHOS.
    No* r2 = remover(22); // Elemento que quero remover não existe.
    No* r3 = remover(18); // Elemento que quero remover possui 2 filhos.
    No* r4 = remover(5) ; // Elemento que quero remover é uma folha.
    No* r5 = remover(25); // Elemento que quero remover possui somente um filho [na esquerda]
    No* r6 = remover(9);  // Elemento que quero remover possui somente um filho [na direita ]
  
    printf("\nElementos removidos:\n");
    
    if (r1 != NULL) printf("r1 = %d\n",r1 -> chave);
    if (r2 != NULL) printf("r2 = %d\n",r2 -> chave);
    if (r3 != NULL) printf("r3 = %d\n",r3 -> chave);
    if (r4 != NULL) printf("r4 = %d\n",r4 -> chave);
    if (r5 != NULL) printf("r5 = %d\n",r5 -> chave);
    if (r6 != NULL) printf("r5 = %d\n",r6 -> chave);

    printf("\n");
    printf("Árvore após a remoção dos elementos:\n");
    in_ordem(raiz);
    
    printf("\n");
    //...........................................................................
        return 0;

}
