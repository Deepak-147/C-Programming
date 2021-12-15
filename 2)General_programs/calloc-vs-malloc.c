/*
Concepts of calloc(), malloc(), free() and realloc().

Used for Dynamic Memory Allocation. The size of the data structure is known at the run-time. We don't know in advance.
Defined in <stdlib.h> header file. calloc() stands for contiguous allocation.
calloc() allocates multiple blocks of memory each of same size and sets all bytes to zero.
malloc() allocates single block of memory of specified size as the argument. It returns a void pointer to the first byte of the allocated space, or if there is an error it returns NULL.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void) {

    int *p;

    /*Allocate the memory for 5 integers containing garbage values. */
    p = (int *) malloc(sizeof(int) * 5);
    if(p)
        printf("\n SUCCESS! Memory allocated. ");
    else
        printf("\n ERROR! Memory not allocated. ");

    printf("\n%d", p);

    /*Garbage value. */
    printf("\n%d", *p);

    /*Deallocates memory previously allocated by malloc(). */
    free(p);

    int *q;

    /*Allocate the memory for 5 integers set to all 0. */
    q = (int *) calloc(sizeof(int), 5); //Notice the change in number of arguments.
    if(q)
        printf("\n SUCCESS! Memory allocated. ");
    else
        printf("\n ERROR! Memory not allocated. ");

    printf("\n%d", q);

    /*Initial value 0. */
    printf("\n%d", *q);

    /*Deallocates memory previously allocated by malloc(). */
    free(q);

    int *r;
    r = (int *) malloc(sizeof(int) * 5);
    if(r)
        printf("\n SUCCESS! Memory allocated. ");
    else
        printf("\n ERROR! Memory not allocated. ");

    /*Allocates a new memory to the variable r. */
    r = (int *)realloc(r, 10);
    if(r)
        printf("\n SUCCESS! Memory re-allocated. ");
    else
        printf("\n ERROR! Memory not re-allocated. ");
    printf("\n%d", r);
    printf("\n%d", *r);

    return 0;
}
