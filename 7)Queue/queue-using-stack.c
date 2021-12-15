/*
Program to implement a queue using two stacks: Better version.

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

/*Structure of Queue having two stacks */
struct queue {
    NODE *stack1;
    NODE *stack2;
};
typedef struct queue QUEUE;

void push(NODE **top_ref, int data) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    /*If node is not successfully created. */
    if(new_node == NULL) {
        printf("\n Memory insufficient");
        exit(0);
    }
    new_node->data = data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
    printf("\n Enqueued item: %d", data);
}

int pop(NODE **top_ref) {
    int popped;
    if(*top_ref == NULL) {
        printf("\n Underflow");
        exit(0);
    }
    NODE *temp = (*top_ref);
    (*top_ref) =(*top_ref)->next;
    popped = temp->data;
    free(temp);
    return popped;
}

void enqueue(QUEUE *q, int data) {
    push(&q->stack1, data);
}

void dequeue(QUEUE *q) {
    int item;
    /* If both stacks are empty then error */
    if(q->stack1 == NULL && q->stack2 == NULL) {
        printf("\n Queue is empty");
        exit(0);
    }
    /*If stack2 is empty then only move elements from stack1 to stack2. */
    if(q->stack2 == NULL) {
        while(q->stack1 != NULL) {
            /*Pop from stack1 and push into stack2 */
            item = pop(&q->stack1);
            push(&q->stack2, item);
        }
    }
    /*If stack2 is not empty, we pop elements directly. */
    item = pop(&q->stack2);
    printf("\n Dequeued item: %d", item);
}

int main(void) {
    QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enqueue(q, 23);
    enqueue(q, 45);
    enqueue(q, 32);
    enqueue(q, 74);
    enqueue(q, 91);
    enqueue(q, 69);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 99);
    dequeue(q);
    return 0;
}