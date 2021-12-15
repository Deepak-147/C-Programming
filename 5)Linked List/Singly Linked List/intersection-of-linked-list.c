/*Find node present at the intersection of the two linked list */
#include<stdio.h>
#include<stdlib.h>

/*List Node structure*/
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node NODE;

/*Finds node present at the intersection. It takes reference of the first element of each list as its argument */
int nodeAtIntersection(NODE *head1, NODE *head2) {

    NODE *h1 = head1;
    NODE *h2 = head2;
    int count1 = getCount(&h1);
    int count2 = getCount(&h2);
    /* h1 and h2 are now at the tail nodes of respective lists */
    /* head1 and head2 are still at the respective heads */

    /*If the last nodes are not same, then there is no intersection */
    if(h1 != h2) {
        printf("There is no intersection in the two lists");
        return 0;/*signal no intersection */
    }

    if(count1 > count2) {
        /*List1 is bigger */
        int i;
        int difference = count1 - count2;

        /*Advance of bigger list by 'difference' number of nodes */
        for(i = 0; i < difference; i++){
            if(head1 == NULL) {
                return -1;
            }
            head1 = head1->next;
        }
    }
    else {
        /*List2 is bigger */
        int i;
        int difference = count2 - count1;

        /*Advance of bigger list by 'difference' number of nodes */
        for(i = 0; i < difference; i++) {
            if(head2 == NULL) {
                return -1;
            }
            head2 = head2->next;
        }
    }

    while(head1 != NULL && head2 != NULL) {
        if(head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}
/*counts the length of each list. And head will be at tail of the list */
int getCount(NODE **head) {

    int count = 0;
    NODE *temp = (*head);
    while(temp != NULL) {
        count++;
        (*head) = temp;
        temp = temp->next;
    }
    /*Now head is at last node(tail node) and temp is at NULL */
    return count;
}

int main(void) {
    /* Quick way to add elements in linked list. Not advised though. */

    /*
        Create two linked lists

        1st 3->6->9->15->30
        2nd 10->15->30

        15 is the intersection point
    */

    NODE *newNode;

    NODE *head1 = (NODE *) malloc(sizeof(NODE));
    head1->data  = 10;

    NODE *head2 = (NODE *) malloc(sizeof(NODE));
    head2->data  = 3;

    newNode = (NODE *) malloc(sizeof(NODE));
    newNode->data = 6;
    head2->next = newNode;

    newNode = (NODE *) malloc(sizeof(NODE));
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = (NODE *) malloc(sizeof(NODE));
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next  = newNode;

    newNode = (NODE *) malloc(sizeof(NODE));
    newNode->data = 30;
    head1->next->next= newNode;

    head1->next->next->next = NULL;

    printf("\n The node at intersection is %d \n", nodeAtIntersection(head1, head2));
    return 0;
}
