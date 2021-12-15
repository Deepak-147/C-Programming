#include<stdio.h>

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pIndex = partition(a, low, high); /*Partition index */
        quickSort(a, low, pIndex-1);
        quickSort(a, pIndex+1, high);
    }
}

/*
Function takes last element as pivot, places the pivot element at its correct place in sorted array,
and places all elements smaller than pivot to the left of the pivot and all greater than pivot to the right of the pivot.
*/

int partition(int a[], int low, int high) {
    int i;
    int pivot = a[high];
    int pIndex = low;
    for(i = low; i < high; i++) {
        if(a[i] <= pivot) {
            swap(&a[i], &a[pIndex]);
            pIndex++;
        }
    }
    swap(&a[pIndex], &a[high]);
    return pIndex;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int a[], int length) {
    int i;
    for(i = 0; i < length; i++)
        printf("%d ", a[i]);
}

int main(void) {
    int a[] = {29, 8, 53, 16, 73, 28, 52, 90, 36, 83, 33, 92, 13, 71};
    int len = sizeof(a)/sizeof(a[0]);
    printf("\n\nArray before sorting is: ");
    display(a, len);

    quickSort(a, 0, len-1);

    printf("\n\nArray after sorting is: ");
    display(a, len);
    return 0;
}
