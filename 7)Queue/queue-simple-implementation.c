/*
Queue implementation:
comes more naturally to use pointers separately.
*/
#include<stdio.h>
/*Structure of a queue node. */
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void enqueue(NODE **rear_ref, NODE **front_ref, int data) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    /*If the queue is empty. It means we are adding the first element. So we have to update both front and rear since this is the first element. */
    if(*rear_ref == NULL) {
        printf("\n Queue is empty. ");
        /*Update front and rear to point to the same node. */
        *rear_ref = *front_ref = new_node;
        printf("\n Enqueued first element: %d", data);
        return;
    }
    /*Otherwise, for any other node in the queue update the rear only. */
    (*rear_ref)->next = new_node;
    *rear_ref = new_node;
    printf("\n Enqueued element: %d", data);
}

void dequeue(NODE **front_ref, NODE **rear_ref) {
    if(*front_ref == NULL) {
        printf("\n Queue is empty. Cannot perform Dequeue. ");
        return;
    }

    /*This is more simpler. */
    /*
    NODE *temp = (*front_ref);
    *front_ref = (*front_ref)->next;

    //If only one node was present, then now front should be at null. In that case make rear also to null.
    if(*front_ref == NULL) {
        *rear_ref = NULL;
        printf("\n Dequeued element: %d", temp->data);
        free(temp);
        printf("\n Queue is empty now. ");
        return;
    }
    printf("\n Dequeued element: %d", temp->data);
    free(temp);

    */

    /*Another way of doing the same thing. */
    NODE *temp = (*front_ref);
    /*
    Check if it is the only node. When both front and rear points to the same non null node, it means there is only one element in the queue.
    In that case update both front and rear to point to null and then free the node.
    */
    if((*front_ref == *rear_ref) && (*front_ref != NULL)) {
        *front_ref = *rear_ref = NULL;
        printf("\n Dequeued element: %d", temp->data);
        free(temp);
        printf("\n Queue is empty now. ");
        return;
    }
    /*Otherwise, update front only. */
    *front_ref = (*front_ref)->next;
    printf("\n Dequeued element: %d", temp->data);
    free(temp);
}

void printQueue(NODE *node) {
    printf("\n\n Status of Queue now is: ");
    while(node != NULL) {
        printf("%d==>", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(void) {
    NODE *front = NULL;
    NODE *rear = NULL;
    /*We have to pass both front and rear because in some cases we may have to update both front and rear. */
    enqueue(&rear, &front, 13);
    printQueue(front);
    enqueue(&rear, &front, 41);
    printQueue(front);
    dequeue(&front, &rear);
    printQueue(front);
    enqueue(&rear, &front, 36);
    printQueue(front);
    enqueue(&rear, &front, 92);
    printQueue(front);
    dequeue(&front, &rear);
    printQueue(front);
    dequeue(&front, &rear);
    printQueue(front);
    dequeue(&front, &rear);
    printQueue(front);
    return 0;
}