#include<stdio.h>

typedef struct
{
    int x;
    float y;
} POINT;

void method1(int, float);/*Passing individual members*/
void method2(POINT);/*Passing entire structure*/
void method3(POINT *);/*Passing address of structure, type1*/
void method4(POINT *);/*Passing address of structure, type2*/

int main(void)
{
    POINT p1 = {2, 4.9}, *ptr;
    method1(p1.x, p1.y);
    method2(p1);
    method3(&p1);
    method4(&p1);
    return(0);
}
void method1(int a, float b)
{
    printf("\n\n The coordinates of a point using Method 1 are: %d and %f", a, b);
}

void method2(POINT p)
{
    printf("\n\n The coordinates of a point using Method 2 are: %d and %f", p.x, p.y);
}

void method3(POINT *ptr)
{
    printf("\n\n The coordinates of a point using Method 3 are: %d and %f", (*ptr).x, (*ptr).y);
}

void method4(POINT *ptr)
{
    printf("\n\n The coordinates of a point using Method 4 are: %d and %f", ptr->x, ptr->y);
}
