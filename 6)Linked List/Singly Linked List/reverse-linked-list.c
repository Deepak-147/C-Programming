/*Reverse a linked list */
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;


NODE* reverseList(NODE *head) {
    NODE *temp = NULL;
    NODE *nextNode = NULL;
    while(head) {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}


/*This function prints contents of linked list starting from head */
void printList(NODE *node) {
    while(node != NULL) {
        printf("%d==>", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(void) {

    NODE *head = (NODE *) malloc(sizeof(NODE));
    head->data = 23;

    NODE *newNode;
    newNode = (NODE *) malloc(sizeof(NODE));
    newNode->data = 31;
    head->next = newNode;

    newNode = (NODE *) malloc(sizeof(NODE));
    newNode->data = 78;
    head->next->next = newNode;

    head->next->next->next = NULL;

    printf("\n\nList before reversal is: ");
    printList(head);

    head = reverseList(head);

    printf("\n\nList after reversal is: ");
    printList(head);
    return 0;
}
