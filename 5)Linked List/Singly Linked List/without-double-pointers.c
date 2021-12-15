/*Implementation without using Double pointers*/
#include<stdio.h>
#include<stdlib.h>
/*List Node structure*/
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

NODE* push(NODE *head, int new_data) {
        NODE *new_node = (NODE *) malloc(sizeof(NODE));
        new_node->data = new_data;
        new_node->next = head;
        return(new_node);
}

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

    head = push(head, 50);
    head = push(head, 90);

    printList(head);

    return 0;
}
