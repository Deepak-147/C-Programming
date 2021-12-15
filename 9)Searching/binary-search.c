/*
Binary Search
Array is already sorted
Time complexity: O(log n)
*/

#include<stdio.h>

int binarySearch(int a[], int num, int start, int end) {
    if(end >= start) {
        int mid = (start + end)/2;
        /*If element is present at middle itself */
        if(num == a[mid])
            return 1;
        /*Element is in first half */
        if(num < a[mid])
            return binarySearch(a, num, start, mid-1);
        /*Element is in other half */
        return binarySearch(a, num, mid+1, end);
    }
    /*element not found */
    return 0;
}

int main(void) {
    int A[] = {10, 24, 43, 59, 77, 92, 243, 340, 552};
    int len = sizeof(A)/sizeof(A[0]);
    int num = 92;
    int res = binarySearch(A, num, 0, len-1);
    if(res)
        printf("\n\nElement found");
    else
        printf("\n\nElement not found");
    return 0;
}
