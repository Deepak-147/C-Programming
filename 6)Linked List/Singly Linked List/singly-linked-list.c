#include<stdio.h>
#include<stdlib.h>
/*List Node structure*/
struct Node {
    int data;
    struct Node *next;
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

    /*Put the data */
    new_node->data = new_data;

    /*Make next of new node as head */
    new_node->next = (*head_ref);

    /*Move the head to point to the next node */
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

    /*Put the data */
    new_node->data  = new_data;

    /*This new node is going to be the last node, so make next of it as NULL */
    new_node->next = NULL;

    /*If the Linked List is empty, then make the new node as head */
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /*Else traverse till the last node */
    while(helper_node->next != NULL)
        helper_node = helper_node->next;

    /*Change the next of last node */
    helper_node->next = new_node;
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
        NODE *prev_node;
        while((counter < position) && (helper_node->next != NULL)) {
            counter++;
            prev_node = helper_node; /*Before advancing the helper_node to point the next node, assign it to prev_node to keep track of the previous node.*/
            helper_node = helper_node->next;
        }

        /*Allocate new node */
        NODE *new_node =(NODE *) malloc(sizeof(NODE));

        /*Memory check */
        if(!new_node) {
            printf("Memory Insufficient!");
            return;
        }

        /*Put the data */
        new_node->data = new_data;

        /*Make the next of prev_node to point to new_node */
        prev_node->next = new_node;

        /*Make next of new node to point to helper_node */
        new_node->next = helper_node;
    }
}

/*Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(NODE **head_ref, int delete_data) {
    NODE *helper_node = (*head_ref);
    NODE *prev_node;

    /*If delete_data is present at the beginning. */
    if((helper_node != NULL) && (helper_node->data) == delete_data) {
        *head_ref = helper_node->next;
        free(helper_node);
        return;
    }

    /*Otherwise, search for the delete_data while keeping track of the previous node */
    while((helper_node != NULL) && (helper_node->data) != delete_data) {
        prev_node = helper_node;/*Before advancing the helper_node to point the next node, assign it to prev_node to keep track of the previous node.*/
        helper_node = helper_node->next;
    }

    /*After traversing the whole list, if delete_data is not present in the list. */
    if(helper_node == NULL)
        return;

    /*Unlink the helper_node from the list */
    prev_node->next = helper_node->next;

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
    /*Start with the empty list */
    NODE *head = NULL;

    /*Insert 10 at the end. So the list becomes 10->NULL */
    append(&head, 10);

    /* Insert 3 at the beginning. So linked list becomes 3->10->NULL */
    push(&head, 3);

    /* Insert 5 at the beginning. So linked list becomes 5->3->10->NULL */
    push(&head, 5);

    /* Insert 56 at the beginning. So linked list becomes 56->5->3->10->NULL */
    push(&head, 56);

    /*Insert 43 at the end. So the list becomes 56->5->3->10->43->NULL */
    append(&head, 43);

    /* Insert 99, at position 4 that is, after 3. So linked list becomes 56->5->3->99->10->43->NULL */
    insertAtPosition(&head, 4, 99);

    /* Insert 21, at position 2 that is, after 56. So linked list becomes 56->21->5->3->99->10->43->NULL */
    insertAtPosition(&head, 2, 21);

    printList(head);

    deleteNode(&head, 3);

    printf("\n\n Linked List after deletion of 3 is: ");

    printList(head);

    deleteNode(&head, 56);

    printf("\n\n Linked List after deletion of 56 is: ");

    printList(head);

    return 0;/*return value of 0 implies normal termination; non-zero values signal unusual or erroneous termination conditions.  */
}
