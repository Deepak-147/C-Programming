/*
Linear Search
Time complexity: O(n)
 */

#include<stdio.h>

void linear_Search(int a[], int len, int num) {
    int i;
    for(i = 0; i < len; i++) {
        if(a[i] == num){
            printf("\nElement found ");
            return;
        }
    }
    printf("\nElement not found ");
    return;
}

int main(void) {
    int A[] = {56, 23, 90, 52, 18};
    int len = sizeof(A)/sizeof(A[0]);
    int num = 23;
    linear_Search(A, len, num);
    return 0;
}
