#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

void printLinkedList( ListNode* );
ListNode* interweaveLinkedList( ListNode* , ListNode* );

int main(int argc, char *argv[])
{
    ListNode* list1 = malloc( sizeof(ListNode) );
    ListNode* list2 = malloc( sizeof(ListNode) );
    ListNode* list3 = malloc( sizeof(ListNode) );
    ListNode* list4 = malloc( sizeof(ListNode) );
    ListNode* list5 = malloc( sizeof(ListNode) );
    ListNode* list6 = malloc( sizeof(ListNode) );
    
    list1->val = 1;
    list1->next = list2;
    list2->val = 2;
    list2->next = list3;
    list3->val = 3;
    list3->next = NULL;

    list4->val = 4;
    list4->next = list5;
    list5->val = 5;
    list5->next = list6;
    list6->val = 6;
    list6->next = NULL;


    printLinkedList( list4 );
    printLinkedList( list1 );
    printLinkedList( interweaveLinkedList( list1, list4 ) );

    return 0;
}

void printLinkedList( ListNode* node ) {
    if ( node == NULL ) {
        printf("\n");
        return;
    }
    printf( "%d, ", node->val );
    printLinkedList( node->next );
}

ListNode* interweaveLinkedList( ListNode* list1, ListNode* list2 ) {
    if ( list1 == NULL ) {
        return list2;
    }

    ListNode* temp = list1->next;
    ListNode* temp1 = list2->next;
    list2->next = temp;
    list1->next = list2;
    list2 = temp1;
    return interweaveLinkedList( list1->next, list2 );
}
