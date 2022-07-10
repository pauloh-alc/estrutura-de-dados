// Autor: Paulo Henrique Diniz de Lima Alencar
// Código: adiciona, remove, lista, busca e ordena elementos em uma lista encadeada.
#include <stdio.h>
#include <stdlib.h>


// Estrutura do tipo No: 
// valores: valor e
// mecanismo para unir os Nos: prox
typedef struct no{
    int valor;
    struct no *prox;
}No;


// Variáveis GLOBAIS
No* inicio = NULL;
No* fim    = NULL;
int tamanho = 0;


// Procedimento: responsável por exibir mensagens de erros.
void erros (char* mensagem)
{
    fprintf(stderr,"Erro: %s !!\n",mensagem);
    exit(1);
}


// Procedimento: responsável por adicionar elemento em minha lista dada uma posição.
void adicionar (int valor, int posicao)
{
    if (posicao >= 0 && posicao <= tamanho) {
        No* NOVO = (No*) malloc (sizeof(No));
        if (NOVO == NULL) {
            erros ("malloc não conseguiu alocar bytes na memória");
        }
        NOVO -> valor = valor;
        NOVO -> prox = NULL;

        if (inicio == NULL) {                   // Lista "vazia" - O(1) Constante
            inicio = NOVO;
            fim    = NOVO;
        }
        else if (posicao == 0) {                // Lista não está "vazia", porém quero add na posição 0 - O(1) Constante
            NOVO -> prox = inicio;
            inicio = NOVO;
        }
        else if (posicao == tamanho) {          // Quero add no final da lista, sem percorrer cada nó - O(1) Constante
            fim -> prox = NOVO;
            fim = NOVO;
        }
        else {
            int i;
            No* aux = inicio;
            for (i = 0; i < posicao - 1; i++) { // Quero adicionar no "meio" - O(n) Linear
                aux = aux -> prox;
            }
            NOVO -> prox = aux -> prox;
            aux -> prox = NOVO;
        }
    tamanho += 1;
    }
    else {
        erros ("posição informada inválida");
    }
}


// Função: responsável por remover elemento da minha lista dada uma posição.
int remover (int posicao)
{   
    No* lixo;
    int removido;

    if (posicao >= 0 && posicao < tamanho) {
       
        if (posicao == 0) {                       // Removendo No na posição 0, isto é, no início - O(1) Constante
            lixo = inicio;
            inicio = inicio -> prox;
        }
        else {
            int i;
            No* aux = inicio;
            for (i = 0; i < posicao - 1; i++) {  // Removendo no "meio-fim" - O(n) Linear
                aux = aux -> prox;
            }
            lixo = aux -> prox;
            aux -> prox = aux -> prox -> prox;
        }
        removido = lixo -> valor;
        free (lixo);
    tamanho -= 1;
    }
    else {
        erros ("posição informada inválida");
    }
    
    return removido;
}


// Procedimento: responsável por buscar um elemento da lista, dado um certo elemento.  O(n) Linear, pois a lista encadeada está desordenada
void buscar (int valor_buscado)
{   
    No* i;
    int sinalizador = 0;
    for (i = inicio; i != NULL; i = i -> prox) { 
        if (valor_buscado == i -> valor) {
            printf("Elemento encontrado: %d | Endereço: %p \n", i -> valor, &(i -> valor)); 
            sinalizador = 1;
            break;
        }
    }

    if (sinalizador != 1) printf("Elemento %d não foi encontrado na lista encadeada !! \n", valor_buscado);
}


// Procedimento: responsável por ordenar a lista encadeada de forma crescente.
void ordenar_lista () 
{   
    No *i, *j, *endereco_do_menor;
    int menor_valor;
    for (i = inicio; i != NULL; i = i -> prox) {
        
        menor_valor = i -> valor;
        endereco_do_menor = i;
        
        for (j = i; j != NULL; j = j -> prox) {
            if (j -> valor < menor_valor) {
                menor_valor = j -> valor;
                endereco_do_menor = j;
            }
        }
        
        endereco_do_menor -> valor = i -> valor;
        i -> valor = menor_valor;
    }
}


// Procedimento: responsável por exibir lista encadeada.
void exibir_lista () 
{   
    No* i;
    for (i = inicio; i != NULL; i = i -> prox) {
        printf("%d ",i -> valor);
    }
    printf("\n");
}


// Função: principal.
int main (void) {
    // adicionando elementos:    
    adicionar (10, 0);
    adicionar (2 , 1);
    adicionar (0 , 1);
    adicionar (-1, 3);
    adicionar (3 , 4);
    adicionar (5 , 5);
    adicionar (4 , 5);
    
    // Exibindo lista:
    exibir_lista (); 
    
    // Removendo elemento e mostrando elemento removido:
    int removido = remover (2);
    printf("Elemento removido: %d \n", removido);
    
    // Exibindo lista:
    exibir_lista ();
    
    // Buscar valor:
    int valor;
    printf("Entre com o elemento que você deseja buscar: ");
    scanf("%d",&valor);
    buscar (valor);
    
    // Ordenando lista:
    ordenar_lista ();
    printf("Lista ordenada: ");

    // Exibindo lista ordenada:
    exibir_lista ();

    return 0;
}

