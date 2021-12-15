#include<stdio.h>
int main(void) {
    int a[] = {54,78,15,23,90,69,84};
    printf("%p %p %p", a, &a, &a[0]);//All prints the same!
    return 0;
}

