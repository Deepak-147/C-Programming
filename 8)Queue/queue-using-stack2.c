/*
Program to implement a queue using two stacks: More Intuitive.
First thing comes in mind is to have two pointers to the stacks. And not having these pointers under a name of a structure.

Enqueue():
Push elements in the stack1.

Dequeue():
If both the stacks are empty, it means that there are no elements in the queue.
If stack2 is empty, then for each element we will pop that element from stack1 and push it to stack2.
If stack is not empty, then we do not need to move the elements and we can directly pop the top of stack2.

*/
#include<stdio.h>
#include<stdlib.h>
/*Structure of a node. */
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void enqueue(NODE **head_ref, int data) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    /*If node is not successfully created. */
    if(new_node == NULL) {
        printf("\n Memory insufficient");
        exit(0);
    }
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("\n Enqueued item: %d", data);
}

void dequeue(NODE **head1_ref, NODE **head2_ref) {
    /* If both stacks are empty then error */
    if(*head1_ref == NULL && *head2_ref == NULL) {
        printf("\n Queue is empty");
        exit(0);
    }
    /*If stack2 is empty then only move elements from stack1 to stack2. */
    if(*head2_ref == NULL) {
        while(*head1_ref != NULL) {
            NODE *new_node = (NODE *)malloc(sizeof(NODE));
            if(new_node == NULL) {
                printf("\n Memory insufficient");
                exit(0);
            }
            /*Pop from stack1 and push into stack2 */
            NODE *temp = *head1_ref;
            new_node->data = (*head1_ref)->data;
            *head1_ref = (*head1_ref)->next;
            free(temp);
            new_node->next = *head2_ref;
            (*head2_ref) = new_node;
        }
    }
    /*If stack2 is not empty, we pop elements directly. */
    NODE *temp = *head2_ref;
    *head2_ref = (*head2_ref)->next;
    int pop = temp->data;
    free(temp);
    printf("\n Dequeued item: %d", pop);
}

int main(void) {
    NODE *head1 = NULL;
    NODE *head2 = NULL;
	/*We have to pass both front and rear because in some cases we may have to update both front and rear. */
    enqueue(&head1, 23);
    enqueue(&head1, 45);
    enqueue(&head1, 32);
    enqueue(&head1, 74);
    enqueue(&head1, 91);
    enqueue(&head1, 69);
    dequeue(&head1, &head2);
    dequeue(&head1, &head2);
    dequeue(&head1, &head2);
    enqueue(&head1, 99);
    dequeue(&head1, &head2);
    return 0;
}