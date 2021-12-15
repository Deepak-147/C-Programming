#include<stdio.h>
#include<stdlib.h>

/*List Node Structure */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node NODE;

/*Given a reference(pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list. */
void push(NODE **head_ref, int new_data) {

    /*Allocate node */
    NODE *new_node = (NODE *) malloc(sizeof(NODE));

    /*Memory check */
    if(!new_node) {
        printf("Memory Insufficient!");
        return;
    }

    /*Put the data  */
    new_node->data = new_data;

    /*Make next of new_node as head and prev as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /*Change prev of head node to new_node */
    if((*head_ref) != NULL)
      (*head_ref)->prev = new_node ;

    /*Move the head to point to the new_node */
    (*head_ref) = new_node;
}

/*Given a reference(pointer to pointer) to the head of a list and an int, appends a new node at the end. */
void append(NODE **head_ref, int new_data) {

    /*Allocate node */
    NODE *new_node = (NODE *) malloc(sizeof(NODE));

    /*Memory check */
    if(!new_node) {
        printf("Memory Insufficient!");
        return;
    }

    NODE *helper_node = *head_ref;

    /*Put the data  */
    new_node->data  = new_data;

    /*This new_node is going to be the last node, so make next of it as NULL */
    new_node->next = NULL;

    /*If the Linked List is empty, then make the new_node as head */
    if(*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /*Else traverse till the last node */
    while(helper_node->next != NULL)
        helper_node = helper_node->next;

    /*Change the next of helper_node */
    helper_node->next = new_node;

    /*Make helper_node as previous of new_node */
    new_node->prev = helper_node;

    return;
}

/*Given a position, insert a new node at that position */
void insertAtPosition(NODE **head_ref, int position, int new_data) {

    /*Checking position*/
    if(position == 1) {
        push(head_ref, new_data);/*Insertion at the beginning. */
    }
    else {
    /*Traverse the list till the position. */
        int counter = 1;
        NODE *helper_node = *head_ref;
        while((counter < position) && (helper_node->next != NULL)) {
            counter++;
            helper_node = helper_node->next;
        }

        /*Allocate a new node */
        NODE *new_node = (NODE *) malloc(sizeof(NODE));

        /*Memory check */
        if(!new_node) {
            printf("Memory Insufficient!");
            return;
        }

        /*Put the data */
        new_node->data = new_data;

        /*Change the pointers of new_node */
        new_node->next = helper_node;
        new_node->prev = helper_node->prev;

        /*Make the next of previous node to point to the new_node */
        (helper_node->prev)->next = new_node;

        /*Make helper_node to point to previous node(that is, new_node) */
        helper_node->prev = new_node;
    }
}

/*Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(NODE **head_ref, int delete_data) {

    NODE *helper_node = (*head_ref);

    /*If delete_data is present at the beginning. */
    if((helper_node != NULL) && (helper_node->data) == delete_data) {
        *head_ref = helper_node->next;
        free(helper_node);
        return;
    }

    /*Otherwise, search for the delete_data */
    while((helper_node != NULL) && (helper_node->data) != delete_data)
        helper_node = helper_node->next;

    /*After traversing the whole list, if delete_data is not present in the list. */
    if(helper_node == NULL)
        return;

    /*Make next of the previous node to point to the next of helper_node */
    (helper_node->prev)->next = helper_node->next;

    /*Make prev of the next of helper_node to point to previous node */
    (helper_node->next)->prev = helper_node->prev;

    /*Free the memory */
    free(helper_node);
}

/*This function prints contents of linked list starting from head */
void printList(NODE *node) {
  printf("\n\n Linked list is: ");
  while(node != NULL) {
     printf("%d==>", node->data);
     node = node->next;
  }
  printf("NULL\n");
}

int main(void) {

    /* Start with the empty list */
    NODE *head = NULL;

    /*Insert 34. So linked list becomes 34->NULL */
    append(&head, 34);

    /*Insert 12 at the beginning. So linked list becomes 12->34->NULL */
    push(&head, 12);

    /*Insert 87 at the beginning. So linked list becomes 87->12->34->NULL */
    push(&head, 87);

    /*Insert 79. So linked list becomes 87->12->34->79->NULL */
    append(&head, 79);

    /*Insert 108, at position 2. So linked list becomes 87->108->12->34->79->NULL */
    insertAtPosition(&head, 2, 108);

    printList(head);

    /*Delete 34. So linked list becomes 87->108->12->34->79->NULL */
    deleteNode(&head, 34);

    printf("\n\n Linked List after deletion of 34 is: ");

    printList(head);

    return 0;
}

