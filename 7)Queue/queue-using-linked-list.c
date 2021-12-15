/*
Queue implementation:
This does not comes intuitively using two pointers under a structure name.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

struct Pointers {
    NODE *front,
    NODE *rear;
};
typedef struct Pointers POINTERS;

POINTERS* createQueue() {
    POINTERS *p = (POINTERS *) malloc(sizeof(POINTERS));
    p->front = p->rear = NULL;
    return p;
}

/*Add an element at the rear of the queue */
void enqueue(POINTERS *p, int data) {
    /*create a new node */
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;

    /*If queue is empty, then front and rear both points at same node */
    if(p->rear == NULL) {
        p->front = p->rear = new_node;
        printf("\n\nEnqueued first element: %d", data);
        return;
    }
    p->rear->next = new_node;
    p->rear = new_node;
    printf("\n\nEnqueued: %d", data);
}

/*Delete an element from front of the queue */
void dequeue(POINTERS *p) {
    /*If queue is empty, then return NIL */
    if(p->front == NULL)
        return NULL;
    NODE *temp = p->front;
    p->front = p->front->next;

    /*If only one node was present, then now front should be at null. In that case make rear also to null. */
    if(p->front == NULL)
        p->rear = NULL;
    printf("\n\nDequeued %d", temp->data);
}

int main(void) {
    POINTERS *p = createQueue();
    enqueue(p, 31);
    enqueue(p, 12);
    enqueue(p, 74);
    enqueue(p, 83);
    enqueue(p, 29);
    dequeue(p);
    dequeue(p);
    return 0;
}