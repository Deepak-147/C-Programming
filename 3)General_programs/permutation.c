/*
Take two input arrays of 11 integers. Output YES, if one is permutation of the other. Output NO, otherwise.
Input:
12537073521
73125052137

Output:
YES

Explanation:
12537073521 can me transformed to 73125052137. So it is a permutation and thus the output YES.

*/

#include<stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void find_permutation(int A[], int B[]) {
    int i, j, flag;
    for(i = 0; i < 11; i++) {
        flag = 0;
        for(j = i; j < 11; j++) {
            if(B[i] == A[j]) {
                swap(&A[i], &A[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("\nNO");
            return;
        }
    }
    printf("\nYES");
}

int main(void) {
    int i, A[11], B[11];
    printf("\nEnter values for first array:");
    for(i = 0; i < 11; i++)
        scanf("\n%d", &A[i]);

    printf("\nEnter values for second array:");
    for(i = 0; i < 11; i++)
        scanf("\n%d", &B[i]);

    find_permutation(A, B);
    return 0;
}
