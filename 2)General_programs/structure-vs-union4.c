#include<stdio.h>
typedef struct
{
    int x;
    int y;
} POINT1;

typedef union
{
    int x;
    int y;
} POINT2;

int main(void)
{
    /*The only difference between structure and union is that in case of unions, you can store information in one field at any one time.
    Think of it as a chunk of memory that is used to store variables of different types. When a new value is assigned to a field, the existing data is replaced with the new data.
    */

    POINT1 p1 = {2, 3};
    // POINT2 p2 = {4, 5}; Illegal in case of unions
    POINT2 p2;
    printf("\n\n The size of structure is: %d", sizeof p1);/*For structure, size is determined by adding sizes of all member elements*/
    printf("\n\n The size of union is: %d", sizeof p2);/*For union, size is determined by the member with the biggest size*/
    p2.x = 4;
    p2.y = 6;
    printf("\n\n The coordinates of p1 are %d and %d", p1.x, p1.y);
    printf("\n\n The coordinates of p2 are %d and %d", p2.x, p2.y);
    return(0);
}
