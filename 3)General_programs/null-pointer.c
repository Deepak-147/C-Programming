/*
Concept of NULL and NULL pointers.

As per C11(published in Dec 2011) standard clause 6.3.2.3:
"An integer constant expression with the value 0, or such an expression cast to type void *,
is called a null pointer constant. If a null pointer constant is converted to a pointer type,
the resulting pointer, called a null pointer, is guaranteed to compare unequal to a pointer to any object or function."

Usage of NULL is preferred because it makes it explicit in code that programmer is using null pointer not integer 0.

As per C11 standard clause 7.19:
"NULL expands to an implementation-defined null pointer constant."
It means that internal representation of the null pointer could be non-zero bit pattern to convey NULL pointer.
That's why NULL always needn't be internally represented as all zeros bit pattern.
A compiler implementation can choose to represent "null pointer constant" as a bit pattern for all 1s or anything else.

NULL macro is defined as ((void *)0) in header files of most of the C compiler implementations.

A null pointer stores a defined value, but one that is defined by the environment to not be a valid address for any member or object.
*/
#include<stdio.h>
int main(void) {
    /*Three ways of making a NULL pointer. */

    /*Method 1: */
    int *p = (void *)0;

    /*Equivalent to if(p!= NULL) */
    if(p)
        printf("\nI am not NULL");
    else
        printf("\nI am a NULL pointer using method 1. ");

    /*Method 2: */
    int *q = NULL;
    if(q)
        printf("\nI am not NULL");
    else
        printf("\nI am a NULL pointer using method 2. ");

    /*Method 3: */
    int *r = 0;
    if(r)
        printf("\nI am not NULL");
    else
        printf("\nI am a NULL pointer using method 3. ");

    int *s = NULL;
    printf("\n%d", s);

    /*Prints the platform specific NULL representation. May be 0 or something else! */
    printf("\n%d", NULL);

    /*Size of the NULL pointer would be equal to size of any pointer. */
    printf("\n%d", sizeof(NULL));

    return 0;
}



