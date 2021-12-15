/*Concept of void pointer or Generic pointer */
#include<stdlib.h>

int main(void) {


    int x = 10;
    char y = 'a';

    /*Assigning address of integer variable to integer pointer. It works as expected.*/
    int *p = &x;
    printf("\n%d", p);
    printf("\n%d", *p);

    /*
    A void pointer is a pointer that has no associated data type with it.
    A void pointer can hold address of any type and can be type casted to any type, without an explicit cast.
    */
    void *q = &x;
    printf("\n%d", q);

    /*We cannot dereference a void pointer. */
    //printf("\n%d", *q);

    /*But we can type cast it explicitly to the correct data type. */
    printf("\n%d", *((int *)q));

    /*
    The C standard doesn't allow pointer arithmetic with void pointers.
    As per C11 standard clause 6.2.5:
    "A pointer to void shall have the same representation and alignment requirements as a pointer to a character type".
    */
    printf("\n%d", sizeof(void));
    printf("\n%d", sizeof(void *));
    printf("\n%d", ++q);

    /*Now our void pointer holds address of char. */
    q = &y;
    printf("\n%d", q);
    printf("\n%c", *((char *)q));
    printf("\n%d", ++q);

    return 0;
}
