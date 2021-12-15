#include<stdio.h>
int main(void) {
    int arr[2][3] = {{20, 30, 40}, {200, 300, 400}};
    int *ptr;
    ptr = arr;

    printf("\n\n%d", arr[1][2]);
    printf("\n%d", &arr[1][2]);
    printf("\n%d", *(arr+1));
    printf("\n%d", *(*(arr+1) + 2));
    return(0);
}
