/*
Concept of Dangling pointer

A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer.
*/
#include<stdio.h>
#include<stdlib.h>
int main(void) {
    int *p = (int *) malloc(sizeof(int));
    *p = 10;
    printf("\n%d", p);
    printf("\n%d", *p);
    free(p);

    /*Now p is a dangling pointer. */
    printf("\n%d", p);
    printf("\n%d", *p);

    return 0;
}
