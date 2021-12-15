#include<stdio.h>
int main(void) {
    int a[] = {54,78,15,23,90,69,84};
    int *ptr = a;// or &a or &a[0]

    printf("%d\n", a);
    printf("%d\n", ptr);
    printf("%d\n\n", *ptr);

    printf("%d\n", ptr++);
    printf("%d\n", *ptr);
    printf("%d\n\n", ptr);

    printf("%d\n", ++ptr);
    printf("%d\n", *ptr);
    printf("%d\n\n", ptr);

    printf("%d\n", ptr+1);
    printf("%d\n", *ptr);
    printf("%d\n\n", ptr);

    printf("%d\n", &a);
    printf("%d\n\n", &a[0]);

    printf("%d\n", a[3]);
    printf("%d\n", 3[a]);
    printf("%d\n", a+3);
    printf("%d\n", *(a+3));
    printf("%d\n\n", *(3+a));

    printf("%d\n", a+4);
    printf("%d\n", 4+a);
    printf("%d\n\n", *a+4);


    int* ptr1 = a;
    int* ptr2 = a+4;
    printf("%d\n", ptr2-ptr1);//Number of elements between these two pointers.
    //printf("%d\n", ptr2+ptr1);pointer addition makes no sense!

    return 0;
}
