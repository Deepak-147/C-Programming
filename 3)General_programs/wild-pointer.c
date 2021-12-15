/*
Concept of Wild pointer

A pointer which has not been initialized to anything (not even NULL) is known as wild pointer.
*/

#include<stdio.h>

int main(void) {

    /*p is wild pointer now. */
    int *p;
    printf("\n%d", p);

    int x = 10;

    /*p is not a wild pointer now. */
    p = &x;
    printf("\n%d", p);
    return 0;
}
