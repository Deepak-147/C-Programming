#include<stdio.h>
int main(void) {
    int a[] = {50, 40, 60, 10, 30, 20};
    int *b[] = {a, a+1, a+4, a+3, a+2, a+2};
    int **c = b;

    /* * and ++ both enjoys same operator precedence, thus in this case associativity will decide the order of evaluation. Here associativity is right to left. */
    *++*c;
    printf("%d, %d, %d", c - b, *c - a, **c);
    /*
    Address + number = New address
    New address = old address + Number * size of data type which pointer is pointing
    */

    /*
    Address2 - Address1 = Address
    Address2 - Address1 = (Simple subtraction of the two address)/size of data type which pointer points
    */
    return 0;
}

