/*Find the element present at the start of the loop. */
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void push(NODE **head_ref, int new_data)
{
    /* allocate node */
    NODE *new_node = (NODE *) malloc(sizeof(NODE));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
/*
 It uses two pointers fast and slow. Let fast moves twice than slow. Let slow comes to the start of the loop after covering k steps.
 Since slow has covered k steps, fast would have covered 2k steps. The difference between them would be 2k - k, that is, k steps.
 Thus fast has covered k steps in the loop. Let the size of the loop be Loop_Size. We can say that fast is (Loop_Size - k) steps behind the slow.
 Now fast has to cover (Loop_Size - k) steps at a relative speed of 1 step per unit time. Thus they will meet after (Loop_Size - k) steps. Let this be the collision spot.
 This will be k steps before the head of the loop. Now we can say that both collision spot and the List Head will be k steps from the start of the loop.
 At this point we will keep one pointer(any of the slow or fast) at the collision spot and the other at the List Head. Now travel at the speed of one node per step.
 Then both will meet at the start of the loop.
 */
NODE* findStartofLoop(NODE *head) {
    NODE *slow = head;
    NODE *fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = (fast->next)->next;
        if(slow == fast) {
            printf("\n\nLoop found ");
            break;
        }
    }
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main(void) {
    /* Start with the empty list */
    NODE *head = NULL;

    push(&head, 60);
    push(&head, 91);
    push(&head, 82);
    push(&head, 109);
    push(&head, 73);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;

    head = findStartofLoop(head);

    printf("\n\nLoop starts at node with data %d ", head->data);
    return 0;
}
