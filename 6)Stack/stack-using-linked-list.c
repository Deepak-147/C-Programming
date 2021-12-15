#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void push(NODE **head_ref, int data) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
    printf("\n\nPushed %d to the stack", new_node->data);
}

int pop(NODE **head_ref) {
    if(*head_ref == NULL) {
        printf("\n\nList is empty");
        return;
    }
    NODE *temp = (*head_ref);
    (*head_ref) = (*head_ref)->next;
    int removed = temp->data;
    free(temp);
    return removed;
}

int main(void) {
    NODE *head = NULL;

    push(&head, 20);
    push(&head, 98);
    push(&head, 34);
    push(&head, 63);
    push(&head, 12);

    int removed = pop(&head);

    printf("\n\nPopped element is : %d", removed);

    return 0;
}