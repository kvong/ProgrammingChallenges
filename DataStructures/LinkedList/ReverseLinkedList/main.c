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
    Node* head= malloc(sizeof(Node));
    head = NULL;

    int list[5] = {1, 2, 3, 4, 5};

    int i;
    for (i = 0; i < sizeof(list)/sizeof(int); ++i) {
        Node* node = malloc(sizeof(Node));
        node->key = list[i];
        node->next = head;
        head = node;
    }

    PrintLinkedList( head );

    PrintLinkedList( ReverseLinkedList( head ) );
    
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
    Node* nextNode = head;
    Node* previousNode = NULL;
    while ( nextNode != NULL ) {
        head = nextNode;
        nextNode = nextNode->next;
        head->next = previousNode;
        previousNode = head;
    }
    return head;
}
