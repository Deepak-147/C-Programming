#include<stdio.h>
int main(void) {
    int a=10, b=20, c=30;
    int *ptr[3];
    ptr[0] = &a;
    ptr[1] = &b;
    ptr[2] = &c;
    printf("\n%d", ptr);
    printf("\n%d", &ptr);
    printf("\n%d", &ptr[0]);//prints address of ptr[0]

    printf("\n\n%d", &a);
    printf("\n%d", *ptr);//prints address of a

    printf("\n\n%d", *ptr[0]);
    printf("\n%d", *ptr[1]);
    printf("\n%d", *ptr[2]);

    return(0);
}



