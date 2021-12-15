#include<stdio.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void push(NODE **head, int new_data) {
    /*Allocate node */
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    if(!new_node) {
        printf("Error!!. Insufficient memory.");
        return;
    }

    /*Put the data */
    new_node->data = new_data;

    /*Make next of new node as head */
    new_node->next = (*head);

    /*Make the head to point to the new node */
    (*head) = new_node;
}

/*This function prints contents of linked list starting from head */
void printList(NODE *node) {
  printf("\n\n Status of list is: ");
  while(node != NULL) {
     printf("%d==>", node->data);
     node = node->next;
  }
  printf("NULL\n");
}
=
void swap(NODE **head) {
    NODE *temp_node = *head;
    while(temp_node->next != NULL)
        temp_node = temp_node->next;
    int temp;
    temp = temp_node->data;
    temp_node->data = (*head)->data;
    (*head)->data = temp;
}

int main(void) {
    /*Start with the empty list */
    NODE *head = NULL;

    int length;
    printf("\n Enter the length of list: ");
    scanf("%d", &length);
    int i, element;
    for(i=0; i<length; i++) {
        printf("\n Enter element: ");
        scanf("%d", &element);
        push(&head, element);
    }
    printList(head);
    swap(&head);
    printList(head);
    return 0;
}
