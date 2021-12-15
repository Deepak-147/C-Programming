/*Detect the presence of loop in a linked list */
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void push(NODE **head_ref, int new_data)
{
    /* allocate node */
    NODE *new_node = (NODE *) malloc(sizeof(NODE));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/*
Problem is solved by Floyd.
It uses two pointers moving at different speeds. The only way faster moving pointer would point to the
same location as a slower moving pointer is ,if somehow the entire list or a part of it is circular.
*/
int detectLoop(NODE *head) {
    NODE *slow = head;
    NODE *fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = (fast->next)->next;
        if(slow == fast) {
            printf("\n\n Loop found ");
            return 1;
        }
    }
    return 0;
}

int main(void) {
    /* Start with the empty list */
    NODE *head = NULL;

    push(&head, 60);
    push(&head, 91);
    push(&head, 82);
    push(&head, 73);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    detectLoop(head);

    return 0;
}



