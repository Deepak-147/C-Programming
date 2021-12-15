#include<stdio.h>

void display(int a[], int length) {
    int i;
    for(i = 0; i < length; i++)
        printf("%d ", a[i]);
}

void mergeSort(int a[], int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        /*Combines the sorted halves */
        merge(a, left, mid, right);
    }
}

/*
Merges the two subarrays of a[],
First subarray is a[left.....mid]
Second subarray is a[mid+1.....right]
 */
void merge(int a[], int left, int mid, int right) {
    /*Length of left and right subarrays */
    int lengthOfLeft = mid - left + 1;
    int lengthOfRight = right - mid;

    /*Create two temp arrays */
    int Left[lengthOfLeft], Right[lengthOfRight];

    int i, j, k;

    /*Copy data to temp arrays Left[] and Right[] */
    for(i = 0; i < lengthOfLeft; i++)
        Left[i] = a[left + i];
    for(j = 0; j < lengthOfRight; j++)
        Right[j] = a[mid + 1 + j];

    /*Merge the temp arrays back into a[left....right] */
    i = 0; /*Initial index of first subarray */
    j = 0; /*Initial index of second subarray */
    k = left; /*Initial index of merged subarray */

    while(i < lengthOfLeft && j < lengthOfRight) {
        if(Left[i] <= Right[j]) {
            a[k] = Left[i];
            i++;
        }
        else {
            a[k] = Right[j];
            j++;
        }
        k++;
    }

    while(i < lengthOfLeft) {
        a[k] = Left[i];
        i++;
        k++;
    }

    while(j < lengthOfRight) {
        a[k] = Right[j];
        j++;
        k++;
    }
}

int main(void) {
    int a[] = {29, 8, 53, 16, 73, 28, 52, 90, 36, 83, 33, 92, 13, 71};
    int len = sizeof(a)/sizeof(a[0]);
    printf("\n\nArray before sorting is: ");
    display(a, len);

    mergeSort(a, 0, len-1);

    printf("\n\nArray after sorting is: ");
    display(a, len);
    return 0;
}
