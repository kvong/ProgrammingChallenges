Given the head of a linked list. Reverse the linked list. For example, `5->4->3->2->1->NULL` we become `1->2->3->4->5->NULL`.

# Solution steps:

We will need three variables for each of the following purpose:
    1. Save the current node to be use on the next iteration as the previous node.
    2. Save the next node so we can traverse the linked list with a while loop.
    3. Head pointer that keep track of the last valid node.

With those three variable we can solve the problem by:
    1. Declare the previous node as NULL because there is no node before the head node on the linked list.
    2. Set the next node as the head node.
    3. Traverse the linked list by checking if the next node is available. If the next node is not available, exit;
    4. Set the head node to be the next node.
    5. Update the next node to be the node after the current next node.
    6. With the next-next node saved, we can now point the next node's pointer to the previous node.
    7. Update the previous node as the current node.
    8. Update the new next node as the next-next node we saved in step 6.
    9. Go back to step 3 until we can no longer proceed.
    
    
# Solution steps (RECURSIVE):

1. `Node* node = ReverseLinkedList( head->next )`
    - If termination condition is not met go to the end of the list until it's met.
    - If termination condition is met, node will equal `head->next`.
2. `head->next->next = head`
    - On reaching the termination condition, `head->next->next` which would be *NULL* will now be the current head;
    - In other word, `node->next` will now be the current `head`.
3. `head->next = NULL`
    - This is adds the *NULL* to the end of the now reversed linked list.
4. `return node`
    - Return the reversed linked list from this recursive call.
