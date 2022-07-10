#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char* value;
    struct node *next;
    struct node *back;
}Node;

Node* head = NULL; // my list is "empty"
Node* tail = NULL;
int size = 0;

/* Show the messages of errors */
void error (char* message)
{
    fprintf(stderr,"Error: %s !!\n", message);
    exit(1);
}

/* To add an item to the end of the list */ 
void append (char* element)
{
    Node* new = (Node*) malloc (sizeof(Node));
    new -> value = element;
    new -> next  = NULL;
    new -> back  = NULL;
    
    if (head == NULL) {
        head = new;
        tail = new;
    }
    else {
        tail -> next = new;
        new -> back = tail;
        tail = new;
    }
    size += 1;
}


/* Insets an item at the specified index */
void insert (int position, char* element)
{
    if (position >= 0 && position <= size) {
        Node* new = (Node*) malloc (sizeof(Node));
        new -> value = element;
        new -> next  = NULL;
        new -> back  = NULL; 

        if (head == NULL) {
            head = new;
            tail = new;
        }
        else if (position == 0) {
            new -> next = head;
            head -> back = new;
            head = new;
        }
        else if (position == size) {
            tail -> next = new;
            new -> back = tail;
            tail = new;
        }
        else {
            Node* aux = head;
            int i;
            for (i = 0; i < position - 1; i++) {
                aux = aux -> next;
            }
            new -> next = aux -> next;
            aux -> next -> back = new;
            new -> back = aux;
            aux -> next = new;
        }
    size += 1;
    }
    else {
        error ("position entered isn't valid");
    }
}


/* Search the address of an element */
Node* search_item (char* element) 
{
    Node* i;
    for (i = head; i != NULL; i = i -> next) {
        if (i -> value == element) {
            return i;
            break;
        }
    }
    return NULL;
}


/* Remove an element through of an element passed like argument */
char* remove_item (char* element)
{
    Node* address_element = search_item (element);
    
    if (address_element == NULL) {
        printf("Element was not found, soon can't to be removed \n");
        return NULL;   
    }

    Node* trash;
    char* removido;

    if (address_element == head) {
        trash = head;
        head = head -> next;
        removido = address_element -> value;
        free(trash);
        size -= 1;    
    }
    else if (address_element == tail) {
        trash = tail;
        tail = tail -> back;
        tail -> next = NULL;
        removido = address_element -> value;
        free(trash);
        size -= 1;
    }
    else {
        Node* aux = head;
        int i;
        for (i = 0; i < size - 1; i++) {
            aux = aux -> next;
            if (aux == address_element) {
                trash = aux;
                aux = aux -> back;
                break;
            }
        }
        aux -> next -> next -> back = aux;
        aux -> next = aux -> next -> next;
        removido = address_element -> value;
        free(trash);
        size -= 1; 
    }
    
    return removido;
}
/* Remove all elements from a linked-list */
void clear ()
{ 
   Node* i = head;
   Node* trash;
   
   while (i != NULL) {
      trash = i;
      head = head -> next;
      i = i -> next;
      free(trash);
   }

   tail = NULL;   
   size = 0; 
}

/* To show all elements from a likend-list */
void show_list ()
{  
     
    Node* i = head;
    printf("[");
    while (i != NULL) {
        printf("\"%s\"",i -> value);
    i = i -> next;
    if (i != NULL) printf(", ");
    }
    printf("]\n");
}


/* To show all element inverted in a linked-list */
void show_list_inverted ()
{
    Node* i = tail;
    printf("[");
    while (i != NULL) {
        printf("\"%s\"", i -> value);
    i = i -> back;
    if (i != NULL) printf(", ");
    }
    printf("]\n");
}


/* Funcion main */
int main (void) {
    // Using the insert()
    insert (0, "Paulo");
    insert (0, "Luara");
    insert (2, "Valério");
    insert (3, "Rilda");

    // Using the append()
    append ("Luan");
    append ("Ludmila");
    
    // Show linked-list:
    printf("Linked-list.........: ");
    show_list ();
    printf("Linked-list inverted: ");
    show_list_inverted ();
    
    // Using the remove()
    char* removido1 = remove_item ("Rilda");
    char* removido2 = remove_item ("Paulo");
    char* removido3 = remove_item ("Gabriel");
    printf("Elements removed are: %s e %s\n",removido1, removido2);

    // After used remove()
    printf("After to used remove: ");
    show_list();
   
    // Using the clear():
    clear ();
    printf("Linked-list empty...: ");
    show_list ();
    show_list_inverted();
    
    return 0;
}
