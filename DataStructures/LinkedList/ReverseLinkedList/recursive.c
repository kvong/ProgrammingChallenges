#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;


Node* ReverseLinkedList( Node* head );

void PrintLinkedList( Node* );

int main(int argc, char *argv[])
{
    int list[5] = {1, 2, 3, 4, 5};

    Node* one = malloc( sizeof(Node) );
    one->next = NULL;
    one->key = 1;
    Node* two = malloc( sizeof(Node) );
    two->next = one;
    two->key = 2;
    Node* three = malloc( sizeof(Node) );
    three->next = two;
    three->key = 3;
    Node* four = malloc( sizeof(Node) );
    four->next = three;
    four->key = 4;

    PrintLinkedList( four );
    Node* reversed = ReverseLinkedList( four );
    PrintLinkedList( reversed );

    return 0;
}

void PrintLinkedList( Node* head ) {
    Node* currentNode = head;
    while ( currentNode != NULL ) {
        printf( "%d, ", currentNode->key );
        currentNode = currentNode->next;
    }
    printf("\n");
}

Node* ReverseLinkedList( Node* head ) {
    if ( head->next == NULL )
        return head;
    Node* node = ReverseLinkedList( head->next );
    head->next->next = head;
    head->next = NULL;
    return node;
}
