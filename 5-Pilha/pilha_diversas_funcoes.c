#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;



int size = 0;

void push (Node **top, int value, int i)
{
    Node* new = (Node*) malloc (sizeof(Node));
    new -> value = value;
    
    if (i == 0) {
        new -> next = top[0];
        top[0] = new;
        size++;
    }
    else {
    
        new -> next = top[1];
        top[1] = new;
        size++;
    }
    
}

int pop (Node **top, int i)
{
    int removed;
    if (i == 0) {
        Node* trash = top[0];
        top[0] = top[0] -> next;
        removed = trash -> value;
        free(trash);
        size--;
        printf("--->%d\n",removed);
    return removed;
    }
    else {
    
        Node* trash = top[1];
        top[1] = top[1] -> next;
        removed = trash -> value;
        free(trash);
        size--;
        printf("-->%d\n",removed);
        return removed;
    }
}

void show (Node* aux)
{
    if (aux != NULL) {
        printf("%d\n",aux -> value);
        show (aux -> next);
    }
}

/*       Pilha:
 *
 *  |  show (NULL) |
 *  |  show (1)    |
 *  |  show (2)    |
 *  |  show (4)    |
 *  |  show (8)    |
 *  |  show (16)   |
 *  |  main()      |
 *
 *
 * */


int my_strlen (char *string)
{   
    int qtd = 0;
    while (*string != '\0') {
        qtd++;
        string += 1;
    }
    return qtd;
}

int my_strcmp (char *string1, char *string2)
{   
    int value;

    while (*string1 != '\0' || *string2 != '\0') {

        if (*string1 == *string2)      value = 0;
        else if (*string1 < *string2)  return -1;
        else                           return  1; 

        string1  += 1;
        string2  += 1;
    }
    
    return value;
}

void undo (Node *stack, Node *stack_trash)
{
    if (stack == NULL) {
        printf("Nothing to undo !!\n");
    }
    else {
        push (&stack_trash, pop(&stack, 0), 1);
    }
}

void redo (Node *stack, Node *stack_trash)
{
    if (stack_trash == NULL) {
        printf("Nothing to redo !!\n");
    }
    else {
        push (&stack, pop(&stack_trash, 1), 0);
    }
}
   


int main (void) {

    
    Node* stack = NULL;
    Node* stack_trash = NULL;
    
    char op[10];
    int value;

    while (1) {
        printf("a - add elemento; ls - listar pilha; undo - desfazer; redo - refazer \n");
        scanf("%s",op);
        
        if (my_strcmp("a",op) == 0) {
            printf(">>>");
            scanf("%d",&value);
            push (&stack, value, 0);
        }
        else if (my_strcmp("ls",op) == 0) {
            show (stack);
            printf("\n");
            show(stack_trash);
        }
        else if (my_strcmp("undo",op) == 0) {
            undo (stack, stack_trash);
        }
        else if (my_strcmp("redo",op) == 0) {
            redo (stack, stack_trash);
        }
        else {
            printf("Invalid option !!\n");
        }
    }
    return 0;
}
