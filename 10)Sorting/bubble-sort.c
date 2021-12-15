/*Time complexity: O(n^2) */

#include<stdio.h>

void display(int a[], int length) {
    int i;
    for(i = 0; i < length; i++)
        printf("%d ", a[i]);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int a[], int length) {
    int i, j;
    int flag = 0;
    /*Responsible for each phase */
    for(i = 0; i < length-1; i++) {
        /*Responsible for operations in each phase */
        for(j = 0; j < length-i-1; j++) {
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        /*If no elements are swapped in the phase, then it means array is already sorted so no need to carry further phases and we can break out */
        if(flag == 0)
            break;
    }
}

int main(void) {
    int a[] = {98,37,9,67,13,41,22,1,52,5};
    int len = sizeof(a)/sizeof(a[0]);
    printf("\n\nArray before sorting is: ");
    display(a, len);

    bubbleSort(a, len);

    printf("\n\nArray after sorting is: ");
    display(a, len);
    return 0;
}

